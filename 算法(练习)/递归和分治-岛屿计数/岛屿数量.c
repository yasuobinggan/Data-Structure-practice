#include<stdio.h>
#define max 100
typedef struct{
	int x;
	int y;
}visit; 
void createmap(int map[max][max],int &length)
{
	int i,j; 
	printf("输入地图维的长度:\n");
	scanf("%d",&length);
	printf("输入岛屿和海洋:\n");
	for(i=0;i<length;i++)
	{
		for(j=0;j<length;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
}
int exist(visit visited[],int l,int x,int y)//标记检查数组的长度 
{
	int i;
	for(i=0;i<l;i++)
	{
		if(x==visited[i].x&&y==visited[i].y)
			return 1;
	}
	if(i==l)
		return 0;
}
void find(int map[max][max],int length,visit visited[],int &l,int i,int j,int &count)
{
	if(i<0||i>(length-1)||j<0||j>(length-1))
		return;
	else if(((map[i-1][j]==0||exist(visited,l,i-1,j))&&(map[i+1][j]==0||exist(visited,l,i+1,j))&&(map[i][j-1]==0||exist(visited,l,i,j-1))
	&&(map[i-1][j]==0||exist(visited,l,i,j+1)))||(map[i][j]==0)||exist(visited,l,i,j))//不是岛屿,四周无法通行,被标记 
		return;
	count++;
	visited[l].x=i;
	visited[l].y=j;
	l++;
	find(map,length,visited,l,i-1,j,count);
	find(map,length,visited,l,i+1,j,count);
	find(map,length,visited,l,i,j+1,count);
	find(map,length,visited,l,i,j-1,count);
}
void findisland(int map[max][max],int length,int k)
{
	int i,j;
	visit visited[max];int l=0;
	int count;
	int c=0;//记录大与定值的岛屿数量 
	for(i=0;i<length;i++)
	{
		for(j=0;j<length;j++)
		{
			count=0;//记录岛屿大小 
			find(map,length,visited,l,i,j,count);
			if(count>=k)
				c++;
		}
	}
	printf("大于%d的岛屿数量为%d",k,c);	
}
int main()
{
 	int map[max][max],length,k;
 	createmap(map,length);
 	printf("输入要寻找的岛屿大小:\n");
 	scanf("%d",&k);
 	findisland(map,length,k);
	return 0;
}