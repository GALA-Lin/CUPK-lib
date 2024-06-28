#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <F:\VS_code_C\Books of YanWeimin\01xulun\Status.h>

#define NAMESIZE 2


//图的存储结构
typedef char Node[NAMESIZE];                            //节点名称类型
typedef struct NeighborNode                                     //节点类型
{
    Node node;                                          //节点
    struct NeighborNode *next;                          //邻接点
}NeighborNode, *Neighbor, *Path;                        //邻接点类型和路径类型相同

typedef struct ANode                                            //邻接点类型
{
    Node node;                                          //节点
    Neighbor adjacents;                                 //邻接点
} ANode, AnyNode;

typedef struct GraphNode
{
    AnyNode node;                                       //节点
    struct GraphNode *next;                             //其他节点
} GraphNode, *Graph;                                    //图的节点和图指针

typedef struct Paths
{
    Path path;                                          //当前路径
    struct Paths *next;                                 //下一条路径
} Paths, *PathsAggregate;                               //路径集合及其指针 */

typedef struct Paths *STACK;

Graph graph;
//ClearTree清空树，回收数据单元。
Graph ClearGraph(Graph graph) //回收树空间
{
    Graph graph1 = graph; //临时树
    while (graph) {
        graph1 = graph;
        graph = graph->next;
        free(graph1); //回收单元
        graph1 = NULL;
    }
    return graph; //返回NULL
}

//（4）双亲与子节点关系构建
//Form_Pa_Ch将兄弟节点（即所有子节点）连接到双亲节点中，构成一个子树。
Graph Form_Pa_Ch(Node pa, Neighbor br) //双亲节点与兄弟节点构成子树
{
    Graph parent;
    parent = (Graph) malloc(sizeof(struct GraphNode)); //创建双亲节点
    strcpy(parent->node.node, pa);
    parent->node.adjacents = br; //兄弟节点与双亲节点构成子树
    parent->next = NULL; 
    return parent; //返回带兄弟节点的双亲节点，即子树
}


//（5）带子节点的双亲加入树中
//AddAsubTree将子树（双亲节点）加入到树中。
Graph AddAsubTree(Graph tree, Graph subtree) //双亲节点加入树中
{
    Graph t = tree; //临时树
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

//（3）兄弟节点关系构建
//AddABrother把一个节点加入到兄弟节点群中。
Neighbor AddABrother(Neighbor br, Node node) //在br兄弟节点群中增加一个兄弟节点node
{
    Neighbor b, pb; //兄弟节点变量
    b = (Neighbor) malloc(sizeof(struct NeighborNode)); //动态开辟一个兄弟单元
    strcpy(b->node, node); 
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
Neighbor CreateBrothers(Neighbor brothers, char *brotherset) //若干个子节点构成兄弟
{
    char *p = brotherset; //多个节点，分隔符‘/’
    Node node;
    CreateStr(brotherset); //变为多个字符串
    while (*p) {
        strcpy(node, p);
        brothers = AddABrother(brothers, node); //加入兄弟关系中
        p += strlen(node) + 1; //下一个节点
    }
    return brothers; //返回兄弟链表
}

//CreateTree从树文件建立树（链表）
Graph CreateTree(Graph graph, char *filename) //从文件中创建树
{
    Graph subgraph;
    Neighbor brothers;
    FILE *fp;
    char parent[200], brotherset[5000];
    fp = fopen(filename, "r");
    while (!feof(fp)) { //文件是否还存在树的节点名称
        fscanf(fp, "%s", parent); //读入双亲节点
        fscanf(fp, "%s", brotherset);
        brothers = NULL; //读入若干兄弟节点（子节点），分隔符‘/’
        brothers = CreateBrothers(brothers, brotherset); //构建双亲节点
        subgraph = Form_Pa_Ch(parent, brothers); //构建子树
        graph = AddAsubTree(graph, subgraph); //树中加入子树 
    }
    fclose(fp); //关闭文件
    return graph; //返回所建的树
}

//CopyNeighbors拷贝所有节点（链表），返回拷贝结果的头指针。
Neighbor CopyNeighbors(Neighbor children) //节点集复制
{
    Neighbor copyNode, lastNode, head = NULL; //没有子节点
    while (children) { //分配节点空间
        copyNode = (Neighbor) malloc(sizeof(struct NeighborNode));
        strcpy(copyNode->node, children->node); //复制节点
        copyNode->next = NULL;
        if (head == NULL) //第一个节点
            head = copyNode;
        else //建立链接，复制子节点集
            lastNode->next = copyNode;
        lastNode = copyNode;
        children = children->next; //下一个子节点
    }
    return head; //返回头节点指针
}

//CopyPath拷贝一条路径，返回新路径。由于路径存储形式与兄弟节点,存储形式一样，采用拷贝兄弟节点的函数，即函数复用。
Path CopyPath(Path path) //复制路径
{
    Path tempath;
    tempath = (Path) CopyNeighbors((Neighbor) path); //路径与兄弟节点集合相同
    return tempath;
}

//AddAPathToPaths把一条路径加入到路径集中。原理上是队列加入数据元素操作。
struct Paths *AddAPathToPaths(Path path, struct Paths *Paths) //路径加入路径集合
{
    Path copypath;
    struct Paths *ps = NULL, *p;
    if (path == NULL) return Paths; //没有路径
    copypath = CopyPath(path); //复制路径
    ps = (struct Paths *) malloc(sizeof(struct Paths)); //开辟路径集合节点
    ps->path = copypath; //复制的路径置入
    ps->next = NULL;
    if (Paths == NULL)  //路径集合为空
        Paths = ps;
    else //新节点路径放置最后
    {
        p = Paths;
        while (p->next) p = p->next;
        p->next = ps;
    }
    return Paths;
}

/* 1.判断节点是否在路径中。IsInPath用于判断节点是否在路径中，返回“真”、“假”，
用于回路的判断 */
Status IsInPath(Node Node, Path path)                   //节点在路径中
{
    Path p = path;
    Status flag = FALSE;                                //存在标记
    
    while(p)    {
        if(strcmp(Node, p->node) == 0)   {
            flag = TRUE;
            break;
        } else  {
            p = p->next;
        }
    }

    return flag;
}

/* 2.删除在路径中的节点。DeleteNodeInPath可以从节点集合中删除其在路劲中的节点，
可以避免形成回路。 */
//不带头结点的单链表删除特定值的节点
Neighbor DeleteNodeInPath(Neighbor adjacents, Path path)
{               //从节点集合adjacents中删除节点在路径path中的节点
    Neighbor n1 = adjacents, n2;
    Status flag = FALSE;
    while(n1)   {                                       //节点集合的每个节点
        flag = IsInPath(n1->node, path);                //节点是否在路径中
        if(flag == TRUE)    {                           //节点在路径中
            if(n1 == adjacents) {                       //首元结点的删除
                adjacents = n1->next;                   
                free(n1);
                n1 = adjacents;
            } else  {                                   //非首元结点的删除
                n2->next = n1->next;                    
                free(n1);
                n1 = n2->next;
            }
        } else  {                                       //遍历操作
            n2 = n1;                                    //记录当前结点的前一个结点
            n1 = n2->next;                              //下一个节点
        }
    }

    return adjacents;
}

//（1）节点加入路径.
// AddANodeToPath在路径中加入一个节点形成新的路径
Path AddANodeToPath(Node Node, Path path)//节点加入路径中
{
    Path p;
    p = (Neighbor) malloc(sizeof(struct NeighborNode)); //开辟节点空间
    strcpy(p->node, Node); //赋值
    if (path == NULL) //路径上第一个节点
        p->next = NULL;
    else
        p->next = path; //加入到路径头部
    path = p; //路径倒序加入
    return path; //返回路径头部
}

/* 3.相邻结点形成路径集合。FormPathsFromNodes 结点集合中的每个节点与路径依次
形成路径集合 */
PathsAggregate FormPathsFromNodes(Neighbor adjacents, Path path, PathsAggregate paths)
{               //将不在路径中的节点加入路径，形成路径集合
    Path tempath;
    adjacents = DeleteNodeInPath(adjacents, path);                      //删除构成回路的节点
    while(adjacents)    {                                               //所有不构成回路的节点
        tempath = CopyPath(path);                                       //复制路径
        tempath = AddANodeToPath(adjacents->node, tempath);             //在路径中加入路径集合

        paths = AddAPathToPaths(tempath, paths);                        //新路径加入路经集合
        adjacents = adjacents->next;                                    //下一个节点
    }

    return paths;                                                       //返回路径集合
}

Neighbor ExpandNodes(Graph graph, Node pa) //由节点获取子节点
{
    Neighbor children = NULL; //孩子节点
    Graph t = graph; //树
    while (t) { //节点不为空
        if (strcmp(t->node.node, pa) == 0) { //找到分支节点
            children = CopyNeighbors(t->node.adjacents);
            break;
        } 
        t = t->next; //下一个双亲节点
    }
    return children;
}
//ClearNeighbors清空兄弟节点群，回收数据单元
Neighbor ClearNeighbors(Neighbor br) //回收兄弟节点变量
{
    Neighbor br1 = br; //临时兄弟变量
    while (br) {
        br1 = br;
        br = br->next;
        free(br1); //回收单元
        br1 = NULL;
    }
    return br; //返回NULL
}

//ClearPath回收路径数据空间，复用了回收兄弟数据空间函数
Path ClearPath(Path path) //回收路径空间
{
    path = (Path) ClearNeighbors((Neighbor) path); //路径与兄弟节点集合形式相同
    return path;
}

//ClearPaths回收路径集数据空间。
PathsAggregate ClearPaths(PathsAggregate paths) //回收路径空间
{
    PathsAggregate paths1 = paths;
    while (paths) //所有路径
    {
        paths1 = paths;
        ClearPath(paths1->path); //回收一条路径空间
        paths = paths->next; //下一条路径
        free(paths1);
    }
    return paths;
}
//ClearStack回收堆栈数据空间，复用了路径集回收函数。
STACK ClearStack(STACK stack) //回收栈空间
{
    stack = ClearPaths((PathsAggregate) stack); //堆栈与路径集合的形式相同
    return stack;
}

//PushAPath把一条路径压入堆栈，返回堆栈头指针
STACK PushAPath(STACK stack, Path path) //一条路径进栈
{
    Path tempath;
    STACK st;
    tempath = CopyPath(path); //复制路径
    st = (PathsAggregate) malloc(sizeof(PathsAggregate)); //路径节点
    st->path = tempath; //置路径于栈中
    if (stack == NULL) //第1条路径
        st->next = NULL;
    else //已有路径
        st->next = stack;
    stack = st;
    return stack;
}

//CopyPaths拷贝路径集，返回路径集的指针。
PathsAggregate CopyPaths(PathsAggregate paths) //复制路径集合, 返回路径集合的指针
{
    PathsAggregate copynode, lastnode, head = NULL;
    while (paths) //路径集合不为空
    {
        copynode = (PathsAggregate) malloc(sizeof(PathsAggregate)); //路径节点
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

//PopANode从堆栈中弹出获取路径和路径的节点名称，返回堆栈头指针。
STACK PopANode(STACK stack, Node node, Path *path) {
    STACK p = stack;
    Path tempath;
    if (p != NULL) {
        tempath = p->path; //一条路径
        strcpy(node, tempath->node); //获取节点
        *path = CopyPath(tempath); //获取路径
        stack = p->next; //栈顶变化
        free(p); //删除路径
    }
    return stack; //返回栈顶
}

//PushPaths把路径集压入堆栈，返回路径集头指针。
STACK PushPaths(STACK stack, PathsAggregate paths) // 所有路径进栈
{
    PathsAggregate p, head;
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

//4.路径搜索。SearchPath 搜索从初始节点到目标节点的一条路径。
Status SearchPath(Graph graph, Node start, Node end, Path *path) //判断节点是否在树中, 并求取路径
{
    Node Node; //树节点名称
    Neighbor adjacents; //树孩子节点
    STACK stack = NULL; //堆栈
    Status flag = FALSE;  //堆栈是否为空的标识
    Path tempath = NULL; //临时路径
    PathsAggregate Paths = NULL; //路径集合
    if (graph == NULL) return flag; //树不存储
    tempath = AddANodeToPath(start, tempath); //形成路径
    stack = PushAPath(stack, tempath); //路径进栈
    while (stack) //堆栈不为空继续搜索
    {
        tempath = ClearPath(tempath);
        stack = PopANode(stack, Node, &tempath); //出栈, 获取树节点和路径
        if (strcmp(end, Node) == 0) //是否为所求目标节点
        {
            flag = TRUE; //修正标识
            *path = CopyPath(tempath); //获取路径
            break;
        }
        adjacents = ExpandNodes(graph, Node); //获取下一级所有节点
        Paths = FormPathsFromNodes(adjacents, tempath, Paths); //形成路径集合
        stack = PushPaths(stack, Paths); //所有路径进栈
        Paths = ClearPaths(Paths); //清除所有路径
    }
    ClearStack(stack); //清除堆栈
    return flag; //获得路径标识
} 

//RevPath路径倒序，即按从树根到目标节点的顺序。
void RevPath(Path path)// 路径倒序
{
    int num = 0, i;
    Node *nodes;
    Path p = path;
    while (p)//统计路径节点的个数
    {
        p = p->next;
        num++;
    }
    nodes = (Node *) malloc(num * sizeof(Node)); // 开辟一维数组
    for (i = 0, p = path; p; p = p->next, i++) //读取路径节点置于数组中
        strcpy(nodes[i], p->node);
    for (i = num - 1, p = path; p; p = p->next, i--) //数组数据倒序置于路径中
        strcpy(p->node, nodes[i]);
    free(nodes); //回收数组空间
}


//兄弟显示
void priNeighbor(Neighbor brother) {
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
void priPath(Path path) //显示路径, 复用了显示兄弟函数
{
    priNeighbor((Neighbor) path); //路径与兄弟节点集合形式相同
}

//ClearTree清空树，回收数据单元。
Graph ClearTree(Graph graph) //回收树空间
{
    Graph graph1 = graph; //临时树
    while (graph) {
        graph1 = graph;
        graph = graph->next;
        free(graph1); //回收单元
        graph1 = NULL;
    }
    return graph; //返回NULL
}

int main(int argc, char* argv[]) 
{
    Node start, end;                            //起始节点
    Path path = NULL;                           //路径
    Status flag;
    Graph graph = NULL;
    char *filename = "F:\\VS_code_C\\xiaoxueqi\\Chapter3\\GraphofStack\\Graph.txt";
    graph = CreateTree(graph, filename);
    printf("\n The Start Node:");
    scanf("%s", start);
    printf("\n The End Node:");
    scanf("%s", end);
    flag = SearchPath(graph, start, end, &path);
    printf("Search %s from %s, Status = %d\n", end, start, flag);
    printf("Path = ");
    RevPath(path);
    priPath(path);
    printf("\n===================\n");
    ClearTree(graph);

    return 0;
} 