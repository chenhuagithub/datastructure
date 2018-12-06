#include<stdio.h>
#define MAX 100
typedef int ElemType;
typedef struct array
{
	ElemType elem[MAX];  //elem[0]用于存放检测的值 
	int length;
}array;


//折半查找
int  bin_search(array*str,int key);
//插值查找
int insert_search(array*str,int key); 
//打印数组
void print(array*str); 
//数组的输入 

int main()
{
	array str;
	int length;
	printf("请输入数组的长度:");
	scanf("%d",&length);
	str.length=length+1;
	printf("请从小到大输入一个数组\n");
	for(int i=1;i<str.length;i++){
		printf("请输入第%d个值：",i);
		scanf("%d",&str.elem[i]);
	}
	print(&str);
	printf("请输入你要查找的值：");
	int key;
	scanf("%d",&key);
	printf("你查找的值的索引为:%d\n",bin_search(&str,key));
	printf("你查找的值的索引为:%d\n",insert_search(&str,key));
}

//折半查找
int  bin_search(array*str,int key)
{
//	printf("我被访问了");
	int low=1;
	int high=str->length;
	int mid;
	while(low<=high){
//		printf("我被执行了。。。");
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


//插值查找 
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

//打印数组
void print(array*str)
{
	printf("\n*********打印数组**********\n");
	for(int i=1;i<str->length;i++){
		printf("%d  ",str->elem[i]);
	}
	printf("\n\n");
}
	
