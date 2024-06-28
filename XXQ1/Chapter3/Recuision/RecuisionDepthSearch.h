#include "F:\VS_code_C\xiaoxueqi\Chapter3\GuoHeGraph.c"


//图的深度优先搜索，递归实现

//1.给定节点的子图
Graph GetSubGraph(Graph graph, Node node);

//2.搜索子图生成路径
Status SearchSubGraph(Graph graph, Graph subgraph,
                      Node end, Path *path, Path *searchpath);

//3.基于递归的搜索图生成路径
Status SearchPath(Graph graph, Node start, Node end, Path *path); 