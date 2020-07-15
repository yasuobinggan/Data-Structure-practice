#include<stdio.h>
#define maxl 20
int count(int n,int length)//qsum-待选数,length为数据总长度3*3 
{
	int i,count=0;
	if(n>length)
		for(i=length;i>(n/2);i--)
			count++;
	else
		for(i=1;i<(n/2);i++)
			count++;
	return count;
}
void intarray(int a[maxl][maxl],int length)
{
	int i,j;
	for(i=0;i<length;i++)
		for(j=0;j<length;j++)
			a[i][j]=0;
}

int main()
{
	int a[maxl][maxl];
	int length;
	int i,j;
	int num=1,gsum;
	int c,count1;
	printf("输入想建立的魔方矩阵的边长(奇数):\n");
	scanf("%d",&length);
	intarray(a,length);
	gsum=((num+length*length)*length*length)/(2*3);
	//printf("%d",gsum);
	
	for(num=1;num<=(length*length);num++)
	{
		count1=gsum-num;
		c=count(count1,(length*length));
		if(c==4)
			a[length/2][length/2]=num;
		else if(c==3)
		{
			if(a[0][0]==0)
			{
				a[0][0]=num;
				//if(a[0][0]!=0 || a[0][length-1]!=0 || a[length-1][length-1]!=0 ||a[length-1][0]!=0)
					//continue;	
			}
				
			if(a[0][length-1]==0)
			{
				a[0][length-1]=num;
				//				if(a[0][0]!=0 || a[0][length-1]!=0 || a[length-1][length-1]!=0 ||a[length-1][0]!=0)
					//continue;	
	
			}
				
			if(a[length-1][0]==0)
			{
				a[length-1][0]=num;
				//if(a[0][0]!=0 || a[0][length-1]!=0 || a[length-1][length-1]!=0 ||a[length-1][0]!=0)
					//continue;	
	
			}
				
			if(a[length-1][length-1]==0)
			{
				a[length-1][length-1]=num;
				//if(a[0][0]!=0 || a[0][length-1]!=0 || a[length-1][length-1]!=0 ||a[length-1][0]!=0)
				//	continue;	
	
			}
				
		} 
	}
	
	for(i=0;i<length;i++)
	{
		for(j=0;j<length;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	return 0;
}
