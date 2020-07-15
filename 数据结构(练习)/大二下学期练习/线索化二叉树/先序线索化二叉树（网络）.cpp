#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef enum pointertag {link,thread};
typedef struct bithnode{
	char data;
	struct bithnode *lchild,*rchild;
	pointertag ltag,rtag;
}bithnode,* bithtree;
bithtree pre;
void creatree(bithtree &s)
{
	char p;scanf("%c",&p);
	if(p=='#')
	{s=NULL;}
	else
{    s=(bithtree)malloc(sizeof(bithnode));
     s->data=p;
     s->ltag=link;
     s->rtag=link;
     creatree(s->lchild);
     creatree(s->rchild);
}
}
void prethreading(bithtree &t)
{
    if(t)
    {
        if(!t->lchild)
        {
            t->ltag=thread;
			t->lchild=pre;        
        }
        if(!pre->rchild)
        {
            pre->rtag=thread;
			pre->rchild=t;       
        }
        pre=t;//获取当前结点 
        if(link==t->ltag) 
            prethreading(t->lchild);
        if(link==t->rtag)
            prethreading(t->rchild);
    }
}
bithtree preorderthreading(bithtree &t)
{
    bithtree s;
    s=(bithtree)malloc(sizeof(bithnode)); 
    s->ltag=link;//头结点 
    s->rtag=thread;
    s->rchild=s; 
    if(!t)
        s->lchild=t;
    else
    {
        s->lchild=t;
        pre=s;
		prethreading(t);
		//尾节点构成双向链表       
        //pre标记树的最后一个节点
		pre->rchild=s;        
        pre->rtag=thread;
        s->rchild=pre;
    }
    return s;
}
void preordertravel(bithtree t)
{
    bithtree p;
    p=t->lchild;
    while(p!=t)
    {
        printf("%c",p->data);
        if(p->ltag==link)
            p=p->lchild;
        else
            p=p->rchild;
    }
}
int main()
{
	bithtree s,t;
	printf("前序输入二叉树:\n");
	creatree(s);
	t=preorderthreading(s);//带有头结点 
	printf("输出前序线索化二叉树:\n");
	preordertravel(t);
	printf("\n-------------------\n");
    return 0;
} 