#include <stdio.h>
#include <F:\VS_code_C\Books of YanWeimin\06shuheerchashu\07 ChildSiblingTree\ChildSiblingTree.c>
#include <F:\VS_code_C\Books of YanWeimin\03zhanheduilie\01 SequenceStack\SequenceStack.c>

Status DFS(CSTree *T, TElemType_CS e, SqStack *S);

int main(int argc, char* argv[])    
{
    char ch;
    SqStack S;
    CSTree T;
    FILE *fp;
    InitStack_Sq(&S);
    InitTree_CS(&T);

    printf("\nPlease enter the character:\n");
    scanf("%c", &ch);

    fp = fopen("F:\\ceshi\\shu.txt", "rt+");
    if(fp == NULL)  {
        printf("\n Cannot open the file, please check it and try again!\n");
        exit(1);
    }

    CreateTree_CS(fp, &T);

    DFS(&T, ch, &S);
    fclose(fp);

    return 0;
}

Status DFS(CSTree *T, TElemType_CS e, SqStack *S)
{
    char t;
    t = e;
    SElemType_Sq p, q, r, tmp;
    r = *T;
    p = *T;
    q = *T;
    Push_Sq(S, *T);
    
    while(!StackEmpty_Sq(*S))    {

        GetTop_Sq(*S, &tmp);
        if(tmp->data == t)  {
            printf("\n Success!\n");
            return TRUE;
        } else {
            Pop_Sq(S, &tmp);
            if(tmp->firstchild) {
                Push_Sq(S, tmp->firstchild);
                p = tmp->firstchild;
                while(p->nextsibling)   {
                    Push_Sq(S, p->nextsibling);
                    p = p->nextsibling;
                }
            } 
        }
    }
    printf("\n Failed!\n");
    return FALSE;
}