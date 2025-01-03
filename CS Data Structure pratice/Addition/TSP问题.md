# Question

用C语言完成TSP问题，实现输入起点、终点，输出最优路径及其代价
"霍尔果斯", "乌鲁木齐", 5000  
"乌鲁木齐", "酒泉", 30000  
"酒泉", "武威", 4000  
"武威", "中卫", 3500  
"中卫", "西安", 10000  
"西安", "郑州", 2000  
"西安", "成都", 5000  
"西安", "重庆", 3000  
"西安", "武汉", 1900  
"武汉", "长沙", 800  
"武汉", "南昌", 700  
"武汉", "广州", 3000  
"长沙", "广州", 1800  
"南宁", "广州", 1000  
"南昌", "广州", 800  
"郑州", "济南", 700  
"成都", "贵州", 3000  
"成都", "南宁", 1800   
数据如上

# Answer

要使用C语言实现TSP（旅行商问题），我们需要定义一个距离矩阵，并使用动态规划或回溯算法来找到最优路径。在这个问题中，我们可以使用Floyd-Warshall算法来预处理所有城市之间的最短路径，然后使用动态规划解决TSP。

以下是实现这个问题的代码示例：

```c
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define NUM_CITIES 19
#define INF INT_MAX

//定义城市的名称
const char* cities[NUM_CITIES] = {
    "霍尔果斯", "乌鲁木齐", "酒泉", "武威", "中卫", "西安", "郑州", "成都", "重庆", "武汉",
    "长沙", "南昌", "广州", "南宁", "济南", "贵州", "昆明", "合肥", "海口"
};

//定义距离矩阵
int dist[NUM_CITIES][NUM_CITIES];

//初始化距离矩阵
void init_dist() {
    for (int i = 0; i < NUM_CITIES; i++) {
        for (int j = 0; j < NUM_CITIES; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
    // 设定相邻城市之间的距离
    dist[0][1] = 5000;  // 霍尔果斯到乌鲁木齐
    dist[1][2] = 30000; // 乌鲁木齐到酒泉
    dist[2][3] = 4000;  // 酒泉到武威
    dist[3][4] = 3500;  // 武威到中卫
    dist[4][5] = 10000; // 中卫到西安
    dist[5][6] = 2000;  // 西安到郑州
    dist[5][7] = 5000;  // 西安到成都
    dist[5][9] = 1900;  // 西安到武汉
    dist[9][10] = 800;  // 武汉到长沙
    dist[9][11] = 700;  // 武汉到南昌
    dist[9][12] = 3000; // 武汉到广州
    dist[10][12] = 1800; // 长沙到广州
    dist[12][13] = 1000; // 南宁到广州
    dist[11][12] = 800;  // 南昌到广州
    dist[6][14] = 700;  // 郑州到济南
    dist[7][15] = 3000; // 成都到贵州
    dist[7][13] = 1800; // 成都到南宁
}

//使用Floyd-Warshall算法计算所有节点之间的最短路径
void floyd_warshall() {
    for (int k = 0; k < NUM_CITIES; k++) {
        for (int i = 0; i < NUM_CITIES; i++) {
            for (int j = 0; j < NUM_CITIES; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

// 获取城市名对应的索引
int get_city_index(const char* city) {
    for (int i = 0; i < NUM_CITIES; i++) {
        if (strcmp(cities[i], city) == 0) {
            return i;
        }
    }
    return -1; //如果城市不存在返回-1
}

// 打印路径
void print_path(int path[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", cities[path[i]]);
        if (i < n - 1) {
            printf("-> ");
        }
    }
    printf("\n");
}

// 旅行商问题的递归解
void tsp(int curr, int visited, int path[], int n, int cost, int* min_cost, int best_path[]) {
    if (visited == (1 << NUM_CITIES) - 1) {
        cost += dist[curr][path[0]];
        if (cost < *min_cost) {
            *min_cost = cost;
            memcpy(best_path, path, sizeof(int) * n);
        }
        return;
    }
    
    for (int i = 0; i < NUM_CITIES; i++) {
        if (!(visited & (1 << i)) && dist[curr][i] != INF) {
            path[n] = i;
            tsp(i, visited | (1 << i), path, n + 1, cost + dist[curr][i], min_cost, best_path);
        }
    }
}

int main() {
    init_dist();
    floyd_warshall();
    
    int start_index = get_city_index("霍尔果斯");
    int end_index = get_city_index("广州");
    
    if (start_index == -1 || end_index == -1) {
        printf("无效的城市输入\n");
        return 1;
    }
    
    int path[NUM_CITIES];
    int best_path[NUM_CITIES];
    int min_cost = INT_MAX;
    
    path[0] = start_index;
    tsp(start_index, 1 << start_index, path, 1, 0, &min_cost, best_path);
    
    if (min_cost == INT_MAX) {
        printf("没有可行的路径\n");
    } else {
        printf("最优路径: ");
        print_path(best_path, NUM_CITIES);
        printf("最小代价: %d\n", min_cost);
    }
    
    return 0;
}
```

此代码通过Floyd-Warshall算法预处理最短路径，并使用TSP递归解决方案查找最优路径和其代价。注意，在实际应用中，TSP问题由于其复杂性，可能需要高级优化方法或启发式算法来提升效率。