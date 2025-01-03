//树的路径求解
#include <stdio.h>
#include <string.h> //包含字符串比较、拷贝等字符串处理函数
#include <malloc.h> //包含动态内存分配、回收函数等内存分配管理函数

#define EqualFun strcmp //符号常量，重命名比较大小，提高复用性
#define SetValue strcpy //符号常量，重命名赋值，提高复用性
#define NAMESIZE 3 //字符串（节点名称）长度

#define TRUE 1
#define FALSE 0
typedef int STATUS;

typedef char NODE[NAMESIZE]; //节点名称类型NODE，存节点名称
struct BROTHERNODE //兄弟节点类型，表示兄弟节点
{
    NODE node; //兄弟节点名称
    struct BROTHERNODE *next; //兄弟节点链接指针，链接其他兄弟
};
//重命名兄弟节点类型，表示若干兄弟节点
typedef struct BROTHERNODE *BROTHER;
struct PARENTNODE //双亲节点类型，表示子树树根节点
{
    NODE node; //双亲节点名称
    BROTHER children; //所有子节点
};
typedef struct PARENTNODE PARENT; //重命名双亲节点类型
struct TREENODE //树分支节点类型
{
    PARENT node; //双亲节点，表示子树树根节点
    struct TREENODE *next; //双亲节点指针指向其他双亲节点
};
//重命名所有双亲节点类型，表示树的存储结构
typedef struct TREENODE *TREE;


//（1）通用比较函数
//Equal判断树的两个节点是否相同，相同为1，不同为0。
int Equal(NODE n1, NODE n2, int *fun()) //fun为比较函数，函数指针变量
{
    return (int) fun(n1, n2);
}

//（2）通用赋值函数
//Set实现树节点的赋值。
void Set(NODE n1, NODE n2, void *fun()) //fun为赋值函数，函数指针变量
{
    fun(n1, n2);
}

//树的建立
//（3）兄弟节点关系构建
//AddABrother把一个节点加入到兄弟节点群中。
BROTHER AddABrother(BROTHER br, NODE node) //在br兄弟节点群中增加一个兄弟节点node
{
    BROTHER b, pb; //兄弟节点变量
    b = (BROTHER) malloc(sizeof(struct BROTHERNODE)); //动态开辟一个兄弟单元
    Set(b->node, node, SetValue);
    b->next = NULL;
    if (br == NULL) //没有兄弟节点的情况
    {
        br = b; //node就是第一个兄弟
    } else {//有兄弟节点的情况，node就是最后一个兄弟节点
        pb = br;
        while (pb->next) {
            pb = pb->next;
        }
        pb->next = b;
    }
    return br; //返回兄弟节点
}

//（4）双亲与子节点关系构建
//Form_Pa_Ch将兄弟节点（即所有子节点）连接到双亲节点中，构成一个子树。
TREE Form_Pa_Ch(NODE pa, BROTHER br) //双亲节点与兄弟节点构成子树
{
    TREE parent;
    parent = (TREE) malloc(sizeof(struct TREENODE)); //创建双亲节点
    Set(parent->node.node, pa, SetValue);
    parent->node.children = br; //兄弟节点与双亲节点构成子树
    parent->next = NULL;
    return parent; //返回带兄弟节点的双亲节点，即子树
}

//（5）带子节点的双亲加入树中
//AddAsubTree将子树（双亲节点）加入到树中。
TREE AddAsubTree(TREE tree, TREE subtree) //双亲节点加入树中
{
    TREE t = tree; //临时树
    if (tree == NULL) { //树不存在
        tree = subtree; //带子节点的双亲节点即为树
    } else { //树存在
        while (t->next) {
            t = t->next;
        }
        t->next = subtree; //带子节点的双亲节点加入树的最后
    }
    return tree; //返回树的指针
}

//（6）清除兄弟节点群
//ClearBrothers清空兄弟节点群，回收数据单元
BROTHER ClearBrothers(BROTHER br) //回收兄弟节点变量
{
    BROTHER br1 = br; //临时兄弟变量
    while (br) {
        br1 = br;
        br = br->next;
        free(br1); //回收单元
        br1 = NULL;
    }
    return br; //返回NULL
}

//（7）清除树
//ClearTree清空树，回收数据单元。
TREE ClearTree(TREE tree) //回收树空间
{
    TREE tree1 = tree; //临时树
    while (tree) {
        tree1 = tree;
        tree = tree->next;
        free(tree1); //回收单元
        tree1 = NULL;
    }
    return tree; //返回NULL
}

//（8）字符数组转换
//CreateSt把字符串的字符‘/’变换为转义字符‘\0’（字符串结束标志），即在数组中存放多个节点名称（兄弟节点）的字符串。
void CreateStr(char *brotherset) //字符数组转换为多个字符串
{
    char *c = brotherset; //临时字符串
    while (*c) {
        if (*c == '/') {
            *c = '\0'; //插入字符串结束标记
        }
        c++;
    }
    c++;
    *c = '\0'; //多一个结束标记
}

//（9）字符数组建立兄弟关系
//CreateBrothers把字符串中含有多个兄弟节点名称建立树的兄弟节点群（链表）。
BROTHER CreateBrothers(BROTHER brothers, char *brotherset) //若干个子节点构成兄弟
{
    char *p = brotherset; //多个节点，分隔符‘/’
    NODE node;
    CreateStr(brotherset); //变为多个字符串
    while (*p) {
        Set(node, p, SetValue);
        brothers = AddABrother(brothers, node); //加入兄弟关系中
        p += strlen(node) + 1; //下一个节点
    }
    return brothers; //返回兄弟链表
}

//（9）从树文件建立树
//树文件为文本文件，其记录格式为单数行为双亲节点，偶数行为子节点（兄弟节点）集合，用字符‘/’分隔符分开。
//CreateTree从树文件建立树（链表）
TREE CreateTree(TREE tree, char *filename) //从文件中创建树
{
    TREE subtree;
    BROTHER brothers;
    FILE *fp;
    char parent[200], brotherset[5000];
    fp = fopen(filename, "r");
    while (!feof(fp)) { //文件是否还存在树的节点名称
        fscanf(fp, "%s", parent); //读入双亲节点
        fscanf(fp, "%s", brotherset);
        brothers = NULL; //读入若干兄弟节点（子节点），分隔符‘/’
        brothers = CreateBrothers(brothers, brotherset); //构建双亲节点
        subtree = Form_Pa_Ch(parent, brothers); //构建子树
        tree = AddAsubTree(tree, subtree); //树中加入子树
    }
    fclose(fp); //关闭文件
    return tree; //返回所建的树
}

//树搜索相关函数
//（1）拷贝子节点集
//CopyBrothers拷贝所有节点（链表），返回拷贝结果的头指针。
BROTHER CopyBrothers(BROTHER children) //节点集复制
{
    BROTHER copynode, lastnode, head = NULL; //没有子节点
    while (children) { //分配节点空间
        copynode = (BROTHER) malloc(sizeof(struct BROTHERNODE));
        Set(copynode->node, children->node, SetValue); //复制节点
        copynode->next = NULL;
        if (head == NULL) //第一个节点
            head = copynode;
        else //建立链接，复制子节点集
            lastnode->next = copynode;
        lastnode = copynode;
        children = children->next; //下一个子节点
    }
    return head; //返回头节点指针
}

//（2）扩展节点集
//ExpandNodes根据树结构，从双亲节点找到所有孩子节点（即兄弟节点），并拷贝所有孩子节点，最后返回所有拷贝结果的头指针。
BROTHER ExpandNodes(TREE tree, NODE pa) //由节点获取子节点
{
    BROTHER children = NULL; //孩子节点
    TREE t = tree; //树
    while (t) { //节点不为空
        if (Equal(t->node.node, pa, EqualFun) == 0) { //找到分支节点
            children = CopyBrothers(t->node.children);
            break;
        }
        t = t->next; //下一个双亲节点
    }
    return children;
}

typedef struct BROTHERNODE *PATH;//路径，与兄弟节点形式相同
struct PATHS {
    PATH path;
    struct PATHS *next;
};
typedef struct PATHS *STACK;

//树的路径求解相关函数
//（1）节点加入路径.
// AddANodeToPath在路径中加入一个节点形成新的路径
PATH AddANodeToPath(NODE node, PATH path)//节点加入路径中
{
    PATH p;
    p = (BROTHER) malloc(sizeof(struct BROTHERNODE)); //开辟节点空间
    Set(p->node, node, SetValue); //赋值
    if (path == NULL) //路径上第一个节点
        p->next = NULL;
    else
        p->next = path; //加入到路径头部
    path = p; //路径倒序加入
    return path; //返回路径头部
}

//（2）拷贝路径与路径集
//CopyPath拷贝一条路径，返回新路径。由于路径存储形式与兄弟节点,存储形式一样，采用拷贝兄弟节点的函数，即函数复用。
PATH CopyPath(PATH path) //复制路径
{
    PATH tempath;
    tempath = (PATH) CopyBrothers((BROTHER) path); //路径与兄弟节点集合相同
    return tempath;
}

//CopyPaths拷贝路径集，返回路径集的指针。
struct PATHS *CopyPaths(struct PATHS *paths) //复制路径集合, 返回路径集合的指针
{
    struct PATHS *copynode, *lastnode, *head = NULL;
    while (paths) //路径集合不为空
    {
        copynode = (struct PATHS *) malloc(sizeof(struct PATHS)); //路径节点
        copynode->path = CopyPath(paths->path); //复制一条路径
        copynode->next = NULL; //复制路径
        if (head == NULL)  //第一条路径
            head = copynode;
        else //其他路径
            lastnode->next = copynode;
        lastnode = copynode; //加入路径集合
        paths = paths->next;
    }
    return head;
}

//（3）路径倒序与显示
//RevPath路径倒序，即按从树根到目标节点的顺序。
void RevPath(PATH path)// 路径倒序
{
    int num = 0, i;
    NODE *nodes;
    PATH p = path;
    while (p)//统计路径节点的个数
    {
        p = p->next;
        num++;
    }
    nodes = (NODE *) malloc(num * sizeof(NODE)); // 开辟一维数组
    for (i = 0, p = path; p; p = p->next, i++) //读取路径节点置于数组中
        Set(nodes[i], p->node, SetValue);
    for (i = num - 1, p = path; p; p = p->next, i--) //数组数据倒序置于路径中
        Set(p->node, nodes[i], SetValue);
    free(nodes); //回收数组空间
}

//兄弟显示
void priBrothers(BROTHER brother) {
    while (brother) {
        printf("%s", brother->node);
        if (brother->next == NULL) {
            break;
        }
        printf("%s", "->");
        brother = brother->next;
    }
}

//显示路径，复用了显示兄弟函数。
void priPath(PATH path) //显示路径, 复用了显示兄弟函数
{
    priBrothers((BROTHER) path); //路径与兄弟节点集合形式相同
}

//（4）路径加入路径集
//AddAPathToPaths把一条路径加入到路径集中。原理上是队列加入数据元素操作。
struct PATHS *AddAPathToPaths(PATH path, struct PATHS *paths) //路径加入路径集合
{
    PATH copypath;
    struct PATHS *ps = NULL, *p;
    if (path == NULL) return paths; //没有路径
    copypath = CopyPath(path); //复制路径
    ps = (struct PATHS *) malloc(sizeof(struct PATHS)); //开辟路径集合节点
    ps->path = copypath; //复制的路径置入
    ps->next = NULL;
    if (paths == NULL)  //路径集合为空
        paths = ps;
    else //新节点路径放置最后
    {
        p = paths;
        while (p->next) p = p->next;
        p->next = ps;
    }
    return paths;
}

//（5）节点集与路径形成路径集
// FormPathsFromNodes把每个节点加入路径，形成一条路径，最终形成多条路径。
struct PATHS *FormPathsFromNodes(BROTHER brothers, PATH path, struct PATHS *paths) //每个节点均加入到路径中, 形成路径集合
{
    PATH tempath;
    while (brothers) //存在节点
    {
        tempath = CopyPath(path); //复制路径
        tempath = AddANodeToPath(brothers->node, tempath); //节点加入路径
        paths = AddAPathToPaths(tempath, paths); //新路径加入路径集合
        brothers = brothers->next; // 下一个节点
    }
    return paths; //返回路径集合
}

//（6）回收路径和路径集空间
//ClearPath回收路径数据空间，复用了回收兄弟数据空间函数
PATH ClearPath(PATH path) //回收路径空间
{
    path = (PATH) ClearBrothers((BROTHER) path); //路径与兄弟节点集合形式相同
    return path;
}

//ClearPaths回收路径集数据空间。
struct PATHS *ClearPaths(struct PATHS *paths) //回收路径空间
{
    struct PATHS *paths1 = paths;
    while (paths) //所有路径
    {
        paths1 = paths;
        ClearPath(paths1->path); //回收一条路径空间
        paths = paths->next; //下一条路径
        free(paths1);
    }
    return paths;
}

//（7）路径进栈与所有路径进栈
//PushAPath把一条路径压入堆栈，返回堆栈头指针
STACK PushAPath(STACK stack, PATH path) //一条路径进栈
{
    PATH tempath;
    STACK st;
    tempath = CopyPath(path); //复制路径
    st = (struct PATHS *) malloc(sizeof(struct PATHS)); //路径节点
    st->path = tempath; //置路径于栈中
    if (stack == NULL) //第1条路径
        st->next = NULL;
    else //已有路径
        st->next = stack;
    stack = st;
    return stack;
}

//PushPaths把路径集压入堆栈，返回路径集头指针。
STACK PushPaths(STACK stack, struct PATHS *paths) // 所有路径进栈
{
    struct PATHS *p, *head;
    head = CopyPaths(paths); //复制路径集合
    p = head;
    if (p != NULL) //逐一加入栈中
    {
        while (p->next) p = p->next;
        p->next = stack;
        stack = head;
    }
    return stack;
}

//（8）出栈与节点
//PopANode从堆栈中弹出获取路径和路径的节点名称，返回堆栈头指针。
STACK PopANode(STACK stack, NODE node, PATH *path) {
    STACK p = stack;
    PATH tempath;
    if (p != NULL) {
        tempath = p->path; //一条路径
        Set(node, tempath->node, SetValue); //获取节点
        *path = CopyPath(tempath); //获取路径
        stack = p->next; //栈顶变化
        free(p); //删除路径
    }
    return stack; //返回栈顶
}

//（9）回收堆栈
//ClearStack回收堆栈数据空间，复用了路径集回收函数。
STACK ClearStack(STACK stack) //回收栈空间
{
    stack = ClearPaths((struct PATHS *) stack); //堆栈与路径集合的形式相同
    return stack;
}

//（10）路径求解
//SearchPath给定树、开始节点、目标节点，求解从开始节点到目标节点的路径。
STATUS SearchPath(TREE tree, NODE start, NODE end, PATH *path) //判断节点是否在树中, 并求取路径
{
    NODE node; //树节点名称
    BROTHER children; //树孩子节点
    STACK stack = NULL; //堆栈
    STATUS flag = FALSE;  //堆栈是否为空的标识
    PATH tempath = NULL; //临时路径
    struct PATHS *paths = NULL; //路径集合
    if (tree == NULL) return flag; //树不存储
    tempath = AddANodeToPath(start, tempath); //形成路径
    stack = PushAPath(stack, tempath); //路径进栈
    while (stack) //堆栈不为空继续搜索
    {
        stack = PopANode(stack, node, &tempath); //出栈, 获取树节点和路径
        if (Equal(end, node, EqualFun) == 0) //是否为所求目标节点
        {
            flag = TRUE; //修正标识
            *path = CopyPath(tempath); //获取路径
            break;
        }
        children = ExpandNodes(tree, node); //获取下一级所有节点
        paths = FormPathsFromNodes(children, tempath, paths); //形成路径集合
        stack = PushPaths(stack, paths); //所有路径进栈
        paths = ClearPaths(paths); //清除所有路径
    }
    ClearStack(stack); //清除堆栈
    return flag; //获得路径标识
}

int  main(int argc, char const *argv[]) {//测试求解路径c2
    NODE start, end;  //树开始节点名称和目标节点名称
    TREE tree = NULL; //链式存储结构树
    STATUS flag; //是否求得路径的标识
    PATH path = NULL; //求得的路径
        //STACK stack = NULL; 路径堆栈
    char *filename = "F:\\VS_code_C\\xiaoxueqi\\Chapter3\\ceshi.txt";  //树数据文件
    tree = CreateTree(tree, filename);
    printf("The Start Node:");
    scanf("%s", start);
    printf("The End Node:");
    scanf("%s", end);
    flag = SearchPath(tree, start, end, &path);
    printf("Search %s from %s, Status=%d\n", end, start, flag);
    if (flag != 0) {
        printf("Path=");
    } else {
        printf("Path=NULL");
    }
    RevPath(path);
    priPath(path);
    printf("\n==================\n");
    ClearPath(path);
    ClearTree(tree);
}
