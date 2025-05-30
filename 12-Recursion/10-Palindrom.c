// accept number and check whether the number is a palidrome or not  using recursion 


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
	
	if(no==ReverseNumber(no,Rno))
	{
		printf("\nThe number %d is Palindrom\n",no);
	}
	else
	{
		printf("\nThe number %d is not Palindrom\n",no);

	}
	
	return 0;
}