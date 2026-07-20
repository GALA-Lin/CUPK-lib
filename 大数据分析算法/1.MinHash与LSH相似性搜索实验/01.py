"""
作业一：MinHash 与 LSH 相似性搜索实验
"""

import random
import math
import itertools
from collections import defaultdict
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import numpy as np

plt.rcParams['font.family'] = 'SimHei'
plt.rcParams['axes.spines.top'] = False
plt.rcParams['axes.spines.right'] = False

# 文档中数据

documents = {
    "D1": "data science uses scientific methods to analyze data",
    "D2": "data science uses scientific techniques to analyze datasets",
    "D3": "deep learning models are widely used in computer vision",
    "D4": "computer vision often uses deep neural networks",
    "D5": "big data systems include Hadoop and Spark",
    "D6": "Spark is widely used for distributed data processing",
}

# 第 1 步：Shingling（k=3）

def get_shingles(text, k=3):
    words = text.lower().split()
    return set(tuple(words[i:i+k]) for i in range(len(words) - k + 1))

print("=" * 60)
print("Shingling（k=3）")
print("=" * 60)

shingles = {}
for doc_id, text in documents.items():
    shingles[doc_id] = get_shingles(text, k=3)
    print(f"\n{doc_id}: {len(shingles[doc_id])} 个 shingles")
    for s in sorted(shingles[doc_id]):
        print(f"    {' '.join(s)}")

for da, db in [("D1", "D2"), ("D3", "D4")]:
    inter = shingles[da] & shingles[db]
    union = shingles[da] | shingles[db]
    print(f"\n--- 选择文档对 {da} & {db} ---")
    print(f"{da} ∩ {db} = {len(inter)} 个: {[' '.join(s) for s in sorted(inter)]}")
    print(f"{da} ∪ {db} = {len(union)} 个")

# 第 2 步：Jaccard 相似度

def jaccard(set_a, set_b):
    inter = set_a & set_b
    union = set_a | set_b
    return len(inter) / len(union) if union else 0.0

print("\n" + "=" * 60)
print("Jaccard 相似度")
print("=" * 60)

doc_ids = list(documents.keys())
jaccard_scores = {}
for i in range(len(doc_ids)):
    for j in range(i + 1, len(doc_ids)):
        d1, d2 = doc_ids[i], doc_ids[j]
        score = jaccard(shingles[d1], shingles[d2])
        jaccard_scores[(d1, d2)] = score
        print(f"J({d1}, {d2}) = {score:.4f}")

max_pair = max(jaccard_scores, key=jaccard_scores.get)
print(f"\n最相似文档对：{max_pair}，Jaccard = {jaccard_scores[max_pair]:.4f}")

# 第 3 步：MinHash（100 个 hash 函数）

print("\n" + "=" * 60)
print("MinHash（100 个 hash 函数）")
print("=" * 60)

all_shingles = set()
for s in shingles.values():
    all_shingles |= s
shingle_list = sorted(all_shingles)
shingle_to_id = {s: i for i, s in enumerate(shingle_list)}

NUM_HASH = 100
PRIME = 2**31 - 1

random.seed(42)
hash_params = [(random.randint(1, PRIME - 1), random.randint(0, PRIME - 1))
               for _ in range(NUM_HASH)]

def minhash_signature(shingle_set, hash_params, prime):
    ids = [shingle_to_id[s] for s in shingle_set]
    sig = []
    for a, b in hash_params:
        min_val = min((a * x + b) % prime for x in ids)
        sig.append(min_val)
    return sig

signatures = {}
for doc_id in documents:
    signatures[doc_id] = minhash_signature(shingles[doc_id], hash_params, PRIME)
    print(f"{doc_id} signature（前10）: {signatures[doc_id][:10]}")

def minhash_similarity(sig_a, sig_b):
    return sum(1 for a, b in zip(sig_a, sig_b) if a == b) / len(sig_a)

minhash_scores = {}
print("\n--- MinHash vs Jaccard 对比 ---")
print(f"{'文档对':<15} {'Jaccard':>10} {'MinHash':>10} {'差值':>10}")
print("-" * 44)
for (d1, d2), j_score in jaccard_scores.items():
    m_score = minhash_similarity(signatures[d1], signatures[d2])
    minhash_scores[(d1, d2)] = m_score
    error = abs(j_score - m_score)
    print(f"({d1},{d2})        {j_score:>10.4f} {m_score:>10.4f} {error:>10.4f}")

# 第 4 步：LSH（bands=50, rows=2）
BANDS = 50
ROWS = 2
assert BANDS * ROWS == NUM_HASH

print("\n" + "=" * 60)
print(f"LSH（bands={BANDS}, rows={ROWS}）")
print("=" * 60)
threshold_approx = (1 / BANDS) ** (1 / ROWS)
print(f"（b={BANDS}, r={ROWS} 阈值约为 {threshold_approx:.2f}）")

def lsh_candidate_pairs(signatures, b, r):
    buckets = defaultdict(set)
    for doc_id, sig in signatures.items():
        for band_idx in range(b):
            band = tuple(sig[band_idx * r: (band_idx + 1) * r])
            buckets[(band_idx, band)].add(doc_id)
    candidates = set()
    for bucket_docs in buckets.values():
        if len(bucket_docs) > 1:
            docs = sorted(bucket_docs)
            for i in range(len(docs)):
                for j in range(i + 1, len(docs)):
                    candidates.add((docs[i], docs[j]))
    return candidates

candidate_pairs = lsh_candidate_pairs(signatures, BANDS, ROWS)
print(f"LSH 找到的 candidate pairs（共 {len(candidate_pairs)} 对）：")
for pair in sorted(candidate_pairs):
    j = jaccard(shingles[pair[0]], shingles[pair[1]])
    print(f"  {pair}  →  Jaccard = {j:.4f}")

high_sim_pairs = [p for p, s in jaccard_scores.items() if s >= 0.1]
print(f"\nJaccard >= 0.1 的文档对：{high_sim_pairs}")
print(f"LSH candidate pairs：{sorted(candidate_pairs)}")

hits   = [p for p in high_sim_pairs if p in candidate_pairs]
misses = [p for p in high_sim_pairs if p not in candidate_pairs]
false_pos = [p for p in candidate_pairs if p not in high_sim_pairs]
print(f"\nLSH 命中高相似度对：{hits}")
print(f"LSH 遗漏（false negative）：{misses}")
print(f"LSH 误报（false positive）：{false_pos}")

# S 曲线分析
print("\n" + "=" * 60)
print("LSH 概率（S 曲线）分析")
print("=" * 60)

configs = [(20, 5), (10, 10), (50, 2)]
print(f"{'s':>6}  {'P(b=20,r=5)':>14}  {'P(b=10,r=10)':>14}  {'P(b=50,r=2)':>14}")
print("-" * 52)
for s in [0.1, 0.2, 0.3, 0.5, 0.7, 0.8, 0.9, 1.0]:
    row = f"{s:>6.1f}"
    for b_, r_ in configs:
        prob = 1 - (1 - s**r_)**b_
        row += f"  {prob:>14.4f}"
    print(row)



# 可视化
BLUE   = '#378ADD'
PINK   = '#D4537E'
GREEN  = '#1D9E75'
AMBER  = '#BA7517'
GRAY   = '#888780'
LGRAY  = '#E8E6E0'

fig = plt.figure(figsize=(14, 11))
fig.patch.set_facecolor('white')

# ── LSH S 曲线 ────────────────────────────────────────
s_arr = np.linspace(0, 1, 200)
curve_configs = [
    (20, 5,  BLUE,  'b=20, r=5'),
    (10, 10, PINK,  'b=10, r=10'),
    (50, 2,  GREEN, 'b=50, r=2'),
]

fig = plt.figure(figsize=(7, 7))
fig.patch.set_facecolor('white')

ax4 = fig.add_subplot()

for b_, r_, color, label in curve_configs:
    probs = 1 - (1 - s_arr**r_)**b_
    t = (1/b_)**(1/r_)
    ax4.plot(s_arr, probs, color=color, linewidth=2, label=label)
    ax4.axvline(t, color=color, linewidth=0.8, linestyle='--', alpha=0.5)

# 标注实验中 D1-D2 的 Jaccard
j12 = jaccard_scores[('D1', 'D2')]
ax4.axvline(j12, color=AMBER, linewidth=1.5, linestyle=':', label=f'J(D1,D2)={j12:.2f}')
ax4.fill_betweenx([0, 1], 0, j12, alpha=0.06, color=AMBER)

ax4.set_xlim(0, 1); ax4.set_ylim(0, 1.05)
ax4.set_xlabel('Jaccard相似度 s', fontsize=9, color=GRAY)
ax4.set_ylabel('候选对概率 P', fontsize=9, color=GRAY)
ax4.set_title('LSH S 曲线', fontsize=11, pad=10, color='#2C2C2A')
ax4.tick_params(colors=GRAY)
ax4.legend(fontsize=8.5, frameon=False, loc='upper left')
ax4.text(0.02, 0.55, '理想\n阶跃', fontsize=7, color=GRAY, alpha=0.6)

# 理想阶跃虚线（参考）
ax4.step([0, 0.5, 0.5, 1], [0, 0, 1, 1], color=GRAY, linewidth=0.8,
         linestyle=(0, (3, 5)), alpha=0.4)

plt.savefig('minhash_lsh_visualization.png',
            dpi=150, bbox_inches='tight', facecolor='white')
print("\n图表已保存：minhash_lsh_visualization.png")
plt.close()

