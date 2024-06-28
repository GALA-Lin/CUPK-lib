#include<stdio.h> 
#include<malloc.h>
typedef  int  ElemType ;
/**
*
* �������Ͷ��� 
*
*/ 
typedef struct DNode       	//˫����������
{   ElemType data;
    struct DNode *prior;    	//ָ��ǰ�����
    struct DNode *next;     	//ָ���̽��
}DLinkNode;

/**
*
* ������������  
*
void InitList(LinkNode *L);//1.1����ʼ��Ϊ�ձ�
void CreateListF(LinkNode *L,ElemType a[],int n);//1.2 ͷ�� 
void CreateListR(LinkNode *L,ElemType a[],int n);//1.3β�� 
void DestroyList(LinkNode *L);//2.���� 
int ListEmpty(LinkNode *L);//3.�п� 
int ListLength(LinkNode *L);//4.�󳤶� 
void DispList(LinkNode *L);//5.��� 
int GetElem(LinkNode *L,int i);//6.���߼���Ų��� 
int LocateElem(LinkNode *L,ElemType e);//7.��Ԫ��ֵ���� 
int ListInsert(LinkNode *L,int i,ElemType e);//8.���� 
int ListDelete(LinkNode *L,int i);//9.ɾ�� 
int ListDelete(LinkNode *L,int i);//9.1�����߼����ɾ��
int DeleteByValue(LinkNode *L,int e);//9.2����Ԫ����ֵɾ��
int DeleteReValue(LinkNode *L);//9.3��ɾ�������ظ�ֵ 
*/
/**
*
* �������㶨�� 
*
*/ 
void InitList(DLinkNode *L)/*��ʼ��Ϊ�ձ�*/
{     //����ͷ���   
    L->next=NULL;
    L->prior=NULL;
    printf("��ʼ��Ϊ�ձ�ɹ�\n");
}
void CreateListF(DLinkNode *L,ElemType a[],int n){
    DLinkNode *s; int i;
	//ͷ���
    L->prior=L->next=NULL;	//ǰ��ָ������ΪNULL
    for (i=0;i<n;i++)		//ѭ���������ݽ��
    {	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));
		s->data=a[i];		//�������ݽ��*s
		s->next=L->next;	//��*s���뵽ͷ���֮��
		if (L->next!=NULL)  //��L�������ݽ��,�޸�ǰ��ָ��
	  	    L->next->prior=s;
		L->next=s;
		s->prior=L;
    }
}
void CreateListR(DLinkNode *L,ElemType a[],int n)
{   DLinkNode *s,*r;
    int i;
    //ͷ���
    r=L;	//rʼ��ָ��β���,��ʼʱָ��ͷ���
    for (i=0;i<n;i++)		//ѭ���������ݽ��
    {   
		s=(DLinkNode *)malloc(sizeof(DLinkNode));
		s->data=a[i];	//�������ݽ��*s
		r->next=s;
	        s->prior=r;	//��*s����*r֮��
		r=s;		//rָ��β���
    }
    r->next=NULL;		//β���next����ΪNULL
}
void DestroyList(DLinkNode *L)//���� 
{   

}
int ListEmpty(DLinkNode *L)//�п� 
{
	
}
int ListLength(DLinkNode *L)//�󳤶� 
{	
	
}
void DispList(DLinkNode *L)//��� 
{   
    DLinkNode *p=L->next;
    while(p!=NULL){
    	printf("%d ",p->data);
    	p=p->next;
	}
	printf("\n");
}
int GetElem(DLinkNode *L,int i)
{     
	
}
int LocateElem(DLinkNode *L,ElemType e)
{ 
     
}
void ListInsert(DLinkNode *L,int i,ElemType e){
	int j=0;
	DLinkNode *p=L,*s;	      	//pָ��ͷ���,j����Ϊ0
    while (j<i-1 && p!=NULL)	//���ҵ�i-1�����
    {	
		j++;
		p=p->next;
    }
	if (p==NULL)		//δ�ҵ���i-1�����,����false
		return ;
    else				//�ҵ���i-1�����*p,���������½��*s
    {       
		s=(DLinkNode *)malloc(sizeof(DLinkNode));
		s->data=e;		//�����½��*s
		s->next=p->next;	//��*p֮�����*s���
		if (p->next!=NULL)	//�����ں�̽��,�޸���ǰ��ָ��
	   	    p->next->prior=s;
		s->prior=p;
		p->next=s;
		
		
    }
}

void ListDelete(DLinkNode *L,int i)
{   int j=0;   
	DLinkNode *p=L,*q; 	 //pָ��ͷ���,j����Ϊ0
    while (j<i-1 && p!=NULL)	  	//���ҵ�i-1�����
    {	
		j++;
	    p=p->next;
    }
    if (p==NULL)	return ;	//δ�ҵ���i-1�����
    else		//�ҵ���i-1�����*p
    {	
		q=p->next;		//qָ���i�����
		if (q==NULL)	   	//�������ڵ�i�����ʱ����false
		    return ;
		p->next=q->next;	//��˫��������ɾ��*q���
		if (p->next!=NULL)    	//�޸���ǰ��ָ��
	        p->next->prior=p;
		free(q);		//�ͷ�*q���
    }
}

int DeleteByValue(DLinkNode *L,int e){//9.2����Ԫ����ֵɾ�����ʵ��ĵ�һ����� 
    
}
int DeleteReValue(DLinkNode *L,int e){//9.3��ɾ�������ظ�ֵ e 
    
}
int Sort(DLinkNode *L)//�������� 
{    
	
}
int InsertByOrder(DLinkNode *L,ElemType e)//�������� 
{    
	
}
void  Reverse(DLinkNode *L)	//˫����������
{    DLinkNode *p=L->next,*q;	//pָ���׸����ݽ��
    L->next=NULL;		//����ֻ��ͷ����˫����L
    while (p!=NULL)		//ɨ��L�����ݽ��
    {	
		q=p->next;	            	//��q�������̽��
		p->next=L->next;	//����ͷ�巨��*p������
		if (L->next!=NULL)	//�޸���ǰ��ָ��
	  	    L->next->prior=p;
		L->next=p;
		p->prior=L;
		p=q;			//��p����ָ�����̽��
    }
}

int main(){
	DLinkNode L;
	InitList(&L);
	ElemType a[10]={22,33,22,33,15,27,68,36,45,56};//����Ԫ�س�ʼֵ 
	CreateListR(&L,a,10);//��ʼ�� 
	DispList(&L);
	Reverse(&L);
    //ListDelete(&L,2);
    DispList(&L);
    //ListInsert(&L,3,15);
    //DispList(&L);
    return 0;
	}


