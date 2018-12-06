#include<stdio.h>
#include<malloc.h>

typedef int ElemType;
typedef struct QNode {
	ElemType data;  //存放队列中的数据
	struct QNode *next;  //指向下一个指针
} QNode,*QueuePrt;

typedef struct LinkQueue {
	QueuePrt front,rear; //font表示队头指针，rear指向队尾指针
} LinkQueue;

//创建一个队列
void initQueue(LinkQueue*q);
//入队列。表示队列，e代表入队列的值
void InsertQueue(LinkQueue*q,ElemType e);
//出队列,e用于保存出队列的值
void  DeleteQueue(LinkQueue*q,ElemType*e);
//输入队列
void print_Queue(LinkQueue*q);

int main() {
	LinkQueue q;
	initQueue(&q);
	InsertQueue(&q,43);
	InsertQueue(&q,44);
	InsertQueue(&q,34);
	InsertQueue(&q,583);
	InsertQueue(&q,123);
	print_Queue(&q);
	int *e;
	DeleteQueue(&q,e);
	DeleteQueue(&q,e);
	print_Queue(&q);

	return 0;
}

//创建一个队列
void initQueue(LinkQueue*q) {
	//创建一个头节点
	QueuePrt head=(QueuePrt)malloc(sizeof(QNode));
	if(!head) {
		printf("内存分配失败\n");
	} else {
		head->next=NULL;
		q->front=head;  //队头和队尾指针全部指向头节点
		q->rear=head;
	}
}

//入队列
void InsertQueue(LinkQueue*q,ElemType e) {
	QueuePrt p;
	p=(QueuePrt)malloc(sizeof(QNode));
	if(!p) {
		printf("入队列失败");
	} else {
		p->data=e;
		p->next=NULL;
		q->rear->next=p;
		q->rear=p;
	}
}

//出队列
void  DeleteQueue(LinkQueue*q,ElemType*e)
 {
	printf("我是deletequeue");
	QueuePrt p;
	if(q->front==q->rear) {
		printf("队列为空，无要出队列的元素");
	} else {
		printf("我进来了");
		*e=q->front->next->data;
		q->front->next=q->front->next->next;
		free(q->front->next);
//		printf("%d\n",q->front->next);
//		printf("%d\n",q->front->next);

	}

}

//输出队列
void print_Queue(LinkQueue*q) {
	QueuePrt head,p;
	head=q->front;
	p=head->next;
	printf("队列中的元素有:\n");
	while(p) {
		printf("%d\n",p->data);
		p=p->next;
	}
}







