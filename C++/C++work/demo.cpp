#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 打印长度为3的回路
void findCycles(int n, const vector<vector<int>>& graph) {
    set<vector<char>> cycles;  // 用于存储回路，避免重复

    // 遍历所有可能的三个节点
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                // 检查路径 i -> j -> k -> i
                if (graph[i][j] == 1 && graph[j][k] == 1 && graph[k][i] == 1) {
                    vector<char> cycle = {
                        static_cast<char>('a' + i), 
                        static_cast<char>('a' + j), 
                        static_cast<char>('a' + k)
                    };
                    cycles.insert(cycle);  // 加入集合中以去重
                }
            }
        }
    }

    // 输出结果
    if (!cycles.empty()) {
        for (const auto& cycle : cycles) {
            cout << cycle[0] << " " << cycle[1] << " " << cycle[2] << " " << cycle[0] << endl;
        }
    } else {
        cout << "Does not exist" << endl;
    }
}

int main() {
    int n;
    cin >> n;

    // 读取邻接矩阵
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    // 查找长度为3的回路
    findCycles(n, graph);

    return 0;
}
