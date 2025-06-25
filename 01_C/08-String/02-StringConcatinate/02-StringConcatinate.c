//Accept two strings and concatinate the contents into 3rd string

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 20

void MemoryAllocation(char ** string1,char ** string2)
{
	printf("\nEnter String1: ");
	*string1 = (char*)malloc(MAX_LENGTH*sizeof(char));
	fgets(*string1,MAX_LENGTH,stdin);
	(*string1)[strcspn((*string1),"\n")] = '\0';
	
	
	printf("\nEnter String2: ");
	*string2 = (char*)malloc(MAX_LENGTH*sizeof(char));
	fgets(*string2,MAX_LENGTH,stdin);
	(*string2)[strcspn(*string2,"\n")] = '\0';
	
}

char * StringConcatinate(char * string1,char * string2,char * string3)
{
	int flag = 0;
	static int i = 0;
	string3 = (char*)malloc(MAX_LENGTH*sizeof(char));
	for(i = 0;string1[i]!='\0';i++)
	{
		string3[i] = string1[i];
		if(i==MAX_LENGTH-1)
		{
			flag = 1;
		}
	}
	
	if(flag==1)
	{
		printf("\nString3 is full can not concatinate\n");
		return string3;
	}
	else
	{
		for(;string2[i]!='\0';i++)
		{
			string3[i] = string2[i];
		}
	}
	
	return string3;
}


void Display(char * string)
{
	printf("\n%s",string);
}


int main(){
	
	char * string1 = NULL;
	char * string2 = NULL;
	char * string3 = NULL;
	
	MemoryAllocation(&string1,&string2);
	
	printf("\nString1: ");
	Display(string1);
	
	printf("\n\nString2: ");
	Display(string2);
	
	string3 = StringConcatinate(string1,string2,string3);
	
	printf("\n\nString3: ");
	Display(string3);
	
	return 0;
}