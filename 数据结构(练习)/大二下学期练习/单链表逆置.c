#include<stdio.h>
#include<stdlib.h>
typedef struct lnode{
	int data;
	struct lnode *next;
}lnode,*link;
void createlink(link &l,int n)
{
	int i;link s;link p;
	l=(link)malloc(sizeof(lnode));
	l->next=NULL;
	s=l;
	for(i=0;i<n;i++)
	{
		p=(link)malloc(sizeof(lnode));
		scanf("%d",&p->data);
		p->next=s->next;
		s->next=p;
		s=p;
	}
}

void inverselink(link &l,int n,link &il)
{
	int i;int w;
	w=n-2;
	link p,q;//q标记p的下一个节点 
	link s;//标记逆置链表头结点个节点 
	
	while(n-2>=0)
	{
		p=l->next;
		for(i=1;i<=n-2;i++) 
		{
			p=p->next;
		}//找到倒数第二个节点 
		q=p->next; 
		p=q->next;
		p->next=NULL;
		if(n=w)
		{
			s=q;
		}	 
		n--; 
	}
	 //il->next=NULL;
	// il->next=s;
	while(s)
	{
		printf("%d ",s->data);
		s=s->next;
	}
}
//（网络）两个节点逆置时，（记住）指针指向第三个节点
//直到第三个节点不存在 
void travellink(link l)
{
	link p;
	p=l->next;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;		
	}
	//printf("%d",p->data);	
}  
int main()
{
	link l;
	int n;
	int q;
	link il;
	il=(link)malloc(sizeof(lnode));
	il->next=NULL;
	printf("输入要输入的数据数量:\n");
	scanf("%d",&n);
	printf("输入数据:\n");
	createlink(l,n);
	printf("输出链表:\n"); 
	travellink(l);
	inverselink(l,n,il);
	printf("\n输出逆置后的链表:\n");
	travellink(il);
	return 0;
}