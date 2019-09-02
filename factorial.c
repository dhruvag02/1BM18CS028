//Factorial Program in C using recursion

#include<stdio.h>
int fact(int n);
int main()
{
	int num,f;
	printf("enter the number \n");
	scanf("%d",&num);
	f=fact(num);
	printf("%d",f);
	return 0;
}
int fact(int n)
{
	if(n==0)
		return 1;
	else
		return (n*fact(n-1));
}

