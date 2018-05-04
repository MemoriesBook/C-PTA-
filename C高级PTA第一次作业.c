//
//  main.c
//  C高级PTA第一次作业
//
//  Created by 李晓静 on 2018/3/25.
//  Copyright © 2018年 李晓静. All rights reserved.
//
//計算兩數的和與差
/*#include <stdio.h>
void sum_diff( float op1, float op2, float *psum, float *pdiff );
int main()
{
    float a, b, sum, diff;
    scanf("%f %f", &a, &b);
    sum_diff(a, b, &sum, &diff);
    printf("The sum is %.2f\nThe diff is %.2f\n", sum, diff);
    return 0;
}
void sum_diff(float op1,float op2,float *psum,float *pdiff)
{
    *psum=op1+op2;
    *pdiff=op1-op2;
}*/
//拆分實數的整數和小數部分
/*#include <stdio.h>
void splitfloat( float x, int *intpart, float *fracpart );
int main()
{
    float x, fracpart;
    int intpart;
    scanf("%f", &x);
    splitfloat(x, &intpart, &fracpart);
    printf("The integer part is %d\n", intpart);
    printf("The fractional part is %g\n", fracpart);
    return 0;
}
void splitfloat(float x,int *intpart,float *fracpart)
{
    *intpart=(int)x;
    *fracpart=x-(int)x;
}*/
//在數組中查找指定元素
/*#include <stdio.h>
 #define MAXN 10
 int search( int list[], int n, int x );
 int main()
 {
 int i, index, n, x;
 int a[MAXN];
 scanf("%d", &n);
 for( i = 0; i < n; i++ )
 scanf("%d", &a[i]);
 scanf("%d", &x);
 index = search( a, n, x );
 if( index != -1 )
 printf("index = %d\n", index);
 else
 printf("Not found\n");
 return 0;
 }
 int search(int list[],int n,int x)
 {
 for(signed int *i=list;i<list+n;i++)
 {
 if(*i==x)
 return i-list;
 }
 return -1;
 }*/
//找最大值及其下標
/*#include<stdio.h>
 #define N 10
 int fun(int *a,int *b,int n);
 int main()
 {
 int a[N],i,max,p=0;
 for(i=0;i<N;i++)
 scanf("%d",&a[i]);
 max=fun(a,&p,N);
 printf("max=%d,position=%d\n",max,p);
 return 0;
 }
 int fun(int *a,int *b,int n)
 {
 int max=*a;
 for(signed int *i=a+1;i<a+n;i++)
 if(*i>max)
 {
 max=*i;
 *b=i-a;
 }
 return max;
 }*/
//最小數放前最大數放後
/*#include<stdio.h>
 void input(int *arr,int n);
 void max_min(int *arr,int n);
 void output(int *arr,int n);
 int main()
 {
 int a[10];
 input(a,10);
 max_min(a,10);
 output(a,10);
 return 0;
 }
 void input(int *arr,int n)
 {
 for(signed short int i=0;i<n;i++)
 scanf("%d",arr+i);
 }
 void max_min(int *arr,int n)
 {
 short int MAX=*arr,MIN=*arr,swap,max,min;
 for(signed short int i=1;i<n;i++)
 {
 if(*(arr+i)>MAX)
 {
 MAX=*(arr+i);
 max=i;
 }
 if(*(arr+i)<MIN)
 {
 MIN=*(arr+i);
 min=i;
 }
 }
 swap=*(arr+min);
 *(arr+min)=*arr;
 *arr=swap;
 swap=*(arr+max);
 *(arr+max)=*(arr+n-1);
 *(arr+n-1)=swap;
 }
 void output(int *arr,int n)
 {
 for(signed short int i=0;i<n;i++)
 printf("%3d",*(arr+i));
 }*/
//指針選擇法排序
/*#include<stdio.h>
 void sort(int *x,int n);
 int main ( )
 {
 int *p,i,a[10];
 p=a;
 for (i=0;i<10;i++)
 scanf("%d",p++);
 p=a;
 sort(a,10);
 for(i=0;i<10;i++)
 printf("%4d",*p++);
 printf("\n");
 return 0;
 }
 void sort(int *x,int n)
 {
 for(signed int *i=x;i<x+n-1;i++)
 for(signed int *j=i+1;j<x+n;j++)
 if(*i<*j)
 {
 int swap;
 swap=*i;
 *i=*j;
 *j=swap;
 }
 }*/
//判斷回文字符串
/*#include <stdio.h>
 #include <string.h>
 #define MAXN 20
 typedef enum {false, true} bool;
 bool palindrome( char *s );
 int main()
 {
 char s[MAXN];
 scanf("%s", s);
 if ( palindrome(s)==true )
 printf("Yes\n");
 else
 printf("No\n");
 printf("%s\n", s);
 return 0;
 }
 bool palindrome(char *s)
 {
 short int N=strlen(s);
 short int i=0,j=N-1;
 for(;i<=N/2;i++)
 while(j>=N/2)
 if(*(i+s)!=*(j+s))
 return false;
 else
 {
 j--;
 break;
 }
 return true;
 }*/
//使用函數實現部分字符串複製
#include <stdio.h>
#define MAXN 20
void strmcpy( char *t, int m, char *s );
void ReadString( char s[] ); /* 由裁判实现，略去不表 */
int main()
{
    char t[MAXN], s[MAXN];
    int m;
    scanf("%d\n", &m);
    ReadString(t);
    strmcpy( t, m, s );
    printf("%s\n", s);
    return 0;
}
void strmcpy(char *t,int m,char *s)
{
    short int i=m-1,j=0;
    if(m>MAXN)
        *s='\0';
    else
    {
        for(i=m-1,j=0;i<MAXN;i++,j++)
            *(s+j)=*(t+i);
        *(t+i+1)='\0';
    }
}

