#include<stdio.h>
int main()
{
	int a[2][3]={
		2,4,6,
		8,0,1
	},(*p)[3],i,j,k=0;
	int temp;
	int temp1;	
	int temp2;
	int qw;
	temp=3;//数组长度的一半 
	temp1=0;
	temp2=2;
	
/*	

		for(i=0;i<2;i++)
		{
			for(j=0;j<3;j++)
			{
				qw=a[i][j];
				a[i][j]=a[1-i][2-j];
				a[1-i][2-j]=qw;
				k++; 
			} 
			if(k==3)
			break;
		}		
*/  //最内层控制循环数组的一半 
	for(i=0;i<=temp1;i++)
	{
		for(j=0;j<=temp2;j++)
		{
			qw=a[i][j];
			a[i][j]=a[1-i][2-j];
			a[1-i][2-j]=qw;
		}
	}

	//p=a;
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",a[i][j]);
		}
	}
	return 0;
}