#include<stdio.h>
#include<stdlib.h>
#define m 10
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
	if(s.top==s.base)printf("wrong");
	e=*--s.top;
}

void travelsq(sqstack s)
{
	btree *i;
	printf("\n输出二叉树路径:\n");
	for(i=s.base;i<s.top;i++)
		printf("%d",(*i)->data);
}
void createtree(btree &tree)
{
	int e;
	scanf("%d",&e);
	if(e==0)tree=NULL;
	else
	{
		tree=(btnode *)malloc(sizeof(btnode));
		tree->data=e;
		createtree(tree->lbt);
		createtree(tree->rbt);
	} 
}
void retravel(btree tree)
{
	sqstack sq;
	btree p;
	p=tree;
	initsq(sq);
	while(sq.top!=sq.base||p)//p控制根节点入栈 
	{
		if(p)
		{
			printf("%d ",p->data);
			pusq(sq,p);	
			p=p->lbt;		
		}
		else
		{
			posq(sq,p);//左端节点出栈 
			p=p->rbt;//右子树压栈 
		}
	}
}
void travel(btree tree)
{
	if(!tree)return;
	printf("%d",tree->data);
	travel(tree->lbt);
	travel(tree->rbt);
}
int main()
{
	btree tree;
	printf("输入字符创建二叉树:\n");
	createtree(tree);
	retravel(tree);
	printf("先序遍历验证\n");
	travel(tree);
	return 0;
}