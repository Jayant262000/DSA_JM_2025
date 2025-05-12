//Write a C program to implement Binary Search. 

#include <stdio.h>
#include <stdlib.h>

int *AllocateMemory(int*array,int size) {
    array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) 
	{
       scanf("%d",&array[i]);
    }
	
	int temp = 0;
	
	for(int i = 0;i<size;i++)
	{
		for(int j = i+1;j<size;j++)
		{
			if(array[i]>array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}	
	}

    return array;
}

void BinarySearch(int *array, int size,int key) 
{
	int flag = 0;
	int mid = 0;
	int high = size;
	int low = 0;
	
	
	do
	{
		mid = (high+low)/2;
		if(high<low)
		{
			flag = 2;
			break;
		}
		if(array[mid]==key)
		{
			flag = 1;
			break;
		}
		else if(array[mid]>key)
		{
			high = mid-1;
		}
		else if(array[mid]<key)
		{
			low = mid+1;
		}
	}while (array[mid]!=key);
	
	
	if(flag==1)
	{
		printf("\nThe element %d found at position: %d in array\n",key,mid);
	}
	else if(flag == 2)
	{
		printf("\n!!!The element is not found!!!\n");
	}

	printf("\nThe time complexity is O(log n)\n");
}

void DisplayArray(int *array, int size)
{
	printf("\n********* Array *********\n");
    for (int i = 0; i < size; i++) 
	{
        printf("%d\n",array[i]);   
    } 
}


int main() {
 
    int size;
	int *array = NULL;
	int key;
	
	printf("\nEnter Size: ");
	scanf("%d",&size);
	
    printf("\n********* Enter  Elements *********\n");
    array = AllocateMemory(array, size);
	
    DisplayArray(array,size);
	
	printf("\nEnter the key: ");
	scanf("%d",&key);
	
	BinarySearch(array,size,key);
	
    return 0;
}