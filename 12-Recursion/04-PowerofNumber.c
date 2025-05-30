// Write a C program to Calculate Power of a Number using recursion

#include<stdio.h>
#include<stdlib.h>

long long int PowerOfNumber(int no,int exp,long long power)
{	
	if(exp!=0)
	{
		power = PowerOfNumber(no,exp-1,power*no);
	}

	return power;
}

int main()
{
	int no;
	int exp;
	long long int power = 1;
	
	
	printf("\nEnter the number: ");
	scanf("%d",&no);
	
	printf("\nEnter the ^exponent: ");
	scanf("%d",&exp);
	
	printf("\npower of number: %d is %lld",no,PowerOfNumber(no,exp,power));
	
	return 0;
}