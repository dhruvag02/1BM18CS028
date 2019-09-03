#CIRCULAR QUEUE

#include<stdio.h>
#include<conio.h>
#define S 20
void insert(int item,int *r,int *f,int q[S]);
int del(int *r,int *f,int q[S]);
void display(int *r,int *f,int q[S]);
int main()
{
int q[S],r=-1,f=-1;
clrscr();
insert(4,&r,&f,q);
insert(5,&r,&f,q);
insert(10,&r,&f,q);
display(&r,&f,q);
getch();
return 0;
}
void insert(int item,int *r,int *f,int q[S])
{
if(*f==*r+1||(*f==0&&*r==S-1))
{printf("Queue is full\n");
return;}
if(*f==-1)
*f=0;
*r=(*r+1)%S;
q[*r]=item;
}
int del(int *r,int *f,int q[S])
{
int item;
if(*f==-1)
{printf("Queue is empty\n");
return -9999;}
else
{
item=q[*f];
if(*f==*r)
{
*f=-1;
*r=-1;
}
else
*f=(*f+1)%S;
return item;
}
}
void display(int *r,int *f,int q[S])
{
int i;
if(*f==-1)
{printf("Queue is empty\n");
return;}
printf("Contents of Queue are:\n");
for(i=*f;i!=*r;i=(i+1)%S)
printf("%d\n",q[i]);
}
