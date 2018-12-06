#include<stdio.h>

#define MAXVEX 100  //最大顶点数 
#define INFINITY 65535  //用65535代表我穷大 

typedef int EdgeType;  //边的数据类型 
typedef char VertexType;  //顶点的数据类型 
typedef int Boolean;
Boolean visited[MAXVEX];

//邻接矩阵结构体 
typedef struct 
{
	VertexType vexs[MAXVEX]; //顶点表
	EdgeType arc[MAXVEX][MAXVEX]; //邻接矩阵，即顶点之间的关系 
	int numVertexes;  //图中的顶点的个数
	int numEdges;  //图中边的条数 	 
}MGraph;

//创建无向网图的邻接矩阵表示
void CreateMGraph(MGraph*g);
//邻接矩阵深度优先遍历算法
void DFS (MGraph g,int i);
//邻接矩阵深度遍历操作
void DFSTraverse(MGraph g);
//创建邻接表结构 
//邻接矩阵广度遍历操作
void EnQueue(MGraph g);
 
void  CreateALGraph();

int main()
{
	
	MGraph g;
	CreateMGraph(&g);
	printf("\n***********输出顶点*************\n");
	DFSTraverse(g);
	printf("\n***********输出顶点*************\n");
	EnQueue(g);
	return 0;
}


//创建邻接矩阵表示
void CreateMGraph(MGraph*g)
{
	printf("请输入顶点个数：");
	scanf("%d",&g->numVertexes);
	printf("请输入边数:");
	scanf("%d",&g->numEdges);
	//初始化顶点数组
	printf("\n***********输入顶点*************\n"); 
	for(int i=0;i<g->numVertexes;i++){
		printf("请输入第%d个顶点:",i+1);
		scanf(" %c",&g->vexs[i]);
	} 
	 
	//初始化邻接矩阵
	for(int i=0;i<g->numVertexes;i++){
		for(int j=0;j<g->numVertexes;j++){
			g->arc[i][j]=INFINITY;
			if(i==j){
				g->arc[i][j]=0;
			}
		}
	}
	
	//邻接矩阵的生成
	printf("\n***********矩阵的生成*************\n");
	for(int i=0;i<g->numEdges;i++){
		int vi,vj,w;
		printf("请输入第%d个边(vi,vj)的上标i,下标j和边的权值w,以逗号分隔:",i+1);
		scanf("%d,%d,%d",&vi,&vj,&w);
		g->arc[vi][vj]=w;
//		g->arc[vj][vi]=w;  //因为是无向图，故对称 
	} 	
}

//邻接矩阵深度优先遍历算法
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

//邻接矩阵深度遍历操作
void DFSTraverse(MGraph g)
{
	for(int i=0;i<g.numVertexes;i++){
		visited[i]=0;   //初始所有顶点都为未访问状态 
	}
	for(int i=0;i<g.numVertexes;i++){
		if(!visited[i]){
			DFS(g,i);
		}
		
	}
}
//邻接矩阵广度遍历操作,注意只有无向图才适合 
void EnQueue(MGraph g)
{
	for(int i=0;i<g.numVertexes;i++){
		visited[i]=0;   //初始所有顶点都为未访问状态 
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




////邻接表结构体 
//typedef struct EdgeNode
//{
//	int adjvex;   //邻接点域，存储该顶点对应的下标 
//	EdgeType weight;  //用于存储权值 
//	struct EdgeNode*next;  //指针域，用于指向下一个邻接点 
//	
//}EdgeNode;
////邻接表结构体 
//typedef struct VertexNode
//{
//	VertexType data;   //存储顶点的数据
//	EdgeNode *firstedge;   //边表头指针 
//}VertexNode,*AdjList[MAXVEX]
////邻接表结构体
//typedef struct
//{
//	AdjList adjList;
//	int numVertexes,numEdges;
// }GraphAdjList;
 

