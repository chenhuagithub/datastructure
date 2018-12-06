#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
typedef int ElemType ;

typedef struct
{
	ElemType*base; //��ʾջ�� 
	ElemType*top;  //��ʾջ�� 
	int stackSize;  //��ʾ��ǰջ��ʹ�õ�������� 
}SqStack;


//����һ��ջ
void initStack(SqStack*s);
//��ջ,e��ʾ��ջ��Ԫ�� 
void push(SqStack*s,ElemType e);
 //��ջ,e��ʾ��ջ�󱣴��Ԫ�� 
void pop(SqStack*s,ElemType*e);
 //���ջ�е�Ԫ��
void print_stack(SqStack*s);
  //�鿴ջ��ʣ������
void stacklength(SqStack*s);
//���ջ
void deletestack(SqStack*s);

int main()
{
	SqStack s;
	initStack(&s);
	push(&s,3);
	push(&s,4);
	push(&s,9);
	print_stack(&s);
	stacklength(&s);
	int e;
	pop(&s,&e);
	print_stack(&s);
	stacklength(&s);
	deletestack(&s);
	print_stack(&s);
	stacklength(&s);
	push(&s,3);
	push(&s,4);

	return 0;
 } 
 
 //����һ��ջ
void initStack(SqStack*s) 
{
	s->base=(ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!s->base)
	{
		printf("ջ�Ĵ���ʧ��\n");
	}else{
		s->top=s->base;
		s->stackSize=STACK_INIT_SIZE;
		printf("����ջ�ɹ�\n");	
	}
	return;

}


//��ջ,e��ʾ��ջ��Ԫ�� 
void push(SqStack*s,ElemType e)
{
	if(s->top-s->base<0)
	{
		printf("ջ�Ѿ�����\n");
	 } 
	 *(s->top)=e;
	 s->top++;
	 s->stackSize--;
 } 
 
 //��ջ,e��ʾ��ջ�󱣴��Ԫ�� 
 void pop(SqStack*s,ElemType*e) 
 {
 	if(s->top-s->base==0)
 	{
 		printf("�Ѿ��ǿ�ջ���޳�ջԪ��\n");
	 }else{
	 	*e=*(s->top);
	 	s->top--;
	 	s->stackSize++;
	 }
	 
 }
 
 //���ջ�е�Ԫ��
 void print_stack(SqStack*s)
 {
 	int temp=0;
// 	printf("s->base=%d\n",s->base);
 	while(s->top-s->base)
 	{
 		printf("%d\n",*(s->base));
 		s->base++;
 		temp+=1;
// 		printf("temp=%d\n",temp);
	 }
	 s->base-=temp;
//	 printf("s->base=%d\n",s->base);
  } 
  
  //�鿴ջ��ʣ������
  void stacklength(SqStack*s)
  {
  	printf("������ʣջ������Ϊ:%d\n",s->stackSize);
  }
  
  //���ջ 
  void deletestack(SqStack*s)
  {
  	s->top=s->base;
  	s->stackSize=STACK_INIT_SIZE;
   } 
