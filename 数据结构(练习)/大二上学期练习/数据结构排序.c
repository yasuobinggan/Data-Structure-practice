#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TABLE  50

typedef struct {
   char  name[15];
   int  score;
   int mingci;
}Stud;
typedef struct {
   Stud *elem;
   int length;
}Student;
void  CreateTable( Student  &ST )     //建立学生基本情况表
{
   int  i, sc;
   char name1[15];
   ST.elem = (Stud*)malloc(MAX_TABLE*sizeof(Stud));
   ST.length = 0;
   printf( "输入学生基本情况（成绩以0表示结束）\n" );
   printf( "输入姓名及成绩\n" );
   scanf("%s%d",name1,&sc);   while( sc > 0 )
   {   strcpy( ST.elem[ST.length].name, name1 );
       ST.elem[ST.length++].score = sc;
       scanf("%s%d",name1,&sc);
   }
   for( i=0; i<ST.length; i++ )
     ST.elem[i].mingci = 0;
}

void Output( Student ST )   //输出学生的基本情况
{
   int  i;
   printf( "      姓名    成绩   名次\n" ); 
   for( i =0; i < ST.length; i++ )
       printf( " %10s%6d%6d\n", ST.elem[i].name, ST.elem[i].score, ST.elem[i].mingci );
   printf( "\n" );
}

void InsertSort( Student &ST )    //插入排序
{
   int i, j ;
   Stud temp;
   for( i=1; i< ST.length; i++ )
      if( ST.elem[i].score>ST.elem[i-1].score )
      {   temp = ST.elem[i];
          ST.elem[i] = ST.elem[i-1];
          for( j = i-2; j >= 0 && ST.elem[j].score < temp.score; j-- )
              ST.elem[j+1] = ST.elem[j];
          ST.elem[j+1] = temp;
      }
   ST.elem[0].mingci = 1;
   for( i=1; i < ST.length; i++ )
      if( ST.elem[i].score == ST.elem[i-1].score )
          ST.elem[i].mingci = ST.elem[i-1].mingci;
      else ST.elem[i].mingci = ST.elem[i-1].mingci+1;
}

void BubbleSort( Student &ST )     //冒泡排序
{
   int i, j;
   Stud temp;
   for( i = 0; i < ST.length; i++ )
     for( j = 0; j < ST.length-i-1; j++ )
        if( ST.elem[j].score < ST.elem[j+1].score )
        {   temp =  ST.elem[j];   ST.elem[j] = ST.elem[j+1];
            ST.elem[j+1] = temp;
        }
   ST.elem[0].mingci = 1;
   for( i=1; i < ST.length; i++ )
      if( ST.elem[i].score == ST.elem[i-1].score )
          ST.elem[i].mingci = ST.elem[i-1].mingci;
      else ST.elem[i].mingci = ST.elem[i-1].mingci+1;
}
void SelectSort( Student &ST )   //选择排序
{
   int i, j, k;
   Stud temp;
   for( i = 0; i < ST.length; i++ )
   {  k = i;
      for( j = i+1; j<ST.length; j++ )
         if( ST.elem[k].score < ST.elem[j].score )
             k = j;
      if ( k != i )
      {    temp =  ST.elem[i];   ST.elem[i] = ST.elem[k];
           ST.elem[k] = temp;
      }
   }
   ST.elem[0].mingci = 1;
   for( i=1; i < ST.length; i++ )
      if( ST.elem[i].score == ST.elem[i-1].score )
          ST.elem[i].mingci = ST.elem[i-1].mingci;
QuickSort( ST );
      else if( select == 5 )
     {
      TR1 = (Stud*)malloc(MAX_TABLE*sizeof(Stud));
      TR1.length = ST.length;
      MergeSort( ST );
     }
     else if( select == 6 )
       HeapSort( ST );
     else
     {   printf( "\n选择编号错误\n" );
         exit(0);
     }
     printf( "\n输出排序后的学生信息\n" );
     Output( ST );
}

//下面是2-归并排序
Student TR1;    //设置全局变量TR1，完成合并后的赋值操作
void Merge( Student &SR,  int i, int m, int n )   //将两个有序子表合并成一个有序子表
{     int j = m+1, k=i, temp = i;
   while( i <= m && j <= n )
      if( SR.elem[i].score > SR.elem[j].score )
         TR1.elem[k++] = SR.elem[i++];  
      else   TR1.elem[k++] = SR.elem[j++]; 
   while( i <= m )
      TR1.elem[k++] = SR.elem[i++];
   while ( j <= n )
       TR1.elem[k++] = SR.elem[j++];
   for( k = temp; k <= n; k++ )
     SR.elem[k] = TR1.elem[k];
}

void MSort( Student &SR, int m, int n )   
{
   int t;
   if ( m < n )
   {   t = ( m+n )/2;
       MSort( SR, m, t );
       MSort( SR, t+1, n );
       Merge( SR, m, t, n );
   }
}//Merge

void MergeSort( Student &ST )
{
   int i;
   MSort( ST, 0, ST.length-1 );
   ST.elem[0].mingci = 1;
   for( i=1; i < ST.length; i++ )
      if( ST.elem[i].score == ST.elem[i-1].score )
          ST.elem[i].mingci = ST.elem[i-1].mingci;
      else ST.elem[i].mingci = ST.elem[i-1].mingci+1;

}

void HeapAdjust( Student &SR, int s, int n )   //将SR.elem[s..n]调整成一个大顶堆
{
   Stud temp;
   int j;
   temp = SR.elem[s];
   j = 2*s+1;
   while( j <=n )
   {
      if( j < n && SR.elem[j].score < SR.elem[j+1].score )
         j++;
      if( temp.score > SR.elem[j].score )
         break;
      SR.elem[s] = SR.elem[j];
      s = j;  j = j*2+1;
   }
   SR.elem[s] = temp;
}

void HeapSort( Student &ST )   //堆排序
{
   int i;
   Stud temp;
   for( i = ( ST.length-1 )/2; i >= 0; i-- )
      HeapAdjust( ST, i, ST.length-1 );
   for ( i = ST.length-1; i > 0; i-- )
   {
      temp = ST.elem[0];   ST.elem[0] = ST.elem[i];
      ST.elem[i] = temp;   
      HeapAdjust( ST, 0, i-1 );
   }
   ST.elem[0].mingci = 1;
   for( i=1; i < ST.length; i++ )
      if( ST.elem[i].score == ST.elem[i-1].score )
          ST.elem[i].mingci = ST.elem[i-1].mingci;
      else ST.elem[i].mingci = ST.elem[i-1].mingci+1;

}

void main()
{
   Student ST;
   int select;
   printf( "建立学生基本情况信息表\n\n" );
   CreateTable( ST );
   printf( "\n输出未排序的学生信息\n" );
   Output( ST );
   printf( "              请选择排序方法\n" );
   printf( "      ******************************\n" );
   printf( "              1．插入排序\n " );
   printf( "              2．冒泡排序\n " );
   printf( "              3．选择排序\n " );
   printf( "              4．快速排序\n " );
   printf( "              5．归并排序\n " );
   printf( "              6．堆排序\n " );
   printf( "      ******************************\n" );
   printf( " 请选择(1--6)：" );
   scanf( "%d", &select );
   if( select == 1 )
      InsertSort( ST );
   else if( select == 2 )
      BubbleSort( ST );
   else if( select == 3 )
      SelectSort( ST );
   else if( select == 4 )
      else ST.elem[i].mingci = ST.elem[i-1].mingci+1;
}

void QuickSort( Student &ST )     //非递归的快速排序
{
   struct Stack{
      int low;
      int high;
   }S[20];
   int low1, high1, i, j, top;
   Stud temp;
   if( ST.length>0 )
{
      top=0;
      S[top].low = 0;  S[top++].high = ST.length-1;
      while( top )
      {
          i = low1 = S[--top].low;
          j = high1 = S[top].high;
          temp = ST.elem[i];
          while( i < j )
          { 
               while( i < j && ST.elem[j].score > temp.score )
                   j--;
               if( i < j )   { ST.elem[i] = ST.elem[j] ; i++;  }
               while( i < j && ST.elem[i].score < temp.score )
                   i++;
               if( i < j )   { ST.elem[j] = ST.elem[i] ; j--;  }
          }
          ST.elem[i] = temp;
          if( i-1 > low1 )
          {  S[top].low = low1;  S[top++].high = i-1;  }
          if( j+1 < high1 )
          {  S[top].low = j+1;  S[top++].high = high1;  }
      }//while
      ST.elem[0].mingci = 1;
      for( i=1; i < ST.length; i++ )
      if( ST.elem[i].score == ST.elem[i-1].score )
          ST.elem[i].mingci = ST.elem[i-1].mingci;
      else ST.elem[i].mingci = ST.elem[i-1].mingci+1;
   }//if
}

