#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *lchild;
struct node *rchild;
};
typedef struct node *NODE;
void inorder(NODE root);
void preorder(NODE root);
void postorder(NODE root);
NODE insert(int item,NODE root);
int check_root(NODE root);
int search(NODE root,int data);
NODE getnode(int item);
int main()
{
int ch,j=1,n,i,v;
NODE root=NULL;
int arr[20],data;
clrscr();
printf("Enter number of elements in array\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter %dth element\n",i);
scanf("%d",&arr[i]);
}
while(j!=0)
{
printf("Enter Choice-\n");
printf("1.Inorder\t2.preorder\t3.postorder\t4.Insert\t5.Insert all elements of array\t6.Search\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
if(check_root(root)==1);
inorder(root);
break;
case 2:
if(check_root(root)==1);
preorder(root);
break;
case 3:
if(check_root(root)==1);
postorder(root);
break;
case 4:
printf("Enter value to be inserted\n");
scanf("%d",&v);
root=insert(v,root);
break;
case 5:
for(i=0;i<n;i++)
{
root=insert(arr[i],root);
}
break;
case 6:
printf("Enter value to be searched\n");
scanf("%d",&data);
printf("%d\n",search(root,data));
break;
default:
printf("Invalid case\n");
exit(0);
break;
}
printf("Enter other than '0' to continue\n");
scanf("%d",&j);
}
getch();
return 0;
}

void inorder(NODE root)
{
if(root==NULL)
return;
inorder(root->lchild);
printf("%d\t",root->data);
inorder(root->rchild);
}

void preorder(NODE root)
{
if(root==NULL)
return;
printf("%d\n",root->data);
preorder(root->lchild);
preorder(root->rchild);
}

void postorder(NODE root)
{
if(root==NULL)
return;
postorder(root->lchild);
postorder(root->rchild);
printf("%d\n",root->data);
}

NODE insert(int item,NODE root)
{
if(root==NULL)
return (getnode(item));
if(item<root->data)
root->lchild=insert(item,root->lchild);
else if(item>=root->data)
root->rchild=insert(item,root->rchild);
return root;
}

NODE getnode(int item)
{
NODE p;
p=(NODE)malloc(sizeof(struct node));
p->data=item;
p->lchild=NULL;
p->rchild=NULL;
return p;
}

int check_root(NODE root)
{
if(root!=NULL)
return 1;
else
printf("Root is null,insert item\n");
return 0;
}

int search(NODE root,int data)
{
while(root!=NULL)
{
if(data>root->data)
root=root->rchild;
else if(data<root->data)
root=root->lchild;
else
return 1;
}
return 0;
}

