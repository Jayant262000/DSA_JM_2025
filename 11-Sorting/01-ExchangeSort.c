//Write a C program to Accept an array and Perform Exchange sort.


#include <stdio.h>
#include <stdlib.h>

int *AllocateMemory(int*array,int size) {
    array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) 
	{
       scanf("%d",&array[i]);
    }

    return array;
}


int * ExchangeSort(int * array, int size)
{
	int temp = 0;
	
	for(int i = 0;i<size;i++)
	{
		for(int j = i+1;j<size;j++)
		{
			if(array[i]>array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}	
	}
	
	return array;
}

void DisplayArray(int *array, int size)
{
	printf("\n********* Array *********\n");
    for (int i = 0; i < size; i++) 
	{
        printf("%d\n",array[i]);   
    } 
}


int main() {
 
    int size;
	int *array = NULL;
	
	printf("\nEnter Size: ");
	scanf("%d",&size);
	
    printf("\n********* Enter  Elements *********\n");
    array = AllocateMemory(array, size);
	
    DisplayArray(array,size);
	
	array = ExchangeSort(array,size);
	
	printf("\n********* Sorted array *********\n");
	DisplayArray(array,size);
	

    return 0;
}
