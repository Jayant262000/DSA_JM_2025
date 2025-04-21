/* 

      write a c program to Create a Singly linked list and revert it 
	  
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| 


O/P ---->    |_4_|_DD_|_100_| --> |_3_|_CC_|_200_| --> |_2_|_BB_|_300_| --> |_1_|_AA_|_NULL_|


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
SLL * RevertList(SLL * );
void DisplaySinglyLinkedList(SLL * );


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


//Revert List
SLL * RevertList(SLL * Head){
	
	
	SLL * Node1 = NULL;
	SLL * Node2 = NULL;	
	SLL * Node3 = NULL;
	SLL * temp = NULL;
	
	Node1 = Head;
	Node2 = Node1->next;
	Node3 = Node2->next;
	
	
	if(Node2->next == NULL){
		Node2->next = Node1;
		Node1->next = NULL;
		return Node2;
	}
	else if(Node3->next==NULL)
	{
		Node3->next = Node2;
		Node2->next = Node1;
		Node1->next = NULL;
		return Node3;
	}
	else{
		while(Node3->next!=NULL)
		{
			temp =  Node3->next;
			Node3->next = temp->next;
			temp->next = Node2->next;
			Node2->next = temp;		 
		}
		
		Node3->next = Node2;
		Node2->next = Node1;
		Node1->next = NULL;
		
		
		Node1 = NULL;
		free(Node1);
		
        Node2 = NULL;
		free(Node2);

		Node3 = NULL;
		free(Node3);
		
		return temp;
	}	
	
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
    	printf("Enter 3: to Revert the Singly Linked List\n");	
		printf("Enter 4: to Exit the Linked List\n");
		
	
		printf("\nChoice: ");			
		scanf("%d",&Choice);
		
		
		switch (Choice){
			
			case 1:	
					Start = NULL;
					Start = CreateLinkedList(Start);
			break;
		
			case 2: 
					printf("\n\t***Students Data***\n");
					DisplaySinglyLinkedList(Start);
			break;
			
			case 3: 
					if(Start==NULL||Start->next==NULL){
						printf("\n!!!Insufficient nodes in list add nodes!!!\n");
					}
					else
					{
						Start = RevertList(Start);
						printf("\n**********List Reverted Successfully**********\n");
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