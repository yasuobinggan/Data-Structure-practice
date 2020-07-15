#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct mgraph{
	int vexs[max];
	int arcs[max][max];
	int vexnum,arcnum;
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
int main()
{
	mgraph mg;
	createmg(mg);
	return 0;
}