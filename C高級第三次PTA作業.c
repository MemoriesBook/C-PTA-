//
//  main.c
//  C高級第三次PTA作業
//
//  Created by 李晓静 on 2018/5/4.
//  Copyright © 2018年 李晓静. All rights reserved.
//

//输出月份英文名
/*
 #include <stdio.h>
 char *getmonth( int n );
 int main()
 {
 int n;
 char *s;
 scanf("%d", &n);
 s = getmonth(n);
 if ( s==NULL ) printf("wrong input!\n");
 else printf("%s\n", s);
 return 0;
 }
 char *getmonth(int n)
 {
 char *months[12]={"January","February","March","April","May","June",
 "July","August","September","October","November","December"};
 if(n<1||n>12)
 return NULL;
 else
 return *(months+n-1);
 }
*/
//查找星期
/*
 #include <stdio.h>
 #include <string.h>
 #define MAXS 80
 int getindex( char *s );
 int main()
 {
 int n;
 char s[MAXS];
 scanf("%s", s);
 n = getindex(s);
 if ( n==-1 ) printf("wrong input!\n");
 else printf("%d\n", n);
 return 0;
 }
 int getindex(char *s)
 {
 char *days[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
 for(short int i=0;i<7;i++)
 if(strcmp(s,*(days+i))==0)
 return i;
 return -1;
 }
*/
//计算最长的字符串长度
/*
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #define MAXN 10
 #define MAXS 20
 int max_len( char *s[], int n );
 int main()
 {
 int i, n;
 char *string[MAXN] = {NULL};
 scanf("%d", &n);
 for(i = 0; i < n; i++)
 {
 string[i] = (char *)malloc(sizeof(char)*MAXS);
 scanf("%s", string[i]);
 }
 printf("%d\n", max_len(string, n));
 return 0;
 }
 int max_len(char *s[],int n)
 {
 short int length=strlen(*s);
 for(short int i=1;i<n;i++)
 if(strlen(*(s+i))>length)
 length=strlen(*(s+i));
 return length;
 }
*/
//指定位置输出字符串
/*
 #include <stdio.h>
 #define MAXS 10
 char *match( char *s, char ch1, char ch2 );
 int main()
 {
 char str[MAXS], ch_start, ch_end, *p;
 scanf("%s\n", str);
 scanf("%c %c", &ch_start, &ch_end);
 p = match(str, ch_start, ch_end);
 printf("%s\n", p);
 return 0;
 }
 char *match(char *s,char ch1,char ch2)
 {
 short int flag=0,j=0;
 char *address={"\n"},result[MAXS];
 for(short int i=0;i<MAXS;i++)
 if(flag==1)
 {
 *(result+j)=*(s+i);
 j++;
 if(*(s+i)==ch2)
 break;
 }
 else
 {
 if(*(s+i)==ch1)
 {
 flag=1;
 *(result+j)=*(s+i);
 j++;
 address=(s+i);
 }
 }
 *(result+j)='\0';
 if(*result==NULL)
 {
 printf("%s",result);
 return address;
 }
 else
 {
 puts(result);
 return address;
 }
 }
*/
//有一个axb的数组,该数组里面顺序存放了从1到a*b的数字。其中a是你大学号的前三位数字，b是你大学号的后四位数字，比如你的学号是2017023936，那么数组大小是201 x 3936，数组中顺序存放了1到791136（201和3936的积）的整数. 要求用筛选法,把该数组里的质数找出并打印出来，打印格式为5个质数一行，数字间用空格隔开。
//筛选法具体做法是：先把N个自然数按次序排列起来。1不是质数，也不是合数，要划去。第二个数2是质数留下来，而把2后面所有能被2整除的数都划去。2后面第一个没划去的数是3，把3留下，再把3后面所有能被3整除的数都划去。3后面第一个没划去的数是5，把5留下，再把5后面所有能被5整除的数都划去。这样一直做下去，就会把不超过N的全部合数都筛掉，留下的就是不超过N的全部质数。
/*#include <stdio.h>
 #include <stdlib.h>
 int array[201][3950];
 void input(int array[201][3950]);
 short int prime(int number);
 void exclude(int array[201][3950],int number);
 void output(int array[201][3950]);
 int main()
 {
 input(array);
 for(int i=0;i<201;i++)
 for(int j=0;j<3950;j++)
 if(array[i][j])
 {
 if(prime(array[i][j]))
 exclude(array,array[i][j]);
 else
 array[i][j]=0;
 }
 output(array);
 return 0;
 }
 void input(int array[201][3950])
 {
 int number=0;
 for(int i=0;i<201;i++)
 for(int j=0;j<3950;j++)
 array[i][j]=++number;
 }
 short int prime(int number)
 {
 if(number==1)
 return 0;
 for(short int i=1;i<=number/2;i++)
 if(i==1)
 continue;
 else if(number%i==0)
 return 0;
 return 1;
 }
 void exclude(int array[201][3950],int number)
 {
 for(int i=0;i<201;i++)
 for(int j=0;j<3950;j++)
 if(array[i][j])
 if(array[i][j]%number==0&&array[i][j]/number!=1)
 array[i][j]=0;
 }
 void output(int array[201][3950])
 {
 short int count=1;
 for(int i=0;i<201;i++)
 for(int j=0;j<3950;j++)
 {
 if(array[i][j])
 {
 if(count==1)
 {
 printf("%d",array[i][j]);
 count++;
 }
 else if(count==5)
 {
 printf(" %d\n",array[i][j]);
 count=1;
 }
 else
 {
 printf(" %d",array[i][j]);
 count++;
 }
 }
 }
 }
*/
//奇数值结点链表
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int data;
    struct ListNode *next;
};
struct ListNode *readlist(void);
struct ListNode *getodd( struct ListNode **L );
void printlist( struct ListNode *L )
{
    struct ListNode *p = L;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    struct ListNode *L,*Odd;
    L=readlist();
    Odd=getodd(&L);
    printlist(Odd);
    printlist(L);
    return 0;
}
struct ListNode *readlist()
{
    struct ListNode *head=NULL;
    for(struct ListNode *i=NULL,*tail=NULL;;tail=i)
    {
        i=(struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d",&i->data);
        i->next=NULL;
        if(i->data==-1)
            break;
        else if(head)
            tail->next=i;
        else
            head=i;
    }
    return head;
}
struct ListNode *getodd(struct ListNode **L)
{
    struct ListNode *oddhead=NULL,*evenhead=NULL;
    for(struct ListNode *i=(*L),*oddtail=NULL,*eventail=NULL;i!=NULL;i=i->next)
        if(i->data%2!=0)
        {
            struct ListNode *odd=(struct ListNode *)malloc(sizeof(struct ListNode));
            odd->data=i->data;
            odd->next=NULL;
            if(oddhead)
                oddtail->next=odd;
            else
                oddhead=odd;
            oddtail=odd;
        }
        else
        {
            struct ListNode *even=(struct ListNode *)malloc(sizeof(struct ListNode));
            even->data=i->data;
            even->next=NULL;
            if(evenhead)
                eventail->next=even;
            else
                evenhead=even;
            eventail=even;
        }
    (*L)=evenhead;
    return oddhead;
}
//学生成绩列表处理#include <stdio.h>
/*#include <stdlib.h>
struct stud_node
{
    int num;
    char name[20];
    int score;
    struct stud_node *next;
};
struct stud_node *createlist();
struct stud_node *deletelist( struct stud_node *head, int min_score );
int main()
{
    int min_score;
    struct stud_node *p,*head=NULL;
    head=createlist();
    scanf("%d",&min_score);
    head=deletelist(head, min_score);
    for( p = head; p != NULL; p = p->next )
        printf("%d %s %d\n", p->num, p->name, p->score);
    return 0;
}
struct stud_node *createlist()
{
    struct stud_node *head=NULL;
    for(struct stud_node *i=NULL,*tail=NULL;;tail=i,i=i->next)
    {
        i=(struct stud_node *)malloc(sizeof(struct stud_node));
        scanf("%d",&i->num);
        if(i->num==0)
            break;
        scanf("%s %d",i->name,&i->score);
        i->next=NULL;
        if(head)
            tail->next=i;
        else
            head=i;
    }
    return head;
}
struct stud_node *deletelist(struct stud_node *head,int min_score)
{
    for(struct stud_node *i=head,*front=head;i!=NULL;i=i->next)
    {
        if(i->score<min_score)
        {
            if(i==head)
                head=i->next;
            else
                front->next=i->next;
            free(i);
            i=front;
        }
        front=i;
    }
    return head;
}
*/
//链表拼接
/*
 #include <stdio.h>
 #include <stdlib.h>
 struct ListNode
 {
 int data;
 struct ListNode *next;
 };
 struct ListNode *createlist(); //裁判实现，细节不表
 struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2);
void printlist( struct ListNode *head )
{
    struct ListNode *p = head;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    struct ListNode  *list1, *list2;
    list1 = createlist();
    list2 = createlist();
    list1 = mergelists(list1, list2);
    printlist(list1);
    return 0;
}
struct ListNode *mergelists(struct ListNode *list1,struct ListNode *list2)
{
    for(struct ListNode *i=list2;i!=NULL;i=i->next)
        for(struct ListNode *j=list1,*front=list1;j!=NULL;j=j->next)
        {
            if(i->data<=j->data)
            {
                struct ListNode *assignment=(struct ListNode *)malloc(sizeof(struct ListNode));
                assignment->data=i->data;
                assignment->next=NULL;
                if(j==list1)
                {
                    assignment->next=list1;
                    list1=assignment;
                }
                else
                {
                    assignment->next=j;
                    front->next=assignment;
                }
                break;
            }
            else if(j->next==NULL)
            {
                struct ListNode *assignment=(struct ListNode *)malloc(sizeof(struct ListNode));
                assignment->data=i->data;
                assignment->next=NULL;
                j->next=assignment;
                break;
            }
            front=j;
        }
    free(list2);
    return list1;
}
*/

