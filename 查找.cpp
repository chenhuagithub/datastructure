#include<stdio.h>
#define MAX 100
typedef int ElemType;
typedef struct array
{
	ElemType elem[MAX];  //elem[0]���ڴ�ż���ֵ 
	int length;
}array;


//�۰����
int  bin_search(array*str,int key);
//��ֵ����
int insert_search(array*str,int key); 
//��ӡ����
void print(array*str); 
//��������� 

int main()
{
	array str;
	int length;
	printf("����������ĳ���:");
	scanf("%d",&length);
	str.length=length+1;
	printf("���С��������һ������\n");
	for(int i=1;i<str.length;i++){
		printf("�������%d��ֵ��",i);
		scanf("%d",&str.elem[i]);
	}
	print(&str);
	printf("��������Ҫ���ҵ�ֵ��");
	int key;
	scanf("%d",&key);
	printf("����ҵ�ֵ������Ϊ:%d\n",bin_search(&str,key));
	printf("����ҵ�ֵ������Ϊ:%d\n",insert_search(&str,key));
}

//�۰����
int  bin_search(array*str,int key)
{
//	printf("�ұ�������");
	int low=1;
	int high=str->length;
	int mid;
	while(low<=high){
//		printf("�ұ�ִ���ˡ�����");
		mid=(low+high)/2;
//		mid=low+(high-low)*(key-str->elem[low])/(str->elem[high]-str->elem[low]);
		if(str->elem[mid]==key){
			str->elem[0]=mid;
			return str->elem[0];
		}else if(str->elem[mid]>key){
			high=mid-1;
		}else if(str->elem[mid]<key){
			low=mid+1;
		}
	}
	return str->elem[0];
	
}


//��ֵ���� 
int insert_search(array*str,int key)
{
	int low=1;
	int high=str->length;
	int mid;
	while(low<=high){

		mid=low+(high-low)*(key-str->elem[low])/(str->elem[high]-str->elem[low]);
		if(str->elem[mid]==key){
			str->elem[0]=mid;
			return str->elem[0];
		}else if(str->elem[mid]>key){
			high=mid-1;
		}else if(str->elem[mid]<key){
			low=mid+1;
		}
	}
	return str->elem[0];
	
}

//��ӡ����
void print(array*str)
{
	printf("\n*********��ӡ����**********\n");
	for(int i=1;i<str->length;i++){
		printf("%d  ",str->elem[i]);
	}
	printf("\n\n");
}
	
