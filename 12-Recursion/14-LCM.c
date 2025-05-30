/*

   write C program to find the LCM (Lowest Common Multiple) of given numbers using recursion

*/

#include<stdio.h>
#include<stdlib.h>

int LCM(int no1, int no2)
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
		LCM(no1, no2%no1);
	}
	
}

int main()
{
	int no1,no2;
	int lcm = 0;
	
	printf("\nEnter the 1st number: ");
	scanf("%d",&no1);
	
	printf("\nEnter the 2nd number: ");
	scanf("%d",&no2);
	
	lcm = (no1*no2)/LCM(no1, no2);
	printf("\nLCM of %d & %d: %d",no1,no2,lcm);
	
	return 0;
}