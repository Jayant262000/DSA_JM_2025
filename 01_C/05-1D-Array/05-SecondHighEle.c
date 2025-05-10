/*

	- Write a C program which allocates an array dynamically.
	- Implement logic that returns 2nd large element from the array 

*/


#include<stdio.h>
#include<stdlib.h>


int * AceptArrayElements(int *arr,int *size){
	
	printf("Enter the size of array: ");
	scanf("%d",size);
	
	arr = (int*)malloc(*size*(sizeof(int)));

	printf("Enter the elements in Array:\n");
	for(int i=0;i<*size;++i){
		scanf("%d",(arr+i));
	}
	
	return arr;
}



void DisplayArray(int * array,int size){
	
	int high1,high2 = 0;
	printf("Array: \n");
	for(int i = 0;i<size;++i){
		printf("array[%d]: %d\n",i,array[i]);
		
		if(high2<array[i])
		{
			high1 = high2;
			high2 = array[i];
		}
	}
	
	printf("\n Second highest element from array: %d",high1);
	
}


int main()
{
	
	int * array = NULL;
	int size = 0;
	
	printf("*****Accept elements in array*****\n");
	array = AceptArrayElements(array,&size);
	
	
	printf("*****Display array*****\n");
	DisplayArray(array,size);

	return 0;
}