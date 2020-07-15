//完全随机化
//迭代加深的dfs
//bfs 
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
#define XL 21
#define YL 41
#define ZL 6
#define maxd 10 
double bottom[XL][YL];//x:,y:,z:0//记录E 
double U = -1;//最大比值 
int cnt[XL][YL],tar[XL][YL];//x:10,y: ,Z:5//
typedef struct point{
	int x;
	int y;
}point;
point p[XL*YL];
 
int TOT,I;

int dir[8][2]{
	1,0,
	1,-1,
	1,1,
	0,1,
	0,-1,
	-1,0,
	-1,-1,
	-1,1,
};

void calU(int x, int y, int z)
{
	int i, j;
	for (i = 0; i<XL; i++)
	{
		for (j = 0; j<YL; j++)
		{
			bottom[i][j] += (I / (pow(abs(x - i), 2) + pow(abs(y - j), 2) + z*z));
		}
	}
}
double TotcalU()
{
	memset(bottom, 0, sizeof(bottom));
	/* 
	for (int i = 0; i<XL; i++)
	{
		for (int j = 0; j<YL; j++)
		{
			if (cnt[i][j] == 1)
			{	
				calU(i, j, 5);
			}
		}
	}
	*/ 
	for(int i=0;i<TOT;i++)
	{
		calU(p[i].x,p[i].y,5);
	}
	double max =bottom[0][0], min =bottom[0][0] ;
	for (int i = 0; i < XL; i++)
	{
		for (int j = 0; j < YL; j++)
		{
			if (bottom[i][j] > max)
				max = bottom[i][j];
			if (bottom[i][j] < min)
				min = bottom[i][j];
		}
	}
	return min / max;
}

void initial()
{
	srand(time(NULL));
	int n=TOT;
	int i=0;
	while(n--)
	{
		int c=rand()%(XL*YL);
		int x=c/YL;
		int y=c%YL;
		cnt[x][y]=1;
		p[i].x=x;p[i].y=y;
		i++;
	}
}
void unitlocalsearch(int x,int y)
{
	int tx=x;int ty=y; 
	for(int i=0;i<8;i++)
	{
		int h=tx+dir[i][0];
		int z=ty+dir[i][1];
		if(!cnt[h][z])
		{
			cnt[h][z]=1;
			cnt[x][y]=0;
			int x1=x;int y1=y;//记录当前的最优解 
			x=h;y=z;
			
			if(TotcalU()>U)
			{
				U=TotcalU();	
			}
			else
			{
				cnt[h][z]=0;
				x=x1;y=y1;
				cnt[x][y]=1;							
			} 
			 
		 } 
	}
	
}
void localsearch()
{
	for(int i=0;i<TOT;i++)
	{
		unitlocalsearch(p[i].x,p[i].y);
	} 
}
void out()
{
	for(int i=0;i<XL;i++)
	{
		for(int j=0;j<YL;j++)
		{
			cout<<cnt[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	cout << "输入灯泡功率:" << endl;
	cin >> I;
	cout << "输入想放入灯泡的数量:" << endl;
	cin >> TOT;
	memset(bottom,0,sizeof(bottom));
	memset(cnt, 0, sizeof(cnt));
	
	initial();
	U=TotcalU();
	for(int i=0;i<maxd;i++)
	{
		localsearch();
	}
	
	cout<<U<<endl;
	out();
	return 0;
}
