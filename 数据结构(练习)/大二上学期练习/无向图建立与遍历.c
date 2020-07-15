#include<stdio.h>
#include<stdlib.h>
#define max_vertex_num 20
#define infinity int_max
typedef struct arccell
{
	int  adj;
	int *info;
}arcell,adjmatrix[max_vertex_num][max_vertex_num];
typedef struct{
	char vexs[max_vertex_num];
	adjmatrix arcs;
	int vexnum,arcnum;
}mgraph;
void creatudn(mgraph g)
{   
    int i,j;int k;int a,b; 
	printf("输入无向图的顶点数，弧数:\n");
	scanf("%d%d",&g.vexnum,&g.arcnum);
	printf("输入顶点名称:\n");
	for(i=0;i<g.vexnum;i++)
	scanf("%c",&g.vexs[i]);
	for(i=0;i<g.vexnum;i++)
{    for(j=0;j<g.vexnum;j++)
	{   g.arcs[i][j].adj=0;
	    g.arcs[i][j].info=NULL;
	}
}
printf("\n--------------------------------\n");   
for(k=0;k<g.arcnum;k++)
{
   printf("输入弧的依附的顶点:\n");
   scanf("%d%d",&a,&b);
   g.arcs[a][b].adj=1;
   g.arcs[b][a]=g.arcs[a][b];
}	
}
void firstadjvex(mgraph g,int v)
{
	
}
void nextadjvex(mgraph g,int v,int w)
{
	
}
void dfs(mgraph g,int v)
{
	int w;
	int visited[g.vexnum];
	v=0;
	printf("%d",g.vexs[v]);
	visited[v]=1;
	for(w=firstadjvex(g,v);w>=0;w=nextadjvex(g,v,w))
	{
		if(visited[w]==0)
		dfs(g,w);
	}
}
void dfstraverse(mgraph g)
{
	int v;int visited[g.vexnum]; 
	for(v=0;v<g.vexnum;v++)
	visited[v]=0;
	for(v=0;v<g.vexnum;v++)
	{
		if(v==0)
		dfs(g,v);
	}
} 
int main()
{   
    mgraph g1;
	creatudn(g1); 
	return 0;
}