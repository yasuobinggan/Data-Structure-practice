#include<stdio.h>
#include<stdlib.h>
typedef struct lnode{
	int data;
	struct lnode *next;
}lnode,*link;
void createlink(link &l,int n)
{
	int i;link s;link p;
	l=(link)malloc(sizeof(lnode));
	l->next=NULL;
	s=l;
	printf("输入%d个数据\n",n);
	for(i=0;i<n;i++)
	{
		p=(link)malloc(sizeof(lnode));
		scanf("%d",&p->data);
		p->next=s->next;
		s->next=p;
		s=p;
	}
}
void criclelink(link &l,int k)
{
	if(k==0)
		return;
	link w;
	link p;
	w=l->next;
	while(w->next->next)
	{
		w=w->next;
	}
	p=w->next;
	w->next=NULL;
	p->next=l->next;
	l->next=p;
	criclelink(l,k-1);
}
/*
void criclelink(link &l,int k)//循环解决 
{
	//if(k==0)
	//	return;
	link w;
	link p;
	while(k>0)
	{
		w=l->next;
		while(w->next->next)
		{
			w=w->next;
		}
		p=w->next;
		w->next=NULL;
		p->next=l->next;
		l->next=p;
		k--;
	}
	//criclelink(l,k-1);
}
*/
void travellink(link l)
{
	link p;
	p=l->next;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;		
	}
}
/*
void travellink1(link l)
{
	link p;
	p=l->next;
	while(p->next->next)
	{
		p=p->next;		
	}
	printf("%d ",p->data);
}  
*/  
int main()
{
	link l;
	int n,k;
	printf("输入创建链表的长度:\n");
	scanf("%d",&n);
	createlink(l,n);
	printf("输入旋转链表的长度:\n");
	scanf("%d",&k);
	criclelink(l,k);
	printf("输出链表:\n");
	travellink(l);
	//travellink1(l);
	return 0;
}