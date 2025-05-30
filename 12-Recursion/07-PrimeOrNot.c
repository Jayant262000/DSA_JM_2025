/*

   write C program to check a given number is prime or not using recursion.

*/


#include<stdio.h>
#include<stdlib.h>

int PrimeOrNot(int no,int cnt,int flag)
{	

	if((flag==0)&&(cnt<=no/2))
	{
		if(no%cnt==0)
		{
			flag=1;
		}
		PrimeOrNot(no,cnt+1,flag);
	}
	else
		return flag;

}

int main()
{
	 int no;
	 int cnt = 2;
	int flag = 0;
	
	printf("\nEnter the number: ");
	scanf("%d",&no);
	
	
	if(PrimeOrNot(no,cnt,flag)==1)
	{
		printf("\nThe Number %d is not a prime Number",no);
	}
	else
	{
		printf("\nThe Number %d is a prime Number",no);
	}
	
	return 0;
}