from itertools import permutations

def is_sorted(arr):
    """检查数组是否升序排列"""
    return all(arr[i] <= arr[i + 1] for i in range(len(arr) - 1))

def find_min_i(N, arr):
    """找到最小的 i，使得经过交换后数组升序排列"""
    for i in range(1, N + 1):
        # Generate all permutations of the first i elements
        for perm in permutations(arr[:i]):
            new_arr = list(perm) + arr[i:]
            if is_sorted(new_arr):
                return i
    return -1  # 如果没有找到则返回 -1

# 输入处理
N = int(input())
arr = list(map(int, input().split()))

# 输出结果
result = find_min_i(N, arr)
print(result)
