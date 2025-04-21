/*
	write a c program to Create a Singly linked list and Find and print the middle element

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SinglyLinkedList{
	
	int rollNo;
	char name[20];
	
	struct SinglyLinkedList * next;	
}SLL;

//Function
SLL * CreateLinkedList(SLL * );
void PrintMiddleNode(SLL * );
void DisplaySinglyLinkedList(SLL * );

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

//Printf Middle node
void PrintMiddleNode(SLL * Head){
	
	SLL*tempNode = Head;
	
	
	while(tempNode!=NULL&&tempNode->next!=NULL){
		tempNode=tempNode->next->next;
		Head=Head->next;			
	}
	
	printf("Roll no : %d \n Name : %s \n------------------------------------------------------------------------------------------------------------------------\n",
	Head->rollNo,Head->name);
   
    tempNode = NULL;
	free(tempNode);
}


//Display List
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

int main()
{
    //code
	char ch; 
	int Choice;
	SLL * Start = NULL;
	
	
	do{
		printf("\n********** Singly Linked List **********\n");
		printf("\nEnter 1: to Create Singly Linked list\n");
    	printf("Enter 2: to Display Singly Linked List\n");	
		printf("Enter 3: to Display the middle node\n");
		printf("Enter 4: to Exit the Linked List\n");
		
		
		printf("\nChoice: ");			
		scanf("%d",&Choice);
		
		switch (Choice){
			
			case 1:	
					Start = NULL;
					Start = CreateLinkedList(Start);
			break;
		
			case 2: 
					printf("\n\t********* Students Data *********\n");
					DisplaySinglyLinkedList(Start);
			break;
			
			case 3: 
					printf("\n\t********* Middle node *********\n");
					PrintMiddleNode(Start);
			break;
			
			case 4:
					printf("\n\n Exiting the linked list ....\n");
					Start = NULL;
					free(Start);
					exit(0);
			break;
			
		}
	  
	}while(Choice!=4);
		
	return 0;
}

