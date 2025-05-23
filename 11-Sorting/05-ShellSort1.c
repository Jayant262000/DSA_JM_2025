//Write a C program to Accept an array and Perform Shell sort.


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


int * ShellSort(int * array, int size)
{
	int gap = size;
    int temp=0;
    int j = size-1;
	int i = 0;

	while(gap!=0)
	{ 
		i=0;
		if(gap==size)
		{
			j = size-1;
		}
		else
		{
			j = i+gap;
		}
		while((i!=(size-gap)+1)&&(j!=size))
		{
			if(array[i]>array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			i++;
			j++;
		}
        if(gap==size)
		{
			gap = size/2;
		}
		else
		{
			gap = gap/2;
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
	
	array = ShellSort(array,size);
	
	printf("\n********* Sorted array *********\n");
	DisplayArray(array,size);
	

    return 0;
}
