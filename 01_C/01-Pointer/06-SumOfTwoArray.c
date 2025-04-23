#include<stdio.h>
#include<stdlib.h>



int * ReturnArray(int *arr1, int *arr2,int size){

    int * arrSum = NULL;
	
	arrSum = (int*)malloc(size*sizeof(int));

    for(int i=0;i<size;i++)
    {
		arrSum[i] = arr1[i]+arr2[i];
    } 

    return arrSum;

}


int main(){

    int *array1 = NULL;
    int	*array2 = NULL;
	int *arraySum = NULL;
    unsigned int size = 0;

    printf("Enter the size of array: ");
    scanf("%d",&size);

    array1 = (int*)malloc(size*sizeof(int));
    array2 = (int*)malloc(size*sizeof(int));
   
    
    for(int i=0;i<size;i++){
        printf("array1[%d]: ",i);
        scanf("%d",&array1[i]);
        printf("array2[%d]: ",i);
        scanf("%d",&array2[i]);
    }

	arraySum = ReturnArray(array1,array2,size);
    printf("/n!!!Addition of 2 arrays/n!!!");
    for(int i=0;i<size;i++){
        printf("\narray1[%d]: %d	array2[%d]: %d	  arraySum[%d]: %d\n",i,array1[i],i,array2[i],i,arraySum[i]);     
    }

    

    return 0;
}