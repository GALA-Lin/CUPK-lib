# ==========================
# 科研版：图表示学习+PageRank节点分类实验
# 实验可复现 | 5折交叉验证 | 结果日志 | 科研级可视化
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
from sklearn.model_selection import cross_val_score, train_test_split
from sklearn.metrics import accuracy_score, f1_score, classification_report
from torch_geometric.datasets import Planetoid
from torch_geometric.utils import to_networkx

# ---------------------- 1. 科研实验基础配置（可复现核心） ----------------------
# 固定随机种子
SEED = 42
np.random.seed(SEED)
torch.manual_seed(SEED)
if torch.cuda.is_available():
    torch.cuda.manual_seed(SEED)
    torch.backends.cudnn.deterministic = True

# 创建实验结果保存目录
os.makedirs("./graph_experiment/results", exist_ok=True)
os.makedirs("./graph_experiment/figures", exist_ok=True)

# 配置日志输出（保存实验过程+结果，科研必备）
logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s - %(levelname)s - %(message)s",
    handlers=[
        logging.FileHandler("./graph_experiment/results/experiment_log.txt"),  # 保存到文件
        logging.StreamHandler(sys.stdout)  # 打印到控制台
    ]
)
logger = logging.getLogger(__name__)
# Gensim/Node2Vec 训练过程默认 INFO 很冗长，教学实验只保留告警以上
logging.getLogger("gensim").setLevel(logging.WARNING)
logging.getLogger("smart_open").setLevel(logging.WARNING)


def setup_matplotlib_chinese_font():
    """按系统选择常见中文字体，避免中文标题/坐标轴回退到 DejaVu 导致缺字警告。"""
    if sys.platform == "darwin":
        plt.rcParams["font.sans-serif"] = [
            "PingFang SC", "Heiti SC", "Songti SC", "STHeiti", "Arial Unicode MS",
            "SimHei", "DejaVu Sans",
        ]
    elif sys.platform.startswith("win"):
        plt.rcParams["font.sans-serif"] = ["Microsoft YaHei", "SimHei", "DejaVu Sans"]
    else:
        plt.rcParams["font.sans-serif"] = [
            "Noto Sans CJK SC", "WenQuanYi Zen Hei", "Noto Serif CJK SC", "SimHei", "DejaVu Sans",
        ]
    plt.rcParams["axes.unicode_minus"] = False


# 实验超参数配置（统一管理，方便调优）
PARAMS = {
    "node2vec_dim": 128,
    "node2vec_walk_len": 10,
    "node2vec_num_walks": 20,
    "node2vec_window": 5,
    "pagerank_alpha": 0.85,
    "lr_max_iter": 2000,
    "cv_folds": 5,  # 5折交叉验证
    "test_size": 0.2
}

# ---------------------- 2. 数据加载与预处理（封装函数，解耦模块） ----------------------
def load_cora_data():
    """加载Cora数据集并做预处理，返回图对象、节点标签、数据集信息"""
    logger.info("开始加载Cora引文网络数据集...")
    dataset = Planetoid(root="./graph_experiment/Cora", name="Cora")
    data = dataset[0]
    # 不挂接 x 可减轻 NetworkX 内存；Node2Vec/PageRank 仅需拓扑
    G = to_networkx(data, to_undirected=True)
    labels = data.y.numpy()
    
    # 输出数据集统计信息（科研实验必备）
    logger.info(f"数据集统计：节点数={G.number_of_nodes()}, 边数={G.number_of_edges()}")
    logger.info(f"类别数={dataset.num_classes}, 特征维度={dataset.num_node_features}")
    logger.info(f"训练集数={data.train_mask.sum().item()}, 测试集数={data.test_mask.sum().item()}")
    
    return G, labels, dataset

# ---------------------- 3. 图特征提取（PageRank+Node2Vec，封装函数） ----------------------
def compute_pagerank(G, alpha=0.85):
    """计算PageRank节点重要性，返回节点-分数字典"""
    logger.info(f"开始计算PageRank，阻尼因子alpha={alpha}")
    # NetworkX 不同版本参数名不同：有的用 seed，旧版曾用 random_state；均无时则完全确定性迭代
    pr_params = inspect.signature(nx.pagerank).parameters
    pr_kw = {"alpha": alpha}
    if "seed" in pr_params:
        pr_kw["seed"] = SEED
    elif "random_state" in pr_params:
        pr_kw["random_state"] = SEED
    pagerank_dict = nx.pagerank(G, **pr_kw)
    # 归一化PageRank分数（消除量纲影响，科研特征工程必备）
    pr_vals = np.array(list(pagerank_dict.values()))
    pr_min, pr_max = pr_vals.min(), pr_vals.max()
    if pr_max > pr_min:
        pr_vals = (pr_vals - pr_min) / (pr_max - pr_min)
    else:
        pr_vals = np.zeros_like(pr_vals)
    pagerank_dict = {node: pr_vals[i] for i, node in enumerate(pagerank_dict.keys())}
    logger.info(f"PageRank计算完成，分数范围=[{pr_vals.min():.6f}, {pr_vals.max():.6f}]")
    return pagerank_dict

def train_node2vec(G, params):
    """训练Node2Vec模型，返回节点嵌入字典"""
    logger.info(f"开始训练Node2Vec，参数={params}")
    node2vec_model = Node2Vec(
        G,
        dimensions=params["node2vec_dim"],
        walk_length=params["node2vec_walk_len"],
        num_walks=params["node2vec_num_walks"],
        workers=os.cpu_count(),  # 自适应多线程，提升性能
        seed=SEED,
        quiet=True  # 关闭冗余输出
    )
    w2v_model = node2vec_model.fit(
        window=params["node2vec_window"],
        min_count=1,
        seed=SEED
    )
    node_emb_dict = {n: w2v_model.wv[n] for n in G.nodes()}
    logger.info(f"Node2Vec训练完成，嵌入维度={params['node2vec_dim']}")
    return node_emb_dict

# ---------------------- 4. 特征构造与模型训练（科研级验证） ----------------------
def construct_features(node_emb_dict, pagerank_dict, G):
    """构造两组特征：纯Node2Vec / Node2Vec+PageRank"""
    logger.info("开始构造实验特征...")
    node_list = sorted(G.nodes())
    # 特征组1：仅Node2Vec嵌入
    X1 = np.array([node_emb_dict[node] for node in node_list])
    # 特征组2：Node2Vec嵌入 + 归一化PageRank特征（列拼接，特征融合）
    pr_feat = np.array([pagerank_dict[node] for node in node_list]).reshape(-1, 1)
    X2 = np.hstack([X1, pr_feat])
    logger.info(f"特征构造完成：纯Node2Vec维度={X1.shape}, 融合特征维度={X2.shape}")
    return X1, X2

def train_and_evaluate(X, y, params, feature_name):
    """
    模型训练与科学验证：
    1. 训练测试集划分
    2. 5折交叉验证（评估泛化能力）
    3. 测试集分类报告
    4. 返回核心指标（Acc, Macro-F1）
    """
    logger.info(f"开始训练与评估：{feature_name}")
    # 划分训练测试集
    X_train, X_test, y_train, y_test = train_test_split(
        X, y, test_size=params["test_size"], random_state=SEED, stratify=y  # 分层抽样，避免类别不平衡
    )
    # 定义模型
    clf = LogisticRegression(
        max_iter=params["lr_max_iter"],
        random_state=SEED,
        n_jobs=os.cpu_count()
    )
    # 5折交叉验证（科研实验必做，验证模型稳定性）
    cv_acc = cross_val_score(clf, X_train, y_train, cv=params["cv_folds"], scoring="accuracy").mean()
    cv_f1 = cross_val_score(clf, X_train, y_train, cv=params["cv_folds"], scoring="f1_macro").mean()
    logger.info(f"{feature_name} - 5折交叉验证：Acc={cv_acc:.4f}, Macro-F1={cv_f1:.4f}")
    
    # 测试集评估
    clf.fit(X_train, y_train)
    y_pred = clf.predict(X_test)
    test_acc = accuracy_score(y_test, y_pred)
    test_f1 = f1_score(y_test, y_pred, average="macro")
    # 输出分类报告（详细结果，用于论文分析）
    logger.info(f"{feature_name} - 测试集分类报告：\n{classification_report(y_test, y_pred)}")
    
    return {
        "cv_acc": cv_acc, "cv_f1": cv_f1,
        "test_acc": test_acc, "test_f1": test_f1
    }

# ---------------------- 5. 科研级可视化（封装函数，可直接用于论文） ----------------------
def plot_experiment_results(res1, res2, save_path):
    """
    绘制实验结果对比图：
    - 子图1：交叉验证指标对比
    - 子图2：测试集指标对比
    带标注、网格、图例，保存为高清png
    """
    setup_matplotlib_chinese_font()
    plt.rcParams["figure.dpi"] = 300  # 高清图（科研要求≥300dpi）
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 5))
    fig.suptitle("Node2Vec vs Node2Vec+PageRank 节点分类性能对比", fontsize=14, fontweight="bold")
    
    # 数据准备
    methods = ["纯Node2Vec", "Node2Vec+PageRank"]
    cv_accs = [res1["cv_acc"], res2["cv_acc"]]
    cv_f1s = [res1["cv_f1"], res2["cv_f1"]]
    test_accs = [res1["test_acc"], res2["test_acc"]]
    test_f1s = [res1["test_f1"], res2["test_f1"]]
    colors = ["#1f77b4", "#ff7f0e"]  # 科研配色（蓝+橙，对比明显）
    
    # 子图1：交叉验证结果
    x = np.arange(len(methods))
    width = 0.35
    ax1.bar(x - width/2, cv_accs, width, label="Accuracy", color=colors[0], alpha=0.8)
    ax1.bar(x + width/2, cv_f1s, width, label="Macro-F1", color=colors[1], alpha=0.8)
    ax1.set_title("5折交叉验证结果", fontsize=12, fontweight="bold")
    ax1.set_xlabel("特征方法", fontsize=10)
    ax1.set_ylabel("指标值", fontsize=10)
    ax1.set_xticks(x)
    ax1.set_xticklabels(methods)
    ax1.legend(loc="upper left")
    ax1.grid(axis="y", alpha=0.3)
    # 数值标注（科研图表必备）
    for i, (acc, f1) in enumerate(zip(cv_accs, cv_f1s)):
        ax1.text(i - width/2, acc + 0.01, f"{acc:.4f}", ha="center", fontsize=8)
        ax1.text(i + width/2, f1 + 0.01, f"{f1:.4f}", ha="center", fontsize=8)
    
    # 子图2：测试集结果
    ax2.bar(x - width/2, test_accs, width, label="Accuracy", color=colors[0], alpha=0.8)
    ax2.bar(x + width/2, test_f1s, width, label="Macro-F1", color=colors[1], alpha=0.8)
    ax2.set_title("测试集结果", fontsize=12, fontweight="bold")
    ax2.set_xlabel("特征方法", fontsize=10)
    ax2.set_ylabel("指标值", fontsize=10)
    ax2.set_xticks(x)
    ax2.set_xticklabels(methods)
    ax2.legend(loc="upper left")
    ax2.grid(axis="y", alpha=0.3)
    # 数值标注
    for i, (acc, f1) in enumerate(zip(test_accs, test_f1s)):
        ax2.text(i - width/2, acc + 0.01, f"{acc:.4f}", ha="center", fontsize=8)
        ax2.text(i + width/2, f1 + 0.01, f"{f1:.4f}", ha="center", fontsize=8)
    
    # 调整布局，保存高清图
    plt.tight_layout()
    plt.savefig(save_path, bbox_inches="tight", dpi=300)
    plt.close()
    logger.info(f"实验结果图已保存至：{save_path}")

def plot_graph_structure(G, labels, save_path):
    """绘制Cora网络结构可视化图，带类别着色"""
    setup_matplotlib_chinese_font()
    plt.rcParams["figure.dpi"] = 300
    plt.figure(figsize=(10, 10))
    pos = nx.spring_layout(G, seed=SEED, k=0.3)  # 固定布局，可复现
    nx.draw(
        G, pos,
        node_size=50,
        node_color=labels,
        cmap=plt.cm.tab10,
        edge_color="#cccccc",
        alpha=0.7,
        with_labels=False
    )
    plt.title("Cora引文网络结构可视化（节点颜色=类别）", fontsize=12, fontweight="bold")
    plt.savefig(save_path, bbox_inches="tight", dpi=300)
    plt.close()
    logger.info(f"网络结构图已保存至：{save_path}")

# ---------------------- 6. 实验主函数（一键运行，流程化） ----------------------
def main():
    # 步骤1：加载数据
    G, labels, dataset = load_cora_data()
    # 步骤2：提取图特征
    pagerank_dict = compute_pagerank(G, alpha=PARAMS["pagerank_alpha"])
    node_emb_dict = train_node2vec(G, PARAMS)
    # 步骤3：构造特征
    X1, X2 = construct_features(node_emb_dict, pagerank_dict, G)
    # 步骤4：模型训练与评估
    res1 = train_and_evaluate(X1, labels, PARAMS, "纯Node2Vec")
    res2 = train_and_evaluate(X2, labels, PARAMS, "Node2Vec+PageRank")
    # 步骤5：可视化
    plot_experiment_results(res1, res2, "./graph_experiment/figures/result_comparison.png")
    plot_graph_structure(G, labels, "./graph_experiment/figures/cora_graph.png")
    # 步骤6：输出实验结论（科研日志必备）
    logger.info("="*50 + "实验结论" + "="*50)
    d_acc = (res2["test_acc"] - res1["test_acc"]) * 100
    d_f1 = (res2["test_f1"] - res1["test_f1"]) * 100
    logger.info(f"PageRank特征对Accuracy的测试集变化：{d_acc:+.2f} 个百分点")
    logger.info(f"PageRank特征对Macro-F1的测试集变化：{d_f1:+.2f} 个百分点")
    if d_acc > 0.5 or d_f1 > 0.5:
        logger.info(
            "实验结论：在本设置下，融合 PageRank 对节点分类指标带来可见正向变化（可进一步调参或换划分验证）。"
        )
    else:
        logger.info(
            "实验结论：本次超参数与随机划分下，PageRank 带来的提升很小；"
            "这不代表方法无效，可尝试增大 Node2Vec 游走长度/次数、换随机种子多次平均，或改用 Cora 论文标准 train/val/test 划分对比。"
        )
    logger.info("="*106)

if __name__ == "__main__":
    main()