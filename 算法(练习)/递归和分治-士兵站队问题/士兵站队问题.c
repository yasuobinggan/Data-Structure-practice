#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int x;
	int y;
}
void map(int n,int m[10][10])
{
	int i,j,k=0;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			m[i][j]=0;
	for(i=0;i<n;i++)
	{
		scanf
	}
}
void print(int m[10][10])
{
	int i,j,count=0;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			printf("%d\t",m[i][j]);
			count++;
		}
		if(count%10==0)
		printf("\n");
	}
}
int main()
{
	int n,m[10][10];
	printf("输入士兵的人数:\n");
	scanf("%d",&n);
	map(n,m);
	print(m);
	return 0;
}