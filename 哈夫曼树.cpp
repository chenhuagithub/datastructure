#include<stdio.h>
#include<malloc.h>
#define MAX 50

typedef struct
{
	char data;  //节点的值 
	int weight;  //节点的权值
	int parent;  //节点的双亲
	int lch;  //节点的左孩子
	int rch;  //节点的右孩子 
}HuffNode,Huffman[MAX];

int numVerxes=0;  //用于记录节点的个数 

//构造哈夫曼树
void init_HuffmanTree(HuffNode H[]);
//根据权值进行排序
void sort(HuffNode H[]);

int main()
{
	
	printf("请输入节点的个数：");
	scanf("%d",&numVerxes);
	fflush(stdin);
	Huffman H;
	for(int i=0;i<numVerxes;i++){
		printf("请输入第%d个节点的值:",i+1);
		scanf("%c",&H[i].data);
		printf("请输入第%d个节点的权值:",i+1);
		scanf("%d",&H[i].weight);
		fflush(stdin);
	}
	sort(H);
	for(int i=0;i<numVerxes;i++){
		printf("%c:%d\n",H[i].data,H[i].weight);
	}
	return 0;
}


void init_HuffmanTree(HuffNode H[])
{
	
}

void sort(HuffNode H[])
{
	HuffNode h;
	for(int i=0;i<numVerxes;i++){
		for(int j=i+1;j<numVerxes;j++){
			if(H[i].weight>H[j].weight){
				h=H[i];
				H[i]=H[j];
				H[j]=h;
			}
		}
	}
}









