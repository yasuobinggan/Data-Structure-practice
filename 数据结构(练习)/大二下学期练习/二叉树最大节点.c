#include<stdio.h>
#include<stdlib.h>
typedef struct btnode{
	char data;
	struct	btnode *lbt;
	struct 	btnode *rbt;
}btnode,*btree;
int i=0;
void createtree(btree &tree)
{
	char e;
	scanf("%c",&e);
	if(e=='#')tree=NULL;
	else
	{
		tree=(btnode *)malloc(sizeof(btnode));
		tree->data=e; 
		createtree(tree->lbt);
		createtree(tree->rbt);
	}
}
void travel(btree tree,char a[100])
{
	if(!tree)return;
	a[i]=tree->data;
	i++; 
	travel(tree->lbt,a);
	travel(tree->rbt,a);
}
int main()
{
	btree tree;
	char max[100],j;
	printf("´´Ôì¶ş²æÊ÷:\n");
	createtree(tree);
	travel(tree,max);
	for(j=0;j<i;j++)
	printf("%c\t",max[j]);
	return 0;
 } 

