/*

    - Write a C program which accepts an array dynamically
    - Find the subarray with maximum sum

*/


#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>


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


void DisplaySubarray(int * array,int size){
	
	int MaxS = INT_MIN;
	int CurrentS = 0;
	int iStart = 0;
	int iEnd = 0;

	for(int i=0;i<size;i++)
	{
		CurrentS = CurrentS + array[i];
		
		if(CurrentS!=0&&CurrentS >= MaxS)
		{
			iEnd = i;
		}
		
		MaxS = fmax(CurrentS,MaxS);
		
		if(CurrentS<0)
		{
			CurrentS = 0;
		}
		if((MaxS==array[i])&&CurrentS==MaxS)
			{
				iStart = i;
				iEnd = i;
			}
		
	}
	printf("\n*******Subarray with maximum sum**********\n");
	for(;iStart<=iEnd;iStart++)
	{
		printf("arr[%d]: %d\n",iStart,array[iStart]);
		
	}
	
	printf("\nmaximum sum: %d\n",MaxS);
	
}



void DisplayArray(int * array,int size){
	
	int sum1 = 0;
	int sum2 = 0;
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
	
	DisplaySubarray(array,size);
	


	return 0;
}