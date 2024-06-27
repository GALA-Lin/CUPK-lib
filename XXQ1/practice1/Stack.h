#include <stdio.h>
#include <stdlib.h>

/* 状态码 */
#define TRUE        1           /* 真 */
#define FALSE       0           /* 假 */
#define YES         1           /* 是 */
#define NO          0           /* 否 */
#define OK          1           /* 通过 */
#define ERROR       0           /* 错误 */
#define SUCCESS     1           /* 成功 */
#define UNSUCCESS   0           /* 失败 */
#define INFEASIBLE  -1          /* 不可行 */

#ifndef _MATH_H_                /* 系统中已有此状态码定义，为避免冲突 */
#define OVERFLOW    -2          /* 栈溢出 */
#define UNDERFLOW   -3          /* 栈下溢 */
#endif

#define STACK_INIT_SIZE 100     /* 顺序栈存储空间的初始分配量 */
#define STACKINCREMENT 10       /* 顺序栈存储空间的分配增量 */
#ifndef NULL
#endif

/* 状态码识别类型 */
typedef int Status;
typedef char ElemType;

/* 顺序栈结构体定义 */
typedef struct
{
    ElemType *base;  /* 栈底指针，在初始化之前和销毁之后，base 值为 NULL */
    ElemType *top;   /* 栈顶指针，指向栈顶元素的下一个位置 */
    int stacksize;   /* 当前栈已分配的内存空间大小（以元素个数为单位） */
} SqStack;

/* 初始化栈 */
Status InitStack_Sq(SqStack *S)
{
    S->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (!S->base)
        exit(OVERFLOW);
    
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    
    return OK;
}

/* 销毁栈 */
Status DestroyStack_Sq(SqStack *S)
{
    free(S->base);
    
    S->base = NULL;
    S->top = NULL;
    S->stacksize = 0;
    
    return OK;
}

/* 清空栈 */
Status ClearStack_Sq(SqStack *S)
{
    S->top = S->base;
    
    return OK;
}

/* 判断栈是否为空 */
Status StackEmpty_Sq(SqStack S)
{
    if (S.top == S.base)
        return TRUE;
    else
        return FALSE;
}

/* 获取栈长度 */
int StackLength_Sq(SqStack S)
{
    return S.top - S.base;
}

/* 获取栈顶元素 */
Status GetTop_Sq(SqStack S, ElemType *e)
{
    if (S.top == S.base)
        return ERROR;
    
    *e = *(S.top - 1);  /* 并不破坏栈 */
    
    return OK;
}

/* 入栈操作 */
Status Push_Sq(SqStack *S, ElemType e)
{
    if (S->top - S->base >= S->stacksize)  /* 栈满，需要追加存储空间 */
    {
        S->base = (ElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(ElemType));
        if (!S->base)
            exit(OVERFLOW);  /* 存储分配失败 */
        
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    
    *(S->top) = e;  /* 入栈，先赋值，再移动栈顶指针 */
    S->top++;
    
    return OK;
}

/* 出栈操作 */
Status Pop_Sq(SqStack *S, ElemType *e)
{
    if (S->top == S->base)
        return ERROR;
    
    S->top--;  /* 出栈，先移动栈顶指针，再获取栈顶元素 */
    *e = *(S->top);
    
    return OK;
}

/* 遍历栈并对每个元素执行 Visit 函数 */
Status StackTraverse_Sq(SqStack S, void(Visit)(ElemType))
{
    ElemType *p = S.base;
    
    while (p < S.top)
        Visit(*p++);
    
    return OK;
}
