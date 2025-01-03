#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_CITIES 10  // 假设最多有10个城市

// 记录最短路径长度
int minCost = INT_MAX;

// 路径数组，用于记录当前路径
int path[MAX_CITIES];
// 最佳路径数组，用于记录最短路径
int bestPath[MAX_CITIES];

// 计算旅行费用
void tsp(int graph[MAX_CITIES][MAX_CITIES], bool visited[MAX_CITIES], int n, int pos, int cost, int count) {
    // 如果已访问所有城市并回到起点，更新最小费用
    if (count == n && graph[pos][0] > 0) {
        if (cost + graph[pos][0] < minCost) {
            minCost = cost + graph[pos][0];
            for (int i = 0; i < n; i++) {
                bestPath[i] = path[i];
            }
            bestPath[n] = 0;  // 回到起点
        }
        return;
    }

    // 考虑下一个城市
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[pos][i] > 0) {
            visited[i] = true;
            path[count] = i;

            // 递归调用tsp函数
            tsp(graph, visited, n, i, cost + graph[pos][i], count + 1);

            // 回溯
            visited[i] = false;
        }
    }
}

int main() {
    int n;  // 城市数量
    printf("请输入城市数量（不超过%d）：", MAX_CITIES);
    scanf("%d", &n);

    int graph[MAX_CITIES][MAX_CITIES];
    printf("请输入城市之间的距离矩阵：\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // 记录已访问城市
    bool visited[MAX_CITIES] = { false };
    visited[0] = true;  // 从第一个城市开始
    path[0] = 0;

    // 调用tsp函数
    tsp(graph, visited, n, 0, 0, 1);

    // 输出最短路径及最短路径长度
    printf("最短路径长度：%d\n", minCost);
    printf("最佳路径：");
    for (int i = 0; i <= n; i++) {
        printf("%d ", bestPath[i] + 1);  // 1-indexed
    }
    printf("\n");

    return 0;
}
/*
样例输入
4
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
*/