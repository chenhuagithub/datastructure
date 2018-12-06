#include<stdio.h>


#define MAXSIZE 20
typedef int ElemType;

typedef struct SqList
{
	ElemType data[MAXSIZE];
	int length;  //���Ա�ǰ���� 
 } SqList,*Node;

//����Ԫ�� ,i��ʾ�����λ�ã�e��ʾ�����Ԫ�� 
int ListInsert(SqList*L,int i,ElemType e)
{
	int k;
	//�ж��Ƿ�Ϊ�ձ� 
	if(L->length==0) 
	{
		return 0;
	}
	//�жϲ����λ���Ƿ���� 
	if(i<1||i>L->length) 
	{
		return 0;
	}
	if(i<L->length)
	{
		for(k=L->length;k>i-1;k--)
		{
			L->data[k]=L->data[k-1];
		}
	}
	L->data[i-1]=e;
	L->length++;
	return 1;	
 } 


//ɾ������,i����ɾ����λ�ã�e����ɾ���󷵻ص�ֵ 
int ListDelete(SqList*L,int i,ElemType*e)
{
	int k;
	if(L->length==0)
	{
		return 0;
	}
	if(i<1||i>L->length)
	{
		return 0;
	}
	//��¼ɾ����ֵ
	*e=L->data[i-1];
	if(i<L->length)
	{
		for(k=i-1;k<L->length;k++)
		{
			L->data[k]=L->data[k+1];
		}
		L->data[L->length]=0;
		L->length--;
	}
	return 1;
 } 

int main()
{
	SqList s;
	int a;
	printf("��������Ҫ��������ݸ�����");
	scanf("%d",&a);
	s.length=a;
	printf("%d",s.length);
	
	for(int i=0;i<a;i++)
	{
		printf("�������%d������",i+1);
		scanf("%d",&s.data[i]); 
	}
	ListInsert(&s,3,89);
	printf("�������ݣ�\n");
	for(int i=0;i<s.length;i++)
	{
		printf("%d\n",s.data[i]);
	}
	int e;
	ListDelete(&s,2,&e);
	printf("ɾ���������\n");
	for(int i=0;i<s.length;i++)
	{
		printf("%d\n",s.data[i]);
	}
	printf("ɾ��������Ϊ��%d",e);
	return 0;
}
