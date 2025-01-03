#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 图的结构定义
typedef struct Graph {
    int n;  // 顶点数量
    char** nodes;  // 存储顶点字符串数组
    int** adjMatrix;  // 邻接矩阵
} Graph;

// 创建图
Graph* createGraph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->n = n;
    graph->nodes = (char**)malloc(n * sizeof(char*));
    graph->adjMatrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        graph->nodes[i] = NULL;
        graph->adjMatrix[i] = (int*)calloc(n, sizeof(int));
    }
    return graph;
}

// 获取顶点在顶点数组中的索引位置
int getNodeIndex(Graph* graph, const char* node) {
    for (int i = 0; i < graph->n; ++i) {
        if (graph->nodes[i] && strcmp(graph->nodes[i], node) == 0) {
            return i;
        }
    }
    return -1;
}

// 添加边到图
void addEdge(Graph* graph, const char* node, const char* neighbors) {
    int nodeIndex = getNodeIndex(graph, node);
    if (nodeIndex == -1) {
        for (int i = 0; i < graph->n; ++i) {
            if (graph->nodes[i] == NULL) {
                graph->nodes[i] = strdup(node);
                nodeIndex = i;
                break;
            }
        }
    }

    char* neighborsCopy = strdup(neighbors);
    char* neighbor = strtok(neighborsCopy, "/");
    while (neighbor != NULL) {
        int neighborIndex = getNodeIndex(graph, neighbor);

        if (neighborIndex == -1) {
            for (int i = 0; i < graph->n; ++i) {
                if (graph->nodes[i] == NULL) {
                    graph->nodes[i] = strdup(neighbor);
                    neighborIndex = i;
                    break;
                }
            }
        }
        graph->adjMatrix[nodeIndex][neighborIndex] = 1;
        neighbor = strtok(NULL, "/");
    }
    free(neighborsCopy);
}

// 深度优先搜索路径存在性检查
int dfs(Graph* graph, int start, int end, int* visited) {
    if (start == end) return 1;
    visited[start] = 1;

    for (int i = 0; i < graph->n; ++i) {
        if (graph->adjMatrix[start][i] && !visited[i]) {
            if (dfs(graph, i, end, visited)) {
                return 1;
            }
        }
    }
    return 0;
}

// 判断路径是否存在
int isPathExist(Graph* graph, const char* start, const char* end) {
    int startIndex = getNodeIndex(graph, start);
    int endIndex = getNodeIndex(graph, end);

    if (startIndex == -1 || endIndex == -1) return 0;

    int* visited = (int*)calloc(graph->n, sizeof(int));
    int result = dfs(graph, startIndex, endIndex, visited);
    free(visited);
    return result;
}

// 释放图的资源
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->n; ++i) {
        if (graph->nodes[i]) free(graph->nodes[i]);
        free(graph->adjMatrix[i]);
    }
    free(graph->nodes);
    free(graph->adjMatrix);
    free(graph);
}

// 主函数，通过标准输入读取图的定义并检查路径是否存在
int main() {
    int n;
    scanf("%d", &n);
    getchar();  // 吃掉换行符

    Graph* graph = createGraph(n);
    char node[256];
    char neighbors[256];

    for (int i = 0; i < n; ++i) {
        fgets(node, 256, stdin);
        node[strcspn(node, "\n")] = '\0';  // 移除换行符
        fgets(neighbors, 256, stdin);
        neighbors[strcspn(neighbors, "\n")] = '\0';  // 移除换行符
        addEdge(graph, node, neighbors);
    }

    char start[256], end[256];
    fgets(start, 256, stdin);
    start[strcspn(start, "\n")] = '\0';  // 移除换行符
    fgets(end, 256, stdin);
    end[strcspn(end, "\n")] = '\0';  // 移除换行符

    if (isPathExist(graph, start, end)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    freeGraph(graph);
    return 0;
}
