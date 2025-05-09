//write a function to find the length of a string.

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
	
	printf("\n-------Length of String-------\n");
	printf("%d",strlen(arr));
}

int main()
{
    char *array = NULL;
    int size;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    array = MemoryAllocation(size);
    DisplayArray(array);

    free(array); 

    return 0;
}
