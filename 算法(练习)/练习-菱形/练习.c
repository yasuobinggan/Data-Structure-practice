#include<stdio.h>
int main()
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		if(i<=5)
		{
			for(j=1;j<=5-i;j++)
				printf(" ");
			printf("%d",i);
			for(j=1;j<=2*((i-1)-1)+1;j++)
				printf(" ");
			if(i!=1)
				printf("%d",i);
			for(j=1;j<=5-i;j++)
				printf(" ");
			printf("\n");	
		}
		else
		{
			for(j=1;j<=i-5;j++)//i-5==(9-i)+1
				printf(" ");
			printf("%d",(9-i)+1);
			for(j=1;j<=(2*(9-1-i))+1;j++)
				printf(" ");
			if((9-i)+1!=1)
				printf("%d",(9-i)+1);
			for(j=1;j<=i-5;j++)
				printf(" ");
			printf("\n");	
		}
	}
} 