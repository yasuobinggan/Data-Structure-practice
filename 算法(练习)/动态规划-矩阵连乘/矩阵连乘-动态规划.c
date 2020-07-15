#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int x;
	int y;
}matrix;
void createma(matrix ma[6])
{
	int i;
	printf("输入连乘矩阵边长\n"); 
	for(i=0;i<6;i++)
	{
		scanf("%d%d",&ma[i].x,&ma[i].y);
	}
}
void createma1(int tama[6][6],matrix ma[6])
{
	int i,j;
	int minele(int i,int j,int tama[6][6],matrix ma[6]);
	for(i=0;i<6;i++)
	{
		for(j=i;j<6;j++)
		{
			tama[i][j]=0;
		}
	}
	
	for(j=1;j<=5;j++)
	{
		for(i=0;i<=5-j;i++)
		{
			tama[i][i+j]=minele(i,i+j,tama,ma);
		}
	}
			
}
int minele(int i,int j,int tama[6][6],matrix ma[6])
{
	int k;int ele[6],w=0,q;
	int min=0;
	for(k=0;k<6;k++)
		ele[k]=0; 
	for(k=i;k<j;k++)
	{
		ele[w]=tama[i][k]+tama[k+1][j]+((ma[i].x)*(ma[k].y)*(ma[j].y));
		w++;
	}
	
	for(q=0;q<w;q++)
	{
		if(ele[min]>ele[q])
			min=q;
	}
	
	return ele[min];
}
void travelma1(int tama[6][6])
{
	int i,j;int count=0;
	for(i=0;i<6;i++)
	{
		for(j=0;j<i;j++)
		{
			printf("\t");
		}
		for(j=i;j<6;j++)
		{
			printf("%d\t",tama[i][j]);
		}
		printf("\n");	
	}
	
}
int main()
{
	//int n;
	//printf("输入矩阵连乘数:\n");
	//scanf("%d",&n);
	matrix ma[6];
	int tama[6][6];
	int i,j;
	createma(ma);
	createma1(tama,ma);
	travelma1(tama);
	//travel(tama);
	return 0;
} 