//Fibonacci series

#include<stdio.h>
int fib(int n);
int main()
{
	int num;
	printf("enter n value \n");
	scanf("%d",&num);
	printf("%d",fib(num));
	return 0;
}
int fib(int n)
{
	if(n==1)
		return 0;
	else if(n==2)
		return 1;
	else
		return ((fib(n-1)+fib(n-2)));
}

