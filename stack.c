#include<stdio.h>

void push(int,int stack[10],int *top);
void display(int stack[10],int *top);
void pop(int stack[10],int *top);
int main()
{
int stack[10];
int top=-1;
push(1,stack,&top);
push(5,stack,&top);
push(10,stack,&top);
display(stack,&top);
pop(stack,&top);
display(stack,&top);
return 0;
}
void push(int e,int stack[10],int *top)
{
if(*top==9)
{printf("Stack overflow\n");
return;}
*top=*top+1;
stack[*top]=e;
}
void display(int stack[10],int *top)
{
int i;
if(*top==-1)
{printf("Stack is empty\n");
return;}
for(i=*top;i>=0;i--){
printf("%d\n",stack[i]);
}}
void pop(int stack[10],int *top)
{
	int e;
	if(*top==-1)
	{printf("Stack underflow\n");
	return;}
	e=stack[*top];
	*top=*top-1;
	printf("Popped value=%d\n",e);
}
	