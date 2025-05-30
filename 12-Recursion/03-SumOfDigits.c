//Accept a  number 'N' and calculate the sum  of digits in the number using recursion 

#include<stdio.h>
#include<stdlib.h>

long long int SumOfDigits(long long int no,long  long int sum)
{	

	if(no!=0)
	{
		sum = SumOfDigits(no/10,sum+(no%10));
	}

	return sum;
}

int main()
{
	long long int no;
	long long int sum = 0;
	
	printf("\nEnter the number: ");
	scanf("%lld",&no);
	
	printf("\nThe No: %lld has %lld digits",no,SumOfDigits(no,sum));
	
	return 0;
}