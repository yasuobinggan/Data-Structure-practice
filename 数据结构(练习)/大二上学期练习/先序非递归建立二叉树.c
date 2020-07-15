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
    snode sdata[100];
    int top;
}Stack;
int Empty(Stack s)
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
void In(Stack &s,BiTree R)          //树节点入栈，flag=0标志从未被取过
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
    BiTree R=T,p;
    do
    {
        cin>>ch;//输入 
        if(Empty(s)&&ch=='#')
            return;//判断第一个节点是否为空 
        else if(ch!='#')
        {
            p=(BiTree)malloc(sizeof(BiTNode));
            p->c=ch;
            if(Empty(s))
            {
                T=p;
                R=p;
            }
            else if(s.sdata[s.top].flag==0)
            {
                Pop(s,R);
                R->lchild=p;
            }
            else
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
int main()
{
    BiTree T;
    CreateBiTree(T);
}