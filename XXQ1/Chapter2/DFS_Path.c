#include <stdio.h>
#include <F:\VS_code_C\Books of YanWeimin\06shuheerchashu\06 ChildTree\ChildTree.c>

void DFS_Path(CTree *T, SqStack *S);
Status Check_C(CTree *T);

int main(int argc, char* argv[])    
{
    
    CTree T;
    FILE *fp;

    fp = fopen("F:\\VS_code_C\\xiaoxueqi\\Chapter3\\TestData_T.txt", "rt+");
    if(fp == NULL)  {
        printf("\n Cannot open the file, please check it and try again!\n");
        exit(1);
    }
    InitTree_C(fp, &T);
    CreateTree_C(fp, &T);
    Check_C(&T);
    
    fclose(fp);

    return 0;
}


void DFS_Path(CTree *T, SqStack *S)
{
    TElemType_C start, end;
    printf("\n Please enter the start node:\n");
    scanf("%c", &start);
    printf("\n Please enter the end node:\n");
    scanf("%c", &end);
    SElemType_Sq tmp;
    CTree p, q;
    int l, m;
    Push_Sq(S, T);

}

Status Check_C(CTree *T)
{
    char ch;
    int flag = 0;
    printf("\n Please enter the character:\n");
    scanf("%c", &ch);
    flag = Order_C(*T, ch);

    if(flag == -1)    {
        printf("\n Failed!\n");
        return FALSE;
    } else  {
        printf("\n Success!\n");
        return TRUE;
    }
}