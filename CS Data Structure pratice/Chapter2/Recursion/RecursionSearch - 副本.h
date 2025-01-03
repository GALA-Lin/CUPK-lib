#include "GuoHeTree.c"

//判断节点end是否在树中
Status DepthSearch(Tree tree, Node end);

//1.定位子树位置
Tree GetSubTree(Tree tree, Node pa);



//2.基于递归搜索子树
Status SearchSubTree(Tree tree, Tree subtree, Node end);

//3.搜索树
Status Search(Tree tree, Node start, Node end);