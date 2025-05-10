//accept n elements in an array and perform right rotaion and left rotation (rotate N elements (N is an user input)) .  
//(Allocate the array dynamically)


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

int * RightRotation(int * arr,int size,int ele){
	int flag = 0;
	for(int i = 0;i<ele;++i){
	
		flag = arr[size-1];
		for(int j=size-2;j>=0;j--)
		{
			arr[j+1] = arr[j];
		}
		arr[0] = flag;
		
	}
	return arr;
}

int * LeftRotation(int * arr,int size,int ele){
	int flag = 0;
	for(int i = 0;i<ele;++i){
		flag = arr[0];
		for(int j=1;j<size;j++)
		{
			arr[j-1] = arr[j];
		}
		arr[size-1] = flag;
		
	}
	
	return arr;
}

void DisplayArray(int * array,int size){
	

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
	
	printf("\nEnter the number of rotation: \n");
	scanf("%d",&no);
	
	 array = RightRotation(array,size,no);
	 DisplayArray(array,size);
	 
	  array = LeftRotation(array,size,no);
	 DisplayArray(array,size);

	return 0;
}