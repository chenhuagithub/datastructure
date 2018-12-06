#include<stdio.h>
#include<stdlib.h>
# define ElemType int

typedef struct BTNOde{
	char data;
	struct BTNOde *lchild,*rchild;
}BTNode,*BTree;

//������ 
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

//��������ĸ߶�
int Depth(BTree bt)
{
	int hl,hr;
	if(bt==NULL){
		return 0;
	}else{
		hl=Depth(bt->lchild) ;//���������ĸ߶� 
		hr=Depth(bt->rchild);//���������ĸ߶�
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
 	printf("����������е����нڵ�:\n");
 	Create(&T);
 	height=Depth(T);
 	printf("�ö������ĸ߶�Ϊ��%d\n",height);
 	return 0;
 }
