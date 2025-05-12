//Write a C program to Accept an array and Perform Insertion sort.

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


/*
int * InsertionSort(int * array, int size)
{
	int temp = 0;
	int small=0;
	
	for(int i = 1;i<size;i++)
	{
		if(array[i]<array[i-1])
		{
			for(int j = i;j>=1;j--)
			{
				
				temp = array[j];
				array[j] = array[j-1];
				array[j-1] = temp;
				
			}	
		}
	}
	
	return array;
}
*/

int * InsertionSort(int *array, int size) 
{
	int key = 0;
    for (int i = 1; i < size; i++) {
         key = array[i];         
        int j = i - 1;

        while (j >= 0 && array[j] > key) 
		{
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;  
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
	
	array = InsertionSort(array,size);
	
	printf("\n********* Sorted array *********\n");
	DisplayArray(array,size);
	

    return 0;
}
