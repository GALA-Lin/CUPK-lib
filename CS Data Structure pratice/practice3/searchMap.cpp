#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
 
using namespace std;
 
/**
 * @brief 定义图的类，用于存储和操作图。
 */
class Graph {
public:
    /**
     * @brief 构造函数，初始化顶点数量。
     * @param n 图中的顶点数量。
     */
    Graph(int n) : n(n) {}
     
    /**
     * @brief 添加一条边到图中。
     * @param node 顶点。
     * @param neighbors 邻接顶点字符串。
     */
    void addEdge(const string& node, const string& neighbors) {
        stringstream ss(neighbors);
        string neighbor;
        while (getline(ss, neighbor, '/')) {
            adjList[node].push_back(neighbor);
        }
    }
     
    /**
     * @brief 判断从起点到终点是否存在路径。
     * @param start 起点。
     * @param end 终点。
     * @return 如果存在路径则返回 true，否则返回 false。
     */
    bool isPathExist(const string& start, const string& end) {
        unordered_set<string> visited;
        return dfs(start, end, visited);
    }
     
private:
    int n;  // 顶点数量
    unordered_map<string, vector<string>> adjList;  // 邻接表
     
    /**
     * @brief 深度优先搜索算法，判断路径是否存在。
     * @param start 当前顶点。
     * @param end 终点。
     * @param visited 访问过的顶点集合。
     * @return 如果路径存在返回 true，否则返回 false。
     */
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
 
/**
 * @brief 主函数，读取输入并检查路径是否存在。
 * @return 程序退出状态码。
 */
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
 
/*
//oprate file: Graph.txt
 * @brief 主函数，通过文件读取图的定义并检查路径是否存在。
 * @return 程序退出状态码。

int main() {
    FILE* file = fopen("Graph.txt", "r");
    if (file == nullptr) {
        cout << "无法打开输入文件。" << endl;
        return 1;
    }
 
    int n;
    fscanf(file, "%d\n", &n); // 读取第一个整数n
     
    Graph graph(n);
 
    char nodeBuffer[256], neighborsBuffer[256];
    for (int i = 0; i < n; ++i) {
        fscanf(file, "%s\n", nodeBuffer); // 读取顶点名称
        fscanf(file, "%s\n", neighborsBuffer); // 读取邻接点
        string node(nodeBuffer);
        string neighbors(neighborsBuffer);
        graph.addEdge(node, neighbors);
    }
 
    char startBuffer[256], endBuffer[256];
    fscanf(file, "%s\n", startBuffer); // 读取起点
    fscanf(file, "%s\n", endBuffer); // 读取终点
    string start(startBuffer);
    string end(endBuffer);
 
    fclose(file);
 
    if (graph.isPathExist(start, end)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
 
    return 0;
}
*/