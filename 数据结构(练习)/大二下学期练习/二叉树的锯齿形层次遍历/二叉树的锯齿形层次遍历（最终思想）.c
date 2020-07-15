#include<stdio.h>
#include<stdlib.h>
#define m 32
typedef struct btnode{
	int tdata;
	int flag; 
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
void enqu(qu &queue,btree e)
{
	queue.data[queue.rear]=e;
	queue.rear=(queue.rear+1)%m; 
}
void dequ(qu &queue,btree &e)
{
	e=queue.data[queue.front];
	queue.front=(queue.front+1)%m;
}
void inverqu(qu &queue)
{
	btree temp;int i,mid;
	mid=(queue.rear-1+queue.front)/2;
	for(i=queue.front;i<=mid;i++)
	{
		temp=queue.data[i];
		queue.data[i]=queue.data[queue.rear-i];
		queue.data[queue.rear-i]=temp;
	}
} 
btree topqu(qu queue)
{
	btree e;
	e=queue.data[queue.front];
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
		tree->flag=0;
		createtree(tree->lbt);
		createtree(tree->rbt);		
	} 
}
void traveltree(btree &tree)//验证函数//逆置队列出现问题//双向队列 
{
	qu queue;
	btree p;btree q;//q获取出队列元素（父节点） 
	btree w; 
	createqu(queue);
	enqu(queue,tree);
	p=topqu(queue);
	p->flag=1;
	while(queue.front!=queue.rear)
	{
		dequ(queue,p);
		printf("%d\t",p->tdata);
		q=p;
		w=topqu(queue);//取栈顶 
		if(p->flag%2!=0)
		{
			if(w->flag==p->flag)
			{
				if(p->lbt)
				{
					p->lbt->flag=q->flag+1;
					enqu(queue,p->lbt);							
				}
				if(p->rbt)
				{
					p->rbt->flag=q->flag+1;
					enqu(queue,p->rbt);
				}		
			}
			else
			{
				if(p->lbt)
				{
					p->lbt->flag=q->flag+1;
					enqu(queue,p->lbt);							
				}
				if(p->rbt)
				{
					p->rbt->flag=q->flag+1;
					enqu(queue,p->rbt);
				}
				inverqu(queue);	
			}			
		}
		else
		{
			if(w->flag==p->flag)
			{
				if(p->rbt)
				{
					p->rbt->flag=q->flag+1;
					enqu(queue,p->rbt);	
				}
				if(p->lbt)
				{
					p->lbt->flag=q->flag+1;
					enqu(queue,p->lbt);				
				}
			}
			else
			{
				if(p->rbt)
				{
					p->rbt->flag=q->flag+1;
					enqu(queue,p->rbt);	
				}
				if(p->lbt)
				{
					p->lbt->flag=q->flag+1;
					enqu(queue,p->lbt);				
				}
				inverqu(queue);
			}
		} 
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
	traveltree(tree); 
	printf("中序输出验证结果:\n");
	midtravel(tree);
	return 0;
}