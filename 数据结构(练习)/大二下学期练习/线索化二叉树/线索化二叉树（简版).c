#include<stdio.h>
#include<stdlib.h>
typedef struct bitnode{
	char data;
	struct bitnode *lbt,*rbt;
	int lflag,rflag;//1表示有子树,0表示有前驱,后继 
}bitnode,*bitree;
void createtree(bitree &tree)
{
	char p;
	scanf("%c",&p);
	if(p=='#')tree=NULL;
	else
	{
		tree=(bitree)malloc(sizeof(bitnode));
		tree->data=p;
		tree->lflag=1;
		createtree(tree->lbt);
		tree->rflag=1;		
		createtree(tree->rbt);
	}
}
void xianthreading(bitree tree)
{
	if(tree)
	{
		if(tree->lbt==NULL)
		{
			tree->lflag=0;			
		}
		else
			xianthreading(tree->lbt);
		if(tree->rbt==NULL)
		{
			tree->rflag=0;
		}
		else
			xianthreading(tree->rbt);
	} 
} 
void travel(bitree tree)
{
	if(!tree)return;
	
		printf("%c:%d,%d\t",tree->data,tree->lflag,tree->rflag);
		travel(tree->lbt);
		travel(tree->rbt);
} 
int main()
{
	bitree tree;
	createtree(tree);
	xianthreading(tree);
	travel(tree);
	return 0;
} 