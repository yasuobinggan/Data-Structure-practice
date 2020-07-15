#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 5
typedef struct{
int *base;  //数组首地址(栈底指针 )
int *top;   //栈顶指针
int stacksize; //栈容量
}SqStack;
void InitStack(SqStack &S){ // 构造一个空栈S 
  S.base= (int*) malloc (STACK_INIT_SIZE *sizeof(int));
  if (!S.base)  printf("wrong");   // 存储分配失败 
  S.top= S.base;            // 空栈长度为 0 
  S.stacksize= STACK_INIT_SIZE; // 初始存储容量 
     } //InitStack
void Push(SqStack &S, int e){ //插入元素e为新的栈顶元素 
 
 *S.top++=e; 
 } 
void Pop(SqStack &S,int &e){ // 若栈不空，则删除栈顶元素，用e返回其值，并返回 OK ；
 //否则返回 ERROR 
 
if(S.top==S.base) printf("wrong");  // 栈空
 e=*--S.top; 
 printf("%d",e); 
 } 
 int main()
 {
 	SqStack S1;int i;int j;
    InitStack(S1);
    scanf("%d",&i);
 	Push(S1,i);
 	Pop(S1,j);
	 printf("%d",j); 
 	return 0;
 }  