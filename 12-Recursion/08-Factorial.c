//Accept number 'N' and calculate factorial of 'N' using recursion

#include<stdio.h>
#include<stdlib.h>

long long int Factorial(int no,long long fact)
{	

	if(no!=0)
	{
		fact = Factorial(no-1,fact*no);
	}

	return fact;
}

int main()
{
	int no;
	long long int fact=1;
	
	printf("\nEnter the number: ");
	scanf("%d",&no);
	
	printf("\nThe factorial of no: %d is %lld ",no,Factorial(no,fact));
	
	return 0;
}