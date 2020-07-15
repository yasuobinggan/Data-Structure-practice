#include<stdio.h>
#include<stdlib.h>
void jishu(int value,int b[10])
{
	int i=0,v[10];
	int j,k;
	while(value>0)
	{
		v[i]=value%10;
		value=value/10;
		i++;
	}
	for(j=0;j<i;j++)
	{
		for(k=0;k<10;k++)
		{
			if(v[j]==k)
			b[k]++;
		}
	}
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
	int value,b[10]={0,0,0,0,0,0,0,0,0,0};
	int i;
	printf("输入字典页号数:\n");
	scanf("%d",&value);
	//jishu(value,b);
	
	for(i=1;i<=value;i++)
	{
		jishu(i,b);
	}
	
	print(b);
	return 0;
}