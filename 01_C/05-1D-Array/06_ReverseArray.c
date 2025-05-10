//Accept n elements in an array and revert the array 


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



void DisplayArrayReverse(int* array, int index) {
    if (index < 0) {
        return;
    }
    printf("array[%d]: %d\n", index, array[index]);
    DisplayArrayReverse(array, index - 1);
}


int main()
{
	
	int * array = NULL;
	int size= 0;
	
	printf("*****Accept elements in array*****\n");
	array = AceptArrayElements(array,&size);
	
	
	printf("*****Display array*****\n");
	DisplayArrayReverse(array,size-1);

	return 0;
}