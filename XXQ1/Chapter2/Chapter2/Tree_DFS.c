#include <stdio.h>
#include <F:\VS_code_C\Books of YanWeimin\06shuheerchashu\07 ChildSiblingTree\ChildSiblingTree.c>
#include <F:\VS_code_C\Books of YanWeimin\03zhanheduilie\01 SequenceStack\SequenceStack.c>

Status Search_CS(CSTree T, TElemType_CS e, SqStack *S);
void Confirm(int t);
int flag = 0;                       //flag����Ƿ��ҵ����ҵ��͸�Ϊ1���Ҳ�������0

int main(int argc, char* argv[])
{
    CSTree T;
    char ch;
    FILE *fp;
    SqStack S;
    InitStack_Sq(&S);

    printf("��������Ҫ���ҵ��ַ���\n");
    scanf("%c", &ch);

    fp = fopen("F:\\ceshi\\shu.txt", "rt");
    if(fp == NULL)  {
        printf("�޷����ļ��������ԣ�\n");
        exit(1);
    }
    InitTree_CS(&T);
    CreateTree_CS(fp, &T);
    Search_CS(T, ch, &S);
    Confirm(flag);
    fclose(fp);

    return 0;
}

Status Search_CS(CSTree T, TElemType_CS e, SqStack *S)
{
    SElemType_Sq tmp;
    char t;
    t = e;
	if(T)
	{
        Push_Sq(S, T);
        while(!StackEmpty_Sq(*S))   {
            Pop_Sq(S, &tmp);
            if(tmp->data == t)  {
                flag = 1;
            }

            Search_CS(T->firstchild, t,S);
		    Search_CS(T->nextsibling, t, S);
        }

	}
    return FALSE;
}

void Confirm(int t)
{
    if(t)   {
        printf("\n Success !\n");
    } else {
        printf("\n Failed !\n");
    }
}
