#include<stdio.h>
struct node
{
int data;
int pri;
struct node *next;
};
typedef struct node *NODE;
NODE getnode(int d,int p)
{
NODE pro;
pro=(NODE) malloc(sizeof(struct node));
pro->data=d;
pro->pri=p;
pro->next=NULL;
return pro;
}
NODE insert(int data,int pri,NODE head)
{
NODE p=head,q=getnode(data,pri);
if(head==NULL)
{
return q;
}
if(head->pri>pri)
{
q->next=head;
head=q;
return head;
}
else
{
while(p->next!=NULL && p->next->pri<pri)
{
p=p->next;
}
q->next=p->next;
p->next=q;
return head;
}
}
NODE pop(NODE head)
{
NODE p=head;
if(head==NULL)
{
printf("Queue is empty\n");
return head;
}
printf("Deleted item=%d having priority=%d\n",p->data,p->pri);
head=head->next;
free(p);
return head;
}
void print(NODE head)
{
NODE p=head;
while(p!=NULL)
{
printf("data=%d and priority=%d\n",p->data,p->pri);
p=p->next;
}
}
int main()
{
NODE head=NULL;
int ch,j=1,e,p;
clrscr();
while(j!=0)
{
printf("Enter choice-\n");
printf("1.Insert\t2.Delete\t3.Display\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter data and it priority\n");
scanf("%d %d",&e,&p);
head=insert(e,p,head);
break;
case 2:
head=pop(head);
break;
case 3:
printf("**********\n");
print(head);
break;
default:
printf("Invalid\n");
exit(0);
break;
}
printf("Enter other than '0' to continue\n");
scanf("%d",&j);
}
getch();
return 0;
}