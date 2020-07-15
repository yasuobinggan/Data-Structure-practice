#include<stdio.h>
#include<stdlib.h>
#define m 32
typedef struct btnode{
	int tdata;
	struct btnode *lbt;
	struct btnode *rbt;
}btnode,*btree;
typedef struct{
	btree data[m];
	int front;
	int rear;
}qu;
void createqu(qu &queue)
{
	queue.front=queue.rear=0;
}
void enqu(qu &queue,btree &e)
{
	queue.data[queue.rear]=e;
	queue.rear=(queue.rear+1)%m; 
}
void dequ(qu &queue,btree &e)
{
	e=queue.data[queue.front];
	queue.front=(queue.front+1)%m;
}
btree topqu(qu queue)
{
	btree e;
	e=queue.data[queue.front];
	queue.front=(queue.front+1)%m;
	return e;
}
void createtree(btree &tree)
{
	int e;
	scanf("%d",&e);
	if(e==0)tree=NULL; 
	else
	{
		tree=(btree)malloc(sizeof(btnode));
		tree->tdata=e;
		createtree(tree->lbt);
		createtree(tree->rbt);		
	} 
}
 
void change(btree &tree)
{
	btree temp;
	temp=NULL;
	temp=tree->lbt;
	tree->lbt=tree->rbt;
	tree->rbt=temp;
}
void change_tree1(btree &tree)
{
	qu queue;
	btree p;
	createqu(queue);
	enqu(queue,tree);
	while(queue.front!=queue.rear)
	{
		dequ(queue,p);
		change(p);
		if(p->lbt) enqu(queue,p->lbt);
		if(p->rbt)enqu(queue,p->rbt);
	}
}
void midtravel(btree tree)
{
	if(!tree)return;
	midtravel(tree->lbt);
	printf("%d\t",tree->tdata);
	midtravel(tree->rbt);
} 
int main()
{
	btree tree;
	printf("输入数据先序建立二叉树:\n");
	createtree(tree);
	change_tree1(tree); 
	printf("中序输出验证结果:\n");
	midtravel(tree);
	return 0;
}