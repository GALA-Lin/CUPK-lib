# ==========================
# 科研版：推荐系统-ItemCF vs SVD矩阵分解对比实验（增强版）
# 必做任务全覆盖 + 进阶任务1（稀疏性实验）+ 进阶任务3（混合推荐）
# ==========================
import os
import sys
import ssl
ssl._create_default_https_context = ssl._create_unverified_context

import logging
import random
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from surprise import Dataset, Reader, SVD, accuracy, Trainset
from surprise.model_selection import train_test_split
from collections import defaultdict
from scipy import stats

# ---------------------- 1. 实验基础配置 ----------------------
SEED = 42
np.random.seed(SEED)
random.seed(SEED)

os.makedirs("./recsys_experiment/results", exist_ok=True)
os.makedirs("./recsys_experiment/figures", exist_ok=True)

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s - %(levelname)s - %(message)s",
    handlers=[
        logging.FileHandler("./recsys_experiment/results/recsys_experiment_log.txt"),
        logging.StreamHandler(sys.stdout)
    ]
)
logger = logging.getLogger(__name__)

PARAMS = {
    "itemcf_k": 20,
    "svd_n_factors": 100,
    "svd_n_epochs": 20,
    "svd_lr_all": 0.005,
    "svd_reg_all": 0.02,
    "test_size": 0.2,
    "cv_folds": 5,
}

RATING_MIN = 1
RATING_MAX = 5


# ---------------------- 2. 数据加载 ----------------------
def load_movielens100k():
    logger.info("Loading MovieLens-100K dataset...")
    data = Dataset.load_builtin("ml-100k", prompt=False)
    trainset, testset = train_test_split(data, test_size=PARAMS["test_size"], random_state=SEED)

    n_users = trainset.n_users
    n_items = trainset.n_items
    n_ratings = trainset.n_ratings
    sparsity = 1 - n_ratings / (n_users * n_items)
    avg_rating = np.mean([r for (_, _, r) in trainset.all_ratings()])

    logger.info(f"Users={n_users}, Items={n_items}, Ratings={n_ratings}")
    logger.info(f"Sparsity={sparsity:.4f}, Avg rating={avg_rating:.2f}")
    logger.info(f"Train={trainset.n_ratings}, Test={len(testset)}")

    return data, trainset, testset


# ---------------------- 3. ItemCF（皮尔逊相似度） ----------------------
class ItemCF_KDemo:
    def __init__(self, k=20, rating_min=1, rating_max=5):
        self.k = k
        self.rating_min = rating_min
        self.rating_max = rating_max
        self.item_sim = None
        self.user_item = None
        self.item_user = None
        self.item_mean = None

    def fit(self, trainset):
        logger.info(f"Start training ItemCF (Pearson), k={self.k}")
        self.user_item = defaultdict(dict)
        self.item_user = defaultdict(dict)
        self.item_mean = defaultdict(float)

        for u, i, r in trainset.all_ratings():
            self.user_item[u][i] = r
            self.item_user[i][u] = r

        for i, users in self.item_user.items():
            self.item_mean[i] = np.mean(list(users.values()))

        self.item_sim = defaultdict(dict)
        items = list(self.item_user.keys())
        n = len(items)

        for idx, i in enumerate(items):
            if idx % 200 == 0:
                logger.info(f"ItemCF progress: {idx}/{n}")
            u_i = set(self.item_user[i].keys())
            for j in items[idx + 1:]:
                u_j = set(self.item_user[j].keys())
                common = u_i & u_j
                if len(common) < 2:
                    continue
                ri = np.array([self.item_user[i][u] for u in common])
                rj = np.array([self.item_user[j][u] for u in common])
                mi, mj = self.item_mean[i], self.item_mean[j]
                num = np.sum((ri - mi) * (rj - mj))
                den = np.sqrt(np.sum((ri - mi) ** 2)) * np.sqrt(np.sum((rj - mj) ** 2))
                sim = num / (den + 1e-8) if den != 0 else 0
                self.item_sim[i][j] = sim
                self.item_sim[j][i] = sim

        logger.info("ItemCF training completed.")

    def predict(self, uid, iid):
        if uid not in self.user_item or iid not in self.item_sim:
            return (self.rating_min + self.rating_max) / 2
        neighbors = sorted(self.item_sim[iid].items(), key=lambda x: -x[1])[:self.k]
        sum_sim, sum_r = 0.0, 0.0
        for j, s in neighbors:
            if j in self.user_item[uid]:
                sum_sim += s
                sum_r += s * self.user_item[uid][j]
        if abs(sum_sim) < 1e-8:
            return self.item_mean.get(iid, (self.rating_min + self.rating_max) / 2)
        return np.clip(sum_r / sum_sim, self.rating_min, self.rating_max)

    def recommend(self, uid, top_n=10):
        if uid not in self.user_item:
            return self._get_hot(top_n)
        rated = set(self.user_item[uid].keys())
        preds = {i: self.predict(uid, i) for i in self.item_sim if i not in rated}
        return [i for i, _ in sorted(preds.items(), key=lambda x: -x[1])[:top_n]]

    def _get_hot(self, n=10):
        cnt = defaultdict(int)
        for u in self.user_item:
            for i in self.user_item[u]:
                cnt[i] += 1
        return [i for i, _ in sorted(cnt.items(), key=lambda x: -x[1])[:n]]


# ---------------------- 4. SVD 训练 ----------------------
def train_svd(trainset, params):
    logger.info(f"Training SVD (n_factors={params['svd_n_factors']})...")
    svd = SVD(
        n_factors=params["svd_n_factors"],
        n_epochs=params["svd_n_epochs"],
        lr_all=params["svd_lr_all"],
        reg_all=params["svd_reg_all"],
        random_state=SEED
    )
    svd.fit(trainset)
    logger.info("SVD training completed.")
    return svd


# ---------------------- 5. 评估函数 ----------------------
def evaluate_model(model, testset, name):
    """通用评估：支持 ItemCF / SVD / HybridModel"""
    true_ratings, pred_ratings = [], []
    for u, i, r in testset:
        true_ratings.append(r)
        if hasattr(model, 'predict_score'):  # HybridModel
            pred_ratings.append(model.predict_score(u, i))
        elif isinstance(model, ItemCF_KDemo):  # ItemCF（任何名字都能正确识别）
            pred_ratings.append(model.predict(u, i))
        else:  # SVD
            pred_ratings.append(model.predict(u, i).est)

    true_arr = np.array(true_ratings)
    pred_arr = np.array(pred_ratings)
    rmse = np.sqrt(np.mean((true_arr - pred_arr) ** 2))
    mae = np.mean(np.abs(true_arr - pred_arr))
    corr, p_val = stats.pearsonr(true_arr, pred_arr)

    logger.info(f"{name}: RMSE={rmse:.4f}, MAE={mae:.4f}, Corr={corr:.4f}(p={p_val:.2e})")
    return rmse, mae


# ---------------------- 6. 冷启动分析 ----------------------
def cold_start_analysis(itemcf, svd, trainset):
    logger.info("Cold-start evaluation...")
    user_items = defaultdict(list)
    for u, i, r in trainset.all_ratings():
        user_items[u].append((i, r))

    candidates = [u for u, il in user_items.items() if len(il) >= 6]
    levels = [1, 3, 5]
    itemcf_hits, svd_hits = [], []

    for L in levels:
        ih = sh = cnt = 0
        for uid in candidates:
            il = user_items[uid]
            hist = il[:L]
            test = [i for i, _ in il[L:]]
            if not test:
                continue

            bak = itemcf.user_item[uid].copy()
            itemcf.user_item[uid] = {i: r for i, r in hist}

            rec_itemcf = set(itemcf.recommend(uid, 10))
            ih += len(set(test) & rec_itemcf) / len(test)

            all_items = list(itemcf.item_user.keys())
            hist_items = {x[0] for x in hist}
            scores = [(i, svd.predict(uid, i).est) for i in all_items if i not in hist_items]
            rec_svd = {i for i, _ in sorted(scores, key=lambda x: -x[1])[:10]}
            sh += len(set(test) & rec_svd) / len(test)

            itemcf.user_item[uid] = bak
            cnt += 1

        itemcf_hits.append(ih / cnt if cnt else 0)
        svd_hits.append(sh / cnt if cnt else 0)
        logger.info(f"Known={L} ratings | ItemCF Hit={itemcf_hits[-1]:.3f} | SVD Hit={svd_hits[-1]:.3f}")

    return levels, itemcf_hits, svd_hits


# ============================================================
# ★ 必做任务4：超参数敏感性实验
# ============================================================
def hyperparam_experiment(data, trainset, testset):
    """
    4a. ItemCF：K = 5/10/20/30 对 RMSE 的影响
    4b. SVD：n_factors = 50/100/200 对 RMSE 的影响
    """
    logger.info("=" * 30 + " Hyperparameter Sensitivity Experiment " + "=" * 30)

    # --- 4a. ItemCF K 值实验 ---
    k_values = [5, 10, 20, 30]
    k_rmses, k_maes = [], []
    logger.info("ItemCF K sensitivity...")
    for k in k_values:
        model = ItemCF_KDemo(k=k)
        model.fit(trainset)
        rmse, mae = evaluate_model(model, testset, f"ItemCF(k={k})")
        k_rmses.append(rmse)
        k_maes.append(mae)

    # --- 4b. SVD 隐因子数量实验 ---
    factor_values = [50, 100, 200]
    f_rmses, f_maes = [], []
    logger.info("SVD n_factors sensitivity...")
    for f in factor_values:
        params = {**PARAMS, "svd_n_factors": f}
        model = train_svd(trainset, params)
        rmse, mae = evaluate_model(model, testset, f"SVD(factors={f})")
        f_rmses.append(rmse)
        f_maes.append(mae)

    # --- 绘图 ---
    fig, axes = plt.subplots(1, 2, figsize=(13, 5))
    fig.suptitle("Hyperparameter Sensitivity Analysis", fontsize=14, fontweight="bold")

    # ItemCF K
    ax = axes[0]
    ax.plot(k_values, k_rmses, marker="o", color="#1f77b4", linewidth=2, label="RMSE")
    ax.plot(k_values, k_maes, marker="s", color="#ff7f0e", linewidth=2, linestyle="--", label="MAE")
    ax.set_title("ItemCF: Effect of Neighbor Count K")
    ax.set_xlabel("K (Number of Neighbors)")
    ax.set_ylabel("Error (Lower is Better)")
    ax.set_xticks(k_values)
    ax.legend()
    ax.grid(alpha=0.3)
    for x, y in zip(k_values, k_rmses):
        ax.annotate(f"{y:.4f}", (x, y), textcoords="offset points", xytext=(0, 8), ha="center", fontsize=9)

    # SVD n_factors
    ax = axes[1]
    ax.plot(factor_values, f_rmses, marker="o", color="#2ca02c", linewidth=2, label="RMSE")
    ax.plot(factor_values, f_maes, marker="s", color="#d62728", linewidth=2, linestyle="--", label="MAE")
    ax.set_title("SVD: Effect of Latent Factors")
    ax.set_xlabel("Number of Latent Factors")
    ax.set_ylabel("Error (Lower is Better)")
    ax.set_xticks(factor_values)
    ax.legend()
    ax.grid(alpha=0.3)
    for x, y in zip(factor_values, f_rmses):
        ax.annotate(f"{y:.4f}", (x, y), textcoords="offset points", xytext=(0, 8), ha="center", fontsize=9)

    plt.tight_layout()
    path = "./recsys_experiment/figures/hyperparam_sensitivity.png"
    plt.savefig(path, dpi=300, bbox_inches="tight")
    plt.close()
    logger.info(f"Saved: {path}")

    return {
        "k_values": k_values, "k_rmses": k_rmses, "k_maes": k_maes,
        "factor_values": factor_values, "f_rmses": f_rmses, "f_maes": f_maes
    }


# ============================================================
# ★ 进阶任务1：数据稀疏性影响实验
# ============================================================
def sparsity_experiment(data, testset):
    """
    构造三种稀疏度数据集（低/中/高），分别训练 ItemCF 和 SVD，
    对比两个模型在稀疏数据上的鲁棒性。
    保留比例：低稀疏=80%, 中稀疏=50%, 高稀疏=20%（即删除20/50/80%评分）
    """
    logger.info("=" * 30 + " Sparsity Robustness Experiment " + "=" * 30)

    # 获取完整训练集原始评分列表
    full_data, full_train, _ = load_movielens100k()
    all_ratings = list(full_train.all_ratings())   # [(uid_inner, iid_inner, r), ...]

    levels = {
        "Low Sparsity\n(keep 80%)":  0.80,
        "Mid Sparsity\n(keep 50%)":  0.50,
        "High Sparsity\n(keep 20%)": 0.20,
    }

    itemcf_rmses, svd_rmses = [], []
    label_names = list(levels.keys())

    for label, keep_ratio in levels.items():
        logger.info(f"Sparsity level: {label.strip()} | keep_ratio={keep_ratio}")

        # 随机保留 keep_ratio 比例的评分
        random.seed(SEED)
        sampled = random.sample(all_ratings, int(len(all_ratings) * keep_ratio))

        # 用 surprise 的内部 id 直接构造 Trainset
        # 需要重新映射到原始 raw id
        raw_trainset = full_train  # 用于 id 转换
        sampled_raw = []
        for u_inner, i_inner, r in sampled:
            try:
                u_raw = raw_trainset.to_raw_uid(u_inner)
                i_raw = raw_trainset.to_raw_iid(i_inner)
                sampled_raw.append((u_raw, i_raw, r))
            except Exception:
                continue

        # 用 Reader + 临时 DataFrame 重建 surprise 数据集
        df = pd.DataFrame(sampled_raw, columns=["user", "item", "rating"])
        reader = Reader(rating_scale=(RATING_MIN, RATING_MAX))
        sparse_data = Dataset.load_from_df(df[["user", "item", "rating"]], reader)
        sparse_trainset = sparse_data.build_full_trainset()

        # 训练并评估 ItemCF
        icf = ItemCF_KDemo(k=PARAMS["itemcf_k"])
        icf.fit(sparse_trainset)
        # 评估时 testset 里用的是 raw id，ItemCF 内部也是 inner id（fit 过程中自动建 map）
        # 这里评估需要用 raw id 版本的 predict
        icf_preds = []
        icf_trues = []
        for u_raw, i_raw, r_true in testset:
            # 把 raw uid/iid 转成 sparse_trainset 的 inner id（可能不存在 → 冷启动）
            try:
                u_in = sparse_trainset.to_inner_uid(u_raw)
            except ValueError:
                u_in = None
            try:
                i_in = sparse_trainset.to_inner_iid(i_raw)
            except ValueError:
                i_in = None
            p = icf.predict(u_in, i_in) if (u_in is not None and i_in is not None) else (RATING_MIN + RATING_MAX) / 2
            icf_preds.append(p)
            icf_trues.append(r_true)
        icf_rmse = np.sqrt(np.mean((np.array(icf_trues) - np.array(icf_preds)) ** 2))
        logger.info(f"  ItemCF RMSE={icf_rmse:.4f}")

        # 训练并评估 SVD
        svd_model = train_svd(sparse_trainset, PARAMS)
        svd_preds, svd_trues = [], []
        for u_raw, i_raw, r_true in testset:
            svd_trues.append(r_true)
            svd_preds.append(svd_model.predict(u_raw, i_raw).est)
        svd_rmse = np.sqrt(np.mean((np.array(svd_trues) - np.array(svd_preds)) ** 2))
        logger.info(f"  SVD RMSE={svd_rmse:.4f}")

        itemcf_rmses.append(icf_rmse)
        svd_rmses.append(svd_rmse)

    # 绘图
    fig, ax = plt.subplots(figsize=(9, 5))
    x = np.arange(len(label_names))
    w = 0.35
    bars1 = ax.bar(x - w / 2, itemcf_rmses, w, label="ItemCF", color="#1f77b4")
    bars2 = ax.bar(x + w / 2, svd_rmses, w, label="SVD", color="#2ca02c")
    ax.set_title("Sparsity Robustness: ItemCF vs SVD", fontsize=13, fontweight="bold")
    ax.set_xlabel("Data Sparsity Level")
    ax.set_ylabel("RMSE (Lower is Better)")
    ax.set_xticks(x)
    ax.set_xticklabels(label_names, fontsize=9)
    ax.legend()
    ax.grid(axis="y", alpha=0.3)
    for bar in bars1:
        ax.text(bar.get_x() + bar.get_width() / 2, bar.get_height() + 0.005,
                f"{bar.get_height():.4f}", ha="center", va="bottom", fontsize=8)
    for bar in bars2:
        ax.text(bar.get_x() + bar.get_width() / 2, bar.get_height() + 0.005,
                f"{bar.get_height():.4f}", ha="center", va="bottom", fontsize=8)
    plt.tight_layout()
    path = "./recsys_experiment/figures/sparsity_robustness.png"
    plt.savefig(path, dpi=300, bbox_inches="tight")
    plt.close()
    logger.info(f"Saved: {path}")

    return label_names, itemcf_rmses, svd_rmses


# ============================================================
# ★ 进阶任务3：混合推荐系统
# ============================================================
class HybridRecommender:
    """
    混合推荐策略：
    - 正常用户：alpha * ItemCF_score + (1-alpha) * SVD_score
    - 冷启动用户（user_item 中无评分）：全走 SVD 预测
    - 物品均值兜底：当 ItemCF 近邻全为空时，用物品均值填充
    """

    def __init__(self, itemcf: ItemCF_KDemo, svd: SVD, alpha=0.4,
                 rating_min=1, rating_max=5):
        self.itemcf = itemcf
        self.svd = svd
        self.alpha = alpha          # ItemCF 权重
        self.rating_min = rating_min
        self.rating_max = rating_max
        self.global_mean = np.mean(list(
            v for uid_dict in itemcf.user_item.values() for v in uid_dict.values()
        ))

    def _item_mean_fallback(self, iid):
        return self.itemcf.item_mean.get(iid, self.global_mean)

    def predict_score(self, uid, iid):
        svd_score = self.svd.predict(uid, iid).est

        # 冷启动用户：直接返回 SVD 分数
        if uid not in self.itemcf.user_item or len(self.itemcf.user_item[uid]) == 0:
            return np.clip(svd_score, self.rating_min, self.rating_max)

        # ItemCF 分数
        icf_score = self.itemcf.predict(uid, iid)

        # 若 ItemCF 退化为物品均值兜底，降低其权重
        neighbors = sorted(
            self.itemcf.item_sim.get(iid, {}).items(), key=lambda x: -x[1]
        )[:self.itemcf.k]
        has_neighbor = any(j in self.itemcf.user_item.get(uid, {}) for j, _ in neighbors)
        alpha = self.alpha if has_neighbor else 0.1   # 近邻为空时更依赖 SVD

        hybrid = alpha * icf_score + (1 - alpha) * svd_score
        return np.clip(hybrid, self.rating_min, self.rating_max)

    def recommend(self, uid, top_n=10):
        # 热门物品作候选（排除已评分）
        rated = set(self.itemcf.user_item.get(uid, {}).keys())
        all_items = list(self.itemcf.item_user.keys())
        scores = {i: self.predict_score(uid, i) for i in all_items if i not in rated}
        return [i for i, _ in sorted(scores.items(), key=lambda x: -x[1])[:top_n]]


# ---------------------- 7. 标准结果绘图 ----------------------
def plot_recsys_results(metrics, cold_data):
    plt.rcParams["figure.dpi"] = 300
    plt.rcParams["font.sans-serif"] = ["DejaVu Sans"]
    plt.rcParams["axes.unicode_minus"] = False

    # --- 柱状图：RMSE & MAE 对比 ---
    fig, ax = plt.subplots(figsize=(9, 5))
    models = ["ItemCF", "SVD", "Hybrid"]
    rmses = [metrics["itemcf_rmse"], metrics["svd_rmse"], metrics["hybrid_rmse"]]
    maes  = [metrics["itemcf_mae"],  metrics["svd_mae"],  metrics["hybrid_mae"]]
    x = np.arange(len(models))
    w = 0.35
    b1 = ax.bar(x - w / 2, rmses, w, label="RMSE", color="#1f77b4")
    b2 = ax.bar(x + w / 2, maes,  w, label="MAE",  color="#ff7f0e")
    ax.set_title("Prediction Performance Comparison (ItemCF vs SVD vs Hybrid)", fontsize=12, fontweight="bold")
    ax.set_xlabel("Model")
    ax.set_ylabel("Error (Lower is Better)")
    ax.set_xticks(x)
    ax.set_xticklabels(models)
    ax.legend()
    ax.grid(axis="y", alpha=0.3)
    for bar in list(b1) + list(b2):
        ax.text(bar.get_x() + bar.get_width() / 2, bar.get_height() + 0.002,
                f"{bar.get_height():.4f}", ha="center", va="bottom", fontsize=8)
    plt.tight_layout()
    plt.savefig("./recsys_experiment/figures/ratings_comparison.png", bbox_inches="tight")
    plt.close()

    # --- 冷启动命中率折线图 ---
    fig, ax = plt.subplots(figsize=(8, 5))
    xs, i_hit, s_hit = cold_data
    ax.plot(xs, i_hit, marker="o", label="ItemCF", linewidth=2, color="#1f77b4")
    ax.plot(xs, s_hit, marker="s", label="SVD",    linewidth=2, color="#2ca02c")
    ax.set_title("Cold-Start Hit Rate: ItemCF vs SVD", fontsize=12, fontweight="bold")
    ax.set_xlabel("Number of Known Ratings")
    ax.set_ylabel("Hit Rate (Higher is Better)")
    ax.legend()
    ax.grid(alpha=0.3)
    plt.tight_layout()
    plt.savefig("./recsys_experiment/figures/cold_start.png", bbox_inches="tight")
    plt.close()

    logger.info("Standard figures saved.")


# ---------------------- 8. 主函数 ----------------------
def main():
    # ── 数据加载 ──
    data, trainset, testset = load_movielens100k()

    # ── 基础模型训练 ──
    itemcf = ItemCF_KDemo(k=PARAMS["itemcf_k"])
    itemcf.fit(trainset)

    svd = train_svd(trainset, PARAMS)

    # ── 必做：基础评估 ──
    logger.info("=" * 30 + " Base Evaluation " + "=" * 30)
    itemcf_rmse, itemcf_mae = evaluate_model(itemcf, testset, "ItemCF")
    svd_rmse,    svd_mae    = evaluate_model(svd,    testset, "SVD")

    # ── 进阶3：混合推荐 ──
    logger.info("=" * 30 + " Hybrid Recommender " + "=" * 30)
    hybrid = HybridRecommender(itemcf, svd, alpha=0.4)
    hybrid_rmse, hybrid_mae = evaluate_model(hybrid, testset, "Hybrid")

    metrics = {
        "itemcf_rmse": itemcf_rmse, "itemcf_mae": itemcf_mae,
        "svd_rmse":    svd_rmse,    "svd_mae":    svd_mae,
        "hybrid_rmse": hybrid_rmse, "hybrid_mae": hybrid_mae,
    }

    # ── 冷启动分析 ──
    cold_data = cold_start_analysis(itemcf, svd, trainset)

    # ── 标准绘图 ──
    plot_recsys_results(metrics, cold_data)

    # ── 必做4：超参数敏感性实验 ──
    hyperparam_experiment(data, trainset, testset)

    # ── 进阶1：稀疏性实验 ──
    sparsity_experiment(data, testset)

    # ── 实验结论 ──
    logger.info("=" * 50 + " Experiment Conclusion " + "=" * 50)
    logger.info(f"ItemCF  : RMSE={itemcf_rmse:.4f}, MAE={itemcf_mae:.4f}")
    logger.info(f"SVD     : RMSE={svd_rmse:.4f},    MAE={svd_mae:.4f}")
    logger.info(f"Hybrid  : RMSE={hybrid_rmse:.4f}, MAE={hybrid_mae:.4f}")
    best = min([("ItemCF", itemcf_rmse), ("SVD", svd_rmse), ("Hybrid", hybrid_rmse)], key=lambda x: x[1])
    logger.info(f"Best model by RMSE: {best[0]} ({best[1]:.4f})")
    logger.info("SVD缓解稀疏：全局隐因子分解，不依赖用户-物品共现")
    logger.info("混合推荐：ItemCF提升可解释性，SVD保证冷启动稳健性，加权融合兼得两者优势")
    logger.info("=" * 110)


if __name__ == "__main__":
    main()
