#include<stdio.h>
#include<stdlib.h>
#define S 20
void insert(int item,int *r,int q[S]);
int del(int *r,int *f,int q[S]);
void display(int *r,int *f,int q[S]);
int main()
{
int q[S],item,r=-1,f=0,x;
int ch,choice=1,v;
while(choice!=0)
{
printf("Enter following number for following operation-\n");
printf("1)Insertion 2)Deletion 3)Display\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Insertion\n");
printf("Enter the value to be inserted\n");
scanf("%d",&v);
insert(v,&r,q);
printf("Enetr 0 to stop\n");
scanf("%d",&choice);
break;
case 2:
printf("Deletion\n");
x=del(&r,&f,q);
printf("Deleted item=%d\n",x);
printf("Enter 0 to stop\n");
scanf("%d",&choice);
break;
case 3:
printf("Display\n");
display(&r,&f,q);
printf("Enter 0 to stop\n");
scanf("%d",&choice);
break;
default:
printf("Invalid\n");
printf("Enter 0 to stop\n");
scanf("%d",&choice);
break;
}
}
return 0;
}
void insert(int item,int *r,int q[S])
{
if(*r==S-1)
{printf("Queue overflow\n");
return;}
*r=*r+1;
q[*r]=item;
}
int del(int *r,int *f,int q[S])
{
int item;
if(*f>*r)
{printf("Queue underflow\n");
return -999;}
item=q[*f];
*f=*f+1;
return item;
}
void display(int *r,int *f,int q[S])
{
int i;
if(*f>*r)
{printf("Queue is empty\n");
return;}
printf("Contents of Queue are:\n");
for(i=*f;i<=*r;i++)
{
 printf("%d\n",q[i]);
}
}
