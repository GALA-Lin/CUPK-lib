# README

这段代码旨在构建图结构并判断在该图中两个节点之间是否存在路径。下面是对代码的详细解释：

1. **包含头文件与命名空间：**
   ```cpp
   #include <iostream>
   #include <vector>
   #include <unordered_map>
   #include <unordered_set>
   #include <sstream>
   
   using namespace std;
   ```

   这些头文件提供基本的输入输出功能、容器（如`vector` 和 `unordered_map`）、数据结构（如`unordered_set`）以及字符串流处理功能。

2. **定义图的数据结构：**
   ```cpp
   class Graph {
   public:
       Graph(int n) : n(n) {}
       
       void addEdge(const string& node, const string& neighbors) {
           stringstream ss(neighbors);
           string neighbor;
           while (getline(ss, neighbor, '/')) {
               adjList[node].push_back(neighbor);
           }
       }
       
       bool isPathExist(const string& start, const string& end) {
           unordered_set<string> visited;
           return dfs(start, end, visited);
       }
       
   private:
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
   };
   ```

   - `Graph` 类包含成员变量 `n` （表示节点数）和 `adjList` （表示邻接表，即每个节点的邻居列表）。
   - `addEdge` 方法用于添加边，参数 `node` 表示起点，`neighbors` 是以 `/` 分隔的邻居节点的字符串。通过字符串流 `stringstream` 和 `getline` 方法将邻居节点分开并加入邻接表。
   - `isPathExist` 方法用于判断从 `start` 到 `end` 是否存在路径。使用深度优先搜索（DFS）算法实现路径查找，路径查找过程中会记录已访问过的节点以避免重复访问。
   - `dfs` 是私有成员方法，递归实现深度优先搜索。

3. **主函数：**
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