#include<stdio.h>
#include<stdlib.h>
struct node{
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
    else{
        printf("Memory could not be allocated\n");
        return NULL;
    }
}
NODE insert_front(int item,NODE head)
{
    NODE p=getnode();
    p->data=item;
    if(head==NULL)
    {
        p->next=NULL;
        p->prev=NULL;
    }
    else
    {
        p->next=head;
        head->prev=p;
        p->prev=NULL;
    }
    head=p;
    return head;
}
NODE insert_rear(int item,NODE head)
{
    NODE p,q;
    q=getnode();
    q->data=item;
    q->next=NULL;
    if(head==NULL)
    {
        q->prev==NULL;
        head=q;
    }
    else
    {
        p=head;
        while(p->next!=NULL)
        {

            p=p->next;
        }
        p->next=q;
        q->prev=p;
    }
    return head;
}
NODE insert_left(int item,NODE head,NODE n)
{
    NODE p=getnode();
    p->data=item;
    if(head==NULL)
    {
        printf("List is empty, no insertion\n");
        return head;
    }
    else
    {
        n->prev->next=p;
        p->prev=n->prev;
        p->next=n;
        n->prev=p;
        return head;
    }
}
NODE del_value(int item,NODE head)
{
    NODE p=head;
    while(p!=NULL)
    {
        if(p->data==value)
        {
            if(p->prev!=NULL)
            {
            p->prev->next=p->next;
            }
            else
            {
            head=p->next;
            }
            if(p->next!=NULL)
            {
            p->next->prev=p->prev;
            }
        free(p);
        return head;
        }
    p=p->next;
}
if(p==NULL)
{
    printf("Value not found\n");
    return head;
}
}
int main()
{
  int ch,j=1,v;
  NODE head=NULL,p;
  while(j!=0)
  {
      printf("Enter choice-\n");
      printf("1.Insert_Front\t2.Inert_rear\t3.Insert_left\t4.Delete_value\t5.Display\n");
      scanf("%d",&ch);
      switch(ch)
      {
      case 1:
        printf("Enter element to be inserted\n");
        scanf("%d",&v);
        head=insert_front(v,head);
        break;
      case 2:
        printf("Enter element to be inserted\n");
        scanf("%d",&v;
        head=insert_rear(v,head);
        break;
      case 3:
        p=p->next;
        printf("Enter element to be insertd\n");
        scanf("%d",&v);
        head=insert_left(v,head,p);
        break;
      case 4:
        printf("Enter value to be deleted\n");
        scanf("%d",&e);
        head=del_val(e,head);
        break;
      default:
        printf("Invalid choice\n");
        exit(0);
        break;
      }
      printf("Enter other than'o' to continue\n");
      scanf("%d",&j);
  }
    return 0;
}
