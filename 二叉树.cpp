#include<stdio.h>
#include<malloc.h>

typedef char ElenType;
 
typedef struct BiTNode
{
	ElenType data;
	struct BiTNode *lchild,*rchild; //���ڱ�ʾ���Ӻ��Һ��ӵ�ָ�� 
}BiTNode,*BiTree;


//��������������������� 
void CreateBiTree(BiTree*T);
//�����������ֵ
void visit(char c,int level);
//����������,������� ,level��ʾ����������� 
void  PreOrderTraverse(BiTree T,int level);


int main()
{
	int level=0;
	BiTree T=NULL;
	CreateBiTree(&T);
	PreOrderTraverse(T,level); 
	return 0;
}
 


//��������������������� 
void CreateBiTree(BiTree*T)
{
	char c;
	scanf("%c",&c);
	//#��ʾ�սڵ�
	if(c=='#')
	{
		*T=NULL;
	 }else{
	 	*T=(BiTree)malloc(sizeof(BiTNode));
	 	(*T)->data=c;
	 	CreateBiTree(&(*T)->lchild);
	 	CreateBiTree(&(*T)->rchild);
	 }
 } 
 
 //�����������ֵ
 void visit(char c,int level)
 {
 	printf("%c λ�ڵ�%d��\n",c,level);
  } 
 
//����������,������� ,level��ʾ����������� 
void  PreOrderTraverse(BiTree T,int level)
{
	if(T)
	{
		visit(T->data,level+1);
		PreOrderTraverse(T->lchild,level+1);
		PreOrderTraverse(T->rchild,level+1);
		
	}
 } 

