/*

      write a C program to create memory for int, char and float variable at run time.
     - create memory for int, char and float variables at run time using malloc() function
     - and before exiting the program release the memory allocated at run time by using free() function.
*/


#include <stdio.h>
#include <stdlib.h>

void MemoryAllocation(int **Integer, char **Character, float **Float)
{
    *Integer = (int *)malloc( sizeof(int));  
	*Character = (char *)malloc( sizeof(char)); 
	*Float = (float *)malloc( sizeof(float)); 

  
    printf("\n----------Enter Data----------\n");
    printf("Integer: ");
	scanf("%d",*Integer);
	
	printf("Character: ");
	scanf(" %c",*Character);
	getchar();

	
	printf("Float: ");
	scanf(" %f",*Float);


}

void Display(int *Integer, char *Character, float *Float)
{
    printf("\n---------Data--------\n");
     printf("Integer: %d\n",*Integer);
	 printf("Character: %c\n",*Character);
	 printf("Float: %f\n",*Float);
}

int main()
{
    int * integer;
	char *character;
	float *fLoat;

     MemoryAllocation(&integer,&character,&fLoat);
    Display(integer,character,fLoat);

    free(integer); 
	free(character); 
	free(fLoat); 

    return 0;
}
