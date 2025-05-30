// write a C Program to print Fibonacci series using Recursion

#include<stdio.h>
#include<stdlib.h>

void Fibonacci(int no,int fib,int i)
{	
	if(no != 0)
	{
		
		printf("%d\t",fib);
		Fibonacci(no-1,fib+i,fib);
	}
}

int main()
{
	int no;
	int fib = 0;
	int i = 1;
	
	printf("\nEnter the number: ");
	scanf("%d",&no);
	
	Fibonacci(no,fib,i);
	
	return 0;
}