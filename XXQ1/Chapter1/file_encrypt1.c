#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
/******************************************
 *							  			  *
 * �ļ���: ��03 ջ�Ͷ���\01 SequenceStack *
 * 							  			  *
 * �ļ���: SequenceStack.c    			  *
 *                            			  *
 ******************************************/

#ifndef SEQUENCESTACK_C
#define SEQUENCESTACK_C

/******************************************
 *						      			  *
 * �ļ���: ��03 ջ�Ͷ���\01 SequenceStack *
 * 							    		  *
 * �ļ���: SequenceStack.h    			  *
 * 							  			  *
 * ��  ��: ˳��ջ��ز����б� 			  *
 *                            			  *
 ******************************************/

#ifndef SEQUENCESTACK_H
#define SEQUENCESTACK_H

#include <stdio.h>
#include <stdlib.h>						//�ṩmalloc��realloc��free��exitԭ��
/**********************************
 *                                *
 * �ļ���: ��01 ����              *
 *                                *
 * �ļ���: Status.h               *
 *                                *
 * ��  ��: ���״̬�뼰�꺯���б� *
 *                                *
 **********************************/ 

#ifndef STATUS_H
#define STATUS_H

/* ״̬�� */
#define	TRUE		1			//�� 
#define	FALSE		0			//��
#define YES			1			//��
#define NO          0			//�� 
#define	OK			1			//ͨ��
#define	ERROR		0			//����
#define SUCCESS		1			//�ɹ� 
#define UNSUCCESS	0			//ʧ�� 
#define	INFEASIBLE	-1			//������

#ifndef _MATH_H_ 				//ϵͳ�����д�״̬�붨�壬Ҫ�����ͻ 
#define	OVERFLOW	-2			//��ջ����
#define UNDERFLOW	-3			//��ջ����
#endif 

#ifndef NULL
#define NULL ((void*)0)
#endif

/* ״̬��ʶ������ */
typedef int Status;

/*�꺯��*/
//������ͣһ��ʱ��
#define Wait(x)\
 {\
	double _Loop_Num_;\
	for(_Loop_Num_=0.01; _Loop_Num_<=100000.0*x; _Loop_Num_+=0.01)\
		;\
 }//����һ����ѭ�� 
 
//��Enter������ 
#define PressEnter\
 {\
	fflush(stdin);\
	printf("Press Enter...");\
	getchar();\
	fflush(stdin);\
 }

#endif


/* �궨�� */
#define STACK_INIT_SIZE	100				//˳��ջ�洢�ռ�ĳ�ʼ������
#define STACKINCREMENT	10 				//˳��ջ�洢�ռ�ķ�������

/* ˳��ջ���Ͷ��� */
/*���Թ������ʽ���������������������ֵ������㷨�У���������Ҫ���¶���*/
#if !defined MAZE_H				&&  \
    !defined EXPRESSION_H		&&  \
    !defined BINARYTREE_H		&&  \
    !defined CHILDSIBLINGTREE_H	&&  \
    !defined Question_8
typedef char SElemType_Sq;
#endif
typedef struct
{
	SElemType_Sq *base;				//��ջ����֮ǰ������֮��base��ֵΪNULL 
	SElemType_Sq *top;				//ջ��ָ�� 
	int stacksize;					//��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ 
}SqStack;

/* ˳��ջ�����б� */
Status InitStack_Sq(SqStack *S);
/*������������������
��(01)�����ջS�� ��
������������������*/

Status DestroyStack_Sq(SqStack *S);
/*��������������
��(02)����S�� ��
��������������*/ 
 
Status ClearStack_Sq(SqStack *S);
/*��������������
��(03)�ÿ�S�� ��
��������������*/

Status StackEmpty_Sq(SqStack S);
/*����������������������
��(04)�ж�S�Ƿ�Ϊ�ա� ��
����������������������*/

int StackLength_Sq(SqStack S);
/*����������������������
��(05)����SԪ�ظ����� ��
����������������������*/
 
Status GetTop_Sq(SqStack S, SElemType_Sq *e);
/*������������������������
��(06)��e��ȡջ��Ԫ�ء� ��
������������������������*/

Status Push_Sq(SqStack *S, SElemType_Sq e);
/*������������������
��(07)Ԫ��e��ջ�� ��
������������������*/

Status Pop_Sq(SqStack *S, SElemType_Sq *e);
/*������������������
��(08)Ԫ��e��ջ�� ��
������������������*/

Status StackTraverse_Sq(SqStack S, void(Visit)(SElemType_Sq));
/*��������������
��(09)����ջ����
��������������*/

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
		
	*e = *(S.top - 1);							//�����ƻ�ջ 
	
	return OK;

} 

Status Push_Sq(SqStack *S, SElemType_Sq e)
{
	if((*S).top-(*S).base>=(*S).stacksize)		//ջ����׷�Ӵ洢�ռ�
	{
		(*S).base = (SElemType_Sq *)realloc((*S).base, ((*S).stacksize+STACKINCREMENT)*sizeof(SElemType_Sq));
		if(!(*S).base)
			exit(OVERFLOW);						//�洢����ʧ��
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	
	*(S->top) = e;								//��ջ�ȸ�ֵ��ջ��ָ�������� 
	(S->top)++;

	return OK;
} 

Status Pop_Sq(SqStack *S, SElemType_Sq *e)
{
	if((*S).top==(*S).base)
		return ERROR;

	(*S).top--;									//��ջջ��ָ���ȵݼ����ٸ�ֵ 
	*e = *((*S).top);

	return OK;
} 

Status StackTraverse_Sq(SqStack S, void(Visit)(SElemType_Sq))
{												//������Ӧ���ƻ�ջ 
	SElemType_Sq *p = S.base;
	
	while(p<S.top)
		Visit(*p++);
	
	return OK;
} 

#endif


char InputKey()                     //��Կ���뺯��
{
    char key;

    printf("Please enter the password : (1-254):\n");
    scanf("%c", &key);
    if((int)key > 255 || (int)key < 0)    {
        printf("�������Կ������Ҫ��������������롣\n");
        scanf("%c", &key);
    }

    return key;
}

void decrypt(FILE * fp, char key)               //����/���ܺ���
{

    SqStack S;                                  //ջ����������ʼ��
    InitStack_Sq(&S);
    char ch;

    rewind(fp);
    ch = fgetc(fp);                             //������/����
    while(ch!=EOF)  {
        ch = ch ^ key;
        fseek(fp,-1L,SEEK_CUR);
        fputc(ch,fp);
        fseek(fp,0,SEEK_CUR);
        ch = fgetc(fp);
    }
    ch = 'a'; 
    

    //�������
    fseek(fp, 0, SEEK_SET);                 //����ѹջ
    ch = fgetc(fp);
    while(ch!=EOF)  {
        Push_Sq(&S, ch);
        ch = fgetc(fp);
    }

    rewind(fp);                             //������ջ
    while(StackLength_Sq(S) != 0)  {
        Pop_Sq(&S, &ch);
        fputc(ch, fp);
    } 

    printf("\nEncrypt/Decrypt Success!");
}

int main(int argc, char* argv[])    {
    FILE *fp;
    char key = '\0';

    fp = fopen("...\\ceshi.txt", "rt+");             //���ļ�
    if(fp == NULL) {
        printf("�޷����ļ�����������ԡ�\n");
        exit(1);
    }


    key = InputKey();               //����InputKey����������Կ

    decrypt(fp, key);               //����decrypt�������ļ����м��ܽ��ܡ�
    /*���ڼ��ܷ�ʽΪ����+�����˵�һ�ε��ú���Ϊ���ܣ��ڶ��ε��ú���Ϊ���ܡ�*/

    fclose(fp);

    return 0;
}