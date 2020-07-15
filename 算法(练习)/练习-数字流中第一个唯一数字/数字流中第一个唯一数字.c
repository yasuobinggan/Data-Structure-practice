#include<stdio.h>
#define max 100
void createarray(int a[max],int n)
{
	int i;
	printf("输入%d个数字:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}
int first_only(int a[max],int n,int end)
{
	int i;
	int flag=0;
	for(i=0;i<n;i++)
	{
		if(a[i]!=end)
		{
			if(a[i]==flag)//
				flag=0;//0视为数字流中不会存在的数字,增加健壮性可以利用结构体 
			else if(flag==0)//
				flag=a[i];//	
		}
		else
		{
			if(flag==0)
				return end;
			return flag;		
		}
		/*
		*/
	}
	if(a[n-1]!=end)
		return -1;
}
int main()
{
	int a[max],n,end;
	printf("输入数字流的长度:\n");
	scanf("%d",&n);
	createarray(a,n);
	printf("输入终止数字:\n");
	scanf("%d",&end);
	printf("输出数字流中第一个唯一的数字:%d\n",first_only(a,n,end));
	return 0;
}