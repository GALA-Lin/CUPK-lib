#include<stdio.h>
#define MaxStackSize 50
typedef int ElementType;
struct Stack{
	ElementType data[MaxStackSize];
	int top; 
}; 
typedef struct Stack SqStack;
// 初始化 空栈 
void InitStack(SqStack *s)
{       
    s->top=-1;
}
//判空 
int StackEmpty(SqStack *s)
{
	return (s->top==-1);
}
//判满 
int StackFull(SqStack *s)
{
	return (s->top==MaxStackSize-1);
}
//进栈 
int Push(SqStack *s,ElementType e)
{   if (StackFull(s)) //栈满的情况，即栈上溢出
		return -1;
    s->top++;		   	//栈顶指针增1
    s->data[s->top]=e;	   	//元素e放在栈顶指针处
    return 1;
}
//出栈 
ElementType  Pop(SqStack *s)
{   if (StackEmpty(s))	//栈为空的情况，即栈下溢出
		return -1;
    ElementType e=s->data[s->top];//取栈顶指针元素的元素
    s->top--;		//栈顶指针减1
    return e;
}
//取栈顶元素 
int GetTop(SqStack *s)
{	
	if (s->top==-1)	//栈为空的情况，即栈下溢出 	   
        return -1;
    return s->data[s->top]; //返回栈顶指针指向的元素
}
//遍历栈 
int TraverseStack(SqStack *s){
	if (StackEmpty(s))	//栈为空的情况，即栈下溢出
		return -1;
	int i=s->top;
	while(i>-1){
		printf("%d,",s->data[i]);
		i--;
	}
	printf("\n");
}
//背包问题求解 
void Knapsack(SqStack *s,ElementType w[],int n,int TotalVolume)
{
	// 背包总体积TotalVolume，n个物品体积在数组w中 
	int k=0;  //遍历物品数组 
	do{
		while(TotalVolume>0 && k<n)
		{//当背包有剩余总体积 ，并且物品没有尝试结束时，继续尝试新组合 
			if(TotalVolume-w[k]>=0)
			{//当背包剩余总体积大于当前遍历物品体积时，当前物品可加入当前组合 
				Push(s,k);//当前物品序号可入栈 
				TotalVolume=TotalVolume-w[k];//背包总体积更新 
			}
			k++;//继续尝试下一个物品 
		}
		//判断上述while结束原因 
		if(TotalVolume==0) TraverseStack(s);//输出当前组合序列，即遍历并输出栈中所有元素 
		k=Pop(s);//栈顶元素出栈 
		TotalVolume=TotalVolume+w[k];////背包总体积更新 
		k++;
	}while(!StackEmpty(s) || k!=n);//栈非空即栈中还有物品，或者物品还没有尝试完，继续寻找新组合 
} 

void main(){
	ElementType w[6]={2,3,4,5,8,1};//各物品体积 
	int T=10;//背包总体积 
	SqStack s;//定义栈 
	InitStack(&s);//初始化空栈 
	Knapsack(&s,w,6,T);//背包问题求解 
	
}
