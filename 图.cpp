#include<stdio.h>

#define MAXVEX 100  //��󶥵��� 
#define INFINITY 65535  //��65535��������� 

typedef int EdgeType;  //�ߵ��������� 
typedef char VertexType;  //������������� 
typedef int Boolean;
Boolean visited[MAXVEX];

//�ڽӾ���ṹ�� 
typedef struct 
{
	VertexType vexs[MAXVEX]; //�����
	EdgeType arc[MAXVEX][MAXVEX]; //�ڽӾ��󣬼�����֮��Ĺ�ϵ 
	int numVertexes;  //ͼ�еĶ���ĸ���
	int numEdges;  //ͼ�бߵ����� 	 
}MGraph;

//����������ͼ���ڽӾ����ʾ
void CreateMGraph(MGraph*g);
//�ڽӾ���������ȱ����㷨
void DFS (MGraph g,int i);
//�ڽӾ�����ȱ�������
void DFSTraverse(MGraph g);
//�����ڽӱ�ṹ 
//�ڽӾ����ȱ�������
void EnQueue(MGraph g);
 
void  CreateALGraph();

int main()
{
	
	MGraph g;
	CreateMGraph(&g);
	printf("\n***********�������*************\n");
	DFSTraverse(g);
	printf("\n***********�������*************\n");
	EnQueue(g);
	return 0;
}


//�����ڽӾ����ʾ
void CreateMGraph(MGraph*g)
{
	printf("�����붥�������");
	scanf("%d",&g->numVertexes);
	printf("���������:");
	scanf("%d",&g->numEdges);
	//��ʼ����������
	printf("\n***********���붥��*************\n"); 
	for(int i=0;i<g->numVertexes;i++){
		printf("�������%d������:",i+1);
		scanf(" %c",&g->vexs[i]);
	} 
	 
	//��ʼ���ڽӾ���
	for(int i=0;i<g->numVertexes;i++){
		for(int j=0;j<g->numVertexes;j++){
			g->arc[i][j]=INFINITY;
			if(i==j){
				g->arc[i][j]=0;
			}
		}
	}
	
	//�ڽӾ��������
	printf("\n***********���������*************\n");
	for(int i=0;i<g->numEdges;i++){
		int vi,vj,w;
		printf("�������%d����(vi,vj)���ϱ�i,�±�j�ͱߵ�Ȩֵw,�Զ��ŷָ�:",i+1);
		scanf("%d,%d,%d",&vi,&vj,&w);
		g->arc[vi][vj]=w;
//		g->arc[vj][vi]=w;  //��Ϊ������ͼ���ʶԳ� 
	} 	
}

//�ڽӾ���������ȱ����㷨
void DFS (MGraph g,int i)
{
	visited[i]=1;
	printf("%c",g.vexs[i]);
	for(int j=0;j<g.numVertexes;j++){
		if(!visited[i]&&g.arc[i][j]!=0&&g.arc[i][j]!=INFINITY){
			DFS(g,j);
		}
	}
}

//�ڽӾ�����ȱ�������
void DFSTraverse(MGraph g)
{
	for(int i=0;i<g.numVertexes;i++){
		visited[i]=0;   //��ʼ���ж��㶼Ϊδ����״̬ 
	}
	for(int i=0;i<g.numVertexes;i++){
		if(!visited[i]){
			DFS(g,i);
		}
		
	}
}
//�ڽӾ����ȱ�������,ע��ֻ������ͼ���ʺ� 
void EnQueue(MGraph g)
{
	for(int i=0;i<g.numVertexes;i++){
		visited[i]=0;   //��ʼ���ж��㶼Ϊδ����״̬ 
	}
	
	for(int i=0;i<g.numVertexes;i++){
		for(int j=0;j<g.numVertexes;j++){
			if(!visited[j]&&g.arc[i][j]!=0&&g.arc[i][j]!=INFINITY){
				printf("%c ",g.vexs[j]);
				visited[j]=1;
			}
		}
	}
}




////�ڽӱ�ṹ�� 
//typedef struct EdgeNode
//{
//	int adjvex;   //�ڽӵ��򣬴洢�ö����Ӧ���±� 
//	EdgeType weight;  //���ڴ洢Ȩֵ 
//	struct EdgeNode*next;  //ָ��������ָ����һ���ڽӵ� 
//	
//}EdgeNode;
////�ڽӱ�ṹ�� 
//typedef struct VertexNode
//{
//	VertexType data;   //�洢���������
//	EdgeNode *firstedge;   //�߱�ͷָ�� 
//}VertexNode,*AdjList[MAXVEX]
////�ڽӱ�ṹ��
//typedef struct
//{
//	AdjList adjList;
//	int numVertexes,numEdges;
// }GraphAdjList;
 

