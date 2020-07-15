#include<stdio.h>
int w=0;
int fa(int x,int y)//x~y 
{
	int i,sum=1;
	for(i=0;i<y;i++)
		sum*=x;
	return sum;
}
void re(int n)
{
	int i;
	if(w==n)
		return;
	for(i=fa(10,w);i<=(fa(10,w+1)-1);i++)
		printf("%d\t",i);
	w++;
	return re(n);
}
int main()
{
	int n;
	printf("输入n的值表示位数:\n");
	scanf("%d",&n);
	re(n);	
	return 0;
}