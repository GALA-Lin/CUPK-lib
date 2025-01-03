#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX 100 // 最大城市数量
#define INF INT_MAX

typedef struct {
    char name[50];
} City;

typedef struct {
    int distance[MAX][MAX];
    City cities[MAX];
    int numCities;
} Graph;

void readDistances(const char* fileName, Graph* graph) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        perror("文件打开失败");
        return;
    }

    char city1[50], city2[50];
    int distance;
    
    while (fscanf(file, "%s %s %d", city1, city2, &distance) != EOF) {
        int i, j;
        
        for (i = 0; i < graph->numCities; i++) {
            if (strcmp(graph->cities[i].name, city1) == 0) break;
        }
        if (i == graph->numCities) {
            strcpy(graph->cities[graph->numCities].name, city1);
            graph->numCities++;
        }
        
        for (j = 0; j < graph->numCities; j++) {
            if (strcmp(graph->cities[j].name, city2) == 0) break;
        }
        if (j == graph->numCities) {
            strcpy(graph->cities[graph->numCities].name, city2);
            graph->numCities++;
        }

        graph->distance[i][j] = distance;
        graph->distance[j][i] = distance;
    }

    fclose(file);
}

int getIndex(City* cities, int numCities, const char* name) {
    for (int i = 0; i < numCities; i++) {
        if (strcmp(cities[i].name, name) == 0) return i;
    }
    return -1;
}

void dijkstra(const Graph* graph, int startIdx, int endIdx) {
    int minDistance[MAX];
    int visited[MAX] = {0};
    int previousCity[MAX];
    
    for (int i = 0; i < graph->numCities; i++) {
        minDistance[i] = INF;
        previousCity[i] = -1;
    }
    minDistance[startIdx] = 0;

    for (int count = 0; count < graph->numCities - 1; count++) {
        int min = INF, u;
        for (int v = 0; v < graph->numCities; v++) {
            if (!visited[v] && minDistance[v] <= min) {
                min = minDistance[v];
                u = v;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < graph->numCities; v++) {
            if (!visited[v] && graph->distance[u][v] && minDistance[u] != INF 
                && minDistance[u] + graph->distance[u][v] < minDistance[v]) {
                minDistance[v] = minDistance[u] + graph->distance[u][v];
                previousCity[v] = u;
            }
        }
    }

    if (minDistance[endIdx] == INF) {
        printf("找不到从 %s 到 %s 的路径\n", graph->cities[startIdx].name, graph->cities[endIdx].name);
        return;
    }

    printf("最短路径: ");
    int path[MAX];
    int count = 0, idx = endIdx;
    while (idx != -1) {
        path[count++] = idx;
        idx = previousCity[idx];
    }

    for (int i = count - 1; i >= 0; i--) {
        printf("%s ", graph->cities[path[i]].name);
    }
    printf("\n最短距离: %d\n", minDistance[endIdx]);
}

int main() {
    char fileName[100];
    printf("请输入文件名: ");
    scanf("%s", fileName);

    Graph graph;
    graph.numCities = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph.distance[i][j] = (i == j) ? 0 : INF;
        }
    }

    readDistances(fileName, &graph);

    char start[50], end[50];
    printf("请输入起点: ");
    scanf("%s", start);
    printf("请输入终点: ");
    scanf("%s", end);

    int startIdx = getIndex(graph.cities, graph.numCities, start);
    int endIdx = getIndex(graph.cities, graph.numCities, end);

    if (startIdx == -1 || endIdx == -1) {
        printf("无效的起点或终点\n");
        return 1;
    }

    dijkstra(&graph, startIdx, endIdx);

    return 0;
}
