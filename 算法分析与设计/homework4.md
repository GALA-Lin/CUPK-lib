# 一、01 backpack problem

Given:

- Value array `v = {8, 10, 6, 3, 7, 2}`
- Weight array `w = {4, 6, 2, 2, 5, 1}`
- Knapsack capacity `c = 12`

## Solution analysis
### 1. Two-dimensional DP

m[i,j] : The largest value in the set of values with volume <=j from the first i items

- if `j < w[i-1]`：`m[i,j] = m[i-1,j]`
- else：`m[i,j] = max(m[i-1,j], m[i-1,j-w[i-1]] + v[i-1])`

#### 1.1 Dynamic Programming Table m[i,j] Construction

**i=0/j=0:**m[i,j]=0

| i\j  |  0   |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  10  |  11  |  12  |
| :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
|  0   |  0   |  0   |  0   |  0   |  0   |  0   |  0   |  0   |  0   |  0   |  0   |  0   |  0   |


**i=1 (Item1, weight=4, value=8)**:

​	w[0]=4,v[0]=8 →`if j >= 4, m[1,j] = max(m[0,j], m[0,j-4]+v[0])`
$$
\therefore m[1,4\rightarrow 12]=8
$$


| i\j  |  0   |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  10  |  11  |  12  |
| :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
| 1   |0|0|0|0|8|8|8|8|8|8|8|8|8|


**i=2 (Item2, weight=6, value=10)**:

​	w[1]=6,v[1]=10 →`if j >= 6,m[2,j] = max(m[1,j],m[1,j-6]+v[1])`

​	`if j<6 m[2,j]=m[1,j]`

​	
$$
\therefore m[1,4\rightarrow 6]=8\\
m[2,6]=max(m[1,6]=8,m[1,6-6]+v[1]=0+10)=10\\
同理：m[2,7]=max(m[1,7]=8,m[1,7-6]+v[1]=0+10)=10\\
...\\
m[2,12]=max(m[1,12],m[1,12-6]+v[1]=8+10=18)
$$


| i\j  |  0   |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  10  |  11  |  12  |
| :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
| 2   |0|0|0|0|8|8|10|10|10|10|18|18|18|

**i=3 (Item3, weight=2, value=6)**:

​	w[2]=2,v[2]=6 →`if j >= 2,m[2,j] = max[m[2,j],m[2,j-2]+v[2])`

​	`if j<2 m[3,j]=m[2,j]`
$$
\therefore m[3,2\rightarrow3]=m[2,2\rightarrow3]+v[2]=0+6=6\\
m[3,4]=max(m[2,4]=8,m[2,4-2]+v[2]=0+6)=8\\
同理：m[2,6]=max(m[2,6]=10,m[2,6-2]+v[2]=8+6)=14\\
m[3,8]=max(m[2,8]=10,m[2,8-2]+v[2]=10+6)=16\\
m[3,10]=max(m[2,10]=18,m[2,10-2]+v[2]=10+6)=18 \\
...\\
m[3,12]=max(m[2,12],m[2,12-2]+v[2]=18+6=24)
$$


| i\j | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|:---:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:--:|:--:|:--:|
| 3   |0|0|6|6|8|8|14|14|16|16|18|18|24|

+++

> [!NOTE]
>
> Since the calculation steps are similar, only the critical steps are shown below
> 

**i=4 (Item4, weight=2, value=3)**:


- `j=4`：`max(8, m[3,2]+3) = max(8, 6+3) = 9`
- `j=6`：`max(14, m[3,4]+3) = max(14, 8+3) = 14`
- `j=8`：`max(16, m[3,6]+3) = max(16, 14+3) = 17`
- `j=10`：`max(18, m[3,8]+3) = max(18, 16+3) = 19`
- `j=12`：`max(24, m[3,10]+3) = max(24, 18+3) = 24`

| i\j | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|:---:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:--:|:--:|:--:|
| 4   |0|0|6|6|9|9|14|14|17|17|19|19|24|

**i=5 (Item5, weight=5, value=7)**:

- `j=11`：`max(19, m[4,6]+7) = max(19, 14+7) = 21`
- `j=12`: `max(24, m[4,7]+7) = max(24, 14+7) = 24`

| i\j | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|:---:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:--:|:--:|:--:|
| 5   |0|0|6|6|9|9|14|14|17|17|19|21|24|

**i=6 (Item6, weight=1, value=2)**:

- `j=1`：`max(0, m[5,0]+2) = max(0, 0+2) = 2`
- `j=3`:  `max(6, m[5,2]+2) = max(6, 6+2) = 8`
- `j=4`: `max(9, m[5,3]+2) = max(9, 6+2) = 9`
- `j=5`: `max(9, m[5,4]+2) = max(9, 9+2) = 11`
- `j=7`: `max(14, m[5,6]+2) = max(14, 14+2) = 16`
- `j=9`: `max(17, m[5,8]+2) = max(17, 17+2) = 19`
- `j=12`: `max(14, m[5,11]+2) = max(24, 21+2) = 24`

| i\j | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|:---:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:--:|:--:|:--:|
| 6   |0|2|6|8|9|11|14|16|17|19|19|21|24|

**m[i,j]**

| i\j | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|:---:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:--:|:--:|:--:|
| 0   | 0  |     0  |     0|       0|       0|       0|       0|       0|       0 |      0|       0|       0|       0|
| 1   |0|0|0|0|8|8|8|8|8|8|8|8|8|
| 2   |0|0|0|0|8|8|10|10|10|10|18|18|18|
| 3   |0|0|6|6|8|8|14|14|16|16|18|18|24|
| 4   |0|0|6|6|9|9|14|14|17|17|19|19|24|
| 5   |0|0|6|6|9|9|14|14|17|17|19|21|24|
| 6   |0|2|6|8|9|11|14|16|17|19|19|21|24|


#### 1. 2 code

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int v[1001], w[1001], f[1001][1001];
// 二维DP
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j]; // f[i][j]表示前i件物品恰好装入容量为j的背包可以获得的最大价值
            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
            // f[i][j]表示前i件物品恰好装入容量为j的背包可以获得的最大价值
            // 状态转移方程：如果不放第i件物品，则f[i][j]等于f[i-1][j]；如果放第i件物品，则f[i][j]等于max(f[i][j],f[i-1][j-v[i]]+w[i])
        }
    }
    
    // 输出DP矩阵
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << f[i][j] << "\t";
        }
        cout << endl;
    }

    cout << f[n][m] << endl;
    return 0;
}
```

#### 1.3 Backtracking to find the optimal combination
- Retrospectively find the optimal combination
  1. **Starting Point**: `i=6`, `j=12` 

  2. Compare & Backtrack:
     - `m[6,12] = 24 == m[5,12] = 24` → **Unselected item 6**
     - `m[5,12] = 24 == m[4,12] = 24` → **Unselected item 5**
     - `m[4,12] = 24 == m[3,12] = 24` → **Unselected item 4**
     - `m[3,12] = 24 > m[2,12] = 18`→ **Selected item 3**, remaining capacity `12-2=10`
     - `m[2,10] = 18 > m[1,10] = 8` → **Selected item 2**, remaining capacity `10-6=4`
     - `m[1,4] = 8 > m[0,4] = 0` → **Selected item 1**, remaining capacity `4-4=0`

  3. **End Result**:
     - **Selected Items**: Item 1、2、3 
     
     - **Total Weight**: `4 + 6 + 2 = 12`
     
     - Total Value: `8 + 10 + 6 = 24`
     

+++

### 2. One-dimensional DP

#### 2.1 Why is it deformed like this?

 The states we define m[i,j] can be used to get arbitrary legal optimal solutions for i and j, but when we only need the final state m[n,m], we only need one-dimensional space to update the state.

#### 2.2 Definition of state `f[j]`

`f[j]`:N items, the optimal solution under the backpack capacity `j`.

#### 2.3 Why does it take to enumerate backpack capacity in one dimension in reverse order?

In the two-dimensional case, the states `f[i][j]` are derived from the states of the previous round `i-1`, and `f[i][j]` and `f[i-1][j]` are independent. After optimizing to one dimension, if we are still in normal order, if f `[smaller volume]` is updated to `f [larger volume],` it is possible that the state of the `i-1` round should be used instead of the state of the i-1 round.

#### code

```cpp
//一维DP
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX(a,b) (a>b?a:b)

int main() {
    int N, V;
    cin >> N >> V;
    int v[1001], w[1001], state[1001] = {0}; // 初始化state数组为0
    for (int i = 1; i <= N; i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = V; j >= v[i]; j--) {
            state[j] = max(state[j], state[j - v[i]] + w[i]);
        // 状态转移方程： 表示容量为j的背包可以承载的最大价值
        // 如果不放第i件物品，则最大价值等于state[j]
        // 如果放第i件物品，则最大价值等于state[j - v[i]] + w[i]
        }
    }
    cout << state[V] << endl;
    return 0;
}

```

+++

####  一维DP方法中文对照：

将状态`f[i][j]`优化到一维`f[j]`，实际上只需要做一个等价变形。
为什么可以这样变形呢？我们定义的状态`f[i][j]`可以求得任意合法的i与j最优解，但题目只需要求得最终状态`f[n][m]`，因此我们只需要一维的空间来更新状态。

1. 状态`f[j]`定义: N 件物品，背包容量 j 下的最优解。
2. 注意枚举背包容量 j 必须从 m 开始。
3. 为什么一维情况下枚举背包容量需要逆序？在二维情况下，状态`f[i][j]`是由上一轮`i - 1`的状态得来的，`f[i][j]`与`f[i - 1][j]`是独立的。而优化到一维后，如果我们还是正序，则有`f[较小体积]`更新到`f[较大体积]`，则有可能本应该用第`i-1`轮的状态却用的是第i轮的状态。
4. 例如，一维状态第i轮对体积为3的物品进行决策，则`f[7]`由`f[4]`更新而来，这里的`f[4]`正确应该是`f[i - 1][4]`，但从小到大枚举j这里的`f[4]`在第 i 轮计算却变成了`f[i][4]`。当逆序枚举背包容量 j 时，我们求`f[7]`同样由`f[4]`更新，但由于是逆序，这里的`f[4]`还没有在第 i 轮计算，所以此时实际计算的`f[4]`仍然是`f[i - 1][4]`。
5. 简单来说，一维情况正序更新状态f[j]需要用到前面计算的状态已经被「污染」，逆序则不会有这样的问题。

**状态转移方程为：`f[j] = max(f[j], f[j - v[i]] + w[i]` 。**

# 二、流水调度算法

Given:
$$
n=7\\(a_0,a_1,a_2,a_3,a_4,a_5,a_6) = (5,3,6,4,8,9,6)\\(b_0\ ,b_1,b_2,b_3,\ b_4,b_5,\ b_6)  =  (2,4,7,2,9,7,3)
$$


## 约翰逊算法步骤

### 划分集合：

集合A:
$$
a_i ≤ b_i:作业1（3≤4）、作业2（6≤7）、作业4（8≤9）
$$
集合B
$$
a_i > b_i：作业0（5>2）、作业3（4>2）、作业5（9>7）、作业6（6>3）
$$


### 排序规则：

集合A按升序排列：作业1 → 作业2 → 作业4

集合B按降序排列：作业5→ 作业6→ 作业3→ 作业0

### 合并顺序：

最终作业顺序：[1, 2, 4, 5, 6, 3, 0]

## 调度甘特图

![4-2.png](https://img.picui.cn/free/2025/05/19/682b35dd68167.png)

# 最短用时 43

