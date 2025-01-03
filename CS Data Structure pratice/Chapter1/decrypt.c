#include <stdio.h>
#include <stdlib.h>
#include <F:\VS_code_C\Books of YanWeimin\03zhanheduilie\01 SequenceStack\SequenceStack.c>

char InputKey()                     //密钥输入函数
{
    char key;

    printf("请输入密钥：(1-254):\n");
    scanf("%c", &key);
    if((int)key > 255 || (int)key < 0)    {
        printf("输入的密钥不符合要求，请检查后重新输入。\n");
        scanf("%c", &key);
    }

    return key;
}

void decrypt(FILE * fp, char key)               //加密/解密函数
{

    SqStack S;                                  //栈的声明，初始化
    InitStack_Sq(&S);
    char ch;

    rewind(fp);
    ch = fgetc(fp);                             //异或加密/解密
    while(ch!=EOF)  {
        ch = ch ^ key;
        fseek(fp,-1L,SEEK_CUR);
        fputc(ch,fp);
        fseek(fp,0,SEEK_CUR);
        ch = fgetc(fp);
    }
    ch = 'a'; 
    

    //逆序操作
    fseek(fp, 0, SEEK_SET);                 //正向压栈
    ch = fgetc(fp);
    while(ch!=EOF)  {
        Push_Sq(&S, ch);
        ch = fgetc(fp);
    }

    rewind(fp);                             //反向退栈
    while(StackLength_Sq(S) != 0)  {
        Pop_Sq(&S, &ch);
        fputc(ch, fp);
    } 

    printf("\n解密/加密成功！");
}