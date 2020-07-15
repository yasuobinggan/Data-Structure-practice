#include<stdio.h>
/*
void s(int *a)
{
	*a=10;
}
int main()
{
	int a=5;
	int *p;
	p=&a; 
	s(p);
	printf("%d",a);
	return 0;
}
*/
void s(int *a)
{
	*a=10;
}
int main()
{
	int a=5;
	s(&a);
	printf("%d",a);
} 