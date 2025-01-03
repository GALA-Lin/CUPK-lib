#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 定义迷宫大小
#define SIZE 5

int maze[SIZE][SIZE]; // 迷宫数组
int startX, startY, endX, endY; // 起点和终点

// 定义四个可能的移动方向
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// 定义优先队列节点
typedef struct Node {
    int x, y;
    int g, h;
    struct Node* parent;
} Node;

// 计算启发性函数（使用曼哈顿距离）
int heuristic(int x, int y, int endX, int endY) {
    return abs(x - endX) + abs(y - endY);
}

// 获取节点的f值
int getF(Node* node) {
    return node->g + node->h;
}

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
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE && maze[x][y] == 0);
}

// 检查两个节点是否相同
int isNodeEqual(Node* a, Node* b) {
    return a->x == b->x && a->y == b->y;
}

// 从节点中复原路径
void printPath(Node* node) {
    if (node == NULL) return;
    printPath(node->parent);
    printf("(%d,%d)\n", node->x, node->y);
}

// 优先队列操作
Node* openList[SIZE * SIZE];
int openListSize = 0;

void push(Node* node) {
    openList[openListSize++] = node;
}

Node* pop() {
    if (openListSize == 0) return NULL;
    int bestIndex = 0;
    for (int i = 1; i < openListSize; i++) {
        if (getF(openList[i]) < getF(openList[bestIndex])) {
            bestIndex = i;
        }
    }
    Node* bestNode = openList[bestIndex];
    openList[bestIndex] = openList[--openListSize];
    return bestNode;
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

    // 初始化起始节点
    Node* startNode = (Node*)malloc(sizeof(Node));
    startNode->x = startX;
    startNode->y = startY;
    startNode->g = 0;
    startNode->h = heuristic(startX, startY, endX, endY);
    startNode->parent = NULL;

    // 初始化开放列表和关闭列表
    int closedList[SIZE][SIZE] = {0};
    openListSize = 0;

    // 将起始节点放入开放列表
    push(startNode);

    // A*算法主循环
    Node* currentNode;
    while ((currentNode = pop()) != NULL) {
        if (currentNode->x == endX && currentNode->y == endY) {
            printf("路径如下：\n");
            printPath(currentNode);
            return 0;
        }

        closedList[currentNode->x][currentNode->y] = 1;

        // 尝试四个方向的移动
        for (int i = 0; i < 4; i++) {
            int newX = currentNode->x + direction[i][0];
            int newY = currentNode->y + direction[i][1];

            if (isSafe(newX, newY) && !closedList[newX][newY]) {
                Node* neighbor = (Node*)malloc(sizeof(Node));
                neighbor->x = newX;
                neighbor->y = newY;
                neighbor->g = currentNode->g + 1;
                neighbor->h = heuristic(newX, newY, endX, endY);
                neighbor->parent = currentNode;
                push(neighbor);
            }
        }
    }

    printf("没有路径可以到达目的地\n");
    return 0;
}
