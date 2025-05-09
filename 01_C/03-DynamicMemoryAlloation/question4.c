/* 

  write a C program to read and print the student details using structure and Dynamic Memory Allocation.
  - create a structure with student details and print the inputted details. 
  - Memory to store and print structure will be allocated at run time by using malloc() and released by free().

*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student{
	
	int rollNo;
	char name[20];
	
}S;

S * CreateNode(S * Node){
   	
	    Node = (S *)malloc(sizeof(S));
		
	
	    printf("\n\t**********Enter Students details**********\n");
		
		printf("Enter the Name of Student: ");
		scanf(" %[^\n]s",Node->name);
		
		printf("Enter the RollNo: ");
		scanf(" %d",&Node->rollNo);
	
		
	  return Node;
}


void DisplayNode(S * Node)
{
	
	printf("Roll no : %d \n Name : %s \n------------------------------------------------------------------------------------------------------------------------\n",
	Node->rollNo,Node->name);   

}

int main()
{
    //code
	char ch; 
	int Choice;
	S * Start = NULL;
	
	
	do{
		printf("\n********** Node Creation **********\n");
		printf("\nEnter 1 Create Node\n");
    	printf("Enter 2 to Display Node\n");	
        printf("Enter 3 to exit\n");
		
			
		printf("\nChoice: ");			
		scanf("%d",&Choice);
		
		
		
		switch (Choice){
			
			case 1:	
					Start = CreateNode(Start);
			break;
		
			case 2: 
					printf("\n\t********* Students Data *********\n");
					DisplayNode(Start);
			break;
			
			case 3: 
					printf("\n\n Exiting the linked list ....\n");
					Start = NULL;
					free(Start);
					exit(0);
			break;
			
		}
				
	}while(Choice!=3);
		
	return 0;
}