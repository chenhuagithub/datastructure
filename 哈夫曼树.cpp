#include<stdio.h>
#include<malloc.h>
#define MAX 50

typedef struct
{
	char data;  //�ڵ��ֵ 
	int weight;  //�ڵ��Ȩֵ
	int parent;  //�ڵ��˫��
	int lch;  //�ڵ������
	int rch;  //�ڵ���Һ��� 
}HuffNode,Huffman[MAX];

int numVerxes=0;  //���ڼ�¼�ڵ�ĸ��� 

//�����������
void init_HuffmanTree(HuffNode H[]);
//����Ȩֵ��������
void sort(HuffNode H[]);

int main()
{
	
	printf("������ڵ�ĸ�����");
	scanf("%d",&numVerxes);
	fflush(stdin);
	Huffman H;
	for(int i=0;i<numVerxes;i++){
		printf("�������%d���ڵ��ֵ:",i+1);
		scanf("%c",&H[i].data);
		printf("�������%d���ڵ��Ȩֵ:",i+1);
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









