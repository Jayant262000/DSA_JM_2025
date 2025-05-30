// accept a string and calculate the length of string  using recursion 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 20


char MemoryAllocation(char * arr)
{
	
	printf("\n...Enter the String...\n");
	
	fgets(arr,MAX_LENGTH,stdin);
	arr[strcspn(arr,"\n")] = '\0';
	
	
}

int LengthOfString(char * arr,int i)
{
	if(arr[i]!='\0')
	{
		i = LengthOfString(arr,i+1);
	}
	
	return i;
}

int main()
{
	char  array[MAX_LENGTH];
	int i=0;
	
	 MemoryAllocation(array);
	printf("\nString: %s\n",array);
	
	printf("\nLength of String: %d",LengthOfString(array,i));
	
	
	return 0;
}