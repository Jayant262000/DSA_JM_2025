/*

	- Write a C program which allocates an array dynamically.
	- Implement logic that removes duplicate elements from the array. 


*/
#include<stdio.h>
#include<stdlib.h>

int * AcceptElementsInArray(int * array, int size){
	for(int i=0;i<size;++i){
		scanf("%d",(array+i));
	}
	
	return array;
}

void RemoveDuplicateElements(int arr[], int size){
	
  int k=0;
	for(int i=0;i<size;++i){
		for(int j = i+1; j<size;++j){
			if(arr[i]==arr[j]){
				
				k = j;
				while(k!=size-1)
				{
				  arr[k] = arr[k+1];
				  k++;
				}
				j=j-1;
				size=size-1;
				arr = (int*)realloc(arr,(size)*sizeof(int));
				
			}
			
		}
		
	}
		int i=0;
	while(size!=0){
				printf("Arr[%d]: %d\n",i,arr[i]);
				i++;
				size--;

	}
	
}

void ShowArrayElements(int arr[], int size){
	
	for(int i=0;i<size;++i){
		printf("Arr[%d]: %d\n",i,arr[i]);
	}
	
}

int main()
{
	// Logic

	   int * array;
   int size;
   
   printf("Enter the size of array: ");
   scanf("%d",&size);
   array = (int*)malloc(size*sizeof(int));  
   
   printf("Enter the element in array:\n");	
   array = AcceptElementsInArray(array,size);
	
   printf("Array elements:\n");
   ShowArrayElements(array,size);
   
   printf("Array elements after duplicates are removed:\n");
   RemoveDuplicateElements(array,size);
	return 0;
}