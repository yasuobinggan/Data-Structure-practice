#include<stdio.h>
#define max 100
int main()
{
	int n,i,j;
	int a[max];
	int count=0;
	printf("输入环的数字数量:\n");
	scanf("%d",&n);
	for(i=2;i<n;i++)
	{
		for(j=2;j<=i;j++)
		{
			if((i==2)||(i%j!=0&&j==i-1))
			{
				printf("%d\t",i);
				count++;
			}
			if(i%j==0)
				break;
		}
	}
	printf("\n%d",count);
	return 0;
} 