// accept two numbers and find the GCD of the numbers  using recursion 

#include<stdio.h>
#include<stdlib.h>

int GCD(int no1, int no2)
{
	int temp = 0;
	
	
	if(no2==0)
	{
		return no1;
	}
	else
	{
		if(no2<no1)
		{
			temp = no2;
			no2 = no1;
			no1 = temp;
		}
		GCD(no1, no2%no1);
	}
	
}

int main()
{
	int no1,no2;
	int gcd = 0;
	
	printf("\nEnter the 1st number: ");
	scanf("%d",&no1);
	
	printf("\nEnter the 2nd number: ");
	scanf("%d",&no2);
	
	gcd = GCD(no1, no2);
	printf("\nGCD of %d & %d: %d",no1,no2,gcd);
	
	return 0;
}