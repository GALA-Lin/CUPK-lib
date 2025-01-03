//树的路径求解
#include <stdio.h>
#include <string.h> //包含字符串比较、拷贝等字符串处理函数
#include <malloc.h> //包含动态内存分配、回收函数等内存分配管理函数
#define EqualFun strcmp //符号常量，重命名比较大小，提高复用性
#define SetValue strcpy //符号常量，重命名赋值，提高复用性
#define NAMESIZE 20 //字符串（节点名称）长度
 
#define TRUE 1
#define FALSE 0
typedef int Status;





//树的建立
//（3）兄弟节点关系构建
//AddANeighbor把一个节点加入到兄弟节点群中。
Neighbor AddANeighbor(Neighbor br, Node Node) //在br兄弟节点群中增加一个兄弟节点Node
{
    Neighbor b, pb; //兄弟节点变量
    b = (Neighbor) malloc(sizeof(struct NeighborNode)); //动态开辟一个兄弟单元
    SetValue(b->node, Node);
    b->next = NULL;
    if (br == NULL) //没有兄弟节点的情况
    {
        br = b; //Node就是第一个兄弟
    } else {//有兄弟节点的情况，Node就是最后一个兄弟节点
        pb = br;
        while (pb->next) {
            pb = pb->next;
        }
        pb->next = b;
    }
    return br; //返回兄弟节点
}

//（5）带子节点的双亲加入树中
//AddAsubTree将子树（双亲节点）加入到树中。
Graph AddAsubTree(Graph graph, Graph subgraph) //双亲节点加入树中
{
    Graph t = graph; //临时树
    if (graph == NULL) { //树不存在
        graph = subgraph; //带子节点的双亲节点即为树
    } else { //树存在
        while (t->next) {
            t = t->next;
        }
        t->next = subgraph; //带子节点的双亲节点加入树的最后
    }
    return graph; //返回树的指针
}

//（6）清除兄弟节点群

//（7）清除树


//（8）字符数组转换
//CreateSt把字符串的字符‘/’变换为转义字符‘\0’（字符串结束标志），即在数组中存放多个节点名称（兄弟节点）的字符串。
void CreateStr(char *NeighborSetValue) //字符数组转换为多个字符串
{
    char *c = NeighborSetValue; //临时字符串
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
//CreateNeighbors把字符串中含有多个兄弟节点名称建立树的兄弟节点群（链表）。
Neighbor CreateNeighbors(Neighbor Neighbors, char *NeighborSetValue) //若干个子节点构成兄弟
{
    char *p = NeighborSetValue; //多个节点，分隔符‘/’
    Node Node;
    CreateStr(NeighborSetValue); //变为多个字符串
    while (*p) {
        SetValue(Node, p);
        Neighbors = AddANeighbor(Neighbors, Node); //加入兄弟关系中
        p += strlen(Node) + 1; //下一个节点
    }
    return Neighbors; //返回兄弟链表
}

//（9）从树文件建立树
//树文件为文本文件，其记录格式为单数行为双亲节点，偶数行为子节点（兄弟节点）集合，用字符‘/’分隔符分开。
//CreateGraph从图文件建立图（链表）
Graph CreateGraph(Graph graph, char *filename) //从文件中创建树
{
    Graph subgraph;
    Neighbor Neighbors;
    FILE *fp;
    char parent[200], NeighborSetValue[5000];
    fp = fopen(filename, "r");
    while (!feof(fp)) { //文件是否还存在树的节点名称
        fscanf(fp, "%s", parent); //读入双亲节点
        fscanf(fp, "%s", NeighborSetValue);
        Neighbors = NULL; //读入若干兄弟节点（子节点），分隔符‘/’
        Neighbors = CreateNeighbors(Neighbors, NeighborSetValue); //构建双亲节点
        subgraph = Form_Pa_Ch(parent, Neighbors); //构建子树
        graph = AddAsubTree(graph, subgraph); //树中加入子树
    }
    fclose(fp); //关闭文件
    return graph; //返回所建的树
}

//树搜索相关函数
//（1）拷贝子节点集


//（2）扩展节点集
//ExpandNodes根据树结构，从双亲节点找到所有孩子节点（即兄弟节点），并拷贝所有孩子节点，最后返回所有拷贝结果的头指针。
Neighbor ExpandNodes(Graph graph, Node pa) //由节点获取子节点
{
    Neighbor children = NULL; //孩子节点
    Graph t = graph; //树
    while (t) { //节点不为空
        if (EqualFun(t->next, pa) == 0) { //找到分支节点
            children = CopyNeighbors(t->next);
            break;
        }
        t = t->next; //下一个双亲节点
    }
    return children;
}

typedef struct NeighborNode *Path;//路径，与兄弟节点形式相同

typedef struct Paths *STACK;

//树的路径求解相关函数


//（2）拷贝路径与路径集


//CopyPaths拷贝路径集，返回路径集的指针。
struct Paths *CopyPaths(struct Paths *Paths) //复制路径集合, 返回路径集合的指针
{
    struct Paths *copyNode, *lastNode, *head = NULL;
    while (Paths) //路径集合不为空
    {
        copyNode = (struct Paths *) malloc(sizeof(struct Paths)); //路径节点
        copyNode->path = CopyPath(Paths->path); //复制一条路径
        copyNode->next = NULL; //复制路径
        if (head == NULL)  //第一条路径
            head = copyNode;
        else //其他路径
            lastNode->next = copyNode;
        lastNode = copyNode; //加入路径集合
        Paths = Paths->next;
    }
    return head;
} 

//（3）路径倒序与显示
//RevPath路径倒序，即按从树根到目标节点的顺序。
void RevPath(Path path)// 路径倒序
{
    int num = 0, i;
    Node *Nodes;
    Path p = path;
    while (p)//统计路径节点的个数
    {
        p = p->next;
        num++;
    }
    Nodes = (Node *) malloc(num * sizeof(Node)); // 开辟一维数组
    for (i = 0, p = path; p; p = p->next, i++) //读取路径节点置于数组中
        SetValue(Nodes[i], p->Node);
    for (i = num - 1, p = path; p; p = p->next, i--) //数组数据倒序置于路径中
        SetValue(p->Node, Nodes[i]);
    free(Nodes); //回收数组空间
}

//兄弟显示
void priNeighbors(Neighbor Neighbor) {
    while (Neighbor) {
        printf("%s", Neighbor->Node);
        if (Neighbor->next == NULL) {
            break;
        }
        printf("%s", "->");
        Neighbor = Neighbor->next;
    }
}

//显示路径，复用了显示兄弟函数。
void priPath(Path path) //显示路径, 复用了显示兄弟函数
{
    priNeighbors((Neighbor) path); //路径与兄弟节点集合形式相同
}

//（4）路径加入路径集











//（6）回收路径和路径集空间
//ClearPath回收路径数据空间，复用了回收兄弟数据空间函数
Path ClearPath(Path path) //回收路径空间
{
    path = (Path) ClearNeighbors((Neighbor) path); //路径与兄弟节点集合形式相同
    return path;
}

//ClearPaths回收路径集数据空间。
struct Paths *ClearPaths(struct Paths *Paths) //回收路径空间
{
    struct Paths *Paths1 = Paths;
    while (Paths) //所有路径
    {
        Paths1 = Paths;
        ClearPath(Paths1->path); //回收一条路径空间
        Paths = Paths->next; //下一条路径
        free(Paths1);
    }
    return Paths;
}

//（7）路径进栈与所有路径进栈
//PushAPath把一条路径压入堆栈，返回堆栈头指针
STACK PushAPath(STACK stack, Path path) //一条路径进栈
{
    Path tempath;
    STACK st;
    tempath = CopyPath(path); //复制路径
    st = (struct Paths *) malloc(sizeof(struct Paths)); //路径节点
    st->path = tempath; //置路径于栈中
    if (stack == NULL) //第1条路径
        st->next = NULL;
    else //已有路径
        st->next = stack;
    stack = st;
    return stack;
}

//PushPaths把路径集压入堆栈，返回路径集头指针。
STACK PushPaths(STACK stack, struct Paths *Paths) // 所有路径进栈
{
    struct Paths *p, *head;
    head = CopyPaths(Paths); //复制路径集合
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
STACK PopANode(STACK stack, Node Node, Path *path) {
    STACK p = stack;
    Path tempath;
    if (p != NULL) {
        tempath = p->path; //一条路径
        SetValue(Node, tempath->Node); //获取节点
        *path = CopyPath(tempath); //获取路径
        stack = p->next; //栈顶变化
        free(p); //删除路径
    }
    return stack; //返回栈顶
}

//（9）回收堆栈


//（10）路径求解


int  main(int argc, char const *argv[]) {//测试求解路径c2
    Node start, end;  //树开始节点名称和目标节点名称
    Graph graph = NULL; //链式存储结构树
    Status flag; //是否求得路径的标识
    Path path = NULL; //求得的路径
        //STACK stack = NULL; 路径堆栈
    char *filename = "F:\\VS_code_C\\xiaoxueqi\\Chapter3\\ceshi.txt";  //树数据文件
    graph = CreateGraph(graph, filename);
    printf("The Start Node:");
    scanf("%s", start);
    printf("The End Node:");
    scanf("%s", end);
    //flag = SearchPath(graph, start, end, &path);
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
    ClearTree(graph);
}
