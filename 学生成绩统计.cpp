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
		printf("请输入学生名字：");
		scanf("%s",p->name);
		printf("请输入学生学号:");
		scanf("%d",&p->number);
		printf("请输入学生班级：");
		scanf("%d",&p->clas);
		printf("请输入学生语文成绩:");
		scanf("%d",&p->score.chinese);
		printf("请输入学生数学成绩:");
		scanf("%d",&p->score.math);
		printf("请输入学生英语成绩:");
		scanf("%d",&p->score.english);
		if(head==NULL){
			head=p;
			q=p;
			printf("在if中........");
			printf("head=%p\n",head);
			printf("q=%p\n",head);
			printf("p=%p\n",p);
		}else{
			printf("在else中........");
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
//	printf("请输入学生名字：");
//	scanf("%s",p->name);
//	printf("请输入学生学号:");
//	scanf("%d",&p->number);
//	printf("请输入学生班级：");
//	scanf("%d",&p->clas);
//	printf("请输入学生语文成绩:");
//	scanf("%d",&p->score.chinese);
//	printf("请输入学生数学成绩:");
//	scanf("%d",&p->score.math);
//	printf("请输入学生英语成绩:");
//	scanf("%d",&p->score.english);

	
	
	//输出学生信息 
	printf("学生名字\t学号\t\t班级\t\t语文\t\t数学\t\t英语\n");
	for(i;i<3;i++){
		p1=head;
		printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p1->name,p1->number,p1->clas,p1->score.chinese,p1->score.math,p1->score.english);
		p1=p1->next;
	}
	
	
	
	return 0;
	
}
