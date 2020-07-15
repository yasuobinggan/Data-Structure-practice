#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct mgraph{
	int vexs[max];
	int arcs[max][max];
	int vexnum,arcnum;//点数，弧数 
}mgraph;
void createmg(mgraph &mg)
{
	int i,j,k;
	printf("输入图的点的数量,弧的数量:\n");
	scanf("%d%d",&mg.vexnum,&mg.arcnum);
	printf("输入点的名称:\n");
	for(i=0;i<mg.vexnum;i++)//点阵 
	{
		scanf("%d",&mg.vexs[i]);
	}
	
	for(i=0;i<mg.vexnum;i++)//初始化邻接矩阵 
	{
		for(j=0;j<mg.vexnum;j++)
		{
			mg.arcs[i][j]=0;
		}
	}
	
	printf("输入弧的坐标:\n");//建立弧的连接 
	for(i=0;i<mg.arcnum;i++)
	{
		scanf("%d%d",&j,&k);
		mg.arcs[j][k]=1;
	}
}
void dfs(int vex,int visit[],mgraph mg)//vex节点名 
{
	int i;
	visit[vex]=1;
	printf("%d\t",vex);
	for(i=0;i<mg.vexnum;i++)
	{
		if(!mg.vexs[vex][i])
			dfs(i,visit,mg);
	} 
} 
int main()
{
	mgraph mg;
	int visit[max],i;
	for(i=0;i<max;i++)
		visit[i]=0;
	createmg(mg);
	dfs(mg.vexs[0],visit,mg);//mg.vexs[0]从第一个节点进入 
	return 0;
}