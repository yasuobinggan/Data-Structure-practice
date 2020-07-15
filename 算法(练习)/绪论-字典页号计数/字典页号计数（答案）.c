#include "stdio.h"
#include "math.h"

int main()
{
   
	int n,i,j,k,len;
	int tempNum, lower, higher;
	int count[10]={0};

	printf("please input the number n:");
	scanf("%d",&n);

	len=log10(n); 


	for(i=0;i<=len;i++) 
	{	
		tempNum=(n/(int)pow(10,len-i))%10;
		higher=n/(int)pow(10,len-i+1);
		lower=n%(int)pow(10,len-i);
		
		count[tempNum]+=lower+1;

		for(j=0;j<tempNum;j++)
			count[j]+=(int)pow(10,len-i)*(higher+1);

		for(j=tempNum;j<10;j++)
			count[j]+=(int) pow(10,len-i)*higher;
		
	}
	for(i=0;i<=len;i++)
		count[0]-=(int)pow(10,i);

	for(i=0;i<10;i++)
	{
		printf("%d ",count[i]);
	}

	return 1;
}
