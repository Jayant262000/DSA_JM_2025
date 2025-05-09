//write a function to reverse the  strings 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *MemoryAllocation(int size)
{
    char *arr = (char *)malloc((size + 1) * sizeof(char));  
   

    printf("\n----------Enter Data----------\n");
    getchar(); 
    fgets(arr, size + 1, stdin); 

    return arr;
}

void DisplayArray(char *arr)
{
    printf("\n---------Data--------\n");
    printf("%s", arr); 
	
}

void DisplayReverseString(char *arr,int size)
{
    printf("\n---------Reverse String--------\n");
	
	for(int i = size; i>=0;i--)
	{
		printf("%c", arr[i]); 
	}
}

int main()
{
    char *array = NULL;
    int size;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    array = MemoryAllocation(size);
    DisplayArray(array);
	DisplayReverseString(array,size);

    free(array); 

    return 0;
}
