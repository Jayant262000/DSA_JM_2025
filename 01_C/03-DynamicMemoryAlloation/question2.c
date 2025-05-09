 /*  

   write a C program to input and print text using Dynamic Memory Allocation.
   - create memory for text string at run time using malloc() function, 
   - text string will be inputted by the user and displayed.
   - Using free() function  release the occupied memory.

*/


#include <stdio.h>
#include <stdlib.h>

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
