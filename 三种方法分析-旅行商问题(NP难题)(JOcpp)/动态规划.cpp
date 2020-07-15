//动态规划
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define maxn 5
//动态规划数组
int dp[maxn][8];
int closed[maxn];
int G[maxn][maxn]={
	0,0,0,0,0,
	0,0,30,6,4,
	0,30,0,5,10,
	0,6,5,0,20,
	0,4,10,20,0,
};
/*
//递推形式实现
int dp[maxn][maxn];
void initial()//初始化
{
	for(int i=1;i<maxn;i++)
	{
		dp[i][maxn-1]=G[i][1];
	}
 }
int dp_tsp()
{
	for(int j=maxn-1;j>=0;j--)
	{
		//int m=0;
		for(int i=1;i<maxn;i++)
		{
			dp[i][j]=min(,dp[i][j]+G[i][j]);
		}
	}
}
*/
void initial()//初始化
{
	for(int i=2;i<maxn;i++)
	{
		dp[i][7]=G[i][1];
	}
}
int compute_s()
{
	int sum=0;
	for(int i=2;i<maxn;i++)
	{
		if(closed[i]==1)
			sum+=(int)pow((double)2,(double)i-2);
	}
	return sum;
}
//递归形式实现
int dp_tsp(int i,int S)//当前城市，当前走过的城市//记忆化搜索
{
	int &ans=dp[i][S];
	if(ans!=(1<<30))
		return ans;

	for(int j=1;j<maxn;j++)
	{
		if(closed[j]!=1)
		{
			closed[j]=1;

			int c_s;//当前走过的城市
			c_s=compute_s();
			ans=min(ans,dp_tsp(j,c_s)+G[i][j]);

			closed[j]=0;
		}

	}

	return ans;
}
int main()
{
//	memset(dp,-1,sizeof(dp));
	for(int i=1;i<maxn;i++)
	{
		for(int j=0;j<8;j++)
		{
			dp[i][j]=(1<<30);
		}
	}
	initial();
	closed[1]=1;
	dp_tsp(1,0);
	cout<<"最短路径:"<<dp[1][0]<<endl;
	return 0;
}

