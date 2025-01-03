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

//1.通用比较函数
int Equal(Node n1, Node n2, int fun(const Node n1, const Node n2));

//2.通用赋值函数
void Set(Node n1, Node n2, char *fun(Node n1, const Node n2));

//3.兄弟节点关系创建
Neighbor AddNeighbor(Neighbor br, Node node);

//3.1 兄弟显示
void priNeighbors(Neighbor Neighbor);


//4.双亲与子节点关系的构建
Graph Form_Pa_Ch(Node pa, Neighbor br);

//5.将带子节点的双亲节点加入到树种
Graph AddsubGraph(Graph graph, Graph subgraph);

//6.清除兄弟节点和树
Neighbor ClearNeighbors(Neighbor br);

//7.ClearGraph 清空树， 回收数据单元
Graph ClearGraph(Graph Graph);

//8.字符数组转换
void CreateStr(char *Neighborset);

//9.字符数组建立兄弟关系
Neighbor CreateNeighbors(Neighbor Neighbors, char *Neighborset);

//10.根据树文件建立树
Graph CreateGraph(Graph Graph, char *filename);

//树搜索实现

//1.复制子节点集
Neighbor CopyNeighbors(Neighbor children);

//2.扩展节点集
Neighbor ExpandNodes(Graph Graph, Node pa);

//路径

//1.节点加入路径
Path AddNodeToPath(Node node, Path path);

//2.复制路径与路径集合

//2.1复制一条路径
Path CopyPath(Path path);

//2.2复制路径集合
PathsAggregate CopyPaths(PathsAggregate paths);

//3.路径倒序与显示

//3.1路径倒序
void RevPath(Path path);

//3.2显示路径
void priPath(Path path);
//4.路径加入路径集合
PathsAggregate AddPathToPaths(Path path, PathsAggregate paths);

//5.节点集合与路径集合形成路径集合
PathsAggregate FormPathsFromNodes(Neighbor Neighbors, Path path, PathsAggregate paths);

//6.回收路径与路径集合空间

//6.1回收路径空间
Path ClearPath(Path path);

//6.2回收路径集合空间
PathsAggregate ClearPaths(PathsAggregate paths);

/* 1.判断节点是否在路径中。IsInPath用于判断节点是否在路径中，返回“真”、“假”，
用于回路的判断 */
Status IsInPath(Node Node, Path path); //节点在路径中