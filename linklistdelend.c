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
NODE del_front(NODE head);
NODE del_end(NODE head);
int main()
{
int item,pos;
int i=1,ch;
NODE head=NULL;
while(i!=0)
{
printf("Menu has been displayed\n");
printf("1.inser_front\t2.insert_end\t3.insert_pos\t4.Delete_front\t5.Del_end\t6.Display\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Insert from front\n");
printf("Enter the value\n");
scanf("%d",&item);
head=insert_front(item,head);
break;
case 2:
printf("Insert from end\n");
printf("Enter the value\n");
scanf("%d",&item);
insert_end(item,head);
break;
case 3:
printf("Insert at position\n");
printf("Enter the position\n");
scanf("%d",&pos);
printf("Enter the value\n");
scanf("%d",&item);
head=insert_pos(item,head,pos);
break;
case 4:
printf("Deletion from front\n");
head=del_front(head);
break;
case 5:
printf("Delete at end\n");
del_end(head);
break;
case 6:
printf("Values are displayed\n");
display(head);
break;
default:
printf("Invalid\n");
exit(0);
}
printf("Enter other than '0' to continue\n");
scanf("%d",&i);
}
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
NODE del_front(NODE head)
{
NODE p=head;
if(head==NULL)
{printf("LIst is empty\n");
return head;}
printf("Deleted element=%d\n",p->data);
head=p->next;
free(p);
return head;
}
NODE del_end(NODE head)
{
NODE p=head;
NODE prev;
if(head==NULL)
{printf("List is empty\n");
return;}
while(p->next!=NULL)
{
prev=p;
p=p->next;
}
printf("Deleted element=%d\n",p->data);
prev->next=NULL;
free(p);
} 
