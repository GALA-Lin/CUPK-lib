#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

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
