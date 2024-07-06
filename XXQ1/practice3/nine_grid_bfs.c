#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3  // 九宫格大小
#define MAX_LIST_SIZE 10000  // 最大列表大小

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

// 生成相邻节点
void get_neighbors(Node* current, Node** neighbors, int* count) {
    int blank_x, blank_y;
    get_blank_pos(current->state, &blank_x, &blank_y);
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    *count = 0;

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
                neighbors[*count] = neighbor;
                (*count)++;
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

// 广度优先搜索算法求解函数
void bfs_search(int initial[N][N]) {
    Node* open_list[MAX_LIST_SIZE];
    int open_count = 0;

    Node* closed_list[MAX_LIST_SIZE];
    int closed_count = 0;

    Node* initial_node = create_node(initial, NULL, 0);
    if (initial_node == NULL) {
        printf("Failed to create initial node.\n");
        return;
    }
    open_list[open_count++] = initial_node;

    while (open_count > 0) {
        Node* current = open_list[0];
        if (is_same_state(current->state, target)) {
            print_path(current);
            count = current->depth;
            free_path(current);
            return;
        }

        for (int i = 0; i < open_count - 1; ++i) {
            open_list[i] = open_list[i + 1];
        }
        open_count--;

        closed_list[closed_count++] = current;

        Node* neighbors[4];
        int neighbor_count;
        get_neighbors(current, neighbors, &neighbor_count);

        for (int i = 0; i < neighbor_count; ++i) {
            Node* neighbor = neighbors[i];
            int is_in_closed_list = 0;
            for (int j = 0; j < closed_count; ++j) {
                if (is_same_state(neighbor->state, closed_list[j]->state)) {
                    is_in_closed_list = 1;
                    break;
                }
            }
            if (!is_in_closed_list) {
                open_list[open_count++] = neighbor;
            } else {
                free(neighbor);
            }
        }
    }

    printf("No solution found\n");
}

int main() {
    int initial[N][N] = {
        {2, 8, 3},
        {1, 6, 4},
        {7, 0, 5}
    };

    bfs_search(initial);  // 调用BFS算法进行搜索
    printf("Total steps from initial to target: %d\n", count);
    return 0;
}
