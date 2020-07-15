#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct mgraph {
	int vexs[max];
	int arcs[max][max];
	int vexnum, arcnum;//点数，弧数 
}mgraph;

void createmg(mgraph &mg)
{
	int i, j, k;
	printf("输入图的点的数量,弧的数量:\n");
	scanf_s("%d%d", &mg.vexnum, &mg.arcnum);
	printf("输入点的名称:\n");
	for (i = 0; i<mg.vexnum; i++)//点一维阵 
	{
		scanf_s("%d", &mg.vexs[i]);
	}

	for (i = 0; i<mg.vexnum; i++)//初始化二维邻接矩阵 
	{
		for (j = 0; j<mg.vexnum; j++)
		{
			mg.arcs[i][j] = 100;
		}
	}

	printf("输入弧的坐标和弧的权值:\n");//建立弧的连接 
	for (i = 0; i<mg.arcnum; i++)
	{
		scanf_s("%d%d", &j, &k);
		scanf_s("%d", &mg.arcs[j][k]);
	}
}
int T(int w, int select[], int n)
{
	int i = 0;
	while (i < n)
	{
		if (w != select[i])
			i++;
		else
			break;
	}
	if (i == n)return 1;//不在数组里返回真值
	else return 0;//在数组里返回0

}
int indegree_0(mgraph &mg,int select[],int n)
{
	int i, j, k;
	int count;
	for (i = 0; i < mg.vexnum; i++) 
	{
		count = 0;
		if(T(i,select,n))
		{ 
			for (j=0;j<mg.vexnum;j++)
			{
				if(mg.arcs[i][j]==100)
					count++;
			}
			if (count == mg.vexnum)
			{
				printf("%d\t", mg.vexs[i]);//i修改mg.vexs[i]
				select[n] = i;
				for (k = 0; k < mg.vexnum; k++)
				{
					mg.arcs[k][i] = 100;
				}
				return i;
			}
		}
	}
	if (i == mg.vexnum)
		return -1;
}
void  Topolo_Sort(mgraph &mg)
{
	int select[max], n=0;//n做标记为判断拓扑排序是否结束
	//int count=0;//判断有向图中是否存在环
	int point;//接受返回值
	while (n < mg.vexnum)
	{
		point=indegree_0(mg, select, n);
		n++;
		if (point == -1 && n < mg.vexnum)
		{
			printf("拓扑排序结束!有向图中存在环\n");
			break;
		}
	}
}
int main()
{
	mgraph mg;
	printf("建立有向图---\n");
	createmg(mg);
	printf("输出有向图的拓扑排序:\n");
	Topolo_Sort(mg);
	return 0;
}