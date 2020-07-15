#include<stdio.h>
#include<stdlib.h>
#define m 32
typedef struct btnode{
	int data;
	struct	btnode *lbt;
	struct 	btnode *rbt;
}btnode,*btree;
typedef struct{
	btree *top;
	btree *base;
}sqstack;
void initsq(sqstack &s)
{
	s.base=(btree *)malloc(m*sizeof(btree));
	if(!s.base)printf("wrong");
	s.top=s.base;
}
void pusq(sqstack &s,btree e)
{
     *s.top++=e; 
}
void posq(sqstack &s,btree &e)
{
	if(s.top==s.base)
	{
		printf("wrong");
		return;
	}
	e=*--s.top;
}
void createtree(btree &tree)
{
	int e;
	scanf("%d",&e);
	if(e==0)tree=NULL;//return;
	else
	{
		tree=(btree)malloc(sizeof(btnode));
		tree->data=e; 
		createtree(tree->lbt);
		createtree(tree->rbt);
	}
}
void max(btree tree,btree &s)
{
	sqstack sq;
	btree p;
	p=tree;
	initsq(sq);
	while(sq.top!=sq.base||p)
	{
		if(p)
		{
			pusq(sq,p);
			if(p->data>s->data)
				s->data=p->data;
			p=p->lbt;	
		}
		else
		{
			posq(sq,p);//左端节点出栈
			p=p->rbt;
		}	
	}
}
void max1(btree tree,btree &s)
{
	if(!tree)
		return;
	else if(tree->data>s->data)
		s->data=tree->data;
	max1(tree->lbt,s);
	max1(tree->rbt,s);	
}
int main()
{
	btree tree;btree s;
	s=(btree)malloc(sizeof(btnode));
	s->data=0;
	printf("创造二叉树:\n");
	createtree(tree);
	//max(tree,s);
	max1(tree,s);
	printf("%d",s->data);	 
	return 0;
 } 

