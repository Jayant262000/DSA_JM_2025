/*

	In C, we want to take input of a person’s name in a character string, 
	but it only stores the first name, and after a space it doesn’t store anything!

	(i) Why does this happen?
	(ii) How can this issue be solved with an explanation?
	(iii) Explore all the options ex - scanf(),gets(),fgets() and write functions for each appraoch 

	INPUT: Soham Yashwant Gadekar
	OUTPUT: Soham
	
	INPUT: Soham Yashwant Gadekar
	OUTPUT: Soham Yashwant Gadekar

*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void InputUsingScanf(char  string1[])
{
	
	printf("\nString1: ");
	scanf("%s",string1);
	printf("string1: %s",string1);
}

void InputUsingGets(char  string2[])
{
	printf("\nString2: ");
	gets(string2);
	printf("\nstring2: %s",string2);
}

void InputUsingFgets(char  string3[])
{
	printf("\nString3: ");
	fgets(string3,20,stdin);
	string3[strcspn(string3,"\n")] = '\0';
	printf("\nstring3: %s",string3);
}

int main()
{
	char string1[20];
	char string2[20];
	char string3[20];

	InputUsingScanf(string1);
	fflush(stdin);
	
	InputUsingGets(string2);
	fflush(stdin);

	InputUsingFgets(string3);
	fflush(stdin);
	
	return 0;
}
