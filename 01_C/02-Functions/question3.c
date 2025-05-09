//Write a separate function to copy one string into another string 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char * CopyString(char*str1,char*str2)
{
	
	return strcpy(str1,str2);
}

void DisplayArray(char *arr)
{
   
    printf("%s", arr); 
	
}

int main()
{
    char *string1 = NULL;
	char *string2 = NULL;
	
    int size1;
	int size2;

    printf("Enter the size of string1: ");
    scanf("%d", &size1);
	
	 printf("Enter the size of string2: ");
    scanf("%d", &size2);

    string1 = (char *)malloc((size1 + 1) * sizeof(char));  
    
	string2 = (char *)malloc((size2 + 1) * sizeof(char));  
	
	printf("\n----------Enter Data----------\n");
    getchar(); 
    fgets(string2, size2 + 1, stdin);
	 
	
	 printf("\n---------String 2--------\n");
	DisplayArray(string2);
	
	
	string1 = CopyString(string1,string2);
	
	 printf("\n---------String1 after copy--------\n");
	 DisplayArray(string1);

    free(string1); 
	free(string2); 

    return 0;
}
