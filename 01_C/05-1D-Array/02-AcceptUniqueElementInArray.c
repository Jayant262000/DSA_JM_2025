/*

	- Write a C program which allocates an array dynamically.
	- Implement logic which accepts only unique elements in array  


*/

#include<stdio.h>
#include<stdlib.h>

void AcceptUniqueElements(int arr[], int size){
	int rev=0;
	int i=0;
	
    do{
	 
		scanf("%d",(arr+i));  
		if(i==0)
		{
		    i++;	
		}	
	  else
	  { 
        
		rev=i;
        while(rev!=0){ 
			if(arr[i]==arr[rev-1]){
				printf("!!! The element arr[%d]:%d is already present in the array!!!\n!!!Please Enter the other element !!!\n",i,arr[i]);
				i--;
					break;
			}			
			rev--;
			
		}
	       i++;		
	  }

	  
  }while(i<size);
}

void ShowArrayElements(int arr[], int size){
	
	for(int i=0;i<size;++i){
		printf("Arr[%d]: %d\n",i,arr[i]);
	}
	
}

int main()
{
	// Logic
  int * array = NULL;

  int size;

  printf("Enter the size of array: ");
  scanf("%d",&size);

    array = (int*)malloc(size*sizeof(int));
  	printf("Enter the elements in array:\n");
    AcceptUniqueElements(array,size);
  
	printf("Array elements:\n");
	ShowArrayElements(array,size);
	
	return 0;
}