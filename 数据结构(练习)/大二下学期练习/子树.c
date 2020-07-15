#include<stdio.h>
#include<stdlib.h>
typedef struct btnode{
	int data;
	struct	btnode *lbt;
	struct 	btnode *rbt;
}btnode,*btree;
void createtree(btree &tree)
{
	int e;
	scanf("%d",&e);
	if(e==0)tree=NULL;//return;
	else
	{
		tree=(btnode *)malloc(sizeof(btnode));
		tree->data=e; 
		createtree(tree->lbt);
		createtree(tree->rbt);
	}
}
void findroot(btree tree1,btree &p,int data)
{
	if(tree1)
	{
		if(tree1->data==data)
		{
			p=tree1;
			return;
			//exit(0);
		}	
		findroot(tree1->lbt,p,data);
		findroot(tree1->rbt,p,data);
	}	
}
void checktravel(btree p,btree tree2)
{
	if(p&&tree2)
	{
		if(p->data==tree2->data)
		{
			checktravel(p->lbt,tree2->lbt);
			checktravel(p->rbt,tree2->rbt);	
		}
		else
		{
			printf("树2不是树1的子树!");
			exit(0); 
		}
	}
	else if(!p&&!tree2)
	{
		printf("树2是树1的子树");
		exit(0);
	}
	else if(p&&!tree2)
	{
		printf("树2是树1的子树");
		exit(0);
	}
	else
	{
		printf("树2不是树1的子树!");
		exit(0);
	}
} 
int main()
{
	btree tree1,tree2;
	btree p;
	printf("创造二叉树1:\n");
	createtree(tree1);
	printf("创造二叉树2:\n");
	createtree(tree2);
	findroot(tree1,p,tree2->data);
	//printf("%d",p->data);
	checktravel(p,tree2);
	return 0;
 } 

