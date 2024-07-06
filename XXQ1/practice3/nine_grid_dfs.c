#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3  // 九宫格大小
#define MAX_DEPTH 100  // 设置最大递归深度，防止无限递归

int count = 0;  // 状态计数

// 目标状态
int target[N][N] = {
    {1, 2, 3},
    {8, 0, 4},
    {7, 6, 5}
};

// 节点结构体
typedef struct Node {
    int state[N][N];  // 当前状态
    struct Node* parent;  // 父节点
    int depth;  // 当前深度
} Node;

// 节点比较以检查两个状态是否相同
int is_same_state(int state1[N][N], int state2[N][N]) {
    return memcmp(state1, state2, N * N * sizeof(int)) == 0;
}

// 生成一个新节点
Node* create_node(int state[N][N], Node* parent, int depth) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node != NULL) {
        memcpy(new_node->state, state, N * N * sizeof(int));
        new_node->parent = parent;
        new_node->depth = depth;
    }
    return new_node;
}

// 获取空格位置
void get_blank_pos(int state[N][N], int* blank_x, int* blank_y) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (state[i][j] == 0) {
                *blank_x = i;
                *blank_y = j;
                return;
            }
        }
    }
}

// 打印路径
void print_path(Node* node) {
    if (node == NULL) return;
    print_path(node->parent);
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
    free_path(node->parent);
    free(node);
}

// 深度优先搜索算法求解函数
int dfs_search(Node* current) {
    if (is_same_state(current->state, target)) {
        print_path(current);
        count = current->depth;
        return 1;
    }
    
    if (current->depth >= MAX_DEPTH) {
        return 0;  // 达到最大深度，停止递归
    }

    int blank_x, blank_y;
    get_blank_pos(current->state, &blank_x, &blank_y);
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    for (int i = 0; i < 4; ++i) {
        int new_x = blank_x + directions[i][0];
        int new_y = blank_y + directions[i][1];
        if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N) {
            int new_state[N][N];
            memcpy(new_state, current->state, N * N * sizeof(int));
            new_state[blank_x][blank_y] = new_state[new_x][new_y];
            new_state[new_x][new_y] = 0;
            Node* neighbor = create_node(new_state, current, current->depth + 1);
            if (neighbor != NULL) {
                if (dfs_search(neighbor)) {  // 递归搜索
                    return 1;
                }
                free(neighbor);
            }
        }
    }
    return 0;
}

int main() {
    int initial[N][N] = {
        {2, 8, 3},
        {1, 6, 4},
        {7, 0, 5}
    };

    Node* initial_node = create_node(initial, NULL, 0);
    if (initial_node == NULL) {
        printf("Failed to create initial node.\n");
        return -1;
    }

    if (!dfs_search(initial_node)) {
        printf("No solution found\n");
    }

    printf("Total steps from initial to target: %d\n", count);
    free_path(initial_node);

    return 0;
}

