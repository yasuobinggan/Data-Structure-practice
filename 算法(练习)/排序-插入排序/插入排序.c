#include<stdio.h>
void createarray(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void insert_sort(int a[],int n)
{
	int i,j,k,w;
	int x; 
	for(i=0;i<=n-2;i++)
	{
		j=i+1;
		x=a[j];
		for(k=0;k<=i;k++)
		{
			if(x<a[k])
			{
				for(w=i;w>=k;w--)
				{
					a[w+1]=a[w];
				}
				a[k]=x;
				break;
			}
		}
	}
}
void insert_sort1(int a[],int n)
{
	int i,j,w;
	int x; 
	for(i=0;i<=n-2;i++)
	{
		j=i+1;x=a[j];
		for(w=i;w>=0;w--)
		{
			if(x<a[w])
			{
				a[w+1]=a[w];
			}
			else
			{
				break;
			}
		}
		a[w+1]=x;//小循环体内可不可以 
	}
}
void print(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
} 
int main()
{
	int n,a[20];
	printf("输入要输入的数据数量:\n");
	scanf("%d",&n);
	printf("输入要排序的数组:\n");
	createarray(a,n);
	//insert_sort(a,n);
	insert_sort1(a,n);
	printf("输出排序后的数组:\n");
	print(a,n);
	return 0;
}
