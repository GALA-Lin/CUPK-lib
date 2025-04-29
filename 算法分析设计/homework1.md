# 1.Summary of Chapter One :

  **Algorithm analysis:** How to measure efficiency (time/space complexity). 

  **Asymptotic notation** (O, Ω, Θ) to describe growth rates. 



# 2. What is Recursion? 

## 2.1 call stack

Recursion is a programming technique where a function calls itself to solve smaller instances of the same problem.It primarily involves two phases:

  **Calling:** This is where the program repeatedly calls itself, often with progressively smaller or simpler arguments, moving towards the "termination condition."

  **Returning:** Upon triggering the "termination condition," the program begins to return from the deepest recursive function, aggregating the results of each layer.Recursion is a programming technique where a function calls itself to solve smaller instances of the same problem. 

**Base case:** A stopping condition (e.g., solving a trivial subproblem). 

**Recursive case:** Breaking the problem into smaller subproblems until the base case is reached.
**Example:** Calculating factorial (n! = n * (n-1)!  **with** **base case** 0! = 1). 

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

**Example:** Calculating factorial (n! = n * (n-1)!   with base case 0! = 1).

**![img](https://p.ananas.chaoxing.com/star3/origin/ca16f71bb917b099aceb0bbcce864379)**

## 3. Properties of Divide-and-Conquer Algorithms

**Divide:** Split the problem into smaller subproblems (usually equal-sized). 

**Conquer:** Solve subproblems recursively.

**Combine:** Merge subproblem solutions to form the final answer. 

**Base case:** Directly solve small instances (e.g., single element in sorting). 

**Efficiency:** Often achieves better time complexity than brute-force methods.



## 4. Examples of Divide-and-Conquer Algorithms and Time Complexity

## 4.1 binary serch O(log n)

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
}// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时（向右查找）使用：
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



## 4.2 Big int mul   O(n^(log 3)) ≈ O(n^1.59)

**![img](https://p.ananas.chaoxing.com/star3/origin/8d178bc06665420efbbc334af77dc24c)**

```Cpp
// 大整数相加：竖式加法
string add(string num1, string num2)
{
    int carry = 0;
    string result;

    // 从最低位开始逐位相加
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0)
    {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;                      // 进位
        result = to_string(sum % 10) + result; // 把当前位的结果加到最终结果的前面
        i--;
        j--;
    }

    return result;
}

// 大整数相减：竖式减法
string subtract(string num1, string num2)
{
    string result;
    int borrow = 0;

    // 从最低位开始逐位相减
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0)
    {
        int digit1 = num1[i] - '0';
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        // 减去借位
        int diff = digit1 - digit2 - borrow;

        if (diff < 0)
        {
            diff += 10; // 借位
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        result = to_string(diff) + result; // 把当前位的结果加到最终结果的前面
        i--;
        j--;
    }

    // 去除结果中的前导零
    size_t pos = result.find_first_not_of('0');
    if (pos != string::npos)
    {
        result = result.substr(pos);
    }

    return (result.empty()) ? "0" : result;
}

// 大整数乘大整数
string multiply(string num1, string num2)
{
    int n = num1.length();
    int m = num2.length();

    // 基本情况：如果有一个操作数为0，则结果为0
    if (n == 0 || m == 0 || num1 == "0" || num2 == "0")
    {
        return "0";
    }

    // 基本情况：如果有一个操作数为1，则结果为另一个操作数
    if (num1 == "1")
    {
        return num2;
    }

    if (num2 == "1")
    {
        return num1;
    }

    // 如果操作数很小，直接相乘
    if (n <= 2 || m <= 2)
    {
        long long int result = stoll(num1) * stoll(num2);
        return to_string(result);
    }

    // 将操作数分成两部分
    int mid = min(n, m) / 2;
    string num1Low = num1.substr(0, n - mid);
    string num1High = num1.substr(n - mid);
    string num2Low = num2.substr(0, m - mid);
    string num2High = num2.substr(m - mid);

    // 递归计算子问题的乘积
    string z0 = multiply(num1Low, num2Low);
    string z1 = multiply(num1High, num2High);
    string z2 = multiply(add(num1Low, num1High), add(num2Low, num2High));
    string z3 = subtract(subtract(z2, z1), z0);

    // 计算最终的乘积
    string result = add(add(z0 + string(mid * 2, '0'), z1), z3 + string(mid, '0'));

    return result;
}        //result
    for (int i = 0; i < max_len; i++) result += '0';  // 高位部分补零
    result = add(result, add(part1, part2));   
```

## 4.3 Hanoi Tower





## 4.4 merge sort O(n log n)

**![img](https://p.ananas.chaoxing.com/star3/origin/5cb169ccb3ed619c5524a82f2f73bbd1)**

```Cpp
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



## 4.5 quick_sort  Average case O(n log n) ; Best case O(n log n); Worst case O(n^2)

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

## 4.6 qselect Average case O(n); Best case O(n); Worst case O(n^2)

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



**4.7 closest pair point O(n log n)**

```cpp
//定义点class Point
{
public:
    int x, y;
};

// 按X坐标排序的比较函数
int compareX(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

// 按Y坐标排序的比较函数
int compareY(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}

// 计算两点之间的距离
float dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

// 暴力方法，用于找到点集P中任意两点的最小距离
float bruteForce(Point P[], int n)
{
    float minDist = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < minDist)
                minDist = dist(P[i], P[j]);
    return minDist;
}

// 返回两个浮点数中的较小值
float min(float x, float y)
{
    return (x < y) ? x : y;
}

// 查找strip中点对的最小距离
// strip[]中的点按Y坐标排序，且所有点到中间线的距离小于d
float stripClosest(Point strip[], int size, float d)
{
    float minDist = d; // 初始化最小距离为d

    qsort(strip, size, sizeof(Point), compareY);

    // 遍历strip中的每个点，并尝试与后续点配对
    // 只要y坐标之差小于当前最小距离
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < minDist; ++j)
            if (dist(strip[i], strip[j]) < minDist)
                minDist = dist(strip[i], strip[j]);

    return minDist;
}

// 递归函数，用于查找点集P的最小距离
float closestUtil(Point P[], int n)
{
    // 如果点数为2或3，使用暴力方法
    if (n <= 3)
        return bruteForce(P, n);

    // 找到中间点
    int mid = n / 2;
    Point midPoint = P[mid];

    // 计算中间线左侧的最小距离dl
    float dl = closestUtil(P, mid);
    // 计算中间线右侧的最小距离dr
    float dr = closestUtil(P + mid, n - mid);

    // 取dl和dr中的较小值为d
    float d = min(dl, dr);

    // 构建strip数组，包含所有距离中间线小于d的点
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;

    // 查找strip中的最小距离，并与d比较，返回较小值
    return min(d, stripClosest(strip, j, d));
}

// 调用closestUtil()查找最小距离
float closest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareX);

    return closestUtil(P, n);
}
```

**Base Case:** When ≤3 points, brute-force compute all pairwise distances. 

**Divide and Conquer:** 

1. Sort by x, split at median 
2. Recursively find DL(left) & DR(right) 
3. D = minimum of DL and DR 

**Merge step:** Check points within D-width strip along median line (sorted by y), compare adjacent points; **Merge step achieves O(n) time via y-sorting and limited comparisons
**