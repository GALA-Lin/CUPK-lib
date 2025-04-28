# 1.Summary of Chapter One :

  **Algorithm analysis:** How to measure efficiency (time/space complexity). 
  **Asymptotic notation** (O, Ω, Θ) to describe growth rates. 



# 2.What is Recursion? 

## 2.1 call stack

Recursion is a programming technique where a function calls itself to solve smaller instances of the same problem.It primarily involves two phases:

**Calling:** This is where the program repeatedly calls itself, often with progressively smaller or simpler arguments, moving towards the "termination condition."

**Returning:** Upon triggering the "termination condition," the program begins to return from the deepest recursive function, aggregating the results of each layer.Recursion is a programming technique where a function calls itself to solve smaller instances of the same problem. 

**Base case:** A stopping condition (e.g., solving a trivial subproblem). 

**Recursive case:** Breaking the problem into smaller subproblems until the base case is reached.
**Example:** Calculating factorial (n! = n * (n-1)!    **with base case** 0! = 1). 

```cpp
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n ;
    cin>>n;
    int result = factorial(n);
    cout << "Factorial of " << n << " is " << result << endl;
    return 0;
}
```
## 2.2 recursive tree

**Example:** Calculating factorial (n! = n * (n-1)!    with base case 0! = 1).

![递归树](https://p.ananas.chaoxing.com/star3/origin/ca16f71bb917b099aceb0bbcce864379)

# 3.Properties of Divide-and-Conquer Algorithms 

**Divide:** Split the problem into smaller subproblems (usually equal-sized). 

**Conquer:** Solve subproblems recursively.

**Combine:** Merge subproblem solutions to form the final answer. 

**Base case:** Directly solve small instances (e.g., single element in sorting). 

**Efficiency:** Often achieves better time complexity than brute-force methods.

# 4.Examples of Divide-and-Conquer Algorithms and Time Complexity



## 4.1 bserch  O(log n)

```cpp
bool check(int x) {/* ... */} // 检查x是否满足某条件

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时(向左查找)使用：
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时（向右查找）使用：
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
```
## 4.2 Big int mul O(n)



## 4.3 merge sort O(n log n)

![归并排序样例](https://p.ananas.chaoxing.com/star3/origin/5cb169ccb3ed619c5524a82f2f73bbd1)


```cpp
/* 合并左子数组和右子数组 */
void merge(int nums[], int left, int mid, int right) {
    // 左子数组区间为 [left, mid], 右子数组区间为 [mid+1, right]
    // 创建一个临时数组 tmp ，用于存放合并后的结果
    int tmp[right - left + 1];
    // 初始化左子数组和右子数组的起始索引
    int i = left, j = mid + 1, k = 0;
    // 当左右子数组都还有元素时，进行比较并将较小的元素复制到临时数组中
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j])
            tmp[k++] = nums[i++];
        else
            tmp[k++] = nums[j++];
    }
    // 将左子数组和右子数组的剩余元素复制到临时数组中
    while (i <= mid) {
        tmp[k++] = nums[i++];
    }
    while (j <= right) {
        tmp[k++] = nums[j++];
    }
    // 将临时数组 tmp 中的元素复制回原数组 nums 的对应区间
    for (k = 0; k < sizeof(tmp) / sizeof(tmp[0]); k++) {
        nums[left + k] = tmp[k];
    }
}

/* 归并排序 */
void mergeSort(int nums[], int left, int right) {
    // 终止条件
    if (left >= right)
        return; // 当子数组长度为 1 时终止递归
    // 划分阶段
    int mid = left + (right - left) / 2;    // 计算中点
    mergeSort(nums, left, mid);      // 递归左子数组
    mergeSort(nums, mid + 1, right); // 递归右子数组
    // 合并阶段
    merge(nums, left, mid, right);
}
```

## 4.4qsort   Average case O(n log n) ; Best case O(n log n); Worst case O(n^2)

```cpp
void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}
```

## 4.5 qselect Average case O(n);Best case O(n);Worst case O(n^2)

```cpp
int partition(int a[], int left, int right, int pivot)
{
    int i = left, j = right;
    while (i <= j)
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j)
            swap(a[i], a[j]);
        else
            return j;
    }
    return -1;
}
int quickSelect(int a[], int left, int right, int k)
{
    if (left == right)
        return a[left];
    int pivot = a[left + right >> 1];
    int pos = partition(a, left, right, pivot); // 找到pivot的位置
    if (pos == k - 1)
        return a[pos];
    else if (pos > k - 1)            // pivot在k左边
        return quickSelect(a, left, pos - 1, k);
    else                            // pivot在k右边
        return quickSelect(a, pos + 1, right, k);
}
```