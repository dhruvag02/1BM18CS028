#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define S 5
struct node
{
int data;
struct node *next;
};
typedef struct node *NODE;
NODE getnode();
NODE push(int item,NODE head,int *len);
NODE pop(NODE head,int *len);
void display(NODE head);
int main()
{
NODE head=NULL;
int ch,len=0,j=1,e;
while(j!=0)
{
printf("Enter the choice\n");
printf("1.PUSH\t2.POP\t3.DISPLAY\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("You entered PUSH\n");
printf("Enter the element to be pushed\n");
scanf("%d",&e);
head=push(e,head,&len);
break;
case 2:
printf("You entered POP\n");
head=pop(head,&len);
break;
case 3:
printf("You entered DISPLAY\n");
display(head);
break;
default:
printf("INVALUD\n");
exit(0);
break;
}
printf("ENter other than '0' to continue\t");
scanf("%d",&j);
}
return 0;
}
NODE getnode()
{
NODE p;
p=(NODE) malloc(sizeof(struct node));
if(p!=NULL)
{return p;}
else
{printf("Memory not allocated\n");
return NULL;}
}
NODE push(int item,NODE head,int *len)
{
NODE p;
if(*len==S-1)
{printf("STack overflow\n");
return head;}
p=getnode();
p->data=item;
p->next=head;
head=p;
*len=*len+1;
return head;
}
NODE pop(NODE head,int *len)
{
NODE p;
if(head==NULL)
{printf("Stack underflow\n");
return head;}
p=head;
printf("Popped element=%d\n",p->data);
head=p->next;
free(p);
*len=*len-1;
return head;
}
void display(NODE head)
{
NODE p;
if(head==NULL)
{printf("List is empty\n");
return;}
p=head;
while(p!=NULL)
{
printf("************\n");
printf("%d\n",p->data);
p=p->next;
}
}
