#include "RecursionSearch.h"


//1.定位子树位置
Tree GetSubTree(Tree tree, Node pa)
{
    Tree subtree = tree;
    while(subtree)  {                           //遍历
        if(Equal(subtree->node.node, pa, EqualFun) == 0)
            break;                              //找到子树退出
        else    {
            subtree = subtree->next;
        }
    }

    return subtree;                             //返回子树
}

/*
//2.基于递归搜索子树
Status SearchSubTree(Tree tree, Tree subtree, Node end)
{
    Tree subsubtree;                                        //子树的子树
    Brother children;                                       //所有子节点
    Status flag = FALSE;                                    //存在标记
    
    if(subtree == NULL)
        return flag;
    
    
    //先序遍历，从根开始搜索
    if(Equal(subtree->node.node, end, EqualFun) == 0)   {   //子树的根节点是被搜索节点
        flag = TRUE;
    } else  {                                               //子根不是
        children = subtree->node.children;
        
        while(children) {                                   //深度优先搜索
            subsubtree = GetSubTree(tree, children->node);  //获得子树
            flag = SearchSubTree(tree, subsubtree, end);    //搜索子树
            if(flag == TRUE)
                break;
            children = children->next;
        }
    }

    return flag;
}

//3.搜索树
Status Search(Tree tree, Node start, Node end)
{
    Tree subtree;
    Status flag = FALSE;
    subtree = GetSubTree(tree, start);
    if(subtree) {
        flag = SearchSubTree(tree, subtree, end);
    } 
    
    return flag;
} 

 int main(int argc, char* argv[])
{
    Tree tree = NULL;
    Node start, end;
    Status flag = FALSE;
    char *filename = "ceshi.txt";
    tree = CreateTree(tree, filename);

    printf("==================\n");
    printf("The Start Node:");
    scanf("%s", start);
    printf("The End Node:");
    scanf("%s", end);

    flag = Search(tree, start, end);
    printf("Search %s from %s, Status = %d\n", end, start, flag);

    if(flag == TRUE)    {
        printf("\n Success!\n");
    } else {
        printf("\n Failed!\n");
    }
    printf("==================\n");

    ClearTree(tree);

    return 0;
} 

*/