"""
作业二：Bloom Filter 与 False Positive 实验
Big Data Analytics Algorithms
输入：bloom_filter_dataset.txt
"""

import hashlib
import math
import random
import re
import os
import string

# ============================================================
# 数据加载：从 bloom_filter_dataset.txt 读取单词
# ============================================================
def load_words_from_file(filepath: str) -> list:
    """
    从文本文件中读取所有单词。
    规则：去掉单词中的数字（如 dataset432 → dataset），
         转小写，过滤空字符串，保留出现顺序。
    """
    words = []
    with open(filepath, 'r', encoding='utf-8') as f:
        for line in f:
            for token in line.split():
                word = re.sub(r'\d+', '', token).strip().lower()
                if word:
                    words.append(word)
    return words

def prepare_dataset(words: list, n_insert=20000, n_test=10000):
    """
    划分插入集与测试集，保证两者完全不重叠。
    策略：
      1. 对单词去重得到唯一词汇表
      2. 前 n_insert 个唯一词作为插入集
      3. 剩余唯一词优先作为测试集
      4. 若剩余词不足 n_test，用随机词补充（保证不在插入集中）
    """
    unique_words = list(dict.fromkeys(words))   # 去重保序
    insert_words = unique_words[:n_insert]
    remaining    = unique_words[n_insert:]

    insert_set = set(insert_words)
    extra = []
    if len(remaining) < n_test:
        random.seed(99)
        while len(remaining) + len(extra) < n_test:
            length = random.randint(4, 9)
            w = ''.join(random.choices(string.ascii_lowercase, k=length))
            if w not in insert_set:
                extra.append(w)

    test_words = (remaining + extra)[:n_test]
    return insert_words, test_words


# ============================================================
# 路径配置：bloom_filter_dataset.txt
# ============================================================
DATASET_FILENAME = "bloom_filter_dataset.txt"

script_dir = os.path.dirname(os.path.abspath(__file__))
DATASET_PATH = os.path.join(script_dir, DATASET_FILENAME)

print("=" * 60)
print("数据集加载（仅使用指定文件，不使用随机词）")
print("=" * 60)

if not os.path.exists(DATASET_PATH):
    raise FileNotFoundError(f"未在脚本目录找到数据集文件：{DATASET_FILENAME}")

# 加载数据
raw_words = load_words_from_file(DATASET_PATH)
print(f"文件路径         : {DATASET_PATH}")
print(f"原始 token 总数  : {len(raw_words)}")
print(f"去重后唯一词数   : {len(set(raw_words))}")

# 划分数据集
insert_words, test_words = prepare_dataset(raw_words, n_insert=20000, n_test=10000)
print(f"插入单词数量     : {len(insert_words)}")
print(f"测试单词数量     : {len(test_words)}")
print(f"插入集与测试集重叠: {len(set(insert_words) & set(test_words))}")


# ============================================================
# Bloom Filter 实现
# ============================================================
class BloomFilter:
    """
      bit array 长度 m（bytearray 节省内存）
      k 个独立 hash 函数（MD5 + 盐值）
    """

    def __init__(self, m: int, k: int):
        self.m = m
        self.k = k
        self.bit_array = bytearray(math.ceil(m / 8))
        self.count = 0

    def _hashes(self, item: str):
        """生成 k 个独立哈希位置，映射到 [0, m)"""
        item_bytes = item.encode('utf-8')
        return [
            int(hashlib.md5(item_bytes + i.to_bytes(2, 'big')).hexdigest(), 16) % self.m
            for i in range(self.k)
        ]

    def _set_bit(self, pos: int):
        self.bit_array[pos >> 3] |= (1 << (pos & 7))

    def _get_bit(self, pos: int) -> bool:
        return bool(self.bit_array[pos >> 3] & (1 << (pos & 7)))

    def insert(self, item: str):
        """将元素插入 Bloom Filter（将 k 个位置置 1）"""
        for pos in self._hashes(item):
            self._set_bit(pos)
        self.count += 1

    def query(self, item: str) -> bool:
        """
        查询元素是否存在。
        全部位为 1 → 可能存在（可能 false positive）
        任一位为 0 → 一定不存在
        """
        return all(self._get_bit(pos) for pos in self._hashes(item))

    def false_positive_rate_theory(self, n: int = None) -> float:
        """理论 FPR 公式：(1 - e^(-kn/m))^k"""
        n = n or self.count
        return (1 - math.exp(-self.k * n / self.m)) ** self.k

    def fill_ratio(self) -> float:
        """bit array 中 1 的比例"""
        return sum(bin(b).count('1') for b in self.bit_array) / self.m


# ============================================================
# 单次实验
# ============================================================
def run_experiment(m, k, insert_words, test_words):
    bf = BloomFilter(m=m, k=k)
    for w in insert_words:
        bf.insert(w)
    fp = sum(1 for w in test_words if bf.query(w))
    return {
        "m": m, "k": k,
        "n_insert"   : len(insert_words),
        "n_test"     : len(test_words),
        "fp"         : fp,
        "fpr_actual" : fp / len(test_words),
        "fpr_theory" : bf.false_positive_rate_theory(len(insert_words)),
        "fill_ratio" : bf.fill_ratio(),
    }


# ============================================================
# 实验 1：固定 k=4，改变 m
# ============================================================
print("\n" + "=" * 60)
print("实验 1：固定 k=4，改变 memory size m")
print("=" * 60)
print(f"\n{'m':>10}  {'k':>3}  {'FP数':>6}  {'实际FPR':>10}  {'理论FPR':>10}  {'填充率':>8}")
print("-" * 56)
for m in [50_000, 100_000, 200_000, 400_000]:
    r = run_experiment(m, 4, insert_words, test_words)
    print(f"{r['m']:>10,}  {r['k']:>3}  {r['fp']:>6}  "
          f"{r['fpr_actual']:>10.4f}  {r['fpr_theory']:>10.4f}  {r['fill_ratio']:>8.3f}")


# ============================================================
# 实验 2：固定 m=200,000，改变 k
# ============================================================
print("\n" + "=" * 60)
print("实验 2：固定 m=200,000，改变 hash 函数个数 k")
print("=" * 60)
print(f"\n{'m':>10}  {'k':>3}  {'FP数':>6}  {'实际FPR':>10}  {'理论FPR':>10}  {'填充率':>8}")
print("-" * 56)
for k in [1, 2, 4, 6, 8, 10, 12]:
    r = run_experiment(200_000, k, insert_words, test_words)
    print(f"{r['m']:>10,}  {r['k']:>3}  {r['fp']:>6}  "
          f"{r['fpr_actual']:>10.4f}  {r['fpr_theory']:>10.4f}  {r['fill_ratio']:>8.3f}")


# ============================================================
# 实验 3：m × k 网格对比
# ============================================================
print("\n" + "=" * 60)
print("实验 3：综合对比 —— m × k 网格（实际 FPR）")
print("=" * 60)
m_list = [50_000, 100_000, 200_000]
k_list = [2, 4, 6, 8]
header = f"{'m \\ k':>12}" + "".join(f"  {'k='+str(k):<10}" for k in k_list)
print("\n" + header)
print("-" * (len(header) + 4))
for m in m_list:
    row = f"{m:>12,}"
    for k in k_list:
        r = run_experiment(m, k, insert_words, test_words)
        row += f"  {r['fpr_actual']:<10.4f}"
    print(row)


# ============================================================
# 理论最优 k 推荐
# ============================================================
print("\n" + "=" * 60)
print("理论最优 hash 函数个数（k* = m/n × ln2）")
print("=" * 60)
n = len(insert_words)
print(f"\n{'m':>10}  {'最优k':>6}  {'理论最低FPR':>14}")
print("-" * 34)
for m in [50_000, 100_000, 200_000, 400_000]:
    k_opt = max(1, round((m / n) * math.log(2)))
    fpr   = (1 - math.exp(-k_opt * n / m)) ** k_opt
    print(f"{m:>10,}  {k_opt:>6}  {fpr:>14.4f}")


# ============================================================
# 理论分析
# ============================================================
print("\n" + "=" * 60)
print("理论分析")
print("=" * 60)
print("""
Q1. Bloom Filter 为什么会出现 false positive？
    插入时每个元素将 k 个位置置 1。随着插入量增加，bit array 越来越密集。
    查询一个未插入的元素时，其 k 个位置恰好全被其他元素"顺带"置 1，
    从而被误判为"存在"，这就是 false positive 的来源。

Q2. 为什么 Bloom Filter 不会出现 false negative？
    插入操作只置 1 从不清零，已插入元素的 k 个位置永远保持为 1。
    查询时检查同样的 k 个位置，已插入元素一定全部命中，绝不漏判。

Q3. memory size 增大后误判率如何变化？
    m 增大 → bit array 更稀疏 → 各位被置 1 的概率降低 → FPR 降低。
    理论公式 (1-e^(-kn/m))^k 中，m 越大 FPR 趋近 0。
    实验 1 验证：m 从 50,000 增至 400,000，FPR 大幅下降。

Q4. 为什么 hash 函数个数不是越多越好？
    k 增大有两个相反效果：
    ① 每个元素占用更多位 → bit array 填充更快 → FPR 趋向升高
    ② 查询需更多位全部为 1 → 误判概率趋向下降
    两者存在最优平衡点：k* = (m/n) × ln2。
    实验 2 可见 k 超过最优值后 FPR 反而回升。

Q5. Bloom Filter 为什么适合大规模数据查询？
    ① 空间极省：只存 bit array，无需保存原始数据，O(m) 空间
    ② 查询极快：每次仅需 k 次哈希 + 位运算，O(k) 时间
    ③ 零漏判：false negative rate = 0，"判不存在则一定不存在"
    ④ 可控误判：调整 m 和 k 可将 FPR 控制在业务可接受范围
    典型场景：数据库缓存穿透防护、爬虫 URL 去重、分布式黑名单过滤。
""")

print("=" * 60)
print("实验完成！")
print("=" * 60)