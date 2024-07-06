#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct TreeNode {
    char name[MAX_NAME_LEN];
    struct TreeNode *left;  // 左孩子
    struct TreeNode *right; // 右兄弟
} TreeNode;

// 创建节点
TreeNode* createNode(char *name) {
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 查找节点
TreeNode* findNode(TreeNode *root, char *name) {
    if (root == NULL) return NULL;
    if (strcmp(root->name, name) == 0) return root;

    TreeNode *found = findNode(root->left, name);
    if (found) return found;

    return findNode(root->right, name);
}

// 添加子节点
void addChildren(TreeNode *parent, char *childrenStr) {
    char *token = strtok(childrenStr, "/");
    TreeNode *current = NULL;

    if (token != NULL) {
        parent->left = createNode(token);
        current = parent->left;
    } else {
        return;
    }

    token = strtok(NULL, "/");
    while (token != NULL) {
        current->right = createNode(token);
        current = current->right;
        token = strtok(NULL, "/");
    }
}

// 构建树
TreeNode* buildTree(int n, char data[][MAX_NAME_LEN]) {
    TreeNode *root = NULL;

    for (int i = 0; i < n * 2; i += 2) {
        char *parentName = data[i];
        char *childrenStr = data[i + 1];

        TreeNode *parent = findNode(root, parentName);
        if (parent == NULL) {
            parent = createNode(parentName);
            if (root == NULL) root = parent;
        }

        if (strcmp(childrenStr, "/") != 0) {
            addChildren(parent, childrenStr);
        }
    }
    return root;
}

// 递归释放内存
void freeTree(TreeNode *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// 查找路径
int findPath(TreeNode *root, char *target, char path[][MAX_NAME_LEN], int pathIndex) {
    if (root == NULL) return 0;

    strcpy(path[pathIndex], root->name);
    if (strcmp(root->name, target) == 0) return 1;

    if (findPath(root->left, target, path, pathIndex + 1)) return 1;
    if (findPath(root->right, target, path, pathIndex)) return 1;

    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    char data[2 * n][MAX_NAME_LEN];
    for (int i = 0; i < 2 * n; i++) {
        scanf("%s", data[i]);
    }

    char target[MAX_NAME_LEN];
    scanf("%s", target);

    TreeNode *root = buildTree(n, data);

    char path[n][MAX_NAME_LEN];
    memset(path, 0, sizeof(path)); // 初始化路径数组

    if (findPath(root, target, path, 0)) {
        int first = 1; // 标识是否是第一个输出的节点
        for (int i = 0; i < n; i++) {
            if (strlen(path[i]) > 0) {
                if (!first) {
                    printf(" ");
                }
                printf("%s", path[i]);
                first = 0; // 已输出第一个节点，后面的都会加空格
            }
        }
        printf("\n"); // 打印完路径后换行
    } else {
        printf("not found\n");
    }

    // 释放树节点的内存
    freeTree(root);

    return 0;
}