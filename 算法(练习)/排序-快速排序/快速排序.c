#include<stdio.h>
#define max 100
void createarray(int a[],int n)
{
	int i;
	printf("输入%d个数据:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}
void quick_sort1(int a[],int &key_n,int start,int end)//快速排序中的一趟排序//排序就是处理一段数组中不符合排序规则的数组段 
{
	int i,j;
	int key,temp;
	//int key,key_n,temp;
	int flag=0;
	key=a[start];
	key_n=start;
	i=start;j=end;
	while(i<j)
	{
		if(flag==0)
		{
			if(a[j]<key)
			{
				temp=a[j];
				a[j]=a[key_n];
				a[key_n]=temp;
				key_n=j;
				flag=1;
			}
			else
				j--;
		}
		if(flag==1)
		{
			if(a[i]>key)
			{
				temp=a[i];
				a[i]=a[key_n];
				a[key_n]=temp;
				key_n=i; 
				flag=0;
			}
			else
				i++;
		}		
	} 
}
void quick_sort(int a[],int key_n,int start,int end)
{
	if(start<end)
	{
		quick_sort1(a,key_n,start,end);
		quick_sort(a,key_n,start,key_n-1);
		quick_sort(a,key_n,key_n+1,end);	
	}
} 
void printarray(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
int main()
{
	int n,a[max];
	printf("输入数组的长度:\n");
	scanf("%d",&n);
	createarray(a,n);
	//quick_sort1(a,0,n-1);//验证一趟排序的正确性 
	quick_sort(a,0,0,n-1);//开始坐标,结束坐标
	printarray(a,n); 
	return 0;
}
// 