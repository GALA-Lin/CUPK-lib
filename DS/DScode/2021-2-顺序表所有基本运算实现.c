#include<stdio.h>
#include<malloc.h>
#define  OK   1
#define  ERROR   -1
#define  MAX_SIZE  100
typedef  int  Status ;
typedef  int  ElemType ;
/**
*
* �������Ͷ��� 
*
*/ 
struct SqList{    
	ElemType *data;
    int length;
};
/**
*
* ������������  
*
*/
Status InitList( struct SqList *L ,ElemType a[],int n);//1����ʼ�� 
void DestroyList(struct SqList *L);//2������ 
Status  ListEmpty(struct SqList *L);//3���п� 
Status ListLength(struct SqList *L);//4���󳤶� 
void DispList(struct SqList *L);//5����� 
Status GetElem(struct SqList *L,int i);//6����ȡ��i��Ԫ��ֵ 
Status LocateElem(struct SqList *L, ElemType e);//7�� ��ȡ��һ����ֵe���߼���� 
Status ListInsert(struct SqList *L,int i,ElemType e);//8�� ���� 
Status  ListDelete(struct SqList *L,int i);//9.1�����߼����ɾ��
Status  DeleteByValue(struct SqList *L,int e);//9.2����Ԫ����ֵɾ��
Status  DeleteReValue(struct SqList *L,int e);//9.3��ɾ�������ظ�ֵ 
Status Sort(struct SqList *L);//10���������� 
/**
*
* ��������ʵ��  
*
*/ 
Status InitList( struct SqList *L ,ElemType a[],int n) {  //��ʼ�� 
	L->data=(ElemType*)malloc(MAX_SIZE*sizeof( ElemType ) ) ;
	int i;
	for(i=0;i<n;i++){
		L->data[i]=a[i];
	}
	L->length=n;
    printf("��ʼ���ɹ���\n");    
    return OK ;   
}
void DestroyList(struct SqList *L)//2������ 
{
    free(L);
    printf("���ٳɹ���"); 
}
Status  ListEmpty(struct SqList *L)//3���п� 
{
    return (L->length==0);
}
Status ListLength(struct SqList *L)//4���󳤶�
{
    return (L->length);
}
void DispList(struct SqList *L)//5����� 
{    int i;
    if (ListEmpty(L)) return;
    for (i=0;i<L->length;i++)
        printf("%d ",L->data[i]);
    printf("\n");
} 
Status GetElem(struct SqList *L,int i)//6����ȡ��i��Ԫ��ֵ 
{     ElemType e;
       if (i<1 || i>L->length)  return ERROR ;
       e=L->data[i-1];
       return e;
}
Status LocateElem(struct SqList *L, ElemType e)//7�� ��ȡ��һ����ֵe���߼���� 
{     int i=0;
      while (i<L->length && L->data[i]!=e)  
            i++;
      if (i>=L->length)  return ERROR ;
      else  return i+1;         

}
Status ListInsert(struct SqList *L,int i,ElemType e)//8�� ���� 
{   int j;
    if (i<1 || i>L->length+1)
		return ERROR ;		//��������ʱ����false
    i--;				//��˳����߼����ת��Ϊ�������
    for (j=L->length;j>i;j--)	//��data[i..n]Ԫ�غ���һ��λ��
		L->data[j]=L->data[j-1];
    L->data[i]=e;		//����Ԫ��e
    L->length++;		//˳�������1
    printf("����ɹ�\n"); 
    return OK;			//�ɹ����뷵��true
}
Status  ListDelete(struct SqList *L,int i)//9.1�����߼����ɾ��
{   int j;
    if (i<1||i>L->length) return ERROR;	//��������ʱ����false	
    i--;	
    for (j=i;j<L->length-1;j++)  	//��data[i..n-1]Ԫ��ǰ��
		L->data[j]=L->data[j+1];
    L->length--;			  //˳����ȼ�1
    return OK;			  //�ɹ�ɾ������true
}

Status DeleteByValue(struct SqList *L,ElemType x)//9.2����Ԫ����ֵɾ��
{    
	int i;		 
    for (i=0;i<L->length;i++){
    	if (L->data[i]==x)    //����ǰԪ��Ϊx��ɾ�� 
        {   
			ListDelete(L,i+1);
    	}
	}
	return OK;			  //�ɹ�ɾ������true
}
Status DeleteReValue(struct SqList *L,int e)//9.3��ɾ�������ظ�ֵ e
{    
	int i=0;		 
    while (i<L->length){//��ȡ��i+1��Ԫ��ֵ 
    	if (L->data[i]==e)    //�����Ԫ��ΪL->data[i]��ɾ��֮ 
        {   
			ListDelete(L,i+1);
			continue; 
    	}
    	i++;
	}
	return OK;			  //�ɹ�ɾ������true
}

Status Sort(struct SqList *L)//10���������� 
{    
	int i,j,t;		 
    for (i=0;i<L->length;i++){
    	for(j=i+1;j<L->length;j++){
    		if (L->data[j]<L->data[i])    //�����Ԫ��С��L->data[i]������ 
        	{   
				t=L->data[i];
				L->data[i]=L->data[j];
				L->data[j]=t;
    		}
		}
	}
	return OK;			  //�ɹ�ɾ������true
}

void main(){
	struct SqList L;//����˳������ 
	int k=1;//ѭ������ 
	int m;//�������
	while(k){
		printf("\n\t------------�������-------------\n");
		printf("\t1.��ʼ��\t2.����\t3.�п�\t4.�󳤶�\t5.���\t6.��λ\t7.����\t8.����\t9.ɾ��\t10.����\n"); 
		printf("��ѡ������ţ�");
		scanf("%d",&m);
		switch(m){
			case 1:{
				ElemType a[10]={11,22,22,33,11,22,11,33};//����Ԫ�س�ʼֵ 
	    		InitList(&L,a,10);//˳����ʼ�� 
				break;
			}
			case 2:{
				DestroyList(&L);
				break;
			}
			case 3:{
				if(ListEmpty(&L)) printf("��˳���Ϊ��\n");
				else printf("��˳���ǿ�\n");
				break;
			}
			case 4:{
				printf("��˳�����Ϊ��%d\n",ListLength(&L));
				break;
			}
			case 5:{
				DispList(&L);
				break;
			}
			case 6:{
				int m=1;
				while(m){
					printf("���������Ԫ�ص��߼����i = ");
					int i;
					scanf("%d",&i);
					if(GetElem(&L,i)) {
						printf("�߼����%d��Ӧ����ֵΪ:%d\n ",i,GetElem(&L,i));
						break;
					}
					else printf("�߼���ŷǷ�\n");
					printf("�Ƿ����²�ѯ��Y(1) or N(0)\n");
					scanf("%d",&m);
				}
				break;
			}
			case 7:{
				int m=1;
				while(m){
					printf("���������Ԫ�ص���ֵ e = ");
					ElemType e;
					scanf("%d",&e);
					if(LocateElem(&L,e)!=-1) {
						printf("��ֵ%d��Ӧ���߼����Ϊ:%d\n ",e,LocateElem(&L,e));
						break;
					}
					else printf("�����ݲ�����\n");
					printf("�Ƿ����²�ѯ��Y(1) or N(0)\n");
					scanf("%d",&m);
				}
				break;
			}
			case 8:{
				printf("��ǰ����%d��Ԫ��\n",L.length);
				printf("������Ԫ�ز���λ�� i = ");
				int i;
				scanf("%d",&i); 
				printf("������Ԫ�ز�����ֵ e = ");
				ElemType e;
				scanf("%d",&e);
				ListInsert(&L,i,e);
				break;
			}
			case 9:{
				int  m;
				printf("\t1.���߼����ɾ��\t2.��Ԫ����ֵɾ��\t3.ɾ�������ظ���ֵ\n");
				scanf("%d",&m);
				switch(m){
					case 1:{
						printf("��ǰ����%d��Ԫ��\n",L.length);
						printf("������ɾ��Ԫ��λ�� i = ");
						int i;
						scanf("%d",&i);
						ListDelete(&L,i); 
						break;
					}
					case 2:{
						printf("������ɾ��Ԫ����ֵ e = ");
						int e;
						scanf("%d",&e);
						DeleteByValue(&L,e); 
						break;
					}
					case 3:{
						printf("������ɾ��Ԫ����ֵ e = ");
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
		printf("�Ƿ��������������Y(1) or N(0)\n");
		scanf("%d",&k);
	} 
	
}
   
