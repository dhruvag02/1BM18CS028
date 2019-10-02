#include<stdio.h>
#include<conio.h>
#include<stdio.h>
#define S 6
struct node
{
int data;
struct node *next;
};
typedef struct node *NODE;
NODE getnode();
NODE insert(int item,NODE head,int *len);
NODE del(NODE head,int *len);
void display(NODE head);


int main()
{
NODE head=NULL;
int ch,j=1,len=0,e;
clrscr();
while(j!=0)
	{
		printf("Enter the choice\n");
		printf("1.INSERT\t2.DELETE\t3.DISPLAY\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("You entered INSERT\n");
			printf("ENter the element to be inserted\n");
			scanf("%d",&e);
			head=insert(e,head,&len);
			break;
			case 2:
			printf("You entered DELET\n");
			head=del(head,&len);
			break;
			case 3:
			printf("You entered DISPLAY\n");
			display(head);
			break;
			default:
			printf("INVALID\n");
			exit(0);
			break;
		}
	printf("Enter other than '0' to continue\t");
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

NODE insert(int item,NODE head,int *len)
{
NODE p,q;
if(*len==S-1)
{printf("QUEUE overflow\n");
return head;}
q=getnode();
q->data=item;
q->next=NULL;
if(head==NULL)
{
*len=*len+1;
return q;
}
else
{
p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=q;
*len=*len+1;
return head;
}
}


NODE del(NODE head,int *len)
{
NODE p;
if(head==NULL)
{printf("Queue underflow\n");
return head;}
p=head;
printf("DELETED element=%d\n",p->data);
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
   printf("%d\n",p->data);
   p=p->next;
 }
}