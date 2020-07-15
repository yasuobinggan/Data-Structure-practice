#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
void map(int a[10][10])
{
	int i,j;
	for(i=1;i<=10;i++)
	{
		for(j=1;j<=10;j++)
		{   if(i==1&&i==10)
			a[i][j]=0;
			else
			a[i][j]=1;
		}
	}
	for(i=1;i<=10;i++)
	{
		for(j=1;j<=10;j++)
		printf("%d",a[i][j]);
	} 
}
int main()
{
	int a[10][10];
	map(a[][10]);
	return 0;
}