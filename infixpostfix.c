#include<stdio.h>
#include<stdlib.h>
#define S 20
void push(char,char stack[S],int *top);
char pop(char stack[S],int *top);
int precd(char);
int isopt(char);

int main()
{
char infix[S],postfix[S],stack[S],temp,item;
int i=0,j=0,top=-1;
printf("Enter infix expression\n");
scanf("%s",infix);
while(infix[i]!='\0')
{
 item=infix[i];
 if(item=='(')
  {
  push(item,stack,&top);
  }
  else if(item>='A'&&item<='Z' || item>='a'&&item<='z')
  {
   postfix[j]=item;
   j++;
  }
  else if(isopt(item)==1)
  {
   temp=pop(stack,&top);
    while(isopt(temp)==1 && precd(temp)>=precd(item))
    {
      postfix[j]=temp;
      j++;
      temp=pop(stack,&top);
     }
     push(temp,stack,&top);
     push(item,stack,&top);
   }
   else if(item==')')
   {
    temp=pop(stack,&top);
    while(temp!='(')
    { 
       postfix[j]=temp;
       j++;
        temp=pop(stack,&top);
     }
     pop(stack,&top);
    }
    else
    {
           printf("Invalid arithmatic expression\n");
         
           exit(0);
     }
  i++;
}
while(top>-1)
{
postfix[j]=pop(stack,&top);
j++;
}
postfix[j]='\0';
printf("postfix expression\n");
printf("%s\n",postfix);
return 0;
}
void push(char item,char stack[S],int *top)
{
if(*top==S-1)
{printf("Stack overflow\n");
return;}
*top=*top+1;
stack[*top]=item;
}
char pop(char stack[S],int *top)
{
char e;
e=stack[*top];
*top=*top-1;
return e;
}
int precd(char ch)
{
if(ch=='^')
{return 3;}
else if(ch=='/'||ch=='*')
{return 2;}
else if(ch=='+'||ch=='-')
{return 1;}
else
{printf("invalid\n");
return 0;}
}
int isopt(char ch)
{
if(ch=='^'||ch=='+'||ch=='-'||ch=='/'||ch=='*')
return 1;
else
return 0;
}


