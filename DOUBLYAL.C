#include<stdio.h>
#include<conio.h>
struct node
{
struct node *prev;
int data;
struct node *next;
};
typedef struct node *NODE;
NODE getnode()
{
NODE p;
p=(NODE) malloc(sizeof(struct node));
if(p!=NULL)
return p;
else
{
printf("Memory could not be allocated\n");
return  NULL;
}
}
NODE insert_front(int item,NODE head)
{
NODE p=getnode();
p->data=item;
p->next=NULL;
p->prev=NULL;
if(head==NULL)
head=p;
else
{
p->next=head;
head->prev=p;
head=p;
}
return head;
}
NODE insert_rear(int item,NODE head)
{
NODE p=getnode(),q=head;
p->data=item;
p->next=NULL;
p->prev=NULL;
if(head==NULL)
head=p;
else
{
while(q->next!=NULL)
{
q=q->next;
}
q->next=p;
p->prev=q;
}
return head;
}
NODE insert_left(int item,NODE head,NODE n)
{
NODE p=getnode();
p->data=item;
p->next=NULL;
p->prev=NULL;
if(head==NULL)
{
printf("List is empty\n");
return head;
}
if(head==n)
{
head->prev=p;
p->next=head;
p->prev=NULL;
head=p;
}
else
{
n->prev->next=p;
p->prev=n->prev;
p->next=n;
n->prev=p;
}
return head;
}
NODE del_rear(NODE head)
{
NODE p=head;
if(head==NULL)
{
printf("List is empty\n");
return head;
}
else if(head->next==NULL)
{
printf("Deleted=%d\n",p->data);
free(p);
return NULL;
}
else
{
while(p->next!=NULL)
{
p=p->next;
}
p->prev->next=NULL;
printf("Deleted=%d\n",p->data);
p->prev=NULL;
free(p);
return head;
}
}
NODE del_val(NODE head,int data)
{
NODE p=head;
if(head==NULL)
{
printf("List is empty\n");
return head;
}
else if(head->next==NULL)
{
if(head->data==data)
{
printf("Delete=%d\n",head->data);
free(head);
return NULL;
}
}
else
{
while(p!=NULL)
{
if(p->data==data)
{
if(p->prev==NULL)
{
head=p->next;
head->prev=NULL;
free(p);
}
else
{
p->prev->next=p->next;
p->next->prev=p->prev;
free(p);
}
}
p=p->next;
}
}
if(p==NULL)
{
printf("Value not found\n");
}
return head;
}
NODE rev(NODE head)
{
NODE p=head;
NODE temp=NULL;
if(head==NULL)
{
printf("List is empty\n");
return head;
}
else if(head->next==NULL)
return head;
else
{
while(p!=NULL)
{
temp=p->prev;
p->prev=p->next;
p->next=temp;
p=p->prev;
}
head=temp->prev;
return head;
}
}
NODE rev_n(NODE head,int n)
{
NODE p=head,curr=head,temp=NULL;
int count=1;
if(head==NULL)
{
printf("List is empty\n");
return head;
}
else if(head->next==NULL)
{
if(n==1)
return head;
}
else
{
while(p!=NULL && count!=n)
{
p=p->next;
count++;
}
if(count==n)
{
curr->prev=p->next;
p->next->prev=curr;
p->next=NULL;
while(curr!=NULL)
{
temp=curr->prev;
curr->prev=curr->next;
curr->next=temp;
curr=curr->prev;
}
head=temp->prev;
}
}
return head;
}
void print(NODE head)
{
NODE p=head;
if(head==NULL)
{
printf("List is empty\n");
return;
}
while(p!=NULL)
{
printf("%d\n",p->data);
p=p->next;
}
}
int main()
{
NODE head=NULL,p=NULL;
int ch,j=1,data,val,i,n,e,value,v,r;
clrscr();
printf("Enter number of values to be inserted\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Value to be inserted\n");
scanf("%d",&e);
head=insert_front(e,head);
}
while(j!=0)
{
printf("Enter choice\n");
printf("1.Insert_front\t2.Insert_rear\t3.Insert_left\t4.del_rear\t5.Del_value\t6.reverse\t7.reverse_n\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("enter value to be inserted\n");
scanf("%d",&val);
head=insert_front(val,head);
break;
case 2:
printf("enter value to be insrted\n");
scanf("%d",&v);
head=insert_rear(v,head);
break;
case 3:
printf("Enter value to be inserted\n");
scanf("%d",&value);
p=head->next;
head=insert_left(value,head,p);
break;
case 4:
head=del_rear(head);
break;
case 5:
printf("Enter value to be deleted\n");
scanf("%d",&data);
head=del_val(head,data);
break;
case 6:
head=rev(head);
break;
case 7:
printf("Enter value to reverse\n");
scanf("%d",&r);
head=rev_n(head,r);
break;
case 8:
printf("**********\n");
print(head);
break;
default:
printf("Invalid\n");
exit(0);
break;
}
printf("ENter other thn '0' to continue\n");
scanf("%d",&j);
}
getch();
return 0;
}

