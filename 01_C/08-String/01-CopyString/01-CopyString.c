//Accept a string and copy the string into another string with and without using the inbuilt copy function 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 20

char * MemoryAllocation(char * string1)
{
	printf("\nEnter String1: ");
	string1 = (char*)malloc(MAX_LENGTH*sizeof(char));
	fgets(string1,MAX_LENGTH,stdin);
	string1[strcspn(string1,"\n")] = '\0';
	
	
	return string1;
}

char * CopyString(char * string1,char * string2)
{
	string2 = (char*)malloc(MAX_LENGTH*sizeof(char));
	for(int i = 0;string1[i]!='\0';i++)
	{
		string2[i] = string1[i];
	}
	return string2;
}


void Display(char * string)
{
	printf("\n%s",string);
}


int main(){
	
	char * string1 = NULL;
	char * string2 = NULL;
	
	string1  = MemoryAllocation(string1);
	
	printf("\nString1: ");
	Display(string1);
	
	string2 = CopyString(string1,string2);
	
	printf("\n\nString2: ");
	Display(string2);
	
	
	return 0;
}