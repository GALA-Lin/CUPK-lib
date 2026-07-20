#include<stdio.h> 
#include<malloc.h>
typedef  int  ElemType ;
/**
*
* 数据类型定义 
*
*/ 
typedef struct DNode       	//双链表结点类型
{   ElemType data;
    struct DNode *prior;    	//指向前驱结点
    struct DNode *next;     	//指向后继结点
}DLinkNode;

/**
*
* 数据运算声明  
*
void InitList(LinkNode *L);//1.1、初始化为空表
void CreateListF(LinkNode *L,ElemType a[],int n);//1.2 头插 
void CreateListR(LinkNode *L,ElemType a[],int n);//1.3尾插 
void DestroyList(LinkNode *L);//2.销毁 
int ListEmpty(LinkNode *L);//3.判空 
int ListLength(LinkNode *L);//4.求长度 
void DispList(LinkNode *L);//5.输出 
int GetElem(LinkNode *L,int i);//6.按逻辑序号查找 
int LocateElem(LinkNode *L,ElemType e);//7.按元素值查找 
int ListInsert(LinkNode *L,int i,ElemType e);//8.插入 
int ListDelete(LinkNode *L,int i);//9.删除 
int ListDelete(LinkNode *L,int i);//9.1、按逻辑序号删除
int DeleteByValue(LinkNode *L,int e);//9.2、按元素数值删除
int DeleteReValue(LinkNode *L);//9.3、删除所有重复值 
*/
/**
*
* 数据运算定义 
*
*/ 
void InitList(DLinkNode *L)/*初始化为空表*/
{     //创建头结点   
    L->next=NULL;
    L->prior=NULL;
    printf("初始化为空表成功\n");
}
void CreateListF(DLinkNode *L,ElemType a[],int n){
    DLinkNode *s; int i;
	//头结点
    L->prior=L->next=NULL;	//前后指针域置为NULL
    for (i=0;i<n;i++)		//循环建立数据结点
    {	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));
		s->data=a[i];		//创建数据结点*s
		s->next=L->next;	//将*s插入到头结点之后
		if (L->next!=NULL)  //若L存在数据结点,修改前驱指针
	  	    L->next->prior=s;
		L->next=s;
		s->prior=L;
    }
}
void CreateListR(DLinkNode *L,ElemType a[],int n)
{   DLinkNode *s,*r;
    int i;
    //头结点
    r=L;	//r始终指向尾结点,开始时指向头结点
    for (i=0;i<n;i++)		//循环建立数据结点
    {   
		s=(DLinkNode *)malloc(sizeof(DLinkNode));
		s->data=a[i];	//创建数据结点*s
		r->next=s;
	        s->prior=r;	//将*s插入*r之后
		r=s;		//r指向尾结点
    }
    r->next=NULL;		//尾结点next域置为NULL
}
void DestroyList(DLinkNode *L)//销毁 
{   

}
int ListEmpty(DLinkNode *L)//判空 
{
	
}
int ListLength(DLinkNode *L)//求长度 
{	
	
}
void DispList(DLinkNode *L)//输出 
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
	DLinkNode *p=L,*s;	      	//p指向头结点,j设置为0
    while (j<i-1 && p!=NULL)	//查找第i-1个结点
    {	
		j++;
		p=p->next;
    }
	if (p==NULL)		//未找到第i-1个结点,返回false
		return ;
    else				//找到第i-1个结点*p,在其后插入新结点*s
    {       
		s=(DLinkNode *)malloc(sizeof(DLinkNode));
		s->data=e;		//创建新结点*s
		s->next=p->next;	//在*p之后插入*s结点
		if (p->next!=NULL)	//若存在后继结点,修改其前驱指针
	   	    p->next->prior=s;
		s->prior=p;
		p->next=s;
		
		
    }
}

void ListDelete(DLinkNode *L,int i)
{   int j=0;   
	DLinkNode *p=L,*q; 	 //p指向头结点,j设置为0
    while (j<i-1 && p!=NULL)	  	//查找第i-1个结点
    {	
		j++;
	    p=p->next;
    }
    if (p==NULL)	return ;	//未找到第i-1个结点
    else		//找到第i-1个结点*p
    {	
		q=p->next;		//q指向第i个结点
		if (q==NULL)	   	//当不存在第i个结点时返回false
		    return ;
		p->next=q->next;	//从双单链表中删除*q结点
		if (p->next!=NULL)    	//修改其前驱指针
	        p->next->prior=p;
		free(q);		//释放*q结点
    }
}

int DeleteByValue(DLinkNode *L,int e){//9.2、按元素数值删除访问到的第一个结点 
    
}
int DeleteReValue(DLinkNode *L,int e){//9.3、删除所有重复值 e 
    
}
int Sort(DLinkNode *L)//升序排序 
{    
	
}
int InsertByOrder(DLinkNode *L,ElemType e)//插入有序 
{    
	
}
void  Reverse(DLinkNode *L)	//双链表结点逆置
{    DLinkNode *p=L->next,*q;	//p指向首个数据结点
    L->next=NULL;		//构造只有头结点的双链表L
    while (p!=NULL)		//扫描L的数据结点
    {	
		q=p->next;	            	//用q保存其后继结点
		p->next=L->next;	//采用头插法将*p结点插入
		if (L->next!=NULL)	//修改其前驱指针
	  	    L->next->prior=p;
		L->next=p;
		p->prior=L;
		p=q;			//让p重新指向其后继结点
    }
}

int main(){
	DLinkNode L;
	InitList(&L);
	ElemType a[10]={22,33,22,33,15,27,68,36,45,56};//数据元素初始值 
	CreateListR(&L,a,10);//初始化 
	DispList(&L);
	Reverse(&L);
    //ListDelete(&L,2);
    DispList(&L);
    //ListInsert(&L,3,15);
    //DispList(&L);
    return 0;
	}


