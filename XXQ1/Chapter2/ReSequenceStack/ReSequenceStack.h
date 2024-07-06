/******************************************
 *						      			  *
 * 文件夹: ▲03 栈和队列\01 SequenceStack *
 * 							    		  *
 * 文件名: SequenceStack.h    			  *
 * 							  			  *
 * 内  容: 顺序栈相关操作列表 			  *
 *                            			  *
 ******************************************/

#ifndef RESEQUENCESTACK_H
#define RESEQUENCESTACK_H

#include <stdio.h>
#include <stdlib.h>						//提供malloc、realloc、free、exit原型
#include "F:\VS_code_C\Data_Structure\Status.h"		//**▲01 绪论**//

/* 宏定义 */
#define STACK_INIT_SIZE	100				//顺序栈存储空间的初始分配量
#define STACKINCREMENT	10 				//顺序栈存储空间的分配增量
#define MAX_TREE_SIZE 100	
/* 顺序栈类型定义 */
/*在迷宫、表达式、二叉树二叉链表、孩子兄弟树等算法中，此类型需要重新定义*/
/* #if !defined MAZE_H				&&  \
    !defined EXPRESSION_H		&&  \
    !defined BINARYTREE_H		&&  \
    !defined CHILDSIBLINGTREE_H	&&  \
    !defined CHILDTREE_H	    &&  \
    !defined Question_8
typedef char SElemType_Sq;
#endif */


/* 孩子树类型定义 */
typedef char TElemType_C;						//假设树中元素均为字符
typedef struct CTNode							//孩子结点 
{
	int child;
	struct CTNode* next;
}CTNode;
typedef CTNode* ChildPtr;						//孩子结点指针 
typedef struct
{
	int parent;									//双亲结点位置 
	TElemType_C data;
	ChildPtr firstchild;						//孩子链表头指针 
}CTBox;
typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int r;										//根的位置 
	int n;										//树的结点数 
}CTree; 

/* 自定义栈元素类型 */
typedef CTBox SElemType_Sq;
typedef struct SqStack
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
