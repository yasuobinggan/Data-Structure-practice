#include<stdio.h>
#include<stdlib.h>
#define tasize 10
typedef struct{
	int *base;
	int *top;	
}ta;
void createta(ta &t)
{
	t.base=(int *)malloc(tasize*sizeof(int));
	if(!t.base)return;
	t.top=t.base; 
}
void createinta(ta &t,int n)
{
	if(n>0)
	{
		*t.top++=n;
		createinta(t,n-1);
	}
	if(n=0)return;
}
void createinta1(ta &t)
{
	*t.top++=6;
} 
int main()
{
	ta t;int e,y;
	int i;
	createta(t);
	//for(i=1;i<=6;i++)
	//createinta(t,i);
	createinta(t,3);
	
	//createinta1(t);
	//e=*--t.top;
	//y=*t.base;
	printf("输出塔的层数%d\n",t.top-t.base);
	e=*--t.top;
	printf("输出塔顶数据:%d\n",*(t.top-1));
	return 0;
}