#include<stdio.h>
#include<stdlib.h>
int g(int value,int v[])
{
	int i=0;
	while(value>0)
	{
		v[i]=value%10;
		value=value/10;
		i++;
	}
	return i;
}
int jie10(int i)
{
	if(i==-1)
	return 0; 
	if(i==0)
	return 1;
	if(i>0)
	return 10*jie10(i-1); 
}
void jishu(int d,int w,int b[10])
{
	int j;
	for(j=0;j<w;j++)
		b[j]+=jie10(d-1);
	for(j=0;j<10;j++)
		b[j]+=w*jie10(d-2);
}
void print(int b[])
{
	int j;
	printf("输出各数字使用频率:\n");
	for(j=0;j<=9;j++)
	printf("%d\t%d\n",j,b[j]);
}
int main()
{
	int value,v[10],val;
	int i,j,k;
	int d;//获取位数 
	int b[10]={0,0,0,0,0,0,0,0,0,0};
	int sum=0; 
	printf("输入字典的页数:\n");
	scanf("%d",&value);
	d=g(value,v);
	//计数主体 
	//val=value-jie10(d-1);
	for(i=0;i<d;i++)
	{
		for(j=i+1;j<d;j++)
		{
			for(k=0;k<=9;k++)
			{
				if(v[j]==k&&i==0)
					b[k]+=(v[i]+1)*jie10(i);
				if(v[j]==k&&i!=0)
					b[k]+=v[i]*jie10(i);
			}	
		}
	}
	
	for(i=0;i<=d-1;i++)
	{
		jishu(i+1,v[i],b);
	}
	b[v[0]]++;
	//
	for(i=0;i<d;i++)
	{
		sum+=jie10(i);
	}
	b[0]-=sum;	
	print(b);
	return 0;
}