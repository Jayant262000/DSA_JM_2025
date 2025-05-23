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
	int gap = size/2;
    int temp=0;
    int j = 0;
	int i = 0;
	int k = 0;

	while(gap>0)
	{ 
		i=0;
		j = gap;
		while((i<(size-gap)+1)&&(j<size))
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
    
        gap = gap/2;
	}

	i = 0;
	j = 0;

	for( i = 1;i<size;i++)
	{
		k = array[i];
		j = i-1;
		while(j>=0&&(k<array[j]))
		{
			array[j+1] = array[j];
			j--;
		}

		array[j+1] = k;
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
