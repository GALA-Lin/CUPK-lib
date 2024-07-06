#include "F:\VS_code_C\xiaoxueqi\Chapter2\Recursion\DepthSearchPath.h"

int main(int argc, char* argv[])
{
    Tree tree = NULL;
    Node start, end;
    Path path = NULL;
    Status flag = FALSE;
    char *filename = "F:\\VS_code_C\\xiaoxueqi\\Chapter2\\Recursion\\ceshi.txt";
    tree = CreateTree(tree, filename);
    printf("====================\n");
    printf("The Start Node:");
    scanf("%s", start);
    printf("The End Node:");
    scanf("%s", end);
    flag = SearchPath(tree, start, end, &path);
    printf("Search %s from %s, Status = %d\n", end, start, flag);
    printf("Path = ");
    //创建路径时采用了头插法，不需要逆序，原来的路径就是正序。
    //RevPath(path);
    priPath(path);
    printf("\n====================\n");
    ClearPath(path);
    ClearTree(tree);

    return 0;
}