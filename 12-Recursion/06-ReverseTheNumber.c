/* 
   Write C program to reverse an integer number using recursion..

*/


#include<stdio.h>
#include<stdlib.h>

long long int ReverseNumber(long long int no,long long Rno)
{	

	if(no!=0)
	{
		Rno = ReverseNumber(no/10,(Rno*10)+(no%10));
	}

	return Rno;
}

int main()
{
	long long int no;
	long long int Rno=0;
	
	printf("\nEnter the number: ");
	scanf("%lld",&no);
	
	printf("\nThe No: %lld \nReverse No: %lld ",no,ReverseNumber(no,Rno));
	
	return 0;
}