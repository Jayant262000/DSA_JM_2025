/*

	- Write a C program which allocates two array dynamically.
	- Implement logic to merge and sort two array. 

*/


#include<stdio.h>
#include<stdlib.h>


void AceptArrayElements(int *arr1,int *size1,int *arr2,int *size2){
	
	printf("Enter the size of array1: ");
	scanf("%d",size1);
	
	arr1 = (int*)malloc(*size1*(sizeof(int)));

	printf("Enter the elements in Array1:\n");
	for(int i=0;i<*size1;++i){
		scanf("%d",(arr1+i));
	}
	
	printf("Enter the size of array2: ");
	scanf("%d",size2);
	arr2 = (int*)malloc(*size2*(sizeof(int)));
	
	printf("Enter the elements in Array2:\n");
	for(int j=0;j<*size2;++j){
		scanf("%d",(arr2+j));
	}
}

int * MergeSortArray(int * array1,int size1,int * array2,int size2){
	
	array1 = (int*)realloc(array1,(size1+size2)*sizeof(int));
	int temp=0;
	for(int i=size1;i<size2;++i){
		for(int j = 0;j<size2;++j){
			array1[i] = array2[j];
		}
	}
	for(int i=0;i<(size1+size2);++i){
		for(int j = i+1;j<(size1+size2);++j){
			if(array1[i]>array1[j]){
				temp = array1[i];
				array1[j] = array1[i];
				array1[i] = array1[j];				
			}			
		}
	}

   return array1; 
 
}

void DisplayArray(int * array1,int size1,int * array2,int size2){
	
	printf("Array1: \n");
	for(int i = 0;i<size1;++i){
		printf("array1[%d]: %d\n",i,array1[i]);
	}
	
	printf("Array2: \n");
	
	for(int j = 0;j<size2;++j){
		printf("array2[%d]: %d\n",j,array2[j]);
	}
}


void DisplayArrayAfterMergeSort(int * array1,int size1,int size2){
	
	printf("Array1: \n");
	for(int i = 0;i<(size1+size2);++i){
		printf("array1[%d]: %d\n",i,array1[i]);
	}

}



int main()
{
	
	int * array1, *array2 = NULL;
	int size1,size2 = 0;
	
	printf("*****Accept elements in array*****\n");
	AceptArrayElements(array1,&size1,array2,&size2);
	
	
	printf("*****Display array*****\n");
	DisplayArray(array1,size1,array2,size2);
	
	printf("*****Merge and sort array in one array*****\n");
	array1 = MergeSortArray(array1,size1,array2,size2);
	
	printf("*****Display array after Merge and sort*****\n");
	DisplayArrayAfterMergeSort(array1,size1,size2);
	
	return 0;
}