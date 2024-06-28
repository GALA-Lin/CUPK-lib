#include<stdio.h> 
#include<malloc.h>
typedef  int  ElemType ;
/**
*
* �������Ͷ��� 
*
*/ 
typedef struct  Lnode    /*�������� */
{   
    ElemType  data;  /*������,�������ֵ */
    struct Lnode * next;  /*ָ����,*ָ���̽��*/
}LinkNode;
/**
*
* ������������  
*
*/
void InitList(LinkNode *L);//1.1����ʼ��Ϊ�ձ�
void CreateListF(LinkNode *L,ElemType a[],int n);/*1.2 ͷ��*/ 
void CreateListR(LinkNode *L,ElemType a[],int n);/*1.3β��*/ 
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
/**
*
* �������㶨�� 
*
*/ 
void InitList(LinkNode *L)/*��ʼ��Ϊ�ձ�*/
{     //����ͷ���   
    L->next=NULL;
    printf("��ʼ��Ϊ�ձ�ɹ�\n");
}
void CreateListF(LinkNode *L,ElemType a[],int n)/*ͷ��*/ 
{   LinkNode *s;
    int i;
    L->next=NULL; //����ͷ���,��next����ΪNULL
    for (i=0;i<n;i++)		//ѭ���������ݽ��
    {	
		s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=a[i];		//�������ݽ��*s
		s->next=L->next;	//*s����ԭ��ʼ���֮ǰ,ͷ���֮��
		L->next=s;
    }  
    printf("ͷ�巨����������ɹ�\n");
}
void CreateListR(LinkNode *L,ElemType a[],int n)/*β��*/ 
{   LinkNode *s,*r;
    int i;
    L->next=NULL;
    r=L; //rʼ��ָ��β���,��ʼʱָ��ͷ���
    for (i=0;i<n;i++)	//ѭ���������ݽ��
    {	s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=a[i];	//�������ݽ��*s
		r->next=s;	//��*s����*r֮��
		r=s;
    }
    r->next=NULL;	//β���next����ΪNULL
    printf("β�巨����������ɹ�\n");
}
void DestroyList(LinkNode *L)//���� 
{   //preָ��*p��ǰ�����
    LinkNode *pre=L;
    LinkNode *p=L->next; 
    while (p!=NULL)	//ɨ�赥����L
    {   free(pre);	//�ͷ�*pre���
        pre=p;		//pre��pͬ������һ�����
        p=pre->next;
    }
    free(pre);     //ѭ������ʱ,pΪNULL,preָ��β���,�ͷ���
    printf("���ٵ�����ɹ�\n");
}
int ListEmpty(LinkNode *L)//�п� 
{
	return (L->next==NULL);
}
int ListLength(LinkNode *L)//�󳤶� 
{	
	int n=0;
	LinkNode *p=L;	//pָ��ͷ���,n��Ϊ0
    while (p->next!=NULL)
    {	n++;
		p=p->next;
    }
    return(n);	//ѭ������,pָ��β���,�����nΪ������
}
void DispList(LinkNode *L)//��� 
{   
    LinkNode *p=L->next;
    while (p!=NULL)//p��Ϊnull,���*p��data��
    {	printf("%d " , p->data);
		p=p->next;		//p������һ�����
    }
    printf("\n");    
}
int GetElem(LinkNode *L,int i)
{     
	int j=0;   //�߼���ţ���ͷ�������Ϊ0��
    LinkNode *p=L;  //pָ��ͷ���
    while (j<i && p!=NULL)
    {	j++;
		p=p->next;
    }
    if (p==NULL)  return -1;	//�����ڵ�i�����ݽ��           
    else return p->data;  //���ڵ�i�����ݽ��,����true
}
int LocateElem(LinkNode *L,ElemType e)
{ 
    int i=0;
	LinkNode *p=L;  //pָ��ͷ���,i��Ϊ0  
    while (p!=NULL && p->data!=e) 
    {   p=p->next;  		
    	i++;
    }
    if (p==NULL)	return(-1);   //Ԫ�ز�����           
    else  return(i);    //����,�������߼����i  
}
int ListInsert(LinkNode *L,int i,ElemType e)
{   
	int j=0;
    LinkNode *p=L,*s;          	//pָ��ͷ���,j��Ϊ0
    while (j<i-1 && p!=NULL)
    {	
		j++;
		p=p->next;
	}
    if (p==NULL)	
		return -1;   //δ�ҵ�	
    else //�ҵ���i-1�����*p,�����½�㲢����true
	{	s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=e;		//�����½��*s,��data����Ϊe
		s->next=p->next;	//��*s���뵽*p֮��
		p->next=s;
		return 1;   
	}
}
int ListDelete(LinkNode *L,int i)
{   ElemType e;  //���ص�i�������ֵ
    int j=0;
	LinkNode *p=L,*q;		//pָ��ͷ���,j��Ϊ0
	while (j<i-1 && p!=NULL)	//���ҵ�i-1�����
    {	
		j++;     
		p=p->next; 
	}
    if (p==NULL)
		return -1;	//δ�ҵ���i-1�����
    else  //�ҵ���i-1�����*p
    {	
		q=p->next;		//qָ���i�����
		if (q==NULL)   
			return -1;  //��i����㲻����
		else 
        {       e=q->data;
	      		p->next=q->next;	//�ӵ�������ɾ��*q���
	      		free(q);	//�ͷ�*q���
	      		return e;   
		}  //����true��ʾ�ɹ�ɾ����i�����
    }
    printf("�߼����Ϊ%d��Ԫ��ɾ���ɹ�\n",i);
}
int DeleteByValue(LinkNode *L,int e){//9.2����Ԫ����ֵɾ��
    int j=0;//Ԫ���߼���� 
	LinkNode *p=L->next,*q;		//pָ���һ�����ݽ��,j��Ϊ1
    while(p!=NULL){	
	    j++;
		p=p->next;		
		if(p->data==e) ListDelete(L,j); 
	    p=q;				  
    }
    printf("Ԫ����ֵ%dɾ���ɹ�\n",e);
    return 1;
}

int Sort(LinkNode *L)//�������� 
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
	printf("Ԫ������ɹ�\n");
	return 1;			  //�ɹ�����true
}
int InsertByOrder(LinkNode *L,ElemType e)//�������� 
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
		s->data=e;		//�����½��*s,��data����Ϊe
		s->next=pro->next;	//��*s���뵽*pro֮��
		pro->next=s;
	}
	printf("�������������ɹ�\n");
	return 1;			  //�ɹ�����true
}
int main(){
	LinkNode L;
    int k=1;//ѭ������ 
	int m;//�������
	while(k){
		printf("\n\t------------�������-------------\n");
		printf("\t1.��ʼ��\t2.����\t3.�п�\t4.�󳤶�\t5.���\t6.��λ\t7.����\t8.����\t9.ɾ��\t10.����\n"); 
		printf("��ѡ������ţ�");
		scanf("%d",&m);
		switch(m){
			case 1:{
				ElemType a[10]={22,33,44,13,15,27,68,36,45,56};//����Ԫ�س�ʼֵ 
	    		CreateListF(&L,a,10);//��ʼ�� 
				break;
			}
			case 2:{
				DestroyList(&L);
				break;
			}
			case 3:{
				if(ListEmpty(&L)) printf("�õ�����Ϊ��\n");
				else printf("�õ�����ǿ�\n");
				break;
			}
			case 4:{
				printf("�õ�������Ϊ��%d\n",ListLength(&L));
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
				int  m;
				printf("\t1.���߼���Ų���\t2.��Ԫ����ֵ�������\n");
				scanf("%d",&m);
				switch(m){
					case 1:{
						printf("��ǰ����%d��Ԫ��\n",ListLength(&L));
						printf("������Ԫ�ز���λ�� i = ");
						int i;
						scanf("%d",&i); 
						printf("������Ԫ�ز�����ֵ e = ");
						ElemType e;
						scanf("%d",&e);
						ListInsert(&L,i,e);
						break;
					}
					case 2:{
						printf("������ɾ��Ԫ����ֵ e = ");
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
				printf("\t1.���߼����ɾ��\t2.��Ԫ����ֵɾ��\t3.ɾ�������ظ���ֵ\n");
				scanf("%d",&m);
				switch(m){
					case 1:{
						printf("��ǰ����%d��Ԫ��\n",ListLength(&L));
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
		printf("�Ƿ��������������Y(1) or N(0)\n");
		scanf("%d",&k);
	} 
    return 0;
	}


