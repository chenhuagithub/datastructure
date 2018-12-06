#include<stdio.h>


#define MAXSIZE 20
typedef int ElemType;

typedef struct SqList
{
	ElemType data[MAXSIZE];
	int length;  //线性表当前长度 
 } SqList,*Node;

//插入元素 ,i表示插入的位置，e表示插入的元素 
int ListInsert(SqList*L,int i,ElemType e)
{
	int k;
	//判断是否为空表 
	if(L->length==0) 
	{
		return 0;
	}
	//判断插入的位置是否符合 
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


//删除数据,i代表删除的位置，e代表删除后返回的值 
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
	//记录删除的值
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
	printf("请输入你要输入的数据个数：");
	scanf("%d",&a);
	s.length=a;
	printf("%d",s.length);
	
	for(int i=0;i<a;i++)
	{
		printf("请输入第%d个数：",i+1);
		scanf("%d",&s.data[i]); 
	}
	ListInsert(&s,3,89);
	printf("所有数据：\n");
	for(int i=0;i<s.length;i++)
	{
		printf("%d\n",s.data[i]);
	}
	int e;
	ListDelete(&s,2,&e);
	printf("删除后的数据\n");
	for(int i=0;i<s.length;i++)
	{
		printf("%d\n",s.data[i]);
	}
	printf("删除的数据为：%d",e);
	return 0;
}
