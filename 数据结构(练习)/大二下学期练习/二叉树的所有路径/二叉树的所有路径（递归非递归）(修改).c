#include<stdio.h>
#include<stdlib.h>
#define m 10
int n=0;
typedef struct btnode{
	int data;
	struct btnode *lbt;
	struct btnode *rbt;
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
void gettop(sqstack s,btree &e)
{
	e=*(s.top-1);
}
void pop(sqstack &s,btree &e)
{
	if(s.top==s.base)
	{
		printf("wrong");
		return;
	}
	s.top=s.top-2;
	e=*s.top;
}
void travelsq(sqstack s)
{
	btree *i;
	printf("\n输出二叉树路径:\n");
	for(i=s.base;i<s.top;i++)
		printf("%d\t",(*i)->data);
}
void createtree(btree &tree)
{
	int e;
	scanf("%d",&e);
	if(e==0)tree=NULL;
	else
	{
		tree=(btree)malloc(sizeof(btnode));
		tree->data=e;
		createtree(tree->lbt);
		createtree(tree->rbt);
	} 
}
void allpath(btree tree)
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
			if(!p->lbt&&!p->rbt)
			{
				travelsq(sq);
			}
			p=p->lbt;	
		}
		else
		{
			gettop(sq,p);//左端节点出栈
			p=p->rbt;
			if(!p);
			pop(sq,p);			
		}	
	}
}
void travel(int path[],int n)
{
	int i;
	printf("\n输出二叉树的一条路径:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",path[i]);
	} 
}
void allpath1(btree tree,int path[],int n)
{
	if(tree==NULL)
	{
		//n--;
		return;
	}
	else
	{
		if(!tree->lbt&&!tree->rbt)
		{
			travel(path,n);
		}
		else
		{
			path[n]=tree->data;
			n++;
		}
	}
	allpath1(tree->lbt,path,n);
	allpath1(tree->rbt,path,n);
}
int main()
{
	btree tree;
	int path[10];
	printf("输入数字创建二叉树:\n");
	createtree(tree);
	allpath(tree);
	//allpath1(tree,path,n);
	return 0;
}