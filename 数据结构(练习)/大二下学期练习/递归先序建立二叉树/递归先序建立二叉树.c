#include<stdio.h>
#include<stdlib.h>
typedef struct btnode{
	char data;
	struct	btnode *lbt;
	struct 	btnode *rbt;
}btnode,*btree;
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
void travel(btree tree)
{
	if(!tree)return;
	
		printf("%c",tree->data);
		travel(tree->lbt);
		travel(tree->rbt);
	
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
	travel(tree);
	//xxtrtree(tree); 
	return 0;
 } 

