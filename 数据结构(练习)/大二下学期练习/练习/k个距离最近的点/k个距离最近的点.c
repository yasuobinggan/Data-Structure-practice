#include<stdio.h>
typedef struct{
	int x;
	int y;
	int range;
}p;
/*void find1(p point[],p origin,int k)
{
	int i;p find[k];
	for(i=0;i<k;i++)
	{
		find[i].x=point[i].x; 
		find[i].y=point[i].y;
		find[i].range=point[i].range;
	}
}*/
void find2(p point[],p origin,int k)
{
	int i,j;p temp;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4-i;j++)
		{
			if(point[j].x<point[j+1].x&&point[j].range==point[j+1].range)
			{
				temp=point[j];
				point[j]=point[j+1];
				point[j+1]=temp;
			}
			if(point[j].y<point[j+1].y&&point[j].range==point[j+1].range)
			{
				temp=point[j];
				point[j]=point[j+1];
				point[j+1]=temp;
			}  
			if(point[j].range>point[j+1].range)
			{
				temp=point[j];
				point[j]=point[j+1];
				point[j+1]=temp;	
			}
		}	
	}
	for(i=0;i<k;i++)
	printf("%d\t%d\t",point[i].x,point[i].y); 
}
int main()
{
	int i,k;p point[5],origin;
	printf("输入要标准点:\n");
	scanf("%d%d",&origin.x,&origin.y);
	printf("输入要寻找点列:\n");
	for(i=0;i<5;i++)
	{
		scanf("%d%d",&point[i].x,&point[i].y);
		point[i].range=(point[i].x-origin.x)*(point[i].x-origin.x)+(point[i].y-origin.y)*(point[i].y-origin.y);
	}
	printf("请输入寻找的点的数量:\n");
	scanf("%d",&k);
	//void find1(point[5],origin,k);
	find2(point,origin,k);
	return 0;
} 
