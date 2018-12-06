#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
typedef int ElemType ;

typedef struct
{
	ElemType*base; //表示栈底 
	ElemType*top;  //表示栈顶 
	int stackSize;  //表示当前栈可使用的最大容量 
}SqStack;


//创建一个栈
void initStack(SqStack*s);
//入栈,e表示入栈的元素 
void push(SqStack*s,ElemType e);
 //出栈,e表示出栈后保存的元素 
void pop(SqStack*s,ElemType*e);
 //输出栈中的元素
void print_stack(SqStack*s);
  //查看栈所剩的容量
void stacklength(SqStack*s);
//清空栈
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
 
 //创建一个栈
void initStack(SqStack*s) 
{
	s->base=(ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!s->base)
	{
		printf("栈的创建失败\n");
	}else{
		s->top=s->base;
		s->stackSize=STACK_INIT_SIZE;
		printf("创建栈成功\n");	
	}
	return;

}


//入栈,e表示入栈的元素 
void push(SqStack*s,ElemType e)
{
	if(s->top-s->base<0)
	{
		printf("栈已经满了\n");
	 } 
	 *(s->top)=e;
	 s->top++;
	 s->stackSize--;
 } 
 
 //出栈,e表示出栈后保存的元素 
 void pop(SqStack*s,ElemType*e) 
 {
 	if(s->top-s->base==0)
 	{
 		printf("已经是空栈，无出栈元素\n");
	 }else{
	 	*e=*(s->top);
	 	s->top--;
	 	s->stackSize++;
	 }
	 
 }
 
 //输出栈中的元素
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
  
  //查看栈所剩的容量
  void stacklength(SqStack*s)
  {
  	printf("现在所剩栈的容量为:%d\n",s->stackSize);
  }
  
  //清空栈 
  void deletestack(SqStack*s)
  {
  	s->top=s->base;
  	s->stackSize=STACK_INIT_SIZE;
   } 
