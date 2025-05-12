//Write a C program to implement Linear Search. Also, print the time complexity at the start of the program. Follow this pattern for all upcoming questions.
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

void LinearSearch(int *array, int size,int key) 
{
	int flag = 0;
	int index = 0;
    for (int i = 0; i < size; i++) {
        
		if(array[i]==key)
		{
		   flag = 1;
		   index = i;
		}
    }
	
	if(flag==1)
	{
		printf("\nThe element %d found at position: %d in array\n",key,index);
	}
	else
	{
		printf("\n!!!The element is not found!!!\n");
	}

	printf("\nThe time complexity is O(n)\n");
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
	int key;
	
	printf("\nEnter Size: ");
	scanf("%d",&size);
	
    printf("\n********* Enter  Elements *********\n");
    array = AllocateMemory(array, size);
	
    DisplayArray(array,size);
	
	printf("\nEnter the key: ");
	scanf("%d",&key);
	
	LinearSearch(array,size,key);
	
    return 0;
}