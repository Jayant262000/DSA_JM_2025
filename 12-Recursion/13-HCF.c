/*

    write C program to find the HCF (Highest Common Factor) of a numbers using recursion

*/

#include<stdio.h>
#include<stdlib.h>

int HCF(int no1, int no2)
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
		HCF(no1, no2%no1);
	}
	
}

int main()
{
	int no1,no2;
	int hcf = 0;
	
	printf("\nEnter the 1st number: ");
	scanf("%d",&no1);
	
	printf("\nEnter the 2nd number: ");
	scanf("%d",&no2);
	
	hcf = HCF(no1, no2);
	printf("\nHCF of %d & %d: %d",no1,no2,hcf);
	
	return 0;
}