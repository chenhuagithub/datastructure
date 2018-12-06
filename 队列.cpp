#include<stdio.h>
#include<malloc.h>

typedef int ElemType;
typedef struct QNode {
	ElemType data;  //��Ŷ����е�����
	struct QNode *next;  //ָ����һ��ָ��
} QNode,*QueuePrt;

typedef struct LinkQueue {
	QueuePrt front,rear; //font��ʾ��ͷָ�룬rearָ���βָ��
} LinkQueue;

//����һ������
void initQueue(LinkQueue*q);
//����С���ʾ���У�e��������е�ֵ
void InsertQueue(LinkQueue*q,ElemType e);
//������,e���ڱ�������е�ֵ
void  DeleteQueue(LinkQueue*q,ElemType*e);
//�������
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

//����һ������
void initQueue(LinkQueue*q) {
	//����һ��ͷ�ڵ�
	QueuePrt head=(QueuePrt)malloc(sizeof(QNode));
	if(!head) {
		printf("�ڴ����ʧ��\n");
	} else {
		head->next=NULL;
		q->front=head;  //��ͷ�Ͷ�βָ��ȫ��ָ��ͷ�ڵ�
		q->rear=head;
	}
}

//�����
void InsertQueue(LinkQueue*q,ElemType e) {
	QueuePrt p;
	p=(QueuePrt)malloc(sizeof(QNode));
	if(!p) {
		printf("�����ʧ��");
	} else {
		p->data=e;
		p->next=NULL;
		q->rear->next=p;
		q->rear=p;
	}
}

//������
void  DeleteQueue(LinkQueue*q,ElemType*e)
 {
	printf("����deletequeue");
	QueuePrt p;
	if(q->front==q->rear) {
		printf("����Ϊ�գ���Ҫ�����е�Ԫ��");
	} else {
		printf("�ҽ�����");
		*e=q->front->next->data;
		q->front->next=q->front->next->next;
		free(q->front->next);
//		printf("%d\n",q->front->next);
//		printf("%d\n",q->front->next);

	}

}

//�������
void print_Queue(LinkQueue*q) {
	QueuePrt head,p;
	head=q->front;
	p=head->next;
	printf("�����е�Ԫ����:\n");
	while(p) {
		printf("%d\n",p->data);
		p=p->next;
	}
}







