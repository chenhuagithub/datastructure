#include<stdio.h>
#define MAX 50

typedef struct
{
	char data;  //�ڵ��ֵ 
	int weight;  //�ڵ��Ȩֵ
	int parent;  //�ڵ��˫��
	int lch;  //�ڵ������
	int rch;  //�ڵ���Һ��� 
}HuffNode;

typedef struct
{
	char bit[MAX];
	int start;
}HuffCode;

HuffNode ht[2*MAX];
HuffCode hcd[MAX];
int n;

void HuffmanTree()
{
	int i,k,left,right,min1,min2;
	printf("����Ҷ�ӽڵ�����");
	scanf("%d",&n);
	for(i=1;i<2*n-1;i++){
		ht[i].parent=ht[i].lch=ht[i].rch=0;
	}
	for(i=1;i<=n;i++){
		getchar();
		printf("�����%d��Ҷ�ӽڵ��ֵ��",i);
		scanf("%c",&ht[i].data);
		printf("����ýڵ��Ȩֵ��");
		scanf("%d",&ht[i].weight);
	}
	for(i=n+1;i<=2*n-1;i++){
		min1=min2;
		left=right=0;
		for(k=1;k<=i-1;k++){
			if(ht[k].parent==0){
				if(ht[k].weight<min1){
					min2=min1;
					right=left;
					min1=ht[k].weight;
					left=k;
				}else if(ht[k].weight<min2){
					min2=ht[k].weight;
					right=k;
				}
			}
		}
		ht[left].parent=i;
		ht[right].parent=i;
		ht[i].weight=ht[left].weight+ht[right].weight;
		ht[i].lch=left;
		ht[i].rch=right;
	}
}

void HuffmanCode()
{
	int i,c,k,f;
	HuffCode cd;
	for(i=1;i<=n;i++){
		cd.start=n;
		c=i;
		f=ht[i].parent;
		while(f!=0){
			if(ht[f].lch==c){
				cd.bit[cd.start]='0';
			}else{
				cd.bit[cd.start]='1';
			}
			cd.start--;
			c=f;
			f=ht[f].parent;
		}
		hcd[i]=cd;
	}
	printf("��������������룺\n");
	for(i=1;i<=n;i++){
		printf("%c:",ht[i].data);
		for(k=hcd[i].start+1;k<=n;k++){
			printf("%c",hcd[i].bit[k]);
		}
		printf("\n");
	}
}

int main()
{
	HuffmanTree();
	HuffmanCode();
	
	return 0;
}



