# README

这段代码旨在构建图结构并判断在该图中两个节点之间是否存在路径。下面是对代码的详细解释：

## 1. **包含头文件与命名空间：**
   ```cpp
   #include <iostream>
   #include <vector>
   #include <unordered_map>
   #include <unordered_set>
   #include <sstream>
   
   using namespace std;
   ```

   这些头文件提供基本的输入输出功能、容器（如`vector` 和 `unordered_map`）、数据结构（如`unordered_set`）以及字符串流处理功能。

## 2. **定义图的数据结构：**
### 构造函数

```cpp
Graph(int n) : n(n) {}
```

- **功能**：构造函数用于初始化图的节点数量 `n`。这里的 `n` 被存储为类的一个成员变量。

### addEdge 方法

```cpp
void addEdge(const string& node, const string& neighbors) {
    stringstream ss(neighbors);
    string neighbor;
    while (getline(ss, neighbor, '/')) {
        adjList[node].push_back(neighbor);
    }
}
```

- **功能**：
  - 将以 `/` 分隔的多个邻居节点添加到图中，表示边的联系。
  - 用 `stringstream` 对输入字符串进行处理，逐个读取邻接点。

- **输入**：
  - `node`：当前节点。
  - `neighbors`：以 `/` 为分隔符的多个邻接点字符串。

### isPathExist 方法

```cpp
bool isPathExist(const string& start, const string& end) {
    unordered_set<string> visited;
    return dfs(start, end, visited);
}
```

- **功能**：
  - 检查从起点 `start` 到终点 `end` 是否存在路径。
  - 利用深度优先搜索 (DFS) 算法。

- **输入**：
  - `start`：起始节点。
  - `end`：目标节点。

### 私有成员变量和方法

```cpp
int n;
unordered_map<string, vector<string>> adjList;

bool dfs(const string& start, const string& end, unordered_set<string>& visited) {
    if (start == end) return true;
    visited.insert(start);
    for (const string& neighbor : adjList[start]) {
        if (visited.find(neighbor) == visited.end()) {
            if (dfs(neighbor, end, visited)) {
                return true;
            }
        }
    }
    return false;
}
```

- **成员变量**：
  - `n`：图的节点数量。
  - `adjList`：存储图的邻接表，表示每个节点的邻居列表。

- **dfs 方法**：
  - **功能**：递归实现深度优先搜索，检查 `start` 和 `end` 之间的路径。
  - **参数**：
    - `start`: 当前处理的节点。
    - `end`: 目标节点。
    - `visited`: 已访问的节点集合，用于避免重复访问节点。
  - **逻辑**：
    - 若 `start` 与 `end` 相等，返回 `true`。
    - 将 `start` 标记为已访问。
    - 遍历 `start` 的邻居节点，递归调用 `dfs` 进行深度搜索。
    - 若找到一条路径返回 `true`，否则返回 `false`。

### 小结

该代码定义了一个 `Graph` 类，用于表示一个图结构，并提供了以下主要功能：
1. **添加边**：使用 `addEdge` 方法根据输入的字符串创建节点及其邻居列表。
2. **检查路径可达性**：使用 `isPathExist` 方法，基于深度优先搜索算法检查两个节点之间是否存在路径。

通过这些功能，用户可以构建一个图并检查任意两个节点之间的连通性。
## 3. **主函数：**
   ```cpp
   int main() {
       int n;
       cin >> n;
       cin.ignore();
       Graph graph(n);
       
       vector<string> edges;
       string line;
       for (int i = 0; i < 2 * n; ++i) {
           getline(cin, line);
           edges.push_back(line);
       }
       
       string start, end;
       getline(cin, start);
       getline(cin, end);
       
       for (int i = 0; i < n; ++i) {
           string node = edges[i * 2];
           string neighbors = edges[i * 2 + 1];
           graph.addEdge(node, neighbors);
       }
       
       if (graph.isPathExist(start, end)) {
           cout << "yes" << endl;
       } else {
           cout << "no" << endl;
       }
       
       return 0;
   }
   ```

   - 首先读取节点数 `n`。
   - 读取下一行以清除输入缓冲区中的新行字符（`cin.ignore()`）。
   - 创建一个 `Graph` 对象 `graph` 并传入 `n`。
   - 使用 `getline` 读取接下来的2 * n行输入，存储到字符串向量 `edges` 中。这些输入表示每个节点及其邻居节点。
   - 读取起点和终点。
   - 使用之前读取的 `edges` 数据，为每个节点添加边。
   - 调用 `isPathExist` 方法，判断从 `start` 到 `end` 是否存在路径，并输出结果（“yes” 或 “no”）。

这段代码展示了如何使用 C++ 构建一个图结构，并使用深度优先搜索（DFS）来查找两个节点之间是否存在路径。