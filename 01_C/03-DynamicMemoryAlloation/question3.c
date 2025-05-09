/*

   write a C program to read a one dimensional array, print sum of all elements along with inputted array elements using Dynamic Memory Allocation.
   - allocate memory for one dimensional array and print the array elements along with sum of all elements. 
   - Memory will be allocated in this program using malloc() and released using free().

*/

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
	printf("\n---------Data--------\n");
	for(int i =0;i<size;i++)
	{
		printf("arr[%d]: %d\n",i,arr[i]);
	}
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