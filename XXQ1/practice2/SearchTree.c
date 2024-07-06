/*读入相应数据以链式存储方式创建树形结构（即表头结点表+边表的邻接表形式），输入待查找的结点名称，判断该结点是否在树中，是则打印"yes"，否则打印"no"
【输入形式】
第一行是树的结点总个数n，其后2n行是双亲结点及其孩子结点，偶数行是双亲结点名称，奇数行是其孩子结点，多个孩子结点之间使用"\"分隔,最后一行输入带查找的结点名称。
【输出形式】
输出数据有1行，判断该结点是否在树中，是则打印"yes"，否则打印"no"*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义最大长度常量
#define MAX_LEN 100

// 定义子节点结构体
typedef struct ChildNode
{
    char name[MAX_LEN];     // 子节点的名称
    struct ChildNode *next; // 指向下一个子节点的指针
} ChildNode;

// 定义父节点结构体
typedef struct ParentNode
{
    char name[MAX_LEN];      // 父节点的名称
    ChildNode *firstChild;   // 指向第一个子节点的指针
    struct ParentNode *next; // 指向下一个父节点的指针
} ParentNode;

// 定义树结构体
typedef struct
{
    ParentNode *head; // 指向树中第一个父节点的指针
} Tree;

// 创建树函数，初始化树
Tree *createTree()
{
    Tree *tree = (Tree *)malloc(sizeof(Tree)); // 动态分配内存
    tree->head = NULL;                         // 初始化头指针为 NULL
    return tree;
}

// 创建父节点函数
ParentNode *createParentNode(char *name)
{
    ParentNode *parentNode = (ParentNode *)malloc(sizeof(ParentNode)); // 动态分配内存
    strcpy(parentNode->name, name);                                    // 设置父节点的名称
    parentNode->firstChild = NULL;                                     // 初始化第一个子节点指针为 NULL
    parentNode->next = NULL;                                           // 初始化下一个父节点指针为 NULL
    return parentNode;
}

// 创建子节点函数
ChildNode *createChildNode(char *name)
{
    ChildNode *childNode = (ChildNode *)malloc(sizeof(ChildNode)); // 动态分配内存
    strcpy(childNode->name, name);                                 // 设置子节点的名称
    childNode->next = NULL;                                        // 初始化下一个子节点指针为 NULL
    return childNode;
}

// 插入子节点到父节点函数
void insertChild(ParentNode *parentNode, char *childNames)
{
    char *token = strtok(childNames, "\\"); // 使用“\”分割字符串
    while (token != NULL)
    {
        ChildNode *childNode = createChildNode(token); // 创建新的子节点
        if (parentNode->firstChild == NULL)
        {                                       // 如果父节点第一个子节点为空
            parentNode->firstChild = childNode; // 设置为新创建的子节点
        }
        else
        {
            ChildNode *temp = parentNode->firstChild; // 遍历子节点链表
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = childNode; // 插入新子节点到链表末尾
        }
        token = strtok(NULL, "\\"); // 继续分割下一个子节点名称
    }
}

// 插入父节点到树函数
void insertParent(Tree *tree, char *parentName, char *childNames)
{
    ParentNode *parentNode = createParentNode(parentName); // 创建新的父节点
    insertChild(parentNode, childNames);                   // 插入子节点到新的父节点

    if (tree->head == NULL)
    {                            // 如果树头指针为空
        tree->head = parentNode; // 设置为新创建的父节点
    }
    else
    {
        ParentNode *temp = tree->head; // 遍历父节点链表
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = parentNode; // 插入新父节点到链表末尾
    }
}

// 简单线性查找树中的名称函数
int searchTree1(Tree *tree, char *searchName)
{
    ParentNode *temp = tree->head; // 从树头指针开始
    while (temp != NULL)
    {
        if (strcmp(temp->name, searchName) == 0)
        { // 如果匹配父节点名称
            return 1;
        }
        ChildNode *childTemp = temp->firstChild; // 查找子节点链表
        while (childTemp != NULL)
        {
            if (strcmp(childTemp->name, searchName) == 0)
            { // 如果匹配子节点名称
                return 1;
            }
            childTemp = childTemp->next;
        }
        temp = temp->next;
    }
    return 0; // 如果没找到，返回 0
}

int bfsSearchTree(Tree *tree, char *searchName)
{
    if (tree->head == NULL)
    {
        return 0;
    }
    ParentNode *queue[1000]; // 定义队列
    int front = 0, rear = 0; // 定义队头和队尾指针

    queue[rear++] = tree->head; // 入队树头指针

    while (front != rear)
    {
        ParentNode *temp = queue[front++]; // 出队父节点指针
        if (strcmp(temp->name, searchName) == 0)
        { // 如果匹配父节点名称
            return 1;
        }
        ChildNode *childTemp = temp->firstChild; // 查找子节点链表
        while (childTemp != NULL)
        {
            if (strcmp(childTemp->name, searchName) == 0)
            { // 如果匹配子节点名称
                return 1;
            }
            if (childTemp->next != NULL)
            {                                    // 如果有下一个子节点
                queue[rear++]= childTemp->next; // 入队下一个子节点
            }
            childTemp = childTemp->next;
        }
    }
    return 0; // 如果没找到，返回 0
}

// 深度优先搜索树函数
int dfsSearchTree(ParentNode *parentNode, char *searchName)
{
    // 检查当前父节点
    if (strcmp(parentNode->name, searchName) == 0)
    {
        return 1;
    }
    // 检查子节点链表
    ChildNode *childTemp = parentNode->firstChild;
    while (childTemp != NULL)
    {
        if (strcmp(childTemp->name, searchName) == 0)
        {
            return 1;
        }
        childTemp = childTemp->next;
    }
    // 递归检查下一个父节点
    if (parentNode->next != NULL)
    {
        return dfsSearchTree(parentNode->next, searchName);
    }

    return 0;
}

// 搜索树函数，使用深度优先搜索
int searchTree2(Tree *tree, char *searchName)
{
    if (tree->head == NULL)
    {
        return 0;
    }
    return dfsSearchTree(tree->head, searchName);
}

int searchTree3(Tree *tree, char *searchName)
{
    if (tree->head == NULL)
    {
        return 0;
    }
    return bfsSearchTree(tree, searchName);
}

int main()
{
    int n;
    scanf("%d", &n); // 读取父节点数量
    getchar();       // 去除换行符

    Tree *tree = createTree(); // 创建树

    for (int i = 0; i < n; i++)
    {
        char parent[MAX_LEN];
        char children[MAX_LEN];

        fgets(parent, MAX_LEN, stdin);        // 读取父节点名称
        parent[strcspn(parent, "\n")] = '\0'; // 去除换行符

        fgets(children, MAX_LEN, stdin);          // 读取子节点名称
        children[strcspn(children, "\n")] = '\0'; // 去除换行符

        insertParent(tree, parent, children); // 插入父节点和子节点到树中
    }

    char searchName[MAX_LEN];
    fgets(searchName, MAX_LEN, stdin);            // 读取要查找的名称
    searchName[strcspn(searchName, "\n")] = '\0'; // 去除换行符

    if (searchTree1(tree, searchName))
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }

    return 0;
}
/*
int main() {
    FILE *file = fopen("d:\\XXQ1\\practice2\\SearchTree.txt", "r");
    if (file == NULL) {
        perror("打开文件失败");
        return 1;
    }
    int n;
    fscanf(file, "%d", &n); // 读取父节点数量
    fgetc(file); // 去除换行符

    Tree *tree = createTree(); // 创建树

    for (int i = 0; i < n; i++) {
        char parent[MAX_LEN];
        char children[MAX_LEN];

        fgets(parent, MAX_LEN, file); // 读取父节点名称
        parent[strcspn(parent, "\n")] = '\0'; // 去除换行符

        fgets(children, MAX_LEN, file); // 读取子节点名称
        children[strcspn(children, "\n")] = '\0'; // 去除换行符

        insertParent(tree, parent, children); // 插入父节点和子节点到树中
    }

    char searchName[MAX_LEN];
    fgets(searchName, MAX_LEN, file); // 读取要查找的名称
    searchName[strcspn(searchName, "\n")] = '\0'; // 去除换行符

    fclose(file);

    if (searchTree1(tree, searchName)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}
*/