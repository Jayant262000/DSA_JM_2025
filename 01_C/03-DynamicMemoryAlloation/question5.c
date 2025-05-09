/*

    write a C program to read and print the N student details using structure and Dynamic Memory Allocation.
    - create a structure with N number of student details and print the inputted details. 
	- Memory to store and print structure will be allocated at run time by using malloc() and released by free().

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct StudentDetails{
	
	int rollNo;
	char name[20];
	
}STD;

STD * CreateNode(STD * Node,int size){
   	

	

	    Node = (STD *)malloc(size*sizeof(STD));
	
	    printf("\n\t**********Enter Students details**********\n");
	
	for(int i=0;i<size;i++)
	{
		printf(" RollNo: ");
		scanf(" %d",&Node[i].rollNo);
	
		printf("Name: ");
		scanf(" %[^\n]s",Node[i].name);
	}
	  return Node;
}


void DisplayNode(STD* Node, int size) {
    for (int i = 0; i < size; i++) {
        printf("Roll No : %d\nName    : %s\n", Node[i].rollNo, Node[i].name);
        printf("------------------------------------------------------------\n");
    }
}

void FreeMemory(STD* Node) {
    free(Node);
}
int main()
{
    //code
	char ch; 
	int Choice;
	STD * Start = NULL;
	int size;
	
	do{
		printf("\n********** Node Creation **********\n");
		printf("\nEnter 1 Create Node\n");
    	printf("Enter 2 to Display Node\n");	
        printf("Enter 3 to exit\n");
		
			
		printf("\nChoice: ");			
		scanf("%d",&Choice);
		
		
		
		switch (Choice){
			
			case 1:	
					printf("\nEnter the size : ");
					scanf("%d",&size);
					Start = CreateNode(Start,size);
			break;
		
			case 2: 
					printf("\n\t********* Students Data *********\n");
					DisplayNode(Start,size);
			break;
			
			case 3: 
					printf("\n\n Exiting the linked list ....\n");
					FreeMemory(Start);
					Start = NULL;
					exit(0);
			break;
			
		}
				
	}while(Choice!=3);
		
	return 0;
}