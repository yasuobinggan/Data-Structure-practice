#include<stdio.h>
#include<stdlib.h>
typedef struct lnode{
	int data;
	struct lnode *next;
}lnode,*linklist;
void creatlinklist(linklist &l)
{
	int i,n;linklist p;
	&l=(linklist)malloc(sizeof(lnode));
	l->next=NULL;
	printf("输入链表数据长度:\n");
	scanf("%d",&n);
	printf("输入数据:\n"); 
	for(i=1;i<=n;i++)
	{
		p=(linklist)malloc(sizeof(lnode));
		scanf("%d",&p->data);
		p->next=l->next;
		l->next=p;
}
}
void deletelinklist(linklist &l)
{
	int i,j;linklist p,q;
	int e;
	p=(linklist)malloc(sizeof(lnode));
	q=(linklist)malloc(sizeof(lnode));
	p=l;
	printf("输入要删除数据顺序数:\n");
	scanf("%d",&i);
	for(j=1;j<i;j++)
	{
		p=p->next;
	}
	q=p->next;
	p->next=q->next;
	e=q->data;
	free(q); 
	
}
int main()
{
	linklist l;int i;linklist p;
	creatlinklist(l);
	p=l->next;
	for(i=0;i<5;i++)
	{
		printf("%d ",p->data);
	    p=p->next;
	}
	deletelinklist(l);
	p=l->next;
	for(i=0;i<5;i++)
	{
		printf("%d ",p->data);
	    p=p->next;
	}

	return 0;
} 