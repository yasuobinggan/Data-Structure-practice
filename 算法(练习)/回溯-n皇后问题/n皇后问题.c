#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct 
{
	int x;
	int y;
}select; 
void createmap(int map[8][8])
{
	int i,j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			map[i][j]=0;
		}
	}
}
void signmap(int map[8][8],int h_o,int v_o)//h_0表示行坐标,v_o表示列坐标 
{
	int i,j;
	int sub_o=abs(h_o-v_o);
	int add_o=abs(h_o+v_o);
	if(h_o>v_o)//"\"
	{
		for(j=0;j+sub_o<8;j++)
			map[j+sub_o][j]=1;	
	} 
	else
	{
		for(i=0;i+sub_o<8;i++)
			map[i][i+sub_o]=1;
	}
	if(h_o<v_o)//"/"
	{
		for(i=0;i<=add_o;i++)
			map[i][add_o-i]=1;
	}
	else
	{
		for(i=7;i>=add_o-7;i--)
			map[i][add_o-i]=1;
	}
	for(i=0;i<8;i++)
	{
		map[i][v_o]=1;
	}
	for(j=0;j<8;j++)
	{
		map[h_o][j]=1;
	}
}
void queenmap(int map[8][8],select selected[])
{
	int i,j;
	int k=0;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(map[i][j]==0)
			{
				signmap(map,i,j);
				selected[k].x=i;
				selected[k].y=j;
				k++;
				break;	
			}
				 
		}
	}
	if(k<8)
		printf("wrong");
}
void printmap(int map[8][8])
{
	int i,j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			printf("%d\t",map[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int map[8][8];
	select selected[8];
	createmap(map);
	queenmap(map,selected);
	//printmap(map);
	return 0;
}
