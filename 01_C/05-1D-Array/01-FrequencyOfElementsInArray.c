/*

	- Write a C program which allocates an array dynamically.
	- Implement logic to check the frequency of each element throughout the array


*/

#include<stdio.h>
#include<stdlib.h>

void CheckFrequency(int arr[], int size){
	
	int cnt = 1;
	int rev = 0;
	for(int i=0;i<size;++i){
		
		rev = i;
		if(i!=0)
		{
		  while(rev!=-1){
			
			if(arr[i]==arr[rev-1]){
				break;
			}
			rev--;
				
		  }
		}
		if(i==0||rev==-1){
			 for(int j=i+1;j<size;++j){	
				if(arr[i]==arr[j]){
					cnt++;
				}
			}
		}
		else
		{
			
			rev=0;
          	continue;
		
		}
	
		printf("Frequency of arr[%d] = %d\n",i,cnt);
		cnt = 1;
	}
	
}



int main()
{
	// Logic

   int * array;
   int size;
   
   printf("Enter the size of array: ");
   scanf("%d",&size);
   array = (int*)malloc(size*sizeof(int));   
   printf("Enter the element in array:\n");	
	for(int i=0;i<size;++i){
		scanf("%d",(array+i));
	}
	
	printf("The frequency of each element in array: \n");
	
	CheckFrequency(array,size);
	
	return 0;
}