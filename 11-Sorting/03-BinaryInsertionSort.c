#include<stdio.h>
#include<stdlib.h>

typedef struct KeyValue
{

    int key;

}KV;

KV * MemoryAllocation(KV * ,int * );
int BinarySearch(KV *,int , int, int);
KV * BinaryInsertionSort(KV*,int);
void Display(KV*,int);


KV * MemoryAllocation(KV * arr, int * size)
{
    printf("\nEnter the size of an array: ");
    scanf("%d",size);

    arr = (KV*)malloc(*size*sizeof(KV));

    printf("\nEnter %d Values\n",*size);
    for(int i=0;i<*size;i++)
    {
        scanf("%d",&arr[i].key);
    }
    return arr;
}

int  BinarySearch(KV* arr,int key,int low,int high)
{
    int mid = 0;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid].key<key)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return low;
}


KV * BinaryInsertionSort(KV* arr, int size)
{
    int low = 0;
    int high = 0;
    int pos = 0;
    int key = 0;
    int j = 0;

    for(int i = 1;i<size;i++)
    {
        key = arr[i].key;

        high = i-1;
        pos = BinarySearch(arr,key,low,high);
        j = i-1;
        while(j>=pos)
        {
            arr[j+1].key = arr[j].key;
            j--;
        }

        arr[pos].key = key;
    }


    return arr;
} 

void Display(KV*arr,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d\n",arr[i].key);
    }
}

int main()
{

    KV  * Array = NULL;
    int size;
    Array = MemoryAllocation(Array,&size);

    printf("\n********************Array before sorting********************\n");
    Display(Array,size);

    Array = BinaryInsertionSort(Array,size);

    printf("\n********************Array After sorting********************\n");
    Display(Array,size);

    free(Array);
    Array = NULL;
    return 0;
}