#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[8]={
		-2,11,8,-4,-1,16,5,0
	};
	int i,strat,end;
	int sum=0;
	int target[8],j;
	for(i=0;i<=7;i++)
	{
		if(a[i]>0)
		{
			strat=i;
			break;	
		}	
	}
	for(i=7;i>=0;i--)
	{
		if(a[i]>0)
		{
			end=i;
			break;	
		}
	}
	//从最前的正数到最后的正数 
	for(i=strat;i<=end;i++)
	{
		sum+=a[i];
		if(sum<0)
			
	} 
	return 0;
}