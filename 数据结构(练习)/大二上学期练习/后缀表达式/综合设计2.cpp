#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h> 
#define m 20
#define n 5
typedef struct{
	char *base;
    char *top;
	int stacksize;
}sqstack;
void initstack(sqstack &s)
{
	s.base=(char *)malloc(m*sizeof(char));
	if(!s.base)printf("wrong");
	s.top=s.base;
	s.stacksize=m;
}
void push(sqstack &s, char e)
{
     *s.top++=e; 
}
void pop(sqstack &s,char &e)
{
	if(s.top==s.base)printf("wrong");
	e=*--s.top;
}
void gettop(sqstack &s,char &e)
{
	if(s.top==s.base)printf("wrong");
	e=*(s.top-1);
	printf("%ds",e-'0');
}
void qianzui(sqstack &s)
{
	char c,i,j,k,x;int a,b,v;int count=0;int y;
	printf("输入操作数或运算符:");scanf("%c",&c);
	for(y=0;y<6;y++) 
{
    if(c=='-')push(s,c);
	else if(c=='+')push(s,c);
	else if(c=='*')push(s,c);
	else if(c=='/')push(s,c);
	else if('0'<=c&&c<='9')  
	{
     push(s,c);
     count=count+1;
	if(count==2)
	{
	pop(s,i);pop(s,j);pop(s,k);
	a=(int)(i-'0');b=(int)(j-'0');
	switch(k){
	case'+':v=a+b;break;
	case'-':v=a-b;break;
	case'*':v=a*b;break;
	case'/':v=a/b;break;}
	x=(char)v;
	push(s,x);
	count=1;
	}
	}
}
}
int main()
{
	sqstack s1;
	int i;char b;
	initstack(s1);
	qianzui(s1);
	gettop(s1,b);
    return 0;
}