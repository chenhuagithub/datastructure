#include<stdio.h>
#include<malloc.h>

typedef struct score{
	int chinese;
	int math;
	int english;
}Score;

typedef struct Student{
	char name[10];
	long number;
	int clas;
	Score score;
	struct Student*next; 
}Student;


int main()

{
	Student *head,*p , *q,*p1;
	int i=0;
	
	
	head=NULL;
	for(i;i<2;i++){
		p=(Student*)malloc(sizeof(Student));
		printf("������ѧ�����֣�");
		scanf("%s",p->name);
		printf("������ѧ��ѧ��:");
		scanf("%d",&p->number);
		printf("������ѧ���༶��");
		scanf("%d",&p->clas);
		printf("������ѧ�����ĳɼ�:");
		scanf("%d",&p->score.chinese);
		printf("������ѧ����ѧ�ɼ�:");
		scanf("%d",&p->score.math);
		printf("������ѧ��Ӣ��ɼ�:");
		scanf("%d",&p->score.english);
		if(head==NULL){
			head=p;
			q=p;
			printf("��if��........");
			printf("head=%p\n",head);
			printf("q=%p\n",head);
			printf("p=%p\n",p);
		}else{
			printf("��else��........");
			q->next=p;
			q=p;
			printf("head=%p\n",head);
			printf("p=%p\n",p);
			printf("q=%p\n",q);
			printf("q->next=%p\n",q->next);
			
		}
	}
	printf("%p\n",head);
	
	
	
//	p=(Student*)malloc(sizeof(Student));
//	printf("������ѧ�����֣�");
//	scanf("%s",p->name);
//	printf("������ѧ��ѧ��:");
//	scanf("%d",&p->number);
//	printf("������ѧ���༶��");
//	scanf("%d",&p->clas);
//	printf("������ѧ�����ĳɼ�:");
//	scanf("%d",&p->score.chinese);
//	printf("������ѧ����ѧ�ɼ�:");
//	scanf("%d",&p->score.math);
//	printf("������ѧ��Ӣ��ɼ�:");
//	scanf("%d",&p->score.english);

	
	
	//���ѧ����Ϣ 
	printf("ѧ������\tѧ��\t\t�༶\t\t����\t\t��ѧ\t\tӢ��\n");
	for(i;i<3;i++){
		p1=head;
		printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p1->name,p1->number,p1->clas,p1->score.chinese,p1->score.math,p1->score.english);
		p1=p1->next;
	}
	
	
	
	return 0;
	
}
