//Accept a string and reverse the content of string 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 20

void MemoryAllocation(char ** string1)
{
	printf("\nEnter String1: ");
	*string1 = (char*)malloc(MAX_LENGTH*sizeof(char));
	fgets(*string1,MAX_LENGTH,stdin);
	(*string1)[strcspn((*string1),"\n")] = '\0';
	
}

char * StringReverse(char * string1)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char temp = '\0';
	
	for(k = 0;string1[k]!='\0';k++);

	for(i = 0,j = (k-1);(i<=(k/2)&&j>=(k/2));i++,j--)
	{
		temp = string1[i];
		string1[i] = string1[j];
		string1[j] = temp;
	}
	
	return string1;
}


void Display(char * string)
{
	printf("\n%s",string);
}


int main(){
	
	char * string1 = NULL;
	
	MemoryAllocation(&string1);
	
	printf("\nString1: ");
	Display(string1);

	
	string1 = StringReverse(string1);
	
	printf("\n\nReverse String: ");
	Display(string1);
	
	return 0;
}