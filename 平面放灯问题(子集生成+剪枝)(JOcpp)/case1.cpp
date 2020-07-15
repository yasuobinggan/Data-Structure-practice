//此题解具有对称性 
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
#define XL 21
#define YL 11
#define ZL 6
double bottom[XL][YL];//x:,y:,z:0//记录E 
double U = -1;//最大比值 

int cnt[YL], tar[YL];//x:10,y: ,Z:5//
int TOT;

int I;

void calU(int x, int y, int z,int op)
{
	int i, j;
	for (i = 0; i<XL; i++)
	{
		for (j = 0; j<YL; j++)
		{
			if(op)
				bottom[i][j] += (I / (pow(abs(x - i), 2) + pow(abs(y - j), 2) + z*z));
			else
				bottom[i][j] -= (I / (pow(abs(x - i), 2) + pow(abs(y - j), 2) + z*z));
			//bottom1[k++] = bottom[i][j];
		}
	}
	//sort(bottom1,bottom1+k);
	//return bottom1[0]/bottom1[k-1];
}
 
double TotcalU()
{
	double max = -1, min = 10000;
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
 
void dfs(int j, int count)
{
	if (count == TOT)
	{
		if (TotcalU()>U)
		{
			U = TotcalU();
			
			for (int i = 0; i < YL; i++)
				tar[i] = cnt[i];
		}
		return;
	}	
	if (count + (YL - j)<TOT)
		return;

	cnt[j] = 1;
	calU(10,j,5,1);
	dfs(j + 1, count + 1);

	cnt[j] = 0;
	calU(10,j,5,0);
	dfs(j + 1, count);
}
int main()
{
	cout << "输入灯泡功率:" << endl;
	cin >> I;
	cout << "输入想放入灯泡的数量:" << endl;
	cin >> TOT;
	//while(cin>>I>>TOT)
	//{
	memset(bottom,0,sizeof(bottom));
	memset(cnt, 0, sizeof(cnt));

	int count = 0;
	dfs(0, count);
	cout<<U<<endl;

	for (int j = 0; j<YL; j++)
	{
		cout << tar[j] << " ";
	}

	cout << endl;
	//}
	
	return 0;
}
