#include<stdio.h>
#define MAX 100

typedef struct SqList
{
	int array[MAX];
	int length;
}SqList;

//冒泡排序
void BubbleSort(SqList*L);
//快速排序 
void QuickSort(SqList*L);
//输出数组
void print(SqList*L); 

int main()
{
	SqList L;
	printf("请输入数组的长度:");
	scanf("%d",&L.length);
	for(int i=0;i<L.length;i++){
		printf("请输入第%d个元素",i+1);
		scanf("%d",&L.array[i]);
	}
	
	BubbleSort(&L);
	print(&L);
	
	return 0;
}

void BubbleSort(SqList*L)
{
	int temp;
	printf("\n************冒泡排序************\n");
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
	printf("\n***********数组输出结果如下**********\n");
	for(int i=0;i<L->length;i++){
		printf("%d  ",L->array[i]);
	}
}
