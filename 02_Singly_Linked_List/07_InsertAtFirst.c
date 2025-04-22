/* 

      write a c program to Create a Singly linked list and Insert a node at Head

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SinglyLinkedList{
	
	int rollNo;
	char name[20];
	
	struct SinglyLinkedList * next;	
}SLL;

//Functions
SLL * CreateLinkedList(SLL * );
SLL * InsertAtFirst(SLL * );
void DisplaySinglyLinkedList(SLL * );
void FreeLinkedList(SLL* );


// List Creation
SLL * CreateLinkedList(SLL * Head){
	char ans;
	 SLL * Node = NULL;
	 SLL * last = Head;
    do{
		
	    Node = (SLL *)malloc(sizeof(SLL));
		Node->next = NULL;
	
	    printf("\n\t**********Enter Students details**********\n");
		printf("Enter the Name of Student: ");
		scanf(" %[^\n]s",Node->name);
		
		printf("Enter the RollNo: ");
		scanf(" %d",&Node->rollNo);
	
	
		if(Head == NULL)
		{
			Head = Node; 
		}
		else{
			last->next = Node;		
		}
		last = Node;
				
			printf("\nDo you want to enter new node? [Y/N]: ");
			scanf(" %c",&ans);				
	}while((ans=='y')||(ans=='Y'));	
	

	last = NULL;
	free(last);
	
	Node = NULL;
	free(Node);
		
	return Head;
}


//Insert Node in the begining
SLL * InsertAtFirst(SLL * Head){
	
	SLL * Node = NULL;
		
	Node = (SLL *)malloc(sizeof(SLL));
	Node->next = NULL;
	
	printf("Enter the Name of Student: ");
	scanf(" %[^\n]s",Node->name);
	
	printf("Enter the RollNo: ");
	scanf(" %d",&Node->rollNo);
	
	
	if(Head == NULL)
	{
		Head = Node; 
	}
   	else{
		
		Node->next = Head;
		Head = Node;
	}
	
	Node = NULL;
	free(Node);
	
	return Head;
}


// Display List
void DisplaySinglyLinkedList(SLL * Head)
{
	if(Head == NULL)
	{
		printf("\n!!!The List is Empty!!!\n");
	}
	else
	{		
		for(;Head!=NULL;Head=Head->next)
		{
			printf(" Roll no : %d \n Name : %s  \n------------------------------------------------------------------------------------------------------------------------\n",Head->rollNo,Head->name);
		}	   
	}
}

//Free Linked List
void FreeLinkedList(SLL * Head){
	SLL * temp = NULL;
	
	while(Head!=NULL){
		temp = Head;
		Head = Head->next;
		free(temp);
	}
}

int main()
{
    //code
	char ch; 
	int Choice;
	SLL * Start = NULL;
	
	
	do{
		printf("\n********** Singly Linked List **********\n");
		printf("\nEnter 1: Create Singly Linked list\n");
    	printf("Enter 2: to Display Singly Linked List\n");	
		printf("Enter 3: to Insert Node At First \n");
		printf("Enter 4: to Exit the Linked List\n");
				
		printf("\nChoice: ");			
		scanf("%d",&Choice);
		
		switch (Choice){
			
			case 1:	
					FreeLinkedList(Start);
					Start = NULL;
					Start = CreateLinkedList(Start);
			break;
		
			case 2: 
					printf("\n\t********* Students Data *********\n\n");
					DisplaySinglyLinkedList(Start);
			break;
			
			case 3: 
					Start = InsertAtFirst(Start);
					printf("\n\t********* Node Added Successfully *********\n");
			break;
			
			case 4:
					printf("\n\n Exiting the linked list ....\n");
					FreeLinkedList(Start);
					Start = NULL;
					exit(0);
			break;
			
		}
	}while(Choice!=4);
		
	return 0;
}