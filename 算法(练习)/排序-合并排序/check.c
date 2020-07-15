#include<stdio.h>

void mergearray(int a[], int s, int mid, int e)
{
	//int c[m];
	int i = 0, j = 0, k;
	int b[100];
	int a_length = 0, b_length = 0;
	//copy(a,e-s+1,c);
	for (i = mid + 1; i <= e; i++)
	{
		b[b_length] = a[i];
		b_length++;
	}
	a_length = mid - s + 1;
	//插入有序数组 
	/*
	*/
	while (j <= b_length - 1)//可优化 
	{
		if (b[j]>a[a_length - 1])
		{
			a[a_length] = b[j];
			a_length++;
		}
		else
		{
			for (i = 0; i<a_length; i++)
			{
				if (b[j] <= a[i])
				{
					for (k = a_length - 1; k >= i; k--)
						a[k + 1] = a[k];
					a[i] = b[j];
					a_length++;
					break;
				}
			}
		}
		j++;
	}
}
void printarray(int a[], int n)
{
	int i;
	for (i = 0; i<n; i++)
		printf("%d ", a[i]);
}
int main()
{
	int a[100] = {5,6,7,9,12,1,2,3,4};//, b[10] = {3,4,9,11,14,18};
	//int a_length=3;
	mergearray(a,0,4,8);
	printarray(a,9);
}