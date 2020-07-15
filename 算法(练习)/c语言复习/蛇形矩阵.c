#include<stdio.h>
int main()
{
	int a[5][5];
	int i,j,k;
	int count=1;
	//(5-1)*2-1;循环次数 
	for(k=0;k<=8;k++)
	{
		if(k>=4)
		{
			if(k%2!=0)
				for(i=k-4;i<=4;i++)
				{
					a[k-i][i]=count;
					count++;		
				}
			else
				for(i=4;i>=k-4;i--)
				{
					a[k-i][i]=count;
					count++;		
				}			
		}
		else
		{
			
			if(k%2!=0)
				for(i=0;i<=k;i++)//横坐标 
				{
					a[k-i][i]=count;
					count++;		
				}
			else
				for(i=k;i>=0;i--)//横坐标 
				{
					a[k-i][i]=count;
					count++;		
				}
		}		
	} 

	
	
	for(i=0;i<=4;i++)
	{
		for(j=0;j<=4;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	return 0;
} 