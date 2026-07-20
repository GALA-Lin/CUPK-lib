#include<stdio.h> 
#include<malloc.h>
typedef  int  ElemType ;
/**
*
* 数据类型定义 
*
*/ 
typedef struct  Lnode    /*结点的类型 */
{   
    ElemType  data;  /*数据域,保存结点的值 */
    struct Lnode * next;  /*指针域,*指向后继结点*/
}LinkNode;
/**
*
* 数据运算声明  
*
*/
void InitList(LinkNode *L);//1.1、初始化为空表
void CreateListF(LinkNode *L,ElemType a[],int n);/*1.2 头插*/ 
void CreateListR(LinkNode *L,ElemType a[],int n);/*1.3尾插*/ 
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
/**
*
* 数据运算定义 
*
*/ 
void InitList(LinkNode *L)/*初始化为空表*/
{     //创建头结点   
    L->next=NULL;
    printf("初始化为空表成功\n");
}
void CreateListF(LinkNode *L,ElemType a[],int n)/*头插*/ 
{   LinkNode *s;
    int i;
    L->next=NULL; //创建头结点,其next域置为NULL
    for (i=0;i<n;i++)		//循环建立数据结点
    {	
		s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=a[i];		//创建数据结点*s
		s->next=L->next;	//*s插在原开始结点之前,头结点之后
		L->next=s;
    }  
    printf("头插法创建单链表成功\n");
}
void CreateListR(LinkNode *L,ElemType a[],int n)/*尾插*/ 
{   LinkNode *s,*r;
    int i;
    L->next=NULL;
    r=L; //r始终指向尾结点,开始时指向头结点
    for (i=0;i<n;i++)	//循环建立数据结点
    {	s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=a[i];	//创建数据结点*s
		r->next=s;	//将*s插入*r之后
		r=s;
    }
    r->next=NULL;	//尾结点next域置为NULL
    printf("尾插法创建单链表成功\n");
}
void DestroyList(LinkNode *L)//销毁 
{   //pre指向*p的前驱结点
    LinkNode *pre=L;
    LinkNode *p=L->next; 
    while (p!=NULL)	//扫描单链表L
    {   free(pre);	//释放*pre结点
        pre=p;		//pre、p同步后移一个结点
        p=pre->next;
    }
    free(pre);     //循环结束时,p为NULL,pre指向尾结点,释放它
    printf("销毁单链表成功\n");
}
int ListEmpty(LinkNode *L)//判空 
{
	return (L->next==NULL);
}
int ListLength(LinkNode *L)//求长度 
{	
	int n=0;
	LinkNode *p=L;	//p指向头结点,n置为0
    while (p->next!=NULL)
    {	n++;
		p=p->next;
    }
    return(n);	//循环结束,p指向尾结点,其序号n为结点个数
}
void DispList(LinkNode *L)//输出 
{   
    LinkNode *p=L->next;
    while (p!=NULL)//p不为null,输出*p的data域
    {	printf("%d " , p->data);
		p=p->next;		//p移向下一个结点
    }
    printf("\n");    
}
int GetElem(LinkNode *L,int i)
{     
	int j=0;   //逻辑序号（即头结点的序号为0）
    LinkNode *p=L;  //p指向头结点
    while (j<i && p!=NULL)
    {	j++;
		p=p->next;
    }
    if (p==NULL)  return -1;	//不存在第i个数据结点           
    else return p->data;  //存在第i个数据结点,返回true
}
int LocateElem(LinkNode *L,ElemType e)
{ 
    int i=0;
	LinkNode *p=L;  //p指向头结点,i置为0  
    while (p!=NULL && p->data!=e) 
    {   p=p->next;  		
    	i++;
    }
    if (p==NULL)	return(-1);   //元素不存在           
    else  return(i);    //存在,返回其逻辑序号i  
}
int ListInsert(LinkNode *L,int i,ElemType e)
{   
	int j=0;
    LinkNode *p=L,*s;          	//p指向头结点,j置为0
    while (j<i-1 && p!=NULL)
    {	
		j++;
		p=p->next;
	}
    if (p==NULL)	
		return -1;   //未找到	
    else //找到第i-1个结点*p,插入新结点并返回true
	{	s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=e;		//创建新结点*s,其data域置为e
		s->next=p->next;	//将*s插入到*p之后
		p->next=s;
		return 1;   
	}
}
int ListDelete(LinkNode *L,int i)
{   ElemType e;  //返回第i个结点数值
    int j=0;
	LinkNode *p=L,*q;		//p指向头结点,j置为0
	while (j<i-1 && p!=NULL)	//查找第i-1个结点
    {	
		j++;     
		p=p->next; 
	}
    if (p==NULL)
		return -1;	//未找到第i-1个结点
    else  //找到第i-1个结点*p
    {	
		q=p->next;		//q指向第i个结点
		if (q==NULL)   
			return -1;  //第i个结点不存在
		else 
        {       e=q->data;
	      		p->next=q->next;	//从单链表中删除*q结点
	      		free(q);	//释放*q结点
	      		return e;   
		}  //返回true表示成功删除第i个结点
    }
    printf("逻辑序号为%d的元素删除成功\n",i);
}
int DeleteByValue(LinkNode *L,int e){//9.2、按元素数值删除
    int j=0;//元素逻辑序号 
	LinkNode *p=L->next,*q;		//p指向第一个数据结点,j置为1
    while(p!=NULL){	
	    j++;
		p=p->next;		
		if(p->data==e) ListDelete(L,j); 
	    p=q;				  
    }
    printf("元素数值%d删除成功\n",e);
    return 1;
}

int Sort(LinkNode *L)//升序排序 
{    
	int t;
    LinkNode *p=L->next,*q;
    while(p!=NULL){
    	q=p->next;
    	while(q!=NULL){
    		if(p->data>q->data) {
    			t=p->data;
    			p->data=q->data;
    			q->data=t;
			}
    		q=q->next;
		}
		p=p->next;
	}
	printf("元素排序成功\n");
	return 1;			  //成功返回true
}
int InsertByOrder(LinkNode *L,ElemType e)//插入有序 
{    
	int i=0;
    LinkNode *pro=L,*p=L->next,*q;
    while(p!=NULL){
    	i++;
    	q=p->next;
    	if(p->data>e) {
    		ListInsert(L,i,e);
    		break;
		}
		else {
			pro=p;
			p=q;
		}
	}
	if(p==NULL) {
		LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=e;		//创建新结点*s,其data域置为e
		s->next=pro->next;	//将*s插入到*pro之后
		pro->next=s;
	}
	printf("链表保持增序插入成功\n");
	return 1;			  //成功返回true
}
int main(){
	LinkNode L;
    int k=1;//循环条件 
	int m;//功能序号
	while(k){
		printf("\n\t------------功能序号-------------\n");
		printf("\t1.初始化\t2.销毁\t3.判空\t4.求长度\t5.输出\t6.定位\t7.查找\t8.插入\t9.删除\t10.排序\n"); 
		printf("请选择功能序号：");
		scanf("%d",&m);
		switch(m){
			case 1:{
				ElemType a[10]={22,33,44,13,15,27,68,36,45,56};//数据元素初始值 
	    		CreateListF(&L,a,10);//初始化 
				break;
			}
			case 2:{
				DestroyList(&L);
				break;
			}
			case 3:{
				if(ListEmpty(&L)) printf("该单链表为空\n");
				else printf("该单链表非空\n");
				break;
			}
			case 4:{
				printf("该单链表长度为：%d\n",ListLength(&L));
				break;
			}
			case 5:{
				DispList(&L);
				break;
			}
			case 6:{
				int m=1;
				while(m){
					printf("请输入查找元素的逻辑序号i = ");
					int i;
					scanf("%d",&i);
					if(GetElem(&L,i)) {
						printf("逻辑序号%d对应的数值为:%d\n ",i,GetElem(&L,i));
						break;
					}
					else printf("逻辑序号非法\n");
					printf("是否重新查询：Y(1) or N(0)\n");
					scanf("%d",&m);
				}
				break;
			}
			case 7:{
				int m=1;
				while(m){
					printf("请输入查找元素的数值 e = ");
					ElemType e;
					scanf("%d",&e);
					if(LocateElem(&L,e)!=-1) {
						printf("数值%d对应的逻辑序号为:%d\n ",e,LocateElem(&L,e));
						break;
					}
					else printf("该数据不存在\n");
					printf("是否重新查询：Y(1) or N(0)\n");
					scanf("%d",&m);
				}
				break;
			}
			case 8:{
				int  m;
				printf("\t1.按逻辑序号插入\t2.按元素数值增序插入\n");
				scanf("%d",&m);
				switch(m){
					case 1:{
						printf("当前共有%d个元素\n",ListLength(&L));
						printf("请输入元素插入位置 i = ");
						int i;
						scanf("%d",&i); 
						printf("请输入元素插入数值 e = ");
						ElemType e;
						scanf("%d",&e);
						ListInsert(&L,i,e);
						break;
					}
					case 2:{
						printf("请输入删除元素数值 e = ");
						int e;
						scanf("%d",&e);
						InsertByOrder(&L,e); 
						break;
					}
					default: return;
				}
				break;		
			}
			case 9:{
				int  m;
				printf("\t1.按逻辑序号删除\t2.按元素数值删除\t3.删除所有重复数值\n");
				scanf("%d",&m);
				switch(m){
					case 1:{
						printf("当前共有%d个元素\n",ListLength(&L));
						printf("请输入删除元素位置 i = ");
						int i;
						scanf("%d",&i);
						ListDelete(&L,i); 
						break;
					}
					case 2:{
						printf("请输入删除元素数值 e = ");
						int e;
						scanf("%d",&e);
						DeleteByValue(&L,e); 
						break;
					}
					case 3:{
						DeleteReValue(&L); 
						break;
					}
					default: return;
				}
				break;	
			}
			case 10:{
				Sort(&L);
				break;
			}
			default: return;
		}
		printf("是否继续其他操作：Y(1) or N(0)\n");
		scanf("%d",&k);
	} 
    return 0;
	}


