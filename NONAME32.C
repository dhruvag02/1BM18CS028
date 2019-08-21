
#include<stdio.h>
#include<conio.h>
void push1(char ,char PE[20],int *top3);
void push2(char ,char OS[20],int *top2);
char pop(char OS[20],int *top2);
char scan(char IE[20],int *top1);
int is_opr(char);
int is_opt(char);
int empty(int *top2);
int precd(char);
int main()
{
char IE[20],OS[20],PE[20];
int top1=-1;
int top2=-1;
int top3=-1;
char symb,topsymb;
printf("Enter the infix expression\n");
gets(IE);
while(top1>=-1 && top1<=19)
{
	symb=scan(IE,&top1);
    if(is_opr(symb))
    {push1(symb,PE,&top3);}
    else if(is_opt(symb))
    {
    while(!empty(&top2) && precd(OS[top2])>precd(symb))
	{
	 topsymb=pop(OS,&top2);
	 push1(topsymb,PE,&top3);
	 }// End of while
	 push2(symb,OS,&top2);
     }//End of else if
     else if(symb==')')
     {
       while(OS[top2]!='(')
       {
       topsymb=pop(OS,&top2);
       push1(topsymb,PE,&top3);
       }//End of while
       pop(OS,&top2);
     }//End of else if
}//End of while
  while(!empty(&top2))
  {
  topsymb=pop(OS,&top2);
  push1(topsymb,PE,&top3);
  }//End of while

printf("Postfix expression is displayed\n");
gets(PE);
return 0;
}

void push1(char ch,char PE[20],int *top3)
{
if(*top3==19)
{printf("Stack overflow\n");
return;}
*top3=*top3+1;
PE[*top3]=ch;
}
void push2(char c,char OS[20],int *top2)
{
if(*top2==19)
{printf("Stack overflow\n");
return;}
*top2=*top2+1;
OS[*top2]=c;
}

char pop(char OS[20],int *top2)
{
char e;
if(*top2==-1)
{printf("Stack underflow\n");
return -99999;}
e=OS[*top2];
*top2=*top2-1;
return e;
}

int is_opt(char ch)
{
if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
return 1;
else
return 0;
}

int is_opr(char c)
{
if((c>='a' && c<='z') || (c>='A' && c<='Z'))
return 1;
else
return 0;
}
int empty(int *top2)
{
if(*top2==-1)
return 1;
else
return 0;
}
int precd(char s)
{
switch(s)
{
case '^':
return 3;
break;
case '+':
case '-':
return 1;
break;
case '*':
case '/':
return 2;
break;
default :
return 0;
break;
}
char scan(char IE[20],int *top1)
{
 *top1=*top+1;
 return IE[*top];
 }
