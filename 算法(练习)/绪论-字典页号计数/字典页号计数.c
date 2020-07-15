#include<stdio.h>
#include<stdlib.h>
//同意外层循环用j，内层循环用w 
int jie10(int i)
{
	if(i==0)
	return 1;
	if(i>0)
	return 10*jie10(i-1); 
}
int jie(int n,int i)
{
	if(i==0)
	return 1;
	if(i>0)
	return n*jie(n,i-1);
}

int main()
{
	int v,n,i=0,j,w,count=0,a[10],b[10]={0,0,0,0,0,0,0,0,0,0};
	printf("输入书的总页号:\n");
	scanf("%d",&v);
	while(v)
	{
		n=v%10; 
		v=v/10;
		a[i]=n;
		i++;
	}
	printf("%d\n",i);
	for(j=0;j<i;j++)
	{
		if(j==1)
		b[9]+=j*a[j];
		for(w=0;w<a[j];w++)
		{
			b[w]++;
			if(j==1)
			b[w]+=a[j-1];
		}
	}
 /*	for(j=0;j<i-1;j++)
	{ 
		b[a[i-1]-1]+=a[j];
	}//补全页号最高位的计数 
*/		
/*	for(j=0;j<10;j++)
	{
		if(a[i-1]==j-1)
		for(w=0;w<j;w++)
		{
			b[w]++;
		}
	}//补全最后一位的计数 
*/	
	for(j=i-1;j>0;j--) 
	{
		for(w=0;w<10;w++)
		{
			b[w]+=(a[i-1])*jie10(i-2);
			b[w]+=jie(i-1,a[i-1]-1);
		}
	}
	//从最高位开始分组补全
/*	for(j=0;j<9;j++)
	{
		for(w=1;w<=i-1;w++)
		{
			b[j]+=((a[w-1])*jie9(w-1));
		}
	}
*/
	//每百位里个数位补全	
	printf("输出各数字使用频率:\n");
	for(j=0;j<10;j++)
	printf("%d\t%d\n",(j+1)%10,b[j]);
	return 0;
} 