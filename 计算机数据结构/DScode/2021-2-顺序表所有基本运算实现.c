#include<stdio.h>
#include<malloc.h>
#define  OK   1
#define  ERROR   -1
#define  MAX_SIZE  100
typedef  int  Status ;
typedef  int  ElemType ;
/**
*
* 数据类型定义 
*
*/ 
struct SqList{    
	ElemType *data;
    int length;
};
/**
*
* 数据运算声明  
*
*/
Status InitList( struct SqList *L ,ElemType a[],int n);//1、初始化 
void DestroyList(struct SqList *L);//2、销毁 
Status  ListEmpty(struct SqList *L);//3、判空 
Status ListLength(struct SqList *L);//4、求长度 
void DispList(struct SqList *L);//5、输出 
Status GetElem(struct SqList *L,int i);//6、获取第i各元素值 
Status LocateElem(struct SqList *L, ElemType e);//7、 获取第一个数值e的逻辑序号 
Status ListInsert(struct SqList *L,int i,ElemType e);//8、 插入 
Status  ListDelete(struct SqList *L,int i);//9.1、按逻辑序号删除
Status  DeleteByValue(struct SqList *L,int e);//9.2、按元素数值删除
Status  DeleteReValue(struct SqList *L,int e);//9.3、删除所有重复值 
Status Sort(struct SqList *L);//10、升序排序 
/**
*
* 数据运算实现  
*
*/ 
Status InitList( struct SqList *L ,ElemType a[],int n) {  //初始化 
	L->data=(ElemType*)malloc(MAX_SIZE*sizeof( ElemType ) ) ;
	int i;
	for(i=0;i<n;i++){
		L->data[i]=a[i];
	}
	L->length=n;
    printf("初始化成功！\n");    
    return OK ;   
}
void DestroyList(struct SqList *L)//2、销毁 
{
    free(L);
    printf("销毁成功！"); 
}
Status  ListEmpty(struct SqList *L)//3、判空 
{
    return (L->length==0);
}
Status ListLength(struct SqList *L)//4、求长度
{
    return (L->length);
}
void DispList(struct SqList *L)//5、输出 
{    int i;
    if (ListEmpty(L)) return;
    for (i=0;i<L->length;i++)
        printf("%d ",L->data[i]);
    printf("\n");
} 
Status GetElem(struct SqList *L,int i)//6、获取第i各元素值 
{     ElemType e;
       if (i<1 || i>L->length)  return ERROR ;
       e=L->data[i-1];
       return e;
}
Status LocateElem(struct SqList *L, ElemType e)//7、 获取第一个数值e的逻辑序号 
{     int i=0;
      while (i<L->length && L->data[i]!=e)  
            i++;
      if (i>=L->length)  return ERROR ;
      else  return i+1;         

}
Status ListInsert(struct SqList *L,int i,ElemType e)//8、 插入 
{   int j;
    if (i<1 || i>L->length+1)
		return ERROR ;		//参数错误时返回false
    i--;				//将顺序表逻辑序号转化为物理序号
    for (j=L->length;j>i;j--)	//将data[i..n]元素后移一个位置
		L->data[j]=L->data[j-1];
    L->data[i]=e;		//插入元素e
    L->length++;		//顺序表长度增1
    printf("插入成功\n"); 
    return OK;			//成功插入返回true
}
Status  ListDelete(struct SqList *L,int i)//9.1、按逻辑序号删除
{   int j;
    if (i<1||i>L->length) return ERROR;	//参数错误时返回false	
    i--;	
    for (j=i;j<L->length-1;j++)  	//将data[i..n-1]元素前移
		L->data[j]=L->data[j+1];
    L->length--;			  //顺序表长度减1
    return OK;			  //成功删除返回true
}

Status DeleteByValue(struct SqList *L,ElemType x)//9.2、按元素数值删除
{    
	int i;		 
    for (i=0;i<L->length;i++){
    	if (L->data[i]==x)    //若当前元素为x，删除 
        {   
			ListDelete(L,i+1);
    	}
	}
	return OK;			  //成功删除返回true
}
Status DeleteReValue(struct SqList *L,int e)//9.3、删除所有重复值 e
{    
	int i=0;		 
    while (i<L->length){//获取第i+1个元素值 
    	if (L->data[i]==e)    //若后继元素为L->data[i]，删除之 
        {   
			ListDelete(L,i+1);
			continue; 
    	}
    	i++;
	}
	return OK;			  //成功删除返回true
}

Status Sort(struct SqList *L)//10、升序排序 
{    
	int i,j,t;		 
    for (i=0;i<L->length;i++){
    	for(j=i+1;j<L->length;j++){
    		if (L->data[j]<L->data[i])    //若后继元素小于L->data[i]，交换 
        	{   
				t=L->data[i];
				L->data[i]=L->data[j];
				L->data[j]=t;
    		}
		}
	}
	return OK;			  //成功删除返回true
}

void main(){
	struct SqList L;//定义顺序表对象 
	int k=1;//循环条件 
	int m;//功能序号
	while(k){
		printf("\n\t------------功能序号-------------\n");
		printf("\t1.初始化\t2.销毁\t3.判空\t4.求长度\t5.输出\t6.定位\t7.查找\t8.插入\t9.删除\t10.排序\n"); 
		printf("请选择功能序号：");
		scanf("%d",&m);
		switch(m){
			case 1:{
				ElemType a[10]={11,22,22,33,11,22,11,33};//数据元素初始值 
	    		InitList(&L,a,10);//顺序表初始化 
				break;
			}
			case 2:{
				DestroyList(&L);
				break;
			}
			case 3:{
				if(ListEmpty(&L)) printf("该顺序表为空\n");
				else printf("该顺序表非空\n");
				break;
			}
			case 4:{
				printf("该顺序表长度为：%d\n",ListLength(&L));
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
				printf("当前共有%d个元素\n",L.length);
				printf("请输入元素插入位置 i = ");
				int i;
				scanf("%d",&i); 
				printf("请输入元素插入数值 e = ");
				ElemType e;
				scanf("%d",&e);
				ListInsert(&L,i,e);
				break;
			}
			case 9:{
				int  m;
				printf("\t1.按逻辑序号删除\t2.按元素数值删除\t3.删除所有重复数值\n");
				scanf("%d",&m);
				switch(m){
					case 1:{
						printf("当前共有%d个元素\n",L.length);
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
						printf("请输入删除元素数值 e = ");
						int e;
						scanf("%d",&e);
						DeleteReValue(&L,e); 
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
	
}
   
