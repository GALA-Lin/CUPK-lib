#include "GuoHeGraph.h"

//1.通用比较函数
int Equal(Node n1, Node n2, int fun(const Node n1, const Node n2))
{
    return (int) fun(n1, n2);
}

//2.通用赋值函数
void Set(Node n1, Node n2, char *fun(Node n1, const Node n2))
{
    fun(n1, n2);
}


//3.邻接点关系创建
//AddANeighbor把一个节点加入到邻接点群中。
Neighbor AddANeighbor(Neighbor gr, Node node) //在gr邻接点群中增加一个邻接点node
{
    Neighbor b, pb; //邻接点变量
    b = (Neighbor) malloc(sizeof(struct NeighborNode)); //动态开辟一个邻接点单元
    strcpy(b->node, node); 
    b->next = NULL;
    if (gr == NULL) //没有邻接点的情况
    {
        gr = b; //node就是第一个邻接点
    } else {//有邻接点的情况，node就是最后一个邻接点
        pb = gr;
        while (pb->next) {
            pb = pb->next;
        }
        pb->next = b;
    }
    return gr; //返回邻接点
}
//3.1 邻接点显示
void priNeighbor(Neighbor neighbor) {
    while (neighbor) {
        printf("%s", neighbor->node);
        if (neighbor->next == NULL) {
            break;
        }
        printf("%s", "->");
        neighbor = neighbor->next;
    }
}

//4.原节点与邻接点关系的构建
//Form_Pa_Ch将邻接点（即所有邻接点）连接到原节点中，构成一个子图。
Graph Form_Pa_Ch(Node pa, Neighbor gr) //原节点与邻接点构成子图
{
    Graph graph;
    graph = (Graph) malloc(sizeof(struct GraphNode)); //创建原节点
    strcpy(graph->node.node, pa);
    graph->node.adjacents = gr; //邻接点与原节点构成子图
    graph->next = NULL; 
    return graph; //返回带邻接点的原节点，即子图
}
//5.将带邻接点的原节点加入到图中
Graph AddsubGraph(Graph tree, Graph subtree) //原节点加入图中
{
    Graph t = tree; //临时图
    if (tree == NULL) { //图不存在
        tree = subtree; //带邻接点的原节点即为图
    } else { //图存在
        while (t->next) {
            t = t->next;
        }
        t->next = subtree; //带邻接点的原节点加入图的最后
    }
    return tree; //返回图的指针
}
//6.清除邻接点和图
//ClearNeighbors清空邻接点群，回收数据单元
Neighbor ClearNeighbors(Neighbor gr) //回收邻接点变量
{
    Neighbor gr1 = gr; //临时邻接点变量
    while (gr) {
        gr1 = gr;
        gr = gr->next;
        free(gr1); //回收单元
        gr1 = NULL;
    }
    return gr; //返回NULL
}
//7.ClearGraph 清空图， 回收数据单元
Graph ClearGraph(Graph graph) //回收图空间
{
    Graph graph1 = graph; //临时图
    while (graph) {
        graph1 = graph;
        graph = graph->next;
        free(graph1); //回收单元
        graph1 = NULL;
    }
    return graph; //返回NULL
}

//8.字符数组转换
//CreateSt把字符串的字符‘/’变换为转义字符‘\0’（字符串结束标志），即在数组中存放多个节点名称（邻接点节点）的字符串。
void CreateStr(char *neighborset) //字符数组转换为多个字符串
{
    char *c = neighborset; //临时字符串
    while (*c) {
        if (*c == '/') {
            *c = '\0'; //插入字符串结束标记
        }
        c++;
    }
    c++;
    *c = '\0'; //多一个结束标记
}

//9.字符数组建立邻接点关系
//CreateNeighbors把字符串中含有多个邻接点节点名称建立图的邻接点节点群（链表）。
Neighbor CreateNeighbors(Neighbor neighbors, char *neighborset) //若干个邻接点构成邻接点
{
    char *p = neighborset; //多个节点，分隔符‘/’
    Node node;
    CreateStr(neighborset); //变为多个字符串
    while (*p) {
        strcpy(node, p);
        neighbors = AddANeighbor(neighbors, node); //加入邻接点关系中
        p += strlen(node) + 1; //下一个节点
    }
    return neighbors; //返回邻接点链表
}

//10.根据图文件建立图
//CreateGraph从图文件建立图（链表）
Graph CreateGraph(Graph graph, char *filename) //从文件中创建图
{
    Graph subgraph;
    Neighbor neighbors;
    FILE *fp;
    char graph1[200], neighborset[5000];
    fp = fopen(filename, "r");
    while (!feof(fp)) { //文件是否还存在图的节点名称
        fscanf(fp, "%s", graph1); //读入原节点
        fscanf(fp, "%s", neighborset);
        neighbors = NULL; //读入若干邻接点节点（邻接点），分隔符‘/’
        neighbors = CreateNeighbors(neighbors, neighborset); //构建原节点
        subgraph = Form_Pa_Ch(graph1, neighbors); //构建子图
        graph = AddsubGraph(graph, subgraph); //图中加入子图 
    }
    fclose(fp); //关闭文件
    return graph; //返回所建的图
}

//图搜索实现

//1.复制邻接点集
Neighbor CopyNeighbors(Neighbor children) //节点集复制
{
    Neighbor copyNode, lastNode, head = NULL; //没有邻接点
    while (children) { //分配节点空间
        copyNode = (Neighbor) malloc(sizeof(struct NeighborNode));
        strcpy(copyNode->node, children->node); //复制节点
        copyNode->next = NULL;
        if (head == NULL) //第一个节点
            head = copyNode;
        else //建立链接，复制邻接点集
            lastNode->next = copyNode;
        lastNode = copyNode;
        children = children->next; //下一个邻接点
    }
    return head; //返回头节点指针
}
//2.扩展节点集
Neighbor ExpandNodes(Graph graph, Node pa) //由节点获取邻接点
{
    Neighbor children = NULL; //孩邻接点
    Graph t = graph; //图
    while (t) { //节点不为空
        if (strcmp(t->node.node, pa) == 0) { //找到分支节点
            children = CopyNeighbors(t->node.adjacents);
            break;
        } 
        t = t->next; //下一个原节点
    }
    return children;
}
//路径

//1.节点加入路径
Path AddNodeToPath(Node node, Path path)
{
    Path p;
    p = (Neighbor)malloc(sizeof(NeighborNode));
    strcpy(p->node, node);
    if(path == NULL)                            //路径上的第一个节点
        p->next = NULL;
    else    {                                   //头插法
        p->next = path;
    }

    path = p;                                   //头插法第二步
    p = NULL;
    return path;                                //返回路径头部
}
//2.复制路径与路径集合

//2.1复制一条路径
Path CopyPath(Path path)
{
    Path tempath;
    tempath = (Path)CopyNeighbors((Neighbor)path);
    return tempath;
}
//2.2复制路径集合
PathsAggregate CopyPaths(PathsAggregate paths);


//3.路径倒序与显示

//3.1路径倒序
void RevPath(Path path)
{
    int num = 0, i;
    Node *nodes = NULL;                                //节点集
    Path p = path;                              //路径

    while(p)    {                               //统计路径条数
        p = p->next;
        num++;
    }
    

    nodes = (Node *) malloc(num*sizeof(Node));
    
    for (i = 0, p = path; p; p = p->next, i++) //读取路径节点置于数组中
        strcpy(nodes[i], p->node);
    for (i = num - 1, p = path; p; p = p->next, i--) //数组数据倒序置于路径中
        strcpy(p->node, nodes[i]);

    free(nodes);                                //释放路径集
    nodes = NULL;
}

//3.2显示路径
void priPath(Path path)
{
    priNeighbor((Neighbor)path);
}

//4.路径加入路径集合
PathsAggregate AddPathToPaths(Path path, PathsAggregate paths)
{
    Path copypath;
    PathsAggregate ps = NULL, p;

    if(path == NULL)                                //路径不存在，直接返回
        return paths;

    copypath = CopyPath(path);                      //路径存在则copy
    ps = (PathsAggregate)malloc(sizeof(Paths));
    ps->path = copypath;
    ps->next = NULL;
    if(paths == NULL)   {                           //第一条路径
        paths = ps;
    } else  {                                       //之后的路径
        p = paths;                                  //遍历，尾插法
        while(p)
            p = p->next;
        p->next = p;
    }

    free(copypath);
    free(ps);
    copypath = NULL;
    ps = NULL;

    return paths;                                   //返回路径集合
}


//5.节点集合与路径集合形成路径集合
PathsAggregate FormPathsFromNodes(Neighbor Neighbors, Path path, PathsAggregate paths)
{
    Path tempath;                                           //暂时存储路径
    while(Neighbors) {                                       //节点集不空
        tempath = CopyPath(path);                           //复制路径
        tempath = AddNodeToPath(Neighbors->node, tempath);   //将节点加入路径
        paths = AddPathToPaths(tempath, paths);             //将新路径加入路径集合
        Neighbors = Neighbors->next;                          //下一个节点
    }

    free(tempath);
    tempath = NULL;

    return paths;                                           //返回更新后的路径
}


//6.1回收路径空间
//ClearPath回收路径数据空间，复用了回收邻接点数据空间函数
Path ClearPath(Path path) //回收路径空间
{
    path = (Path) ClearNeighbors((Neighbor) path); //路径与邻接点节点集合形式相同
    return path;
}


//6.2回收路径集合空间
PathsAggregate ClearPaths(PathsAggregate paths)
{
    PathsAggregate paths1 = paths;            //暂时存放路径集合
    while(paths)    {                       //路径集合不空
        paths1 = paths;                     //指向相同空间
        ClearPath(paths1->path);            //释放路径集合
        paths = paths->next;                //下一条路径
        free(paths1);                       //释放指针
        paths1 = NULL;
    }

    return paths;                           //返回NULL
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