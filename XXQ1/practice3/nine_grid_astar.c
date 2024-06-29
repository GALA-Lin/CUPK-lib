#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3  // 九宫格大小
#define MAX_LIST_SIZE 10000  // 加大列表以防越界

// 目标状态
int target[N][N] = {
    {1, 2, 3},
    {8, 0, 4},
    {7, 6, 5}
};

int count = 0;  // 状态计数

// 节点结构体
typedef struct Node {
    int state[N][N];  // 当前状态
    int g;  // 实际代价
    int h;  // 预估代价（曼哈顿距离）
    struct Node* parent;  // 父节点指针
} Node;

// 曼哈顿距离计算
int manhattan(int state[N][N]) {
    int distance = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (state[i][j] != 0) {  // 忽略空格位置
                int target_x = (state[i][j] - 1) / N;
                int target_y = (state[i][j] - 1) % N;
                distance += abs(target_x - i) + abs(target_y - j);
            }
        }
    }
    return distance;
}

// 生成一个新节点
Node* create_node(int state[N][N], int g, int h, Node* parent) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node != NULL) {  // 检查内存分配是否成功
        memcpy(new_node->state, state, N * N * sizeof(int));  // 复制状态
        new_node->g = g;  // 设置实际代价
        new_node->h = h;  // 设置预估代价
        new_node->parent = parent;  // 设置父节点
    }
    return new_node;
}

// 节点比较函数（用于优先队列）
int compare_nodes(const void* a, const void* b) {
    Node* nodeA = *(Node**)a;
    Node* nodeB = *(Node**)b;
    return (nodeA->g + nodeA->h) - (nodeB->g + nodeB->h);  // 按f = g + h排序
}

// 获取空格位置
void get_blank_pos(int state[N][N], int* blank_x, int* blank_y) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (state[i][j] == 0) {
                *blank_x = i;
                *blank_y = j;  // 找到空格位置
                return;
            }
        }
    }
}

// 生成相邻节点
void get_neighbors(Node* current, Node** neighbors, int* count) {
    int blank_x, blank_y;
    get_blank_pos(current->state, &blank_x, &blank_y);  // 获取空格的位置
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  // 上下左右四个方向
    *count = 0;

    // 遍历四个方向，生成合法的相邻节点
    for (int i = 0; i < 4; ++i) {
        int new_x = blank_x + directions[i][0];
        int new_y = blank_y + directions[i][1];
        if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N) {  // 检查新坐标是否在边界内
            int new_state[N][N];
            memcpy(new_state, current->state, N * N * sizeof(int));  // 复制当前状态
            new_state[blank_x][blank_y] = new_state[new_x][new_y];  // 交换空格与目标位置
            new_state[new_x][new_y] = 0;
            Node* neighbor = create_node(new_state, current->g + 1, manhattan(new_state), current);  // 生成新节点
            if (neighbor != NULL) {  // 检查节点生成是否成功
                neighbors[*count] = neighbor;
                (*count)++;
            }
        }
    }
}

// 判断两个状态是否相同
int is_same_state(int state1[N][N], int state2[N][N]) {
    return memcmp(state1, state2, N * N * sizeof(int)) == 0;
}

// 打印路径
void print_path(Node* node) {
    if (node == NULL) return;
    print_path(node->parent);  // 递归打印父节点的路径
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", node->state[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// 释放路径
void free_path(Node* node) {
    if (node == NULL) return;
    free_path(node->parent);  // 递归释放父节点
    free(node);
}

// A* 算法求解函数
void astar_search(int initial[N][N]) {
    Node* open_list[MAX_LIST_SIZE];
    int open_count = 0;

    Node* closed_list[MAX_LIST_SIZE];
    int closed_count = 0;

    Node* initial_node = create_node(initial, 0, manhattan(initial), NULL);  // 生成初始节点
    if (initial_node == NULL) {
        printf("Failed to create initial node.\n");
        return;
    }
    open_list[open_count++] = initial_node;  // 初始节点加入开启列表

    while (open_count > 0) {
        qsort(open_list, open_count, sizeof(Node*), compare_nodes);  // 根据f值对开启列表排序
        
        Node* current = open_list[0];  // 取出f值最小的节点
        if (is_same_state(current->state, target)) {  // 检查是否达到目标状态
            print_path(current);  // 打印路径
            count = current->g;  // 记录从初始状态到目标状态所经过的步数
            free_path(current);  // 释放路径
            return;
        }

        // 从开启列表中移除当前节点
        for (int i = 0; i < open_count - 1; ++i) {
            open_list[i] = open_list[i + 1];
        }
        open_count--;

        closed_list[closed_count++] = current;  // 将当前节点加入关闭列表

        Node* neighbors[4];
        int neighbor_count;
        get_neighbors(current, neighbors, &neighbor_count);  // 生成当前节点的所有邻居节点

        // 遍历所有邻居节点
        for (int i = 0; i < neighbor_count; ++i) {
            Node* neighbor = neighbors[i];
            int is_in_closed_list = 0;
            for (int j = 0; j < closed_count; ++j) {
                if (is_same_state(neighbor->state, closed_list[j]->state)) {
                    is_in_closed_list = 1;  // 如果邻居节点已经在关闭列表中则跳过
                    break;
                }
            }
            if (!is_in_closed_list) {
                open_list[open_count++] = neighbor;  // 将合法的邻居节点加入开启列表
            } else {
                free(neighbor);  // 若邻居节点在关闭列表中则释放节点
            }
        }
    }

    printf("No solution found\n");  // 没有找到解决方案
}

int main() {
    int initial[N][N] = {
        {1, 4, 3},
        {2, 7, 5},
        {6, 0, 8}
    };

    astar_search(initial);  // 调用A*算法进行搜索
    printf("Total steps from initial to target: %d\n", count);  // 打印步数
    return 0;
}
