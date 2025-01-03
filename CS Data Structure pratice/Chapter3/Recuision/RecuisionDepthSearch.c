#include "RecuisionDepthSearch.h"

//图的深度优先搜索，递归实现


//1.给定节点的子图
Graph GetSubGraph(Graph graph, Node node)
{
    Graph subgraph = graph;
    while(subgraph) {                                   //遍历
        if(strcmp(subgraph->node.node, node) == 0)      //找到退出
            break;
        else                
            subgraph = subgraph->next;                  //找不到下一个
    }

    return subgraph;
}

//2.搜索子图生成路径
Status SearchSubGraph(Graph graph, Graph subgraph,
                      Node end, Path *path, Path *searchpath)
{
    Graph subsubgraph = NULL;
    Neighbor adjacents;
    Status flag = FALSE;

    if(subgraph == NULL)    {
        *path = NULL;
        *searchpath = NULL;
        return flag;
    }

    if(strcmp(subgraph->node.node, end) == 0)   {
        flag = TRUE;
        *searchpath = AddNodeToPath(end, *searchpath);
        *path = AddNodeToPath(end, *path);
    } else if(IsInPath(subgraph->node.node, *searchpath) == FALSE)  {
        *searchpath = AddNodeToPath(subgraph->node.node, *searchpath);
        adjacents = subgraph->node.adjacents;
        while(adjacents)    {
            if(IsInPath(adjacents->node, *searchpath) == FALSE) {
                subsubgraph = GetSubGraph(subgraph, adjacents->node);
                flag = SearchSubGraph(subgraph, subsubgraph, end, path, searchpath);

                if(flag == TRUE)    {
                    *path = AddNodeToPath(adjacents->node, *path);
                    break;
                }
            }
            adjacents = adjacents->next;
        }
    }
    return flag;
}

//3.基于递归的搜索图生成路径
Status SearchPath(Graph graph, Node start, Node end, Path *path)
{
    Graph subgraph = NULL;
    Status flag = FALSE;
    Path searchpath = NULL;
    subgraph = GetSubGraph(graph, start);
    if(subgraph)    {
        flag = SearchSubGraph(graph, subgraph, end, path, &searchpath);
    }
    printf("Search %s from %s, Status = %d\n", end, start, flag);
    if(flag)    {
        printf("\n Success!\n");
        printf("Search Path = ");
        RevPath(searchpath);
        priPath(searchpath);
    } else  {
        printf("\nFailed!\n");
    }
    printf("\n==================\n");
    ClearPath(searchpath);

    return flag;
}