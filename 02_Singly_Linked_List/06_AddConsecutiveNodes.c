/* 

      write a c program to Create a Singly Linked list and  Display the addition of two consecutive nodes to the next node 
	  
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| 

O/P ---->    |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_AABB_|_700_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_800_| --> |_7_|_CCDD_|_NULL_|

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
SLL * AddConsecutiveNode(SLL * );
void DisplaySinglyLinkedList(SLL * );
void FreeLinkedList(SLL* );


//Linked List Creation
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


// Add Consecutive nodes
SLL * AddConsecutiveNode(SLL * Head){
	
	SLL * iter = Head;
	SLL *temp=NULL;
		
	
	for(;iter->next!=NULL;){
		
		temp = (SLL*)malloc(sizeof(SLL));
		temp->next = NULL;
		   
		temp->next = iter->next->next;
		iter->next->next = temp;
		
		temp->rollNo = iter->rollNo + iter->next->rollNo;
		
		strcpy(temp->name,iter->name);
		strcat(temp->name,iter->next->name);
		
		if(temp->next==NULL)
		{
			break;
		}
		else
		{			  
		   iter = temp->next;
		}
	}
	
	iter = NULL;
	free(iter);
	
	temp = NULL;
	free(temp);
	
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
	
	
	do{
		printf("\n********** Singly Linked List **********\n");
		printf("\nEnter 1: to Create Singly Linked list\n");
    	printf("Enter 2: to Display Singly Linked List\n");	
		printf("Enter 3: to add consecutive nodes\n");
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
					printf("\n\t************* Students Data *************\n\n");
					DisplaySinglyLinkedList(Start);
			break;
			
			case 3: 
					if(Start==NULL||Start->next==NULL)
					{
						printf("\n!!!Insufficient data!!!\n!!!Please Enter more data!!!\n");				
					}
					else
					{
						Start = AddConsecutiveNode(Start);
						printf("\n\t************* Nodes are added successfully *************\n");
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