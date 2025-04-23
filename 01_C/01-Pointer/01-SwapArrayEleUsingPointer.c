#include<stdio.h>
#include<stdlib.h>



void SwapArray(int *arr1, int *arr2,int size){

    int temp=0;

    for(int i=0;i<size;i++)
    {
        temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;

        printf("\narr1[%d]: %d      arr2[%d]: %d\n",i,arr1[i],i,arr2[i]);  
    } 

    

}


int main(){

    int *array1, *array2;
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


    printf("/n!!!Arrays before swapping/n!!!");
    for(int i=0;i<size;i++){
        printf("\narray1[%d]: %d      array2[%d]: %d\n",i,array1[i],i,array2[i]);     
    }

    printf("/n!!!Arrays after swapping/n!!!");
    SwapArray(array1,array2,size);

    return 0;
}