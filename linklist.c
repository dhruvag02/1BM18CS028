#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
typedef struct node *NODE;
NODE getnode();
NODE insert_front(int item,NODE head);
void insert_end(int item,NODE head);
NODE insert_pos(int item,NODE head,int pos);
void display(NODE head);
int main()
{
int item,pos;
NODE head=NULL;
head=insert_front(10,head);
head=insert_front(20,head);
head=insert_front(30,head);
printf("Enter the value\n");
scanf("%d",&item);
printf("Enter the position\n");
scanf("%d",&pos);
head=insert_pos(item,head,pos);
insert_end(50,head);
display(head);
return 0;
}
NODE getnode()
{
NODE p;
p=(NODE)malloc(sizeof(struct node));
if(p!=NULL)
return p;
else
{
printf("Memory could not be allocated\n");
exit(0);
}
}
NODE insert_front(int item,NODE head)
{
NODE p;
p=getnode();
p->data=item;
p->next=head;
head=p;
return head;
}
NODE insert_pos(int item,NODE head,int pos)
{
NODE curr,prev=NULL,newn;
int count=1;
newn=getnode();
newn->data=item;
newn->next=NULL;
if(head==NULL)
{
if(pos==1)
 {
  return newn;
 }
else  
 {
  printf("Invalid position\n");
  return head;
 }
}
else if(pos==1)
{
newn->next=head;
head=newn;
return head;
}
else
{
curr=head;
 while(curr!=NULL&&count!=pos)
 {
  prev=curr;
  curr=curr->next;
  count++;
 } 
 if(count==pos)
 {
  prev->next=newn;
  newn->next=curr;
  return head;
 }
 else
 { 
  printf("Invalid position\n");
  return head;
 }
}
}
void insert_end(int item,NODE head)
{
NODE p,q;
q=getnode();
q->data=item;
p=head;
while(p->next!=NULL)
{
p=p->next;
}
p->next=q;
q->next=NULL;
}
void display(NODE head)
{
NODE p;
printf("***********\n");
if(head==NULL)
{
printf("List is empty\n");
exit(0);
}
p=head;
while(p!=NULL)
{
printf("%d\n",p->data);
p=p->next;
}
} 
