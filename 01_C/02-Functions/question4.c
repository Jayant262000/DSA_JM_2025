//write a function to concatenate  two strings 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char * ConcatinateString(char*str1,char*str2)
{
	
	return strcat(str1,str2);
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
	
	printf("\n----------Enter Data in string 1----------\n");
    getchar(); 
    fgets(string1, size1 + 1, stdin);
	string1[strcspn(string1,"\n")] = '\0';
    
	string2 = (char *)malloc((size2 + 1) * sizeof(char));  
	
	printf("\n----------Enter Data in string 2----------\n"); 
    fgets(string2, size2 + 1, stdin);
	string2[strcspn(string2,"\n")] = '\0';
	    getchar();
	 
	printf("\n---------String 1--------\n");
	DisplayArray(string1);
	
	printf("\n---------String 2--------\n");
	DisplayArray(string2);
	
	
	string1 = ConcatinateString(string1,string2);
	
	 printf("\n---------String1 after copy--------\n");
	 DisplayArray(string1);

    free(string1); 
	free(string2); 

    return 0;
}
