#include<stdio.h>
void push(int,int stack[20],int *top);
int pop(int stack[20],int *top);
int is_opr(char);
int main()
{
char postfix[20],ch;
int stack[20];
int i=0,op1,op2,m,result;
int top=-1;
printf("Enter the postfix expression\n");
scanf("%s",postfix);
while(postfix[i]!='\0')
{
ch=postfix[i];
   if(is_opr(ch))
    {
      printf("Enter value of %c:",ch);
      scanf("%d",&m);
      push(m,stack,&top);
     }
        else 
	 {
           printf("%c is an operator\n",ch);
           op1=pop(stack,&top);
           op2=pop(stack,&top);
           switch(ch)
              {
                case'/':
		result=op2/op1;
		push(result,stack,&top);
		break;
		case'*':
		result=op2*op1;
		push(result,stack,&top);
		break;
		case'+':
   		result=op2+op1;
		push(result,stack,&top);
		break;
 		case'-':
		result=op2-op1;
		push(result,stack,&top);
		break;
		default:
  		printf("Invalid operation\n");
		push(op2,stack,&top);
		push(op1,stack,&top);
		break;
	       }
	    }
     i++;
}
result=pop(stack,&top);
printf("Required result=%d\n",result);
return 0;
}
void push(int e,int stack[20],int *top)
{
if(*top==19)
{printf("Stack overflow\n");
return;}
*top=*top+1;
stack[*top]=e;
}
 
int pop(int stack[20],int *top)
{
int v;
if(*top==-1)
{printf("Stack underflow\n");
return -9999;}
v=stack[*top];
*top=*top-1;
return v;
}
 
int is_opr(char ch)
{
if(ch>='a' && ch<='z' || ch>='A' && ch<='Z')
return 1;
else 
return 0;
}

