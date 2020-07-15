#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define maxn 5
int G[maxn][maxn]={
	0,0,0,0,0,
	0,0,30,6,4,
	0,30,0,5,10,
	0,6,5,0,20,
	0,4,10,20,0,
};//距离表 
int closed[maxn]; 
int minlen=1e9;//最短路径 
int curlen=0;//当前路径
bool judge()
{
	for(int i=1;i<maxn;i++)
	{
		if(closed[i]!=1)
			return false;
	}
	return true;
 } 
void dfs(int start)
{
	if(judge())//保存最优解 
	{
		if(curlen+G[start][1]<minlen)
			minlen=curlen+G[start][1];
		return;
	}
	if(curlen>minlen)//剪枝策略 
	{
		return;
	}
	for(int i=1;i<maxn;i++)
	{
		if(!closed[i])
		{
			closed[i]=1;
			curlen+=G[start][i]; 
			dfs(i);
			
			curlen-=G[start][i];
			closed[i]=0;
		}
	}
}
int main()
{
	memset(closed,0,sizeof(closed));
	closed[1]=1;
	dfs(1);
	cout<<"最短路径:"<<minlen<<endl;
	return 0;
}
