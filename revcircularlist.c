#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
typedef struct node *NODE;
NODE getnode();
NODE insert(int item,NODE head);
NODE rev(NODE head);
void print(NODE head);

int main()
{
NODE head=NULL;
int ch,j=1,i,val;
while(j!=0)
{
printf("Enter choice\n");
printf("1.insert\t2.Reverse\t3.Display\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter element to be inserted\n");
scanf("%d",&val);
head=insert(val,head);
break;
case 2:
head=rev(head);
break;
case 3:
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
return 0;
}

NODE getnode()
{
NODE p;
p=(NODE) malloc(sizeof(struct node));
if(p!=NULL)
return p;
else
{
printf("Memory could not be allocated\n");
return NULL;
}
}
NODE insert(int item,NODE head)
{
NODE p=getnode();
NODE q=head;
p->data=item;
p->next=p;
if(head==NULL)
return p;
else if(head->next==head)
{
p->next=head->next;
head->next=p;
}
else
{
while(q->next!=head)
{
q=q->next;
}
q->next=p;
p->next=head;
}
return head;
}
NODE rev(NODE head)
{
NODE curr=head->next;
NODE prev=head;
NODE nextn=NULL;
if(head==NULL)
{
printf("List is empty\n");
return head;
}
else if(head->next==head)
{
return head;
}
else
{
while(curr!=head)
{
nextn=curr->next;
curr->next=prev;
prev=curr;
curr=nextn;
}
head=prev;
curr->next=head;
return head;
}
}
void print(NODE head)
{
NODE p=head;
if(head==NULL)
{
printf("List is empty\n");
return;
}
while(p->next!=head)
{
printf("%d\t",p->data);
p=p->next;
}
printf("%d\n",p->data);
}

