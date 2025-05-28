# 最小生成树

**在ABCDE各城市间建⽴通信⽹络,分别⽤Prim算法和Kruskal算法构造最⼩⽣成树**

<img src="https://img.picui.cn/free/2025/05/28/6836eafe7ab84.png" alt="1748429563458.png" style="zoom:50%;" />

## 一、Prim算法（以顶点A为起点）

1. **初始化**：  
   - 已选顶点 \( U = \{A\} \)，未选顶点 \( V-U = \{B,C,D,E\} \)。  
   - 距离数组：`dist[B]=25`，`dist[C]=5`，`dist[D]=45`，`dist[E]=∞`。

2. **迭代选择最近顶点**：  
   - **第1次**：选C（`dist[C]=5`），更新 `dist[B]=7`（C-B）、`dist[D]=44`（C-D）、`dist[E]=34`（C-E）。  
   - **第2次**：选B（`dist[B]=7`），更新 `dist[D]=11`（B-D）、`dist[E]=12`（B-E）。  
   - **第3次**：选D（`dist[D]=11`），无需更新E（B-E已更优）。  
   - **第4次**：选E（`dist[E]=12`），结束。

3. **生成树边**：A-C（5）、C-B（7）、B-D（11）、B-E（12），权和 **35**。

### 表格表述

| 迭代次数 | 已选顶点集合 |  A   |  B   |  C   |  D   |  E   | 新添加边 |
| :------: | :----------: | :--: | :--: | :--: | :--: | :--: | :------: |
|    1     |     {A}      |  -   |  25  |  5*  |  25  |  45  |   A-C    |
|    2     |    {A, C}    |  -   |  7*  |  -   |  44  |  34  |   C-B    |
|    3     |  {A, C, B}   |  -   |  -   |  -   | 11*  | 12*  |   B-D    |
|    4     | {A, C, B, D} |  -   |  -   |  -   |  -   |  78  |   B-E    |



## 二、Kruskal算法

1. **排序边（升序）**：  5（A-C）、7（C-B）、11（B-D）、12（B-E）、25（A-B）、…（后续边无需考虑，因已选4条边）。

2. **并查集合并**：  
   - 选A-C（5）：合并{A,C}。  
   - 选C-B（7）：合并{A,C,B}。  
   - 选B-D（11）：合并{A,C,B,D}。  
   - 选B-E（12）：合并所有顶点，结束。

3. **生成树边**：同Prim算法，权和 **35**。



## 三、结果验证  
- 两种算法均得到最小生成树，边为 **A-C（5）、C-B（7）、B-D（11）、B-E（12）**，权值和 **35**，无环且连接所有顶点，符合最小生成树定义。

**答案：**  
- **Prim算法**：按上述步骤选择边，最终生成树边为A-C、C-B、B-D、B-E，权和35。  
- **Kruskal算法**：排序边后依次选择无环边，最终生成树边同上，权和35。



# 四、Code

## 4.1 Prime

```cpp
#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

// Prim算法构造最小生成树
vector<pair<int, int>> prim(int n, vector<vector<int>>& graph) {
    vector<int> visited(n, 0); // 记录顶点是否已被加入生成树
    vector<int> minDist(n, INF); // 每个顶点到生成树的最短距离
    vector<int> parent(n, -1); // 记录每个顶点的父节点
    minDist[0] = 0; // 从顶点0开始

    // 优先队列，按距离最小的顺序弹出
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // 起始顶点

    while (!pq.empty()) {
        int u = pq.top().second; // 当前顶点
        pq.pop();

        if (visited[u]) continue; // 如果顶点已被访问，跳过
        visited[u] = 1;

        // 遍历与顶点u相邻的顶点
        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != 0 && !visited[v]) { // 如果顶点v未被访问且有边
                if (graph[u][v] < minDist[v]) {
                    minDist[v] = graph[u][v];
                    parent[v] = u;
                    pq.push({minDist[v], v});
                }
            }
        }
    }

    // 构造生成树的边
    vector<pair<int, int>> mst;
    for (int i = 1; i < n; ++i) {
        mst.push_back({parent[i], i});
    }
    return mst;
}

int main() {
    // 定义图的邻接矩阵
    int n = 5;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    graph[0][1] = 25; graph[1][0] = 25; // A-B: 25
    graph[0][2] = 5; graph[2][0] = 5; // A-C: 5
    graph[0][3] = 25; graph[3][0] = 25; // A-D: 25
    graph[0][4] = 45; graph[4][0] = 45; // A-E: 45
    graph[1][2] = 7; graph[2][1] = 7; // B-C: 7
    graph[1][3] = 11; graph[3][1] = 11; // B-D: 11
    graph[1][4] = 12; graph[4][1] = 12; // B-E: 12
    graph[2][3] = 44; graph[3][2] = 44; // C-D: 44
    graph[2][4] = 34; graph[4][2] = 34; // C-E: 34
    graph[3][4] = 78; graph[4][3] = 78; // D-E: 78

    // 使用Prim算法构造最小生成树
    vector<pair<int, int>> mst = prim(n, graph);

    // 输出最小生成树的边
    cout << "Prim算法构造的最小生成树：" << endl;
    for (const auto& edge : mst) {
        cout << char('A' + edge.first) << "-" << char('A' + edge.second) << endl;
    }

    return 0;
}

```

### 	输出

```
Prim算法构造的最小生成树：
C-B
A-C
B-D
B-E
```

## 4.2 Kruskal

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 并查集（Union-Find）结构
class UnionFind {
public:
    vector<int> parent;

    UnionFind(int size) {
        parent.resize(size);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
};

// 每条边的结构
struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

// Kruskal算法构造最小生成树
vector<pair<int, int>> kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    UnionFind uf(n);
    vector<pair<int, int>> mst;
    for (const auto& edge : edges) {
        int rootU = uf.find(edge.u);
        int rootV = uf.find(edge.v);
        if (rootU != rootV) {
            uf.unionSet(rootU, rootV);
            mst.emplace_back(edge.u, edge.v);
        }
    }
    return mst;
}

int main() {
    // 定义图的边
    int n = 5;
    vector<Edge> edges = {
        Edge(0, 1, 25), Edge(0, 2, 5),Edge(0, 3, 25), Edge(0, 4, 45),
        Edge(1, 2, 7), Edge(1, 3, 11), Edge(1, 4, 12),
        Edge(2, 3, 44), Edge(2, 4, 34),
        Edge(3, 4, 78)
    };

    // 使用Kruskal算法构造最小生成树
    vector<pair<int, int>> mst = kruskal(n, edges);

    // 输出最小生成树的边
    cout << "Kruskal算法构造的最小生成树：" << endl;
    for (const auto& edge : mst) {
        cout << char('A' + edge.first) << "-" << char('A' + edge.second) << endl;
    }

    return 0;
}

```



### 	输出

```
Kruskal算法构造的最小生成树：
A-C
B-C
B-D
B-E
```



算法输出边均为 A-C（5）、C-B（7）、B-D（11）、B-E（12），权值和 35
