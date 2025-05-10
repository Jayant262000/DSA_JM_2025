//Accept n elements in an array and search a perticular element 


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

void SearchEle(int * arr,int size,int ele){
	int flag = 0;
	for(int i = 0;i<size;++i){
		
		if(arr[i]==ele){
			printf("\nElement Fount at: array[%d]: %d\n",i,arr[i]);
			flag = 1;
		}
	}
	
	if(flag==0){
			printf("\n!!!! Element not found !!!!\n");
	}
	
}

void DisplayArray(int * array,int size){
	

	printf("Array: \n");
	for(int i = 0;i<size;++i){
		printf("array[%d]: %d\n",i,array[i]);
		
	}
	
	
}


int main()
{
	
	int * array = NULL;
	int size,no = 0;
	
	printf("*****Accept elements in array*****\n");
	array = AceptArrayElements(array,&size);
	
	
	printf("*****Display array*****\n");
	DisplayArray(array,size);
	
	printf("\nEnter the element to search: \n");
	scanf("%d",&no);
	
	SearchEle(array,size,no);

	return 0;
}