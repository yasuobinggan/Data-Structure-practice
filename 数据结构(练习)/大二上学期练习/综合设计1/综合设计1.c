#include<stdio.h>
#include<stdlib.h> 
#include<malloc.h>
#define m 10
typedef struct{
	int *elem;
	int *p;
	int length;
	int listsize;
}sqlist;
int main()
{
	sqlist l1,l2,lc;
	int i;int count=1;
	int *pa,*pb,*pa1,*pb1,*pc,*pc1,*pa_last,*pb_last;
	l1.elem=(int *)malloc(m*sizeof(sqlist));
    l1.p=(int *)malloc(m*sizeof(sqlist));
	if(!l1.elem)printf("wrong");
	l1.length=0;
	l1.listsize=m;
    printf("输入一元多项式的系数和指数：\n");
    for(i=1;i<=5;i++)
    {
    	scanf("%d",&l1.p[i-1]);
    	scanf("%d",&l1.elem[i-1]);
   		l1.length++;
   	}
   	 printf("输出:\n");
	for(i=1;i<=l1.length;i++)
	{
		if(i!=l1.length)
			printf("%dx%d+",l1.p[i-1],l1.elem[i-1]);
		else
			printf("%dx%d",l1.p[i-1],l1.elem[i-1]);
	}
    printf("\n————————————————————\n");
    l2.elem=(int *)malloc(m*sizeof(sqlist));
    l2.p=(int *)malloc(m*sizeof(sqlist));
	if(!l2.elem)printf("wrong");
	l2.length=0;
	l2.listsize=m;
    printf("输入一元多项式的系数和指数：\n");
    for(i=1;i<=5;i++)
    {
    	scanf("%d",&l2.p[i-1]);
   		scanf("%d",&l2.elem[i-1]);
   		l2.length++;
   	}
   	for(i=1;i<=l1.length;i++)
	{
		if(i!=l1.length)
			printf("%dx%d+",l2.p[i-1],l2.elem[i-1]);
		else
			printf("%dx%d",l2.p[i-1],l2.elem[i-1]);
	}
	pa=l1.elem;pb=l2.elem;
	pa1=l1.p;pb1=l2.p;
	lc.listsize=lc.length=l1.length+l2.length;
	pc=lc.elem=(int *)malloc(lc.listsize*sizeof(sqlist));
	pc1=lc.p=(int *)malloc(lc.listsize*sizeof(sqlist));
	if(!lc.elem)printf("wrong");
    pa_last=l1.elem+l1.length-1;
	pb_last=l2.elem+l2.length-1;
	while(pa<=pa_last&&pb<=pb_last)
	{
		if(*pa==*pb)
	   {
		*pc++=*pa++;
		*pc1=*pa1+*pb1;
		pb++;
		pc1++;
		pa1++;
		pb1++;
		count++;
	    }
		else if(*pa<*pb)
	   {    *pc++=*pa++;
			*pc1++=*pa1++;count++;
	   }
		else
	    {    *pc++=*pb++;
			 *pc1++=*pb1++;
			 count++;
		}
	}
	while(pa<=pa_last){*pc++=*pa++;*pc1++=*pa1++;}
	while(pb<=pb_last){*pc++=*pb++;*pc1++=*pb1++;}
	printf("\n输出相加后的多项式:\n");
	for(i=1;i<=count+1;i++)
	{
		if(i!=count+1)
			printf("%dx%d+",lc.p[i-1],lc.elem[i-1]);
		else
			printf("%dx%d",lc.p[i-1],lc.elem[i-1]);
	}
	return 0;
}