#include<stdio.h>
#include<stdlib.h>

int * MemoryAllocation(int*,int*);
int * InsertionSort();
void Display();


int main()
{
    int * array = NULL;
    int size;

    array = MemoryAllocation(array,&size);

    printf("\n********************Array before sorting********************\n");
    Display(array,size);

    array = InsertionSort(array,size);

    printf("\n********************Array After sorting********************\n");
    Display(array,size);

    free(array);
    array = NULL;
    return 0;


}

int * MemoryAllocation(int * arr, int* size)
{
    printf("\nEnter the Size of Array: ");
    scanf("%d",size);

    arr = (int *)malloc(*size*sizeof(int));

    if(arr==NULL)
    {
        printf("\n!!!Memory Allocation failed!!!\n");
        return NULL;
    }
    else
    {
        printf("\nMermory Allocation Successfull........\n");
    }
    
    printf("\n____________________Enter the elements in array____________________\n");

    for(int i = 0;i<*size;i++)
    {
        scanf(" %d",&arr[i]);
    }
    return arr;
}

void Display(int * arr, int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d\n",arr[i]);
    }
}


int * InsertionSort(int * arr, int size)
{
    int j = 0;
    int ele = 0;
    for(int i = 1;i<size;i++)
    {
        ele = arr[i];
        j = i-1;
        while(j>=0)
        {
            if(ele<arr[j])
            {
                arr[j+1] = arr[j];
                j--;
            }
            else
                break;
        }
        arr[j+1] = ele;

    }

    return arr;
}