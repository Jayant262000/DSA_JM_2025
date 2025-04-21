/* 

      write a c program to Create a Singly linked list and Insert a node in the given position.

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
SLL * CreateLinkedList(SLL * ,int * );
SLL * InsertInPosition(SLL * ,int ,int * );
void DisplaySinglyLinkedList(SLL * );


//List Creation
SLL * CreateLinkedList(SLL * Head, int * NodeCount)
{
	char ans;
	 SLL * Node = NULL;
	 SLL * last = Head;
    do{
		
	    Node = (SLL *)malloc(sizeof(SLL));
		Node->next = NULL;
		*NodeCount+=1;
	
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


//Insert Node in given position
SLL * InsertInPosition(SLL * Head, int pos, int * totalNodes)
{
	
		SLL * Node = NULL;
		SLL * iter = Head;
		int ipos = 0;
	
		Node = (SLL *)malloc(sizeof(SLL));
		Node->next = NULL;
		*totalNodes+=1;
		
		printf("Enter the Name of Student: ");
    	scanf(" %[^\n]s",Node->name);
	
		printf("Enter the RollNo: ");
		scanf(" %d",&Node->rollNo);
	
	    if((pos == 1)&&(Head == NULL)){
			Head = Node;
			return Head;
		}
		else if((pos==1)&&(Head!=NULL)){
			Node->next = Head;
	    	Head = Node;
		}
		else{
			for( ipos = 1;(ipos < pos-1)&&(iter->next!=NULL);iter = iter->next,ipos++);
			Node->next = iter->next;
			iter->next = Node;
		}			
        
	iter = NULL;
	free(iter);
	
	Node = NULL;
	free(Node);
		
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



int main()
{
    //code
	char ch; 
	int Choice;
	int position;
	int totalNodes = 0;
	SLL * Start = NULL;
	
	
	do{
	printf("\n********** Singly Linked List **********\n");
		printf("\nEnter 1: to Create Singly Linked list\n");
    	printf("Enter 2: to Display Singly Linked List\n");	
		printf("Enter 3: to Insert Node in given position\n");
		printf("Enter 4: to Exit the Linked List\n");
		
		printf("\nChoice: ");			
		scanf("%d",&Choice);
		
		switch (Choice){
			
			case 1:	
					Start = NULL;
					Start = CreateLinkedList(Start,&totalNodes);

			break;
		
			case 2: 
					printf("\n\t********* Students Data *********\n");
					DisplaySinglyLinkedList(Start);
			break;
			
			case 3: 
					printf("\nEnter the Position:  ");
					scanf("%d",&position);
					
					if(position <= 0 || position > totalNodes+1)
					{
						printf("\n!!!Invalid Position please enter the position again!!!\n");
					}
					else{
						Start = InsertInPosition(Start,position,&totalNodes);
						printf("\n********* Node Insered Successfully *********\n");
					}
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