//Accept a  number 'N' and calculate the number of digits in the number using recursion 

#include<stdio.h>
#include<stdlib.h>

long long int Digits(long long int no,long  long int cnt)
{	

	if(no!=0)
	{
		cnt = Digits(no/10,cnt+1);
	}

	return cnt;
}

int main()
{
	long long int no;
	long long int cnt = 0;
	
	printf("\nEnter the number: ");
	scanf("%lld",&no);
	
	printf("\nThe No: %lld has %lld digits",no,Digits(no,cnt));
	
	return 0;
}