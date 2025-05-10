//Accept n elements in an array and display the differance between the sum of 1st half  and 2nd half of that array                                       


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
	
	int sum1 = 0;
	int sum2 = 0;
	printf("Array: \n");
	for(int i = 0;i<size;++i){
		printf("array[%d]: %d\n",i,array[i]);	
		
		if(i<(size/2))
		{
			sum1 = sum1+array[i];
		}
		else{
			sum2 = sum2+array[i];
		}
	}
	
	printf("\nThe Diff : %d",(sum1-sum2));
	 
}


int main()
{
	
	int * array = NULL;
	int size,no = 0;
	
	printf("*****Accept elements in array*****\n");
	array = AceptArrayElements(array,&size);
	
	
	printf("*****Display array*****\n");
	DisplayArray(array,size);
	


	return 0;
}