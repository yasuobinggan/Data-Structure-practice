#include<stdio.h>
#include<stdlib.h>
#define m 32
typedef struct lnode{
	int ldata;
	struct lnode *next;
}lnode,*link;
void createzlink(link &l)
{
	int i;int data;link p,q;
	l=(link)malloc(sizeof(lnode));
	l->next=NULL;
	q=(link)malloc(sizeof(lnode));
	l=q;	
	p=(link)malloc(sizeof(lnode));
	p->next=l->next;
	l->next=p;
	//p->next=NULL;

	printf("输入数据:\n");
	
	scanf("%d",&p->ldata);
	
	printf("输出:\n");		//q=p;
	printf("%d",q->ldata);

}
int main()
{
	link l;
	createzlink(l);
	return 0;
}