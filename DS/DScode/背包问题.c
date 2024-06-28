#include<stdio.h>
#define MaxStackSize 50
typedef int ElementType;
struct Stack{
	ElementType data[MaxStackSize];
	int top; 
}; 
typedef struct Stack SqStack;
// ��ʼ�� ��ջ 
void InitStack(SqStack *s)
{       
    s->top=-1;
}
//�п� 
int StackEmpty(SqStack *s)
{
	return (s->top==-1);
}
//���� 
int StackFull(SqStack *s)
{
	return (s->top==MaxStackSize-1);
}
//��ջ 
int Push(SqStack *s,ElementType e)
{   if (StackFull(s)) //ջ�����������ջ�����
		return -1;
    s->top++;		   	//ջ��ָ����1
    s->data[s->top]=e;	   	//Ԫ��e����ջ��ָ�봦
    return 1;
}
//��ջ 
ElementType  Pop(SqStack *s)
{   if (StackEmpty(s))	//ջΪ�յ��������ջ�����
		return -1;
    ElementType e=s->data[s->top];//ȡջ��ָ��Ԫ�ص�Ԫ��
    s->top--;		//ջ��ָ���1
    return e;
}
//ȡջ��Ԫ�� 
int GetTop(SqStack *s)
{	
	if (s->top==-1)	//ջΪ�յ��������ջ����� 	   
        return -1;
    return s->data[s->top]; //����ջ��ָ��ָ���Ԫ��
}
//����ջ 
int TraverseStack(SqStack *s){
	if (StackEmpty(s))	//ջΪ�յ��������ջ�����
		return -1;
	int i=s->top;
	while(i>-1){
		printf("%d,",s->data[i]);
		i--;
	}
	printf("\n");
}
//����������� 
void Knapsack(SqStack *s,ElementType w[],int n,int TotalVolume)
{
	// ���������TotalVolume��n����Ʒ���������w�� 
	int k=0;  //������Ʒ���� 
	do{
		while(TotalVolume>0 && k<n)
		{//��������ʣ������� ��������Ʒû�г��Խ���ʱ��������������� 
			if(TotalVolume-w[k]>=0)
			{//������ʣ����������ڵ�ǰ������Ʒ���ʱ����ǰ��Ʒ�ɼ��뵱ǰ��� 
				Push(s,k);//��ǰ��Ʒ��ſ���ջ 
				TotalVolume=TotalVolume-w[k];//������������� 
			}
			k++;//����������һ����Ʒ 
		}
		//�ж�����while����ԭ�� 
		if(TotalVolume==0) TraverseStack(s);//�����ǰ������У������������ջ������Ԫ�� 
		k=Pop(s);//ջ��Ԫ�س�ջ 
		TotalVolume=TotalVolume+w[k];////������������� 
		k++;
	}while(!StackEmpty(s) || k!=n);//ջ�ǿռ�ջ�л�����Ʒ��������Ʒ��û�г����꣬����Ѱ������� 
} 

void main(){
	ElementType w[6]={2,3,4,5,8,1};//����Ʒ��� 
	int T=10;//��������� 
	SqStack s;//����ջ 
	InitStack(&s);//��ʼ����ջ 
	Knapsack(&s,w,6,T);//����������� 
	
}
