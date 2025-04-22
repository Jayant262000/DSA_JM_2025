/* 

      write a c program to Create Linked List using Recursion.

	  

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SinglyLinkedList{
	
	int rollNo;
	char name[20];
	int standard;
	char division;
	
	struct SinglyLinkedList * next;	
}SLL;

SLL * CreateLinkedList(SLL * ,SLL ** , char );
void DisplaySinglyLinkedList(SLL * );
void FreeLinkedList(SLL* );

SLL * CreateLinkedList(SLL * Head,SLL ** last, char ans){
	
	
    if(ans=='Y'||ans=='y'){
		
		SLL * Node = NULL;
		
		
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
			(*last)->next = Node;
		}
			(*last) = Node;
		
		
		 	
		printf("\nDo you want to enter new node? [Y/N]: ");
		scanf(" %c",&ans);
		
		 Head = CreateLinkedList(Head,last, ans);
	}
	    
	  return Head;
}


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
	char ch1 = 'y';
	SLL * Start = NULL;
	SLL * last = NULL;
	
	do{
		printf("\n********** Singly Linked List **********\n");
		printf("\nEnter 1: to Create Singly Linked list\n");
    	printf("Enter 2: to Display Singly Linked List\n");	
		printf("Enter 3: to Exit the Linked List\n");

		
	
		printf("\nChoice: ");			
		scanf(" %d",&Choice);
		getchar();
		
		
		
		switch (Choice){
			
			case 1:	
					FreeLinkedList(Start);
					Start = NULL;
					Start = CreateLinkedList(Start,&last,ch1);
			break;
		
			case 2: 
					printf("\n\t***Students Data***\n");
					DisplaySinglyLinkedList(Start);
			break;
			
			case 3:
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