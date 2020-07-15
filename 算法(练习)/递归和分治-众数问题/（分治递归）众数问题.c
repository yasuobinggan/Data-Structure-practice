#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int v;
	int c;	
}z;
void seek(int a[10])//递归求解 
{
	
}
void seek1(z a[10])
{
	/* 
	int i,j=0,k;
	z b[10],temp;
	for(i=0;i<10;i++)
	{
		if(a[i]==a[0]||a[i]!=a[i-1])
		{
			b[j].v=a[i];
			j++;
		}
	}
	for(i=0;i<j;i++)
		b[i].c=0;
	for(k=0;k<j;k++)
	{
		for(i=0;i<10;i++)
		{
			if(a[i]==b[k].v)
			{
				b[k].c++;
			}
		} 
	}
	for(i=0;i<j-1;i++)
	{ 
		for(k=0;k<j-1-i;k++)
		{
			if(b[k].c<b[k+1].c)
			{
				temp=b[k];
				b[k]=b[k+1];
				b[k+1]=temp;
			}
			
		}
	}
	printf("众数%d重数%d",b[0].v,b[0].c);
	*/
	int i,j;z temp;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(a[i].v==a[j].v)
				a[i].c++;
		}
	}
	for(i=0;i<10-1;i++)
	{ 
		for(j=0;j<10-1-i;j++)
		{
			if(a[j].c<a[j+1].c)
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
			
		}
	}
	printf("众数%d重数%d",a[0].v,a[0].c);	
		 
}
int main()
{
	z a[10];int i;
	printf("输入十个整数:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i].v);
		a[i].c=0;
	}	
	seek1(a);//非递归 
	//seek(a);
	return 0;
} 