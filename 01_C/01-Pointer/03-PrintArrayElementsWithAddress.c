#include<stdio.h>
#include<stdlib.h>


int main(){

    int *array1, *array2;
    unsigned int size = 0;

    printf("Enter the size of array: ");
    scanf("%d",&size);

    array1 = (int*)malloc(size*sizeof(int));

   
    
    for(int i=0;i<size;i++){
        printf("array1[%d]: ",i);
        scanf("%d",&array1[i]);
   
    }


    printf("/n!!!Array/n!!!");
    for(int i=0;i<size;i++){
        printf("\narray1[%d]: %d     Address of array2[%d]: %d\n",i,array1[i],i,&array1[i]);     
    }

   
    return 0;
}