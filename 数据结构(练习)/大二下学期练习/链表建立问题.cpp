#include<stdio.h>
#include<stdlib.h>
typedef struct lnode
{
	int data;
	struct lnode *next;
}lnode;
int main()
{
	lnode *l,*p;
	lnode *flag;
	l=(lnode *)malloc(sizeof(lnode));
	l->next=NULL;
	p=l;
	p->data=1;
	p=p->next;
	p=(lnode *)malloc(sizeof(lnode));
	p->data=2;
	p->next=NULL;
	flag=l;
	while(flag)
	{
		printf("%d",flag->data);
		flag=flag->next;	
	}
	
	return 0;
} 