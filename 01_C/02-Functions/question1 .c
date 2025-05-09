//Write a function to calculate the sum of all elements of an array

#include<stdio.h>
#include<stdlib.h>


int * MemoryAllocation(int * arr,int size)
{
	arr = (int*)malloc(size*sizeof(int));
	
	printf("\n----------Enter Data----------\n");
	
	for(int i=0;i<size;i++)
	{
		printf("arr[%d]: ",i);
		scanf("%d",&arr[i]);
	}
	
	return arr;
}

void DisplayArray(int * arr,int size)
{
	int sum = 0;
	printf("\n---------Data--------\n");
	for(int i =0;i<size;i++)
	{
		printf("arr[%d]: %d\n",i,arr[i]);
		
		sum = arr[i]+sum;
	}
	
	printf("summ of all elements: %d\n",sum);
}

int main()
{
    int * array = NULL;
	int size;
	
	printf("\nEnter the size of array: ");
	scanf(" %d",&size);
	
	array = MemoryAllocation(array,size);
	DisplayArray(array,size);
	
	
	return 0;

}