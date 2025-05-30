// accept an array and display the array in reverse order using recursion 

#include<stdio.h>
#include<stdlib.h>

int * MemoryAllocation(int * arr, int * size)
{
	printf("\nEnter the size of Array: ");
	scanf("%d",size);
	
	arr = (int *)malloc(*size*sizeof(int));
	if(arr==NULL)
	{
		printf("\n!!! Allocation is failed !!!\n");
	}
	else
	{
		printf("\n Memory Allocation is Successfull ......\n");
	}
	
	printf("\n...Enter the elements of Array...\n");
	for(int i =0;i<*size;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	return arr;
	
}

void Display(int * arr, int size)
{
	for(int i = 0; i<size; i++)
	{
		printf("%d  ",arr[i]);
	}
}

void ReverseDisplay(int * arr, int size)
{
	if(size!=0)
	{
		printf("%d  ",arr[size-1]);
	    ReverseDisplay(arr, size-1);
		
	}
}

int main()
{
	int * array = NULL;
	int size;
	
	array = MemoryAllocation(array,&size);
	
	printf("\n ********** Normal Array **********\n");
	Display(array,size);
	
	printf("\n ********** Reverse Array **********\n");
	ReverseDisplay(array,size);
	
	free(array);
	array = NULL;
	
	return 0;
}