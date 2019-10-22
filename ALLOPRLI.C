#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
typedef struct node *NODE;
NODE getnode();
NODE insert(int item,NODE head);
NODE del(NODE head);
NODE reverse(NODE head);
void search(NODE head,int data);
void sort(NODE head);
void print(NODE head);
NODE concatenate(NODE head,NODE h1);
NODE merge(NODE head,NODE h1);
int main()
{
NODE head=NULL,h1=NULL;
int e,ch,j=1,n,n1,i,v,val;
int data;
clrscr();
printf("Enter number of nodes to be created\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter the value to be inserted\n");
scanf("%d",&v);
head=insert(v,head);
}
while(j!=0)
{
printf("Enter Choice-\n");
printf("1.Insert\t2.Delete\t3.Reverse\t4.Search\t5.Sort in Ascending\t6.concarenate\t7.Merge\t8.Display\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter the value to be inserted\n");
scanf("%d",&e);
head=insert(e,head);
break;
case 2:
head=del(head);
break;
case 3:
head=reverse(head);
break;
case 4:
printf("Enter the value to be searched\n");
scanf("%d",&data);
search(head,data);
break;
case 5:
sort(head);
break;
case 6:
printf("Create another list\n");
printf("Enter number of nodes\n");
scanf("%d",&n1);
for(i=0;i<n1;i++)
{
printf("Enter data to be inserted\n");
scanf("%d",&val);
h1=insert(val,h1);
}
h1=concatenate(head,h1);
break;
case 7:
printf("Create another list\n");
printf("Enter number of nodes\n");
scanf("%d",&n1);
for(i=0;i<n1;i++)
{
printf("Enter value to be inserted\n");
scanf("%d",&val);
h1=insert(val,h1);
}
h1=merge(head,h1);
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
printf("Enter Other than '0' to continue\n");
scanf("%d",&j);
}
getch();
return 0;
}

NODE getnode()
{
NODE p;
p=(NODE) malloc(sizeof(struct node));
if(p!=NULL)
return p;
else
{printf("Memory could not be allocated\n");
return NULL;}
}
NODE insert(int item,NODE head)
{
NODE p=getnode();
p->data=item;
p->next=head;
head=p;
return head;
}
NODE del(NODE head)
{
NODE p=head;
if(head==NULL)
{printf("List is empty\n");
return head;}
printf("Deleted item=%d\n",p->data);
head=p->next;
free(p);
return head;
}
NODE reverse(NODE head)
{
NODE curr=head,prev=NULL,nextn=NULL;
if(head==NULL)
{printf("List is empty\n");
return head;}
if(head->next==NULL)
return head;
while(curr!=NULL)
{
nextn=curr->next;
curr->next=prev;
prev=curr;
curr=nextn;
}
head=prev;
return head;
}
void search(NODE head,int data)
{
NODE curr=head;
int count=1;
if(head==NULL)
{printf("List is empty\n");
return;}
else if(head->next==NULL)
{
if(head->data==data)
{
printf("Value found at pos %d\n",count);
}
else
{printf("Value do not match\n");}
}
else
{
while(curr!=NULL&&curr->data!=data)
{
curr=curr->next;
count++;
}
if(curr->data==data)
{
printf("Searched value found at pos %d\n",count);
}
else
{
printf("Searched failed\n");
}
}
}
void sort(NODE head)
{
NODE p=head,q=NULL;
int temp;
if(head==NULL)
{printf("List is empty\n");
return;}
while(p->next!=NULL)
{
q=p->next;
while(q!=NULL)
{
if(p->data>q->data)
{
temp=p->data;
p->data=q->data;
q->data=temp;
}
q=q->next;
}
p=p->next;
}
}
void print(NODE head)
{
NODE p=head;
if(head==NULL)
{printf("List is empty\n");
return;}
while(p!=NULL)
{
printf("%d\n",p->data);
p=p->next;
}
}
NODE concatenate(NODE head,NODE h1)
{
NODE curr=head,h2;
if(head==NULL)
return h1;
if(h1==NULL)
return head;
else
{
while(curr->next!=NULL)
{
curr=curr->next;
}
curr->next=h1;
h2=head;
return h2;
}
}
NODE merge(NODE head,NODE h1)
{
if(head==NULL)
return h1;
if(h1==NULL)
return head;
if(head->data<h1->data)
{
head->next=merge(head->next,h1);
return head;
}
else
{
h1->next=merge(h1->next,head);
return h1;
}
}