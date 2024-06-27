#include "RecursionSearch.c"

//基于递归搜索路径

//1.基于递归搜索子树路径
Status SearchSubTree(Tree tree, Tree subtree, Node end, Path *path)
{
    Tree subsubtree;
    Brother children;
    Status flag = FALSE;
    
    if(!subtree)    {
        *path = NULL;
        return flag;
    }

    if(Equal(subtree->node.node, end, EqualFun) == 0)   {
        flag = TRUE;
        *path = AddNodeToPath(subtree->node.node, *path);
    } else  {
        children = subtree->node.children;
        
        while(children) {
            subsubtree = GetSubTree(subtree, children->node);
            flag = SearchSubTree(subtree, subsubtree, end, path);
            if(flag == TRUE)    {
                *path = AddNodeToPath(subtree->node.node, *path);
                break;
            }
            children = children->next;
        }
    }

    return flag;
}


//2基于递归的完整路径求解--深度优先搜索
Status SearchPath(Tree tree, Node start, Node end, Path *path)
{
    Tree subtree;
    Status flag = FALSE;
    subtree = GetSubTree(tree, start);
    if(subtree)
        flag = SearchSubTree(tree, subtree, end, path);
    
    return flag;
}