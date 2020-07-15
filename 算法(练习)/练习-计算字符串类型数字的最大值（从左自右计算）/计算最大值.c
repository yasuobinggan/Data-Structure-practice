#include<stdio.h>
#define max 100
void createarray(int a[],int n)
{
	int i;
	printf("输入%d个数字:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}
int char_max(int a[],int n)
{
	int i;
	int c_max=a[0];	
	for(i=1;i<=n-1;i++)
	{
		if(a[i]<=1||c_max<=1)
			c_max+=a[i];
		else
			c_max*=a[i];
	}
	return c_max;
}
int main()
{
	int a[max],n;
	printf("输入字符串数字的长度:\n");
	scanf("%d",&n);
	createarray(a,n);
	printf("输出字符串数字的最大值:%d\n",char_max(a,n));
	return 0;
}