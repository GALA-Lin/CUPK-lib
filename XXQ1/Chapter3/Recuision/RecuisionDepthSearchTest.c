#include "RecuisionDepthSearch.c"

int main(int argc, char* argv[])
{
    Node start, end;
    Path path = NULL;
    Status flag = FALSE;
    Graph graph = NULL;
    char *filename = (char*)"F:\\VS_code_C\\xiaoxueqi\\Chapter3\\Recuision\\Graph.txt";
    graph = CreateGraph(graph, filename);
    printf("The Start Node:");
    scanf("%s", start);
    printf("The End Node:");
    scanf("%s", end);
    flag = SearchPath(graph, start, end, &path);

    return 0; 
}