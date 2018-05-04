//
//  main.c
//  C高级第二次PTA作业
//
//  Created by 李晓静 on 2018/4/8.
//  Copyright © 2018年 李晓静. All rights reserved.
//

//删除字符串中数字字符
/*
 #include "stdio.h"
 void delnum(char *s);
 int main ()
 {
 char item[80];
 gets(item);
 delnum(item);
 printf("%s\n",item);
 return 0;
 }
 void delnum(char *s)
 {
 short int j=0;
 for(short int i=0;*(s+i)!='\0';i++)
 if(*(s+i)<='9'&&*(s+i)>='0')
 continue;
 else
 {
 *(s+j)=*(s+i);
 j++;
 }
 *(s+j)='\0';
 }
*/
//统计子串在母串出现的次数
/*
 #include<stdio.h>
 int fun(char *str,char *substr);
 int main()
 {
 char str[81]="asdasasdfgasdaszx67asdmklo",substr[4]="asd";
 int n;
 n=fun(str,substr);
 printf("n=%d\n",n);
 return 0;
 }
 int fun(char *str,char *substr)
 {
 short int j=0,count=0;
 for(short int i=0;*(str+i)!='\0';i++)
 {
 for(j=0;*(substr+j)!='\0';j++)
 if(*(str+i)==*(substr+j))
 i++;
 else
 break;
 if(*(substr+j)=='\0')
 count++;
 }
 return count;
 }
*/
//字符串中除首尾字符外的其余字符外按降序排列
/*
 #include <stdio.h>
 int fun(char *s,int num);
 int main()
 {
 char s[10];
 gets(s);
 fun(s,7);
 printf("%s",s);
 return 0;
 }
 int fun(char *s,int num)
 {
 for(short int i=1;i<num-2;i++)
 {
 short int k=i,swap;
 for(short int j=i+1;j<num-1;j++)
 if(*(s+k)<*(s+j))
 k=j;
 swap=*(s+k);
 *(s+k)=*(s+i);
 *(s+i)=swap;
 }
 }
*/
//输出学生成绩
/*#include <stdio.h>
 #include <stdlib.h>
 #include <malloc.h>
 void main()
 {
 short int N;
 scanf("%d\n",&N);
 short int *grade=(int *)malloc(N*sizeof(short int));
 if(grade!=NULL)
 {
 float max=-1,min=101,sum=0;
 for(short int i=0;i<N;i++)
 {
 scanf("%d",grade+i);
 if(max<*(grade+i))
 max=*(grade+i);
 if(min>*(grade+i))
 min=*(grade+i);
 sum+=*(grade+i);
 }
 printf("average = %.2f\nmax = %.2f\nmin = %.2f\n",sum/N,max,min);
 free(grade);
 }
 system("pause");
 }
*/
//计算职工工资
/*
 #include <stdio.h>
 #include <stdlib.h>
 struct Staffinformation
 {
 char name[10];float basepay;
 float fluctuatingwages;float expenses;
 float actualwages;
 };
 void main()
 {
 signed short int N;
 scanf("%d",&N);
 struct Staffinformation s;
 for(signed short int i=0;i<N;i++)
 {
 scanf("%s %f %f %f\n",s.name,&s.basepay,&s.fluctuatingwages,&s.expenses);
 s.actualwages=s.basepay+s.fluctuatingwages-s.expenses;
 printf("%s %.2f\n",s.name,s.actualwages);
 }
 system("pause");
 }
*/
//计算平均成绩
/*
 #include <stdio.h>
 #include <stdlib.h>
 struct student
 {
 char number[6];char name[10];
 int grade;
 };
 void main()
 {
 int N,sum=0;
 scanf("%d",&N);
 struct student infor[N];
 for(signed short int i=0;i<N;i++)
 {
 scanf("%s %s %d\n",infor[i].number,infor[i].name,&infor[i].grade);
 sum+=infor[i].grade;
 }
 printf("%.2f\n",sum/N*1.0f);
 for(signed short int i=0;i<N;i++)
 if(sum/N*1.0f>infor[i].grade)
 printf("%s %s\n",infor[i].name,infor[i].number);
 system("pause");
 }
*/
//按等级统计学生成绩
/*
 #include <stdio.h>
 #define MAXN 10
 struct student
 {
 int num;char name[20];
 int score;char grade;
 };
 int set_grade( struct student *p, int n );
 int main()
 {
 struct student stu[MAXN], *ptr;
 int n, i, count;
 ptr = stu;
 scanf("%d\n", &n);
 for(i = 0; i < n; i++)
 scanf("%d%s%d", &stu[i].num, stu[i].name, &stu[i].score);
 count = set_grade(ptr, n);
 printf("The count for failed (<60): %d\n", count);
 printf("The grades:\n");
 for(i = 0; i < n; i++)
 printf("%d %s %c\n", stu[i].num, stu[i].name, stu[i].grade);
 return 0;
 }
 int set_grade(struct student *p,int n)
 {
 short int count=0;
 for(signed short int i=0;i<n;i++)
 if((p+i)->score>=85&&(p+i)->score<=100)
 (p+i)->grade='A';
 else if((p+i)->score>=70&&(p+i)->score<=84)
 (p+i)->grade='B';
 else if((p+i)->score>=60&&(p+i)->score<=69)
 (p+i)->grade='C';
 else
 {
 (p+i)->grade='D';
 count++;
 }
 return count;
 }
*/
//结构体数组按总分排序

 #include <stdio.h>
 struct student
 {
 int num;
 char name[15];
 float score[3];
 float sum;
 };
 void calc(struct student *p,int n);
 void sort(struct student *p,int n);
 int main()
 {
 struct student stu[5];
 int i,j;
 float f;
 for(i=0;i<5;i++)
 {
 scanf("%d%s",&stu[i].num,stu[i].name);
 for(j=0;j<3;j++)
 {
 scanf("%f",&f);
 stu[i].score[j]=f;
 }
 }
 calc(stu,5);
 sort(stu,5);
 for(i=0;i<5;i++)
 {
 printf("%5d%15s",stu[i].num,stu[i].name);
 printf("  %.1f  %.1f  %.1f  %.1f\n",stu[i].score[0],stu[i].score[1],stu[i].score[2], stu[i].sum);
 }
 return 0;
 }
 void calc(struct student *p,int n)
 {
 for(signed short int i=0;i<n;i++)
 {
 (p+i)->sum=0;
 for(signed int j=0;j<3;j++)
 (p+i)->sum+=(p+i)->score[j];
 }
 }
 void sort(struct student *p,int n)
 {
 for(signed short int i=0;i<n-1;i++)
 {
 short int k=i;
 for(signed short int j=i+1;j<n;j++)
 if((p+k)->sum<(p+j)->sum)
 k=j;
 struct student swap=p[k];
 p[k]=p[i];
 p[i]=swap;
 }
 }
