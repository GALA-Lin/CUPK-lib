#include <stdio.h>

// 定义迷宫大小
#define SIZE 5

int maze[SIZE][SIZE]; // 迷宫数组
int visited[SIZE][SIZE]; // 标记已访问节点
int startX, startY, endX, endY; // 起点和终点

// 定义四个可能的移动方向
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// 打印迷宫
void printMaze() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// 检查当前位置是否越界，是否可以访问
int isSafe(int x, int y) {
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE && maze[x][y] == 0 && !visited[x][y]);
}

// 深度优先搜索
int dfs(int x, int y) {
    if (x == endX && y == endY) {
        printf("(%d,%d)\n", x, y);
        return 1;
    }

    // 标记当前节点已访问
    visited[x][y] = 1;

    // 尝试四个方向的移动
    for (int i = 0; i < 4; i++) {
        int newX = x + direction[i][0];
        int newY = y + direction[i][1];
        if (isSafe(newX, newY)) {
            if (dfs(newX, newY)) {
                printf("(%d,%d)\n", x, y);
                return 1;
            }
        }
    }

    // 回溯
    visited[x][y] = 0;
    return 0;
}

int main() {
    // 输入迷宫
    printf("请输入迷宫(%d x %d)，0表示可通，1表示不可通：\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    // 打印迷宫
    printf("迷宫如下：\n");
    printMaze();

    // 输入起点和终点
    printf("请输入起点(x, y)和终点(x, y)的坐标（如：0 0 4 4）：\n");
    scanf("%d %d %d %d", &startX, &startY, &endX, &endY);

    // 初始化访问数组
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            visited[i][j] = 0;
        }
    }

    printf("路径如下：\n");
    if (!dfs(startX, startY)) {
        printf("没有路径可以到达目的地\n");
    }

    return 0;
}
