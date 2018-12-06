#include<stdio.h>
#include<malloc.h> 
typedef int ElemType;  //�������ͱ��� 
typedef struct Node
{
	ElemType data;  //������ 
	struct Node *next; //��һ��ָ��ָ��Ľڵ� 
	int length=0;  //��ͷָ���м�¼����ĳ��� 
}Node,*LinkList;


//β�巨��������
LinkList CreateLink(LinkList L,int temp) 
{
	LinkList head,p,q;
	head=(LinkList)malloc(sizeof(Node));
	//�ж�����ĳ����Ƿ����� 
	if(temp<1)
	{
		printf("����Ҫ������");
		
	}else{
		p=(LinkList)malloc(sizeof(Node));
		printf("�������%d��������",1);
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
			printf("�������%d��������",i+1);
			scanf("%d",&p->data);
			q->next=p;
			q=p;
			head->length++;
			
		}
	}
	q->next=NULL;

	return head;  //����ͷ�ڵ� 
}

//�������в���һ���ڵ�,head��ʾ�����ͷָ�룬i��ʾ����Ԫ�ص�λ�ã�e��ʾ�����Ԫ�� 
void InsertLink(LinkList head,int i,ElemType e) 
{
	LinkList p,s;
	int j=1;
	if(i<1||i>(head->length)+1)
	{
		printf("�����λ������");
	}else{
		p=head->next;
		while(j<i&&p)
		{
			p=p->next;
			j++;
		}
		s=(LinkList)malloc(sizeof(Node));
		s->data=e;  //���½ڵ㸳ֵ 
		s->next=p->next;
		p->next=s;
		head->length++;
	}
	
}

//ɾ���ڵ� ,head��ʾ�����ͷ�ڵ㣬e�洢ɾ����ֵ 
void DeleteLink(LinkList head,int i,ElemType*e)
{
	LinkList p;
	int j=1;
	if(i<1||i>(head->length)+1)
	{
		printf("ɾ����λ������");
		
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
	printf("����Ϊ:%d\n",head->length);
	printf("ɾ����ֵΪ:%d",e);
	return 0;
}
