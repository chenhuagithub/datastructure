#include<stdio.h>
#include<malloc.h>

typedef char ElenType;
 
typedef struct BiTNode
{
	ElenType data;
	struct BiTNode *lchild,*rchild; //用于表示左孩子和右孩子的指针 
}BiTNode,*BiTree;


//创建二插树，先序遍历法 
void CreateBiTree(BiTree*T);
//输出二叉树的值
void visit(char c,int level);
//遍历二叉树,先序遍历 ,level表示二叉树的深度 
void  PreOrderTraverse(BiTree T,int level);


int main()
{
	int level=0;
	BiTree T=NULL;
	CreateBiTree(&T);
	PreOrderTraverse(T,level); 
	return 0;
}
 


//创建二插树，先序遍历法 
void CreateBiTree(BiTree*T)
{
	char c;
	scanf("%c",&c);
	//#表示空节点
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
 
 //输入二叉树的值
 void visit(char c,int level)
 {
 	printf("%c 位于第%d层\n",c,level);
  } 
 
//遍历二叉树,先序遍历 ,level表示二叉树的深度 
void  PreOrderTraverse(BiTree T,int level)
{
	if(T)
	{
		visit(T->data,level+1);
		PreOrderTraverse(T->lchild,level+1);
		PreOrderTraverse(T->rchild,level+1);
		
	}
 } 

