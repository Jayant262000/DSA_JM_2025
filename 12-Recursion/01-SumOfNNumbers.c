// Accept  N  numbers and calculate sum of all numbers using recursion 

#include<stdio.h>
#include<stdlib.h>

int Addition(int size,int sum)
{
	int no;
	if(size!=0)
	{
		printf("\n\n    %d\n+",sum);
		printf("   ");
		scanf("%d",&no);
		printf("____________\n");
		sum = sum+no;
		printf("=   %d",sum);
		
		sum = Addition(size-1,sum);	
	}
	
	return sum;
	
}

int main()
{
	int size;
	int sum = 0;
	
	printf("\nEnter the no. of numbers: ");
	scanf("%d",&size);

	sum = Addition(size,sum);
	
	printf("\n\n---------------Addition---------------\n");
	printf("\nTotal Sum: %d",sum);
	
	return 0;
}
