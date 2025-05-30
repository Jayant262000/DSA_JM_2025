#include<stdio.h>
#include<stdlib.h>

int * MemoryAllocation(int * arr, int * size)
{
    printf("\nEnter the size of an array: ");
    scanf("%d",size);

    arr = (int *)malloc(*size*sizeof(int));

    if(arr==NULL)
    {
        printf("\n!!! Memory allocation is failed !!!\n");
    }
    else
    {
        printf("\nMemory allocation is Successfull........\n");
    }

    printf("\nEnter the Array Elements: \n");
    for(int i = 0;i<*size;i++)
    {
        scanf("%d",&arr[i]);
    }

    return arr;
}


void Display(int * arr, int size)
{
    for(int i = 0; i<size; i++)
    {
        printf("\n%d",arr[i]);
    }

}

int NumberOfDigits(int * arr, int size)
{
    int No = 0;
    int NoD = 0;
    int HNoD = 0;

    for(int i=0;i<size;i++)
    {
        No = arr[i];
        do
        {
            No = No / 10;
            NoD ++;
        }while(No!=0);
        
        if(NoD >= HNoD)
        {
            HNoD = NoD;
        }
        NoD = 0;
    }

    return HNoD;
}

int * RadixSort(int * arr, int size)
{
    int TempArr[size][2];
    

    int HD = NumberOfDigits(arr,size);
    int j = HD;
    int Low = 0;
    int No  = 0;
    int p =0;

    while(j!=-1)
    {
        for(int i = 0; i<size; i++)
        {
            No = 0;
            No = arr[i];
            Low = 0;
            for(int h = 0; h<=(HD-j);h++)
            {
                Low = No%10;
                if(h>0)
                {
                    No = No/10;
                }
            }

            
          if(i==0)
          {
                TempArr[0][0] = arr[0];
                TempArr[0][1] = Low;
               
          }
          else
          {
            
            if(TempArr[i-1][1]<=Low)
            {
                TempArr[i][0] = arr[i];
                TempArr[i][1] = Low;
                
            }
            else 
            {
                p = 0;
                for(int n = 0;n<i;n++)
                {
                    if(TempArr[n][1]>Low){
                        p = i-1;
                        while(p>=n)
                        {
                            TempArr[p+1][0] = TempArr[p][0];
                            TempArr[p+1][1] = TempArr[p][1];
                            p--;
                         }
                    
                         TempArr[p+1][0] = arr[i];
                         TempArr[p+1][1] = Low;
                         break;
                       }
                   }
               }
           }       
        }
            for(int i = 0;i<size;i++)
            {
                arr[i] = TempArr[i][0];
            }
        
        j--;
    }
  

        return arr;

}

int main()
{
    int *  array = NULL;
    int size;

    printf("\n................. Memory Allocation .................\n");

    array = MemoryAllocation(array,&size);

    printf("\n................. Array Before Sorting .................\n");

    Display(array,size);

    printf("\n................. Array After Sorting .................\n");

    array = RadixSort(array,size);
    Display(array,size);
    
    return 0;
}