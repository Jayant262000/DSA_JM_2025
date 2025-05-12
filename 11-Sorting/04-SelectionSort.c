//Write a C program to Accept an array and Perform Selection sort.

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

int * SelectionSort(int *array, int size) 
{
	int small = 0;
	int index = 0;
	int temp = 0;
	int flag = 0;
	
    for (int i = 0; i < size-1; i++) {
        small = array[i];
        for(int j=i;j<size;j++)
		{
            if(small>array[j])
			{
				small = array[j];
				index = j;
				flag=1;
			}
			else
			{
				flag=0;
			}
        }
		if(flag==1)
		{
			temp = array[i];
			array[i] = array[index];
			array[index] = temp;
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
	
	array = SelectionSort(array,size);
	
	printf("\n********* Sorted array *********\n");
	DisplayArray(array,size);
	

    return 0;
}