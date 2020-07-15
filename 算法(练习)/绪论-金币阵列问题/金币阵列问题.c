#include<stdio.h>
#include<stdlib.h>
#define m 4
#define n 3
void createma(int a[m][n])
{
	int i,j;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
}
void printfma(int a[m][n])
{
	int i,j,count=0;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			{
				printf("%d\t",a[i][j]);
				count++;
				if(count%n==0)
				printf("\n");
			}
	printf("\n");
}
void inversion(int i,int a[m][n])
{
	int j;
	for(j=0;j<n;j++)
	{
		if(a[i][j]==0)a[i][j]=1;
		if(a[j][i]==1)a[j][i]=0;	
	}
}//倒置函数 
void swap(int hang,int i,int j,int a[m][n])
{
	int w,b[m];
	for(w=0;w<m;w++)
		b[w]=a[w][i];
	for(w=0;w<m;w++)
		a[w][i]=a[w][j];
	for(w=0;w<m;w++)
		a[w][j]=b[w];				
}//两列置换，思考用每行的排列组合解决
int sub(int hang,int a[m][n],int b[m][n])
{
	int i,j;int count=0;
	for(i=0;i<n;i++)
	{
		if(b[hang][i]==0&&a[hang][i]==1)
		for(j=i+1;j<n;j++)
	 	{
		 	if(a[hang][j]==0&&b[hang][j]==1)
			{
				swap(hang,i,j,a);
				count++;
				break;
			} 
	 	} 
	}
	return count;
}
int compare(int a[m][n],int b[m][n])
{
	int i,j,count=0;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(a[i][j]==b[i][j])
				count++;
	if(count==m*n)
		return 1;
	else
		return 0;
} 
int find(int a[m][n],int b[m][n])
{
	int i,j,k=0,com,count,countk=0,counta0=0,counta1=0,countb0=0,countb1=0,countstep=0,countstepsum=0,w[m]; 
	for(i=0;i<m;i++)
	{
		count=0;
		for(j=0;j<n;j++)
			{
				if(a[i][j]==b[i][j])
					count++;
			}
		if(count!=n)
		{			
			w[k]=i;
			k++;
		}
	}
	countk=k;k=0;count=0;//记录原阵列与目标阵列不相同的行 
	for(k=0;k<countk;k++)
		for(j=0;j<n;j++)
			printf("%d\t",a[w[k]][j]); 
	for(k=0;k<countk;k++)//寻找主体 
	{
		counta0=0;counta1=0;countb1=0;countb0=0;	
		for(j=0;j<n;j++)
		{
			if(a[w[k]][j]==0)counta0++;
			if(a[w[k]][j]==1)counta1++;
			if(b[w[k]][j]==1)countb1++;
			if(b[w[k]][j]==0)countb0++;
		}
		printf("行号%d\t%d\t%d\t%d\t%d\t%d\t%d\n",w[k],counta0,counta1,countb0,countb1,counta0+countb1,n);
		if((counta0+countb1==n)||counta0==countb1||counta1==countb0)
		{
			if(counta0==countb0)
			{
				countstep+=sub(w[k],a,b);
			}
			else if(counta0!=countb0)
			{
				inversion(i,a);countstep++;
				countstep+=sub(w[k],a,b);
			}
		}	
		else if(counta0+countb1!=n)
		{printf("\n没有方法达成目标阵列!");return -1;}
	}
	com=compare(a,b);
	if(com==0)
	{printf("\t没有方法达成目标阵列!");return -1;}
	countstepsum+=countstep;
	return countstepsum;
}	 
int main()
{
	int a[m][n],b[m][n];
	printf("创建矩阵:\n");createma(a);
	printf("创建矩阵:\n");createma(b);
	printf("原金币矩阵:\n");printfma(a);
	printf("目标金币矩阵:\n");printfma(b);
	printf("输出最短移动次数:\n");
	printf("%d\n",find(a,b));
	return 0;
} 
//置换列的最短规则，置换后判断是否与原数组相等 