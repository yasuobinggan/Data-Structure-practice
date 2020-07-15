#include<stdio.h>
#include<math.h>
int main()
{
	int a[7]={
		-4,-1,2,5,7,8,9
	};
	int i,k;
	int  target[7];
	for(i=0;i<7;i++)
	{
		k=a[i];
		target[i]=abs(-4-k)+abs(-1-k)+abs(2-k)+abs(3-k)+abs(5-k)+abs(7-k)+abs(8-k)+abs(9-k);
	}
	int min=0;
	for(i=0;i<7;i++)
	{
		if(target[i]<target[min])
		min=i;
	}
	printf("%d,%d",min,target[min]);
	return 0;
}