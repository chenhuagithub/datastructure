#include<stdio.h>
#include<malloc.h> 
typedef int ElemType;  //定义类型别名 
typedef struct Node
{
	ElemType data;  //数据域 
	struct Node *next; //下一个指针指向的节点 
	int length=0;  //在头指针中记录链表的长度 
}Node,*LinkList;


//尾插法创建链表
LinkList CreateLink(LinkList L,int temp) 
{
	LinkList head,p,q;
	head=(LinkList)malloc(sizeof(Node));
	//判断输入的长度是否有误 
	if(temp<1)
	{
		printf("长度要大于零");
		
	}else{
		p=(LinkList)malloc(sizeof(Node));
		printf("请输入第%d个整数：",1);
		scanf("%d",&p->data);
		head->next=p;
		head->length=1;
		q=p;
		
		for(int i=1;i<temp;i++)
		{
			p=(LinkList)malloc(sizeof(Node));
			if(i==0)
			{
				head->next=p;
			}
			printf("请输入第%d个整数：",i+1);
			scanf("%d",&p->data);
			q->next=p;
			q=p;
			head->length++;
			
		}
	}
	q->next=NULL;

	return head;  //返回头节点 
}

//向链表中插入一个节点,head表示链表的头指针，i表示插入元素的位置，e表示插入的元素 
void InsertLink(LinkList head,int i,ElemType e) 
{
	LinkList p,s;
	int j=1;
	if(i<1||i>(head->length)+1)
	{
		printf("插入的位置有误");
	}else{
		p=head->next;
		while(j<i&&p)
		{
			p=p->next;
			j++;
		}
		s=(LinkList)malloc(sizeof(Node));
		s->data=e;  //给新节点赋值 
		s->next=p->next;
		p->next=s;
		head->length++;
	}
	
}

//删除节点 ,head表示链表的头节点，e存储删除的值 
void DeleteLink(LinkList head,int i,ElemType*e)
{
	LinkList p;
	int j=1;
	if(i<1||i>(head->length)+1)
	{
		printf("删除的位置有误");
		
	}else{
		p=head->next;
		while(j<i-1&&p)
		{
			p=p->next;
			j++;
		}
		*e=p->next->data;
		p->next=p->next->next;
		head->length--;
	}
}

int main()
{
	LinkList L,head,p;
	head=CreateLink(L,5);
	InsertLink(head,3,9);
	int e;
	DeleteLink(head,2,&e);
	p=head->next;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	printf("长度为:%d\n",head->length);
	printf("删除的值为:%d",e);
	return 0;
}
