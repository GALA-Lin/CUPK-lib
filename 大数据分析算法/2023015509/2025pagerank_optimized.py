# ==========================
# 科研版（优化）：图表示学习+PageRank节点分类实验
# 新增：① 节点原始特征 x（1433维词袋）融合
#       ② Cora 论文标准 train/val/test 划分
# 对比方案：纯Node2Vec / +PageRank / +x特征 / +PageRank+x特征
# ==========================
import os
import sys
import logging
import inspect
import numpy as np
import networkx as nx
import matplotlib.pyplot as plt
import torch
from node2vec import Node2Vec
from sklearn.linear_model import LogisticRegression
from sklearn.neural_network import MLPClassifier

from sklearn.model_selection import cross_val_score
from sklearn.metrics import accuracy_score, f1_score, classification_report
from sklearn.preprocessing import StandardScaler
from torch_geometric.datasets import Planetoid
from torch_geometric.utils import to_networkx

# ---------------------- 1. 基础配置 ----------------------
SEED = 42
np.random.seed(SEED)
torch.manual_seed(SEED)
if torch.cuda.is_available():
    torch.cuda.manual_seed(SEED)
    torch.backends.cudnn.deterministic = True

os.makedirs("./graph_experiment/results", exist_ok=True)
os.makedirs("./graph_experiment/figures", exist_ok=True)

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s - %(levelname)s - %(message)s",
    handlers=[
        logging.FileHandler("./graph_experiment/results/experiment_log_optimized.txt"),
        logging.StreamHandler(sys.stdout)
    ]
)
logger = logging.getLogger(__name__)
logging.getLogger("gensim").setLevel(logging.WARNING)
logging.getLogger("smart_open").setLevel(logging.WARNING)


def setup_matplotlib_chinese_font():
    if sys.platform == "darwin":
        plt.rcParams["font.sans-serif"] = [
            "PingFang SC", "Heiti SC", "Songti SC", "STHeiti", "Arial Unicode MS", "SimHei", "DejaVu Sans"
        ]
    elif sys.platform.startswith("win"):
        plt.rcParams["font.sans-serif"] = ["Microsoft YaHei", "SimHei", "DejaVu Sans"]
    else:
        plt.rcParams["font.sans-serif"] = [
            "Noto Sans CJK SC", "WenQuanYi Zen Hei", "Noto Serif CJK SC", "SimHei", "DejaVu Sans"
        ]
    plt.rcParams["axes.unicode_minus"] = False


PARAMS = {
    "node2vec_dim": 128,
    "node2vec_walk_len": 30,  # 原来 10
    "node2vec_num_walks": 50,  # 原来 20
    "node2vec_window": 5,
    "pagerank_alpha": 0.85,
    "lr_max_iter": 2000,
    "cv_folds": 5,
}

# ---------------------- 2. 数据加载（新增：返回原始特征 x 和标准 mask） ----------------------
def load_cora_data():
    """
    加载 Cora，返回：
      G        - NetworkX 图（拓扑）
      labels   - 所有节点标签 (N,)
      node_x   - 节点原始词袋特征 (N, 1433)，已按 sorted(G.nodes()) 排好序
      masks    - dict: train_mask / val_mask / test_mask（Cora 标准划分，布尔数组）
    """
    logger.info("开始加载 Cora 引文网络数据集...")
    dataset = Planetoid(root="./graph_experiment/Cora", name="Cora")
    data = dataset[0]

    G = to_networkx(data, to_undirected=True)
    node_list = sorted(G.nodes())  # 保证特征行序与节点一一对应

    labels = data.y.numpy()

    # 提取节点原始特征x，按node_list顺序排列
    raw_x = data.x.numpy()           # shape (N, 1433)，节点 id 即行号
    node_x = raw_x[node_list]        # 按 sorted 节点顺序重新索引（Cora 节点 id 连续，一般等价）

    # Cora标准划分mask
    masks = {
        "train": data.train_mask.numpy()[node_list],
        "val":   data.val_mask.numpy()[node_list],
        "test":  data.test_mask.numpy()[node_list],
    }

    logger.info(f"节点数={G.number_of_nodes()}, 边数={G.number_of_edges()}")
    logger.info(f"类别数={dataset.num_classes}, 原始特征维度={dataset.num_node_features}")
    logger.info(
        f"标准划分 - 训练:{masks['train'].sum()} / 验证:{masks['val'].sum()} / 测试:{masks['test'].sum()}"
    )

    return G, labels[node_list], node_x, masks, node_list


# ---------------------- 3. 图特征提取 ----------------------
def compute_pagerank(G, node_list, alpha=0.85):
    logger.info(f"计算 PageRank，alpha={alpha}")
    pr_params = inspect.signature(nx.pagerank).parameters
    pr_kw = {"alpha": alpha}
    if "seed" in pr_params:
        pr_kw["seed"] = SEED
    elif "random_state" in pr_params:
        pr_kw["random_state"] = SEED
    pr_dict = nx.pagerank(G, **pr_kw)

    pr_vals = np.array([pr_dict[n] for n in node_list])
    pr_min, pr_max = pr_vals.min(), pr_vals.max()
    pr_vals = (pr_vals - pr_min) / (pr_max - pr_min) if pr_max > pr_min else np.zeros_like(pr_vals)
    logger.info(f"PageRank 范围=[{pr_vals.min():.6f}, {pr_vals.max():.6f}]")
    return pr_vals.reshape(-1, 1)   # (N, 1)


def train_node2vec(G, params):
    logger.info(f"训练 Node2Vec，dim={params['node2vec_dim']}")
    model = Node2Vec(
        G,
        dimensions=params["node2vec_dim"],
        walk_length=params["node2vec_walk_len"],
        num_walks=params["node2vec_num_walks"],
        workers=os.cpu_count(),
        seed=SEED,
        quiet=True,
    )
    w2v = model.fit(window=params["node2vec_window"], min_count=1, seed=SEED)
    logger.info("Node2Vec 训练完成")
    return w2v


# ---------------------- 4. 特征构造（4种对比方案） ----------------------
def construct_all_features(w2v, pr_feat, node_x, node_list, params):
    """
    返回 4 组特征（均已对原始特征 x 做 StandardScaler 归一化）：
      X_n2v        : 纯 Node2Vec (N, 128)
      X_n2v_pr     : Node2Vec + PageRank (N, 129)
      X_n2v_x      : Node2Vec + 原始特征 x (N, 128+1433)
      X_n2v_pr_x   : Node2Vec + PageRank + 原始特征 x (N, 130+1433)
    """
    logger.info("构造 4 组对比特征...")

    # Node2Vec 嵌入（按 node_list 顺序）
    emb = np.array([w2v.wv[n] for n in node_list])   # (N, dim)

    # 方向1：对原始 x 做标准化（量纲对齐，防止高维特征淹没嵌入）
    scaler = StandardScaler()
    x_scaled = scaler.fit_transform(node_x)           # (N, 1433)

    X_n2v      = emb
    X_n2v_pr   = np.hstack([emb, pr_feat])
    X_n2v_x    = np.hstack([emb, x_scaled])           # ← 核心新增
    X_n2v_pr_x = np.hstack([emb, pr_feat, x_scaled])  # ← 全融合

    for name, X in [("Node2Vec", X_n2v), ("+PageRank", X_n2v_pr),
                    ("+x特征", X_n2v_x), ("+PageRank+x", X_n2v_pr_x)]:
        logger.info(f"  {name} 维度={X.shape}")

    return X_n2v, X_n2v_pr, X_n2v_x, X_n2v_pr_x


# ---------------------- 5. 模型训练与评估（双模式：随机划分 & 标准划分） ----------------------
def train_and_evaluate_random(X, y, params, name):
    """原始随机 80/20 划分 + 5折交叉验证（保留兼容）"""
    from sklearn.model_selection import train_test_split
    X_tr, X_te, y_tr, y_te = train_test_split(
        X, y, test_size=0.2, random_state=SEED, stratify=y
    )
    clf = MLPClassifier(
        hidden_layer_sizes=(256, 128),
        max_iter=500,
        random_state=SEED
    )
    cv_acc = cross_val_score(clf, X_tr, y_tr, cv=params["cv_folds"], scoring="accuracy").mean()
    cv_f1  = cross_val_score(clf, X_tr, y_tr, cv=params["cv_folds"], scoring="f1_macro").mean()
    clf.fit(X_tr, y_tr)
    y_pred = clf.predict(X_te)
    return {
        "name": name,
        "cv_acc": cv_acc, "cv_f1": cv_f1,
        "test_acc": accuracy_score(y_te, y_pred),
        "test_f1":  f1_score(y_te, y_pred, average="macro"),
    }


def train_and_evaluate_standard(X, y, masks, params, name):
    """
    使用 Cora 论文标准 train/val/test 划分
    训练集：140条（20类×7）| 测试集：1000条（论文固定）
    5折 CV 在标准训练集上做
    """
    X_tr, y_tr = X[masks["train"]], y[masks["train"]]
    X_te, y_te = X[masks["test"]],  y[masks["test"]]

    clf = MLPClassifier(
        hidden_layer_sizes=(256, 128),
        max_iter=500,
        random_state=SEED
    )
    # 训练集仅 140 条，cv_folds 设为 5 时每折 ~28 条，仍可运行
    cv_folds = min(params["cv_folds"], len(y_tr) // 7)
    cv_acc = cross_val_score(clf, X_tr, y_tr, cv=cv_folds, scoring="accuracy").mean()
    cv_f1  = cross_val_score(clf, X_tr, y_tr, cv=cv_folds, scoring="f1_macro").mean()

    clf.fit(X_tr, y_tr)
    y_pred = clf.predict(X_te)
    test_acc = accuracy_score(y_te, y_pred)
    test_f1  = f1_score(y_te, y_pred, average="macro")

    logger.info(f"[标准划分] {name} - CV Acc={cv_acc:.4f}, CV F1={cv_f1:.4f}")
    logger.info(f"[标准划分] {name} - Test Acc={test_acc:.4f}, Test F1={test_f1:.4f}")
    logger.info(f"分类报告：\n{classification_report(y_te, y_pred)}")

    return {
        "name": name,
        "cv_acc": cv_acc, "cv_f1": cv_f1,
        "test_acc": test_acc, "test_f1": test_f1,
    }


# ---------------------- 6. 可视化 ----------------------
def plot_comparison(results, title, save_path, mode_label="测试集"):
    """通用多方案对比柱状图"""
    setup_matplotlib_chinese_font()
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 5))
    fig.suptitle(title, fontsize=14, fontweight="bold")

    names    = [r["name"] for r in results]
    cv_accs  = [r["cv_acc"]  for r in results]
    cv_f1s   = [r["cv_f1"]   for r in results]
    t_accs   = [r["test_acc"] for r in results]
    t_f1s    = [r["test_f1"]  for r in results]
    colors   = ["#1f77b4", "#ff7f0e", "#2ca02c", "#d62728"]

    x, w = np.arange(len(names)), 0.35

    for ax, accs, f1s, subtitle in [
        (ax1, cv_accs, cv_f1s, f"5折交叉验证"),
        (ax2, t_accs,  t_f1s,  mode_label),
    ]:
        bars1 = ax.bar(x - w/2, accs, w, label="Accuracy", alpha=0.85,
                       color=[colors[i] for i in range(len(names))])
        bars2 = ax.bar(x + w/2, f1s,  w, label="Macro-F1", alpha=0.55,
                       color=[colors[i] for i in range(len(names))], hatch="//")
        ax.set_title(subtitle, fontsize=12, fontweight="bold")
        ax.set_xticks(x)
        ax.set_xticklabels(names, fontsize=8, rotation=10)
        ax.set_ylabel("指标值")
        ax.legend(loc="lower right", fontsize=8)
        ax.grid(axis="y", alpha=0.3)
        ax.set_ylim(0, max(max(accs), max(f1s)) + 0.12)
        for i, (a, f) in enumerate(zip(accs, f1s)):
            ax.text(i - w/2, a + 0.005, f"{a:.4f}", ha="center", fontsize=7)
            ax.text(i + w/2, f + 0.005, f"{f:.4f}", ha="center", fontsize=7)

    plt.tight_layout()
    plt.savefig(save_path, bbox_inches="tight", dpi=300)
    plt.close()
    logger.info(f"图表已保存：{save_path}")


def plot_feature_dim_bar(results, save_path):
    """附图：各方案特征维度对比（直观展示融合代价）"""
    setup_matplotlib_chinese_font()
    dims = {"纯N2V": 128, "+PR": 129, "+x": 128+1433, "+PR+x": 129+1433}
    fig, ax = plt.subplots(figsize=(7, 4))
    colors = ["#1f77b4", "#ff7f0e", "#2ca02c", "#d62728"]
    bars = ax.barh(list(dims.keys()), list(dims.values()), color=colors, alpha=0.8)
    ax.set_xlabel("特征维度")
    ax.set_title("各方案特征维度对比", fontweight="bold")
    for bar, val in zip(bars, dims.values()):
        ax.text(val + 10, bar.get_y() + bar.get_height()/2, str(val), va="center", fontsize=10)
    plt.tight_layout()
    plt.savefig(save_path, bbox_inches="tight", dpi=300)
    plt.close()
    logger.info(f"特征维度图已保存：{save_path}")


# ---------------------- 7. 主函数 ----------------------
def main():
    # 步骤1：加载数据（含 x 特征 和 标准划分 mask）
    G, labels, node_x, masks, node_list = load_cora_data()

    # 步骤2：提取图特征
    pr_feat      = compute_pagerank(G, node_list, alpha=PARAMS["pagerank_alpha"])
    w2v          = train_node2vec(G, PARAMS)

    # 步骤3：构造 4 组特征
    X_n2v, X_n2v_pr, X_n2v_x, X_n2v_pr_x = construct_all_features(
        w2v, pr_feat, node_x, node_list, PARAMS
    )

    feature_groups = [
        ("纯N2V",   X_n2v),
        ("+PR",     X_n2v_pr),
        ("+x",      X_n2v_x),
        ("+PR+x",   X_n2v_pr_x),
    ]

    # ─────────────────────────────────────────────────────────
    # 步骤4a：随机 80/20 划分（与原实验对齐，方便横向比较）
    # ─────────────────────────────────────────────────────────
    logger.info("\n" + "="*30 + " 随机划分实验 " + "="*30)
    rand_results = []
    for name, X in feature_groups:
        res = train_and_evaluate_random(X, labels, PARAMS, name)
        rand_results.append(res)
        logger.info(
            f"[随机划分] {name} - CV Acc={res['cv_acc']:.4f} F1={res['cv_f1']:.4f} | "
            f"Test Acc={res['test_acc']:.4f} F1={res['test_f1']:.4f}"
        )

    # ─────────────────────────────────────────────────────────
    # 步骤4b：★ Cora 标准划分（方向4，可与文献直接对比）
    # ─────────────────────────────────────────────────────────
    logger.info("\n" + "="*30 + " 标准划分实验 " + "="*30)
    std_results = []
    for name, X in feature_groups:
        res = train_and_evaluate_standard(X, labels, masks, PARAMS, name)
        std_results.append(res)

    # 步骤5：可视化
    plot_comparison(
        rand_results,
        title="4种特征方案对比（随机80/20划分）",
        save_path="./graph_experiment/figures/random_split_comparison.png",
        mode_label="测试集(随机)",
    )
    plot_comparison(
        std_results,
        title="4种特征方案对比（Cora标准划分，可与文献对比）",
        save_path="./graph_experiment/figures/standard_split_comparison.png",
        mode_label="测试集(标准)",
    )
    plot_feature_dim_bar(
        std_results,
        save_path="./graph_experiment/figures/feature_dim_comparison.png",
    )

    # 步骤6：实验结论汇总
    logger.info("\n" + "="*30 + " 实验结论汇总 " + "="*30)
    logger.info(f"{'方案':<12} {'随机_Acc':>10} {'随机_F1':>10} {'标准_Acc':>10} {'标准_F1':>10}")
    for r, s in zip(rand_results, std_results):
        logger.info(
            f"{r['name']:<12} {r['test_acc']:>10.4f} {r['test_f1']:>10.4f} "
            f"{s['test_acc']:>10.4f} {s['test_f1']:>10.4f}"
        )

    # 定位最佳方案
    best_std = max(std_results, key=lambda r: r["test_acc"])
    logger.info(f"\n标准划分下最优方案：{best_std['name']}，Test Acc={best_std['test_acc']:.4f}")

    base_std = std_results[0]   # 纯 Node2Vec 作为基线
    for r in std_results[1:]:
        delta = (r["test_acc"] - base_std["test_acc"]) * 100
        logger.info(f"  {r['name']} 相对纯N2V提升：{delta:+.2f} 个百分点")


if __name__ == "__main__":
    main()
