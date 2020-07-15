#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct BiTNode
{
    char c;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
typedef struct
{
    BiTree x;
    int flag;
}snode;
typedef struct
{
    snode sdata[100];//数据栈 
    int top;
}Stack;
int Empty(Stack s)//判断栈是否为空(s.top==-1,栈不空)(s.top==0,栈为空) 
{
    if(s.top==-1) return 1;
    else return 0;
}
void Pop(Stack &s,BiTree R)          //取栈顶元素,flag=1标志已经被取过一次
{
    R=s.sdata[s.top].x;
    s.sdata[s.top].flag=1;
}
void Out(Stack &s,BiTree R)         //取栈顶元素，并且栈顶元素出栈
{
    R=s.sdata[s.top].x;
    s.top--;
}
void In(Stack &s,BiTree R)          //元素入栈，flag=0标志从未被取过
{
    s.top++;
    s.sdata[s.top].x=R;
    s.sdata[s.top].flag=0;
}
void CreateBiTree(BiTree T)
{
    char ch;
    Stack s;
    T=NULL;
    s.top=-1;
    BiTree R=T;
    BiTree p;//作为输入的节点 
    do
    {
        cin>>ch;
        if(Empty(s)&&ch=='#')//栈为空 
            return;
        else if(ch!='#')
        {
            p=(BiTree)malloc(sizeof(BiTNode));
            p->c=ch;
            if(Empty(s))
            {
                T=p;
                R=p;
            }
            else if(s.sdata[s.top].flag==0)//栈顶元素未被取过 
            {
                Pop(s,R);
                R->lchild=p;
            }
            else//栈顶元素被取过 
            {
                Out(s,R);
                R->rchild=p;
            }
            In(s,p);
        }
        else
        {
            if(s.sdata[s.top].flag==0)
            {
                Pop(s,R);
				R->lchild=NULL;
            }
            else
            {
                Out(s,R);
                R->rchild=NULL;
            }
        }
    }while(s.top!=-1);
}
void trtree(BiTree T)
{
	
} 
int main()
{
    BiTree T;
    CreateBiTree(T);
}