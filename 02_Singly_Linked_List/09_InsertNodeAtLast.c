/* 

      write a c program to Create a Singly linked list and Insert a node at the last 
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
SLL * CreateLinkedList(SLL * ,SLL** );
SLL * InsertNodeAtLast(SLL *,SLL** );
void DisplaySinglyLinkedList(SLL * );
void FreeLinkedList(SLL* );


//List Creation
SLL * CreateLinkedList(SLL * Head,SLL ** last){
	char ans;
	 SLL * Node = NULL;
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
			(*last)->next = Node;		
		}
		*last = Node;
				
			printf("\nDo you want to enter new node? [Y/N]: ");
			scanf(" %c",&ans);				
	}while((ans=='y')||(ans=='Y'));	
	
	
	Node = NULL;
	free(Node);
	
	return Head;

}

//Insert Node at last
SLL * InsertNodeAtLast(SLL * Head, SLL ** last){
	
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
   	else
	{	
		(*last)->next = Node;	
	}
    *last = Node;	
	
	return Head;
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
	SLL * last = NULL;
	
	
	do{
	    printf("\n********** Singly Linked List **********\n");
		printf("\nEnter 1: to Create Singly Linked list\n");
    	printf("Enter 2: to Display Singly Linked List\n");	
		printf("Enter 3: to Insert Node at Last\n");
		printf("Enter 4: to Exit the Linked List\n");
		
		
		printf("\nChoice: ");			
		scanf("%d",&Choice);
		
		
		
		switch (Choice){
			
			case 1:	
					FreeLinkedList(Start);
					Start = NULL;
					last = NULL;
					Start = CreateLinkedList(Start,&last);
			break;
		
			case 2: 
					printf("\n\t**********Students Data**********\n");
					DisplaySinglyLinkedList(Start);
			break;
			
			case 3:
					
					Start = InsertNodeAtLast(Start,&last);
					printf("\n\t********** Node Added Successfully **********\n");
			break;	

			case 4:
					printf("\n\n Exiting the linked list ....\n");
					
					FreeLinkedList(Start);
					Start = NULL;
					
					last = NULL;
					free(last);
					exit(0);
			break;
			
		}
	 
	}while(Choice!=4);
		
	return 0;
}