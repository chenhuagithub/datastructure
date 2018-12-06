#include<stdio.h>
#include<stdlib.h>
# define ElemType int

typedef struct BTNOde{
	char data;
	struct BTNOde *lchild,*rchild;
}BTNode,*BTree;

//创建树 
void Create(BTree *T)
{
	char ch;
	scanf("%c",&ch);
	if(ch=='#'){
		*T=NULL;
	}else{
		*T=(BTree)malloc(sizeof(BTNode));
		(*T)->data=ch;
		Create(&((*T)->lchild));
		Create(&((*T)->rchild));
	}
	
}

//求二叉树的高度
int Depth(BTree bt)
{
	int hl,hr;
	if(bt==NULL){
		return 0;
	}else{
		hl=Depth(bt->lchild) ;//求左子树的高度 
		hr=Depth(bt->rchild);//求右子树的高度
		if(hl>hr){
			return (hl+1);
		} else{
			return (hr+1);
		}
	}
 } 
 
int main(){
 	BTree T;
 	int height;
 	printf("输入二叉树中的所有节点:\n");
 	Create(&T);
 	height=Depth(T);
 	printf("该二叉树的高度为：%d\n",height);
 	return 0;
 }
