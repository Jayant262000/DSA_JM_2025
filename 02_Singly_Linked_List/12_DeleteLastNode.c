/* 

      write a c program to Create a Singly linked list and Delete the node at the last position 
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
SLL * DeleteNodeAtLast(SLL * );
void DisplaySinglyLinkedList(SLL * );
void FreeLinkedList(SLL* );


//List Creation
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

//Delete Node at last
SLL * DeleteNodeAtLast(SLL * Head){
	    
		SLL * iter = Head;
		SLL * temp = NULL;
        if(Head->next == NULL)
		{
			free(Head);
			return NULL;
		}
		else
		{
			for(;iter->next->next!=NULL;iter = iter->next);	
			temp = iter->next; 
			iter->next = NULL;

			temp = NULL;
			free(temp);
			
			iter = NULL;
			free(iter);
			
			return Head;		
		}
}

//Display list
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
		printf("\nEnter 1: to Create Singly Linked list\n");
    	printf("Enter 2: to Display Singly Linked List\n");
		printf("Enter 3: to Delete Last Node\n");	
		printf("Enter 4: to Exit the Linked List\n");
	
		printf("\nChoice: ");			
		scanf(" %d",&Choice);
		getchar();
		
		switch (Choice){
			
			case 1:	
					FreeLinkedList(Start);
					Start = NULL;
					Start = CreateLinkedList(Start);
			break;
		
			case 2: 
					printf("\n\t**********Students Data**********\n");
					DisplaySinglyLinkedList(Start);
			break;
			
			case 3:
					if(Start==NULL){
							printf("\n!!!Linked List is Empty!!!\n!!!Entert the Data!!!\n");
					}
					else
					{
						Start = DeleteNodeAtLast(Start);
						printf("\n\t**********Node Deleted Successfully**********\n");
					}
			break;
			
			case 4:
					printf("\n\n Exiting the linked list ....\n");
					FreeLinkedList(Start);
					Start = NULL;
					exit(0);
			break;
			
			default: 
					printf("!!! Invalid Choice  !!!");
			continue;
		}
	}while(Choice!=4);
		
	return 0;
}