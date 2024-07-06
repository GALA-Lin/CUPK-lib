#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
/******************************************
 *							  			  *
 * 文件夹: ▲03 栈和队列\01 SequenceStack *
 * 							  			  *
 * 文件名: SequenceStack.c    			  *
 *                            			  *
 ******************************************/

#ifndef SEQUENCESTACK_C
#define SEQUENCESTACK_C

/******************************************
 *						      			  *
 * 文件夹: ▲03 栈和队列\01 SequenceStack *
 * 							    		  *
 * 文件名: SequenceStack.h    			  *
 * 							  			  *
 * 内  容: 顺序栈相关操作列表 			  *
 *                            			  *
 ******************************************/

#ifndef SEQUENCESTACK_H
#define SEQUENCESTACK_H

#include <stdio.h>
#include <stdlib.h>						//提供malloc、realloc、free、exit原型
/**********************************
 *                                *
 * 文件夹: ▲01 绪论              *
 *                                *
 * 文件名: Status.h               *
 *                                *
 * 内  容: 相关状态码及宏函数列表 *
 *                                *
 **********************************/ 

#ifndef STATUS_H
#define STATUS_H

/* 状态码 */
#define	TRUE		1			//真 
#define	FALSE		0			//假
#define YES			1			//是
#define NO          0			//否 
#define	OK			1			//通过
#define	ERROR		0			//错误
#define SUCCESS		1			//成功 
#define UNSUCCESS	0			//失败 
#define	INFEASIBLE	-1			//不可行

#ifndef _MATH_H_ 				//系统中已有此状态码定义，要避免冲突 
#define	OVERFLOW	-2			//堆栈上溢
#define UNDERFLOW	-3			//堆栈下溢
#endif 

#ifndef NULL
#define NULL ((void*)0)
#endif

/* 状态码识别类型 */
typedef int Status;

/*宏函数*/
//函数暂停一段时间
#define Wait(x)\
 {\
	double _Loop_Num_;\
	for(_Loop_Num_=0.01; _Loop_Num_<=100000.0*x; _Loop_Num_+=0.01)\
		;\
 }//设立一个空循环 
 
//摁Enter键继续 
#define PressEnter\
 {\
	fflush(stdin);\
	printf("Press Enter...");\
	getchar();\
	fflush(stdin);\
 }

#endif


/* 宏定义 */
#define STACK_INIT_SIZE	100				//顺序栈存储空间的初始分配量
#define STACKINCREMENT	10 				//顺序栈存储空间的分配增量

/* 顺序栈类型定义 */
/*在迷宫、表达式、二叉树二叉链表、孩子兄弟树等算法中，此类型需要重新定义*/
#if !defined MAZE_H				&&  \
    !defined EXPRESSION_H		&&  \
    !defined BINARYTREE_H		&&  \
    !defined CHILDSIBLINGTREE_H	&&  \
    !defined Question_8
typedef char SElemType_Sq;
#endif
typedef struct
{
	SElemType_Sq *base;				//在栈构造之前和销毁之后，base的值为NULL 
	SElemType_Sq *top;				//栈顶指针 
	int stacksize;					//当前已分配的存储空间，以元素为单位 
}SqStack;

/* 顺序栈函数列表 */
Status InitStack_Sq(SqStack *S);
/*━━━━━━━━┓
┃(01)构造空栈S。 ┃
┗━━━━━━━━*/

Status DestroyStack_Sq(SqStack *S);
/*━━━━━━┓
┃(02)销毁S。 ┃
┗━━━━━━*/ 
 
Status ClearStack_Sq(SqStack *S);
/*━━━━━━┓
┃(03)置空S。 ┃
┗━━━━━━*/

Status StackEmpty_Sq(SqStack S);
/*━━━━━━━━━━┓
┃(04)判断S是否为空。 ┃
┗━━━━━━━━━━*/

int StackLength_Sq(SqStack S);
/*━━━━━━━━━━┓
┃(05)返回S元素个数。 ┃
┗━━━━━━━━━━*/
 
Status GetTop_Sq(SqStack S, SElemType_Sq *e);
/*━━━━━━━━━━━┓
┃(06)用e获取栈顶元素。 ┃
┗━━━━━━━━━━━*/

Status Push_Sq(SqStack *S, SElemType_Sq e);
/*━━━━━━━━┓
┃(07)元素e进栈。 ┃
┗━━━━━━━━*/

Status Pop_Sq(SqStack *S, SElemType_Sq *e);
/*━━━━━━━━┓
┃(08)元素e出栈。 ┃
┗━━━━━━━━*/

Status StackTraverse_Sq(SqStack S, void(Visit)(SElemType_Sq));
/*━━━━━━┓
┃(09)访问栈。┃
┗━━━━━━*/

#endif


Status InitStack_Sq(SqStack *S)
{
 	(*S).base = (SElemType_Sq *)malloc(STACK_INIT_SIZE*sizeof(SElemType_Sq));
	if(!(*S).base)
		exit(OVERFLOW);
		
	(*S).top = (*S).base;
	(*S).stacksize = STACK_INIT_SIZE;
	
	return OK;
} 

Status DestroyStack_Sq(SqStack *S)
{
	free((*S).base);
	
	(*S).base = NULL;
	(*S).top = NULL;
	(*S).stacksize = 0;
	
	return OK;
} 

Status ClearStack_Sq(SqStack *S)
{
	(*S).top = (*S).base;
	
	return OK;
} 

Status StackEmpty_Sq(SqStack S)
{
	if(S.top==S.base)
		return TRUE;
	else
		return FALSE;
} 

int StackLength_Sq(SqStack S)
{
	return S.top - S.base;
} 

Status GetTop_Sq(SqStack S, SElemType_Sq *e)
{
	if(S.top==S.base)
		return ERROR;
		
	*e = *(S.top - 1);							//并不破坏栈 
	
	return OK;

} 

Status Push_Sq(SqStack *S, SElemType_Sq e)
{
	if((*S).top-(*S).base>=(*S).stacksize)		//栈满，追加存储空间
	{
		(*S).base = (SElemType_Sq *)realloc((*S).base, ((*S).stacksize+STACKINCREMENT)*sizeof(SElemType_Sq));
		if(!(*S).base)
			exit(OVERFLOW);						//存储分配失败
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	
	*(S->top) = e;								//进栈先赋值，栈顶指针再自增 
	(S->top)++;

	return OK;
} 

Status Pop_Sq(SqStack *S, SElemType_Sq *e)
{
	if((*S).top==(*S).base)
		return ERROR;

	(*S).top--;									//出栈栈顶指针先递减，再赋值 
	*e = *((*S).top);

	return OK;
} 

Status StackTraverse_Sq(SqStack S, void(Visit)(SElemType_Sq))
{												//遍历不应该破坏栈 
	SElemType_Sq *p = S.base;
	
	while(p<S.top)
		Visit(*p++);
	
	return OK;
} 

#endif


char InputKey()                     //密钥输入函数
{
    char key;

    printf("Please enter the password : (1-254):\n");
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

    printf("\nEncrypt/Decrypt Success!");
}

int main(int argc, char* argv[])    {
    FILE *fp;
    char key = '\0';

    fp = fopen("...\\ceshi.txt", "rt+");             //打开文件
    if(fp == NULL) {
        printf("无法打开文件，请检查后重试。\n");
        exit(1);
    }


    key = InputKey();               //调用InputKey函数输入密钥

    decrypt(fp, key);               //调用decrypt函数对文件进行加密解密。
    /*由于加密方式为逆序+异或，因此第一次调用函数为加密，第二次调用函数为解密。*/

    fclose(fp);

    return 0;
}