#include<stdio.h>
#include<stdlib.h>
typedef struct lnode{
	int data;
	struct lnode *prioir;
	struct lnode *next;
}lnode,*linklist;
void creatlinklist(linklist &l)
{
	int i,j;linklist p,s;
	l=(linklist)malloc(sizeof(lnode));
	s=(linklist)malloc(sizeof(lnode));
	l->next=s;l->prioir=NULL;
    s->prioir=l;s->next=NULL; 
	printf("输入尾节点数据:\n");
	scanf("%d",&s->data);
	printf("输入剩余要输入的数据数量:\n");
	scanf("%d",&i);
	printf("输入数据:\n");
	for(j=1;j<=i;j++)
	{
		p=(linklist)malloc(sizeof(lnode));
		scanf("%d",&p->data);
		p->next=l->next;
		l->next=p; 
		
	}
		
}  
int main()
{
	linklist l;
	creatlinklist(l);
	while(l->next)
	{
		printf("%d ",l->next->data);
		l=l->next
	}
	return 0;
} 