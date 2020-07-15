#include<stdio.h>
#include<stdlib.h>
#define m 100
//int i=0;全局变量 
void createarray(int a[], int n)
{
	int i;
	for (i = 0; i<n; i++)
		scanf_s("%d", &a[i]);
}
/*
void mergearray(int a[],int &a_length,int b[],int &b_length)
{
int i=0,j=0;
int k;
while(j<=b_length-1)
{
if(b[j]>a[a_length-1])
{
a[a_length]=b[j];
a_length++;
}
else
{
for(i=0;i<a_length;i++)
{
if(b[j]<=a[i])
{
for(k=a_length-1;k>=i;k--)
a[k+1]=a[k];
a[i]=b[j];
a_length++;
break;
}
}
}
j++;
}
}
*/
void copy(int a[], int a_length, int b[])
{
	int i, j = 0;
	for (i = 0; i<a_length; i++)
	{
		b[j] = a[i];
		j++;
	}
}
void mergearray(int a[], int s, int mid, int e)
{
	int i = 0, j = 0, k;
	int b[m];
	int a_length = 0, b_length = 0;
	for (i = mid + 1; i <= e; i++)
	{
		b[b_length] = a[i];
		b_length++;
	}
	a_length = mid - s + 1;
	while (j <= b_length - 1)//可优化，将第一层if放入第二层循环中
	{
		if (b[j]>a[mid])//？
		{
			a[mid+1] = b[j];
			mid++;
		}
		else
		{
			for (i = s; i <= mid; i++)
			{
				if (b[j] <= a[i])
				{
					for (k = mid; k >= i; k--)
						a[k + 1] = a[k];
					a[i] = b[j];
					mid++;
					break;
				}
			}
		}
		j++;
	}
}
void mergesort(int a[], int s, int e)
{
	//int k;
	int mid;
	//int p1[m],p2[m],p1_length=0,p2_length=0;
	mid = (s + e) / 2;//mid中间点 
	if (s<e)//if(p1_length<=1||p2_length<=1)//if((p1_length==1&&p2_length==1)||(p1_length==1&&p2_length=0)||(p1_length=0&&p2_length=1))
	{
		/*
		for(k=s;k<=mid;k++)
		{
		p1[p1_length]=a[k];
		p1_length++;
		}
		for(k=mid+1;k<=e-1;k++)
		{
		p2[p2_length]=a[k];
		p2_length++;
		}
		mergesort(p1,s,mid);
		mergesort(p2,mid+1,e);
		mergearray(p1,p1_length,p2,p2_length);
		*/
		mergesort(a, s, mid);
		mergesort(a, mid + 1, e);
		mergearray(a,s,mid,e);
		//递归具有参数按层的规律
	}
	//mergearray(a, s, mid, e);
}

void printarray(int a[], int n)
{
	int i;
	for (i = 0; i<n; i++)
		printf("%d ", a[i]);
}
int main()
{
	int a[m], n;
	printf("输入数组的长度:\n");
	scanf_s("%d", &n);
	printf("输入数据创建数组:\n");
	createarray(a, n);
	mergesort(a, 0, n-1);
	printf("输出排序后的数组:\n");
	printarray(a, n);
	return 0;
}