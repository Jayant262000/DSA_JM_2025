/*

	In C, we want to take the FULL name as input and make sure that the 1st letter of the first, middle, and last name is capitalized and the rest are in small,
	if not, then make it in that format and also check if there are any numbers or special characters in the name, if there then print invalid name.

	Sample 1: 
	INPUT: sOhaM YashWANT gaDeKaR
	OUTPUT: Soham Yashwant Gadekar

	Sample 2: 
	INPUT: sOhaM Y@shWANT gaDeKaR3
	OUTPUT: Invalid name

	Sample 3: 
	INPUT: sOhaM
	OUTPUT: Enter your FULL name! FIRST MIDDLE LAST

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 20

char * MemoryAllocation(char * name)
{
	name = (char*)malloc(MAX_LENGTH*sizeof(char));
	
	printf("\nname: ");
	fgets(name,MAX_LENGTH,stdin);
	name[strcspn(name,"\n")] = '\0';
	
	return name;
}

char * StringFormat(char * name)
{
	int flag1 = 0;
	int flag2 = 0;
	for(int i = 1;name[i]!='\0';i++)
	{
		if(name[0] != ' '&&name[i-1]==' '&&name[i]!=' ')
		{
			flag1 += 1;
		}
		if(name[0]>=97&&name[0]<=122||name[i]>=65&&name[i]<=90)
		{
			flag2 = 1;
		}
		
	}
	
	if(flag1 < 2)
	{
		printf("\n!!! Enter the Full name !!!\n");
	}
	if(flag2 != 1)
	{
		printf("\n!!! string contains special characters or numbers !!!\n");
	}
	if(flag1==2&&flag2==1)
	{
		for(int i = 0;name[i]!='\0';i++)
		{
			if(name[0]>=97&&name[0]<=122)
			{
				name[0]=name[0]-32;
			}
			else if(name[i-1]==' '&&name[i]!=' ')
			{
				if(name[i]>=97&&name[i]<=122)
				{
					name[i]=name[i]-32;
				}
			}
			else if(name[i-1]!=' ')
			{
				if(name[i]>=65&&name[i]<=90)
				{
					name[i]=name[i]+32;
				}
			}		
	    }
	}
	
	return name;

}

int main()
{
	char * name = NULL;
	name = MemoryAllocation(name);
	
	printf("\nname before formatting\n%s\n",name);
	
	name = StringFormat(name);
	
	printf("\nname after formatting\n%s\n",name);
	
	
	return 0;
}