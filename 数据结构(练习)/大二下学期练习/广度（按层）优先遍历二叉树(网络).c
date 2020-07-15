#include<stdio.h>
#include<stdlib.h>
#define m 100
typedef struct btnode{
	char data;
	struct	btnode *lbt;
	struct 	btnode *rbt;
}btnode,*btree;
typedef struct{
	btree *top;
	btree *base;
}sq;
void createtree(btree &tree)
{
	char e;
	//printf("输入字符\n");
	scanf("%c",&e);
	if(e=='#')tree=NULL;//return;
	else
	{
		tree=(btnode *)malloc(sizeof(btnode));
		tree->data=e; 
		createtree(tree->lbt);
		createtree(tree->rbt);
	}
}
void initsq(sq &s)
{
	s.base=(btree *)malloc(m*sizeof(btree));
	if(!s.base)printf("wrong");
	s.top=s.base;
}
void push(sq &s,btree e)
{
     *s.top++=e; 
}
int emptysq(sq s)
{
	if(s.base==s.top)
		return 0;
	else
		return 1;
}
btree gettop(sq &s,btree &e)
{
	if(s.top==s.base)printf("wrong");
	e=*(s.top-1);
	return e;
} 
void travel(btree tree)
{
	if(!tree)return;
	
		printf("%c",tree->data);
		travel(tree->lbt);
		travel(tree->rbt);
	
}
int print_at_level(btree T, int level)//level为当前层数 
{
	if (!T || level < 0)
		return 0;
	if (0 == level) {
		printf("%c",T->data);
		return 1;
	}
	return print_at_level(T->lbt, level - 1) + print_at_level(T->rbt, level - 1);
}
void print_by_level_1(btree T) {
	int i = 0; 
	for (i = 0; ; i++)//从第一层遍历 
 	{
		if (!print_at_level(T, i))
			break;
	}
	printf("\n");
}
void xxtrtree(btree tree)//深度优先遍历二叉树 
{
	//printf("输出当前层的字符:\n");
	if(tree==NULL)return;
	printf("%d\n",tree->data); 
	if(tree->lbt!=NULL)
		xxtrtree(tree->lbt);
	if(tree->rbt!=NULL)
		xxtrtree(tree->rbt);
	
}
int main()
{
	btree tree;
	printf("创造二叉树:\n");
	createtree(tree);
	print_by_level_1(tree); 
	return 0;
 } 

