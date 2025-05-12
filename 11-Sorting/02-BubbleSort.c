//Write a C program to Accept an array and Perform Bubble sort.


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


int * BubbleSort(int * array, int size)
{
	int temp = 0;
	
	for(int i = 0;i<size;i++)
	{
		for(int j = 0;j<(size-i);j++)
		{
			if(array[j]>array[j+1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
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
	
	array = BubbleSort(array,size);
	
	printf("\n********* Sorted array *********\n");
	DisplayArray(array,size);
	

    return 0;
}
