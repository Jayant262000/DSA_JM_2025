/*

write a c program to create and display a node. with structure "Student" with following data members:   
-Name 
-Roll no
-standard
-Division

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SinglyLinkedList{
	
	int rollNo;
	char name[20];
	
	struct SinglyLinkedList * next;	
}SLL;

SLL * CreateNode(SLL * Node){
   	
	    Node = (SLL *)malloc(sizeof(SLL));
		Node->next = NULL;
	
	    printf("\n\t**********Enter Students details**********\n");
		printf("Enter the Name of Student: ");
		scanf(" %[^\n]s",Node->name);
		
		printf("Enter the RollNo: ");
		scanf(" %d",&Node->rollNo);
	
		
	  return Node;
}


void DisplayNode(SLL * Node)
{
	if(Node == NULL)
	{
		printf("\n!!!Node is does not exist!!!\n");
	}
	else
	{		
		
		printf("Roll no : %d \n Name : %s \n------------------------------------------------------------------------------------------------------------------------\n",Node->rollNo,Node->name);
	   
	}
}

int main()
{
    //code
	char ch; 
	int Choice;
	SLL * Start = NULL;
	
	
	do{
		printf("\n********** Node Creation **********\n");
		printf("\nEnter 1 Create Node\n");
    	printf("Enter 2 to Display Node\n");	
        printf("Enter 3 to Display Node\n");
		
			
		printf("\nChoice: ");			
		scanf(" %d",&Choice);
		getchar();
		
		
		
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
			
			default: 
					printf("!!! Invalid Choice  !!!");
			continue;
			
		}
				
	}while(Choice!=3);
		
	return 0;
}