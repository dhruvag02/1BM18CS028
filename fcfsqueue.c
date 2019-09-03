#include<stdio.h>
#include<conio.h>
#define S 20
void insert(int item,int q[S],int *r);
void display(int q[S],int *r,int *f);
int del(int q[S],int *r,int *f);
int main()
{
int i,n,bt[S],at[S],q[S],r=-1,f=0,et,x;
clrscr();
printf("Enter the number of processes\n");
scanf("%d",&n);
printf("Enter burst time for each process\n");
for(i=0;i<n;i++)
{
scanf("%d",&bt[i]);
}
at[0]=0;
for(i=0;i<n;i++)
{
at[i+1]=at[i]+bt[i];
printf("Insert P%d at %d\n",i,at[i]);
insert(i,&r,q);
}
display(q,&r,&f);
et=0;
for(i=0;i<n;i++)
{
et=et+bt[i];
printf("Execute/Delete p%d at %d\n",i,et);
x=del(q,&r,&f);
printf("p%d got executed at %d\n",x,et);
}
getch();
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
void display(int q[S],int *r,int *f)
{
int i;
if(*f>*r)
{printf("Queue is empty\n");
return;}
for(i=*f;i<=*r;i++)
printf("P%d\t\n",q[i]);
}
int del(int q[S],int *r,int *f)
{
int item;
if(*f>*r)
{printf("Queue underflow\n");
return -999;}
item=q[*f];
*f=*f+1;
return item;
}
