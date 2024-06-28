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
