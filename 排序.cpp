#include<stdio.h>
#define MAX 100

typedef struct SqList
{
	int array[MAX];
	int length;
}SqList;

//ð������
void BubbleSort(SqList*L);
//�������� 
void QuickSort(SqList*L);
//�������
void print(SqList*L); 

int main()
{
	SqList L;
	printf("����������ĳ���:");
	scanf("%d",&L.length);
	for(int i=0;i<L.length;i++){
		printf("�������%d��Ԫ��",i+1);
		scanf("%d",&L.array[i]);
	}
	
	BubbleSort(&L);
	print(&L);
	
	return 0;
}

void BubbleSort(SqList*L)
{
	int temp;
	printf("\n************ð������************\n");
	for(int i=0;i<L->length;i++){
		for(int j=i+1;j<L->length;j++){
			if(L->array[i]>L->array[j]){
				temp=L->array[i];
				L->array[i]=L->array[j];
				L->array[j]=temp;
				
			}
		}
	}
}

void print(SqList*L)
{
	printf("\n***********��������������**********\n");
	for(int i=0;i<L->length;i++){
		printf("%d  ",L->array[i]);
	}
}
