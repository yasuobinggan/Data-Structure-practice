#include<stdio.h>
#include<stdlib.h>
#define m 10  
typedef struct bitnode{
	char data;
	struct bitnode *lbt;
	struct bitnode *rbt;
}bitnode,*bitree;
typedef struct{
	bitree *top;
	bitree *base;
}sq;
void initsq(sq &s)
{
	s.base=(bitree *)malloc(m*sizeof(bitree));
	if(!s.base)printf("wrong");
	s.top=s.base;
}
void push(sq &s,bitree e)
{
     *s.top++=e; 
}
void pop(sq &s,bitree &e)
{
	if(s.top==s.base)printf("wrong");
	e=*--s.top;
}
bitree gettop(sq &s,bitree &e)
{
	if(s.top==s.base)printf("wrong");
	e=*(s.top-1);
	return e;
}
void createtree(bitree tree)
{
	char e;
	//printf("输入字符\n");
	scanf("%c",&e);
	if(e=='#')tree=NULL;//return;
	else
	{
		tree=(bitree)malloc(sizeof(bitnode));
		tree->data=e; 
		createtree(tree->lbt);
		createtree(tree->rbt);
	}
}
void Nrtree(bitree tree)//非递归遍历函数 
{
	sq s;bitree p;
	if(tree!=NULL)
	{
		initsq(s);
		push(s,tree);
		while(s.top!=s.base)
		{
			printf("%c",p->data);
			push(s,p->lbt);
			pop(s,p);
			if(s.top!=s.base&&gettop(s,p)->rbt!=NULL)
			{
				pop(s,p);
				push(s,p->rbt);
			}	
		}
		
	}
	else
		printf("此树为空\n");
} 
int main()
{
	bitree tree;
	createtree(tree);
	Nrtree(tree);
	return 0;
} 