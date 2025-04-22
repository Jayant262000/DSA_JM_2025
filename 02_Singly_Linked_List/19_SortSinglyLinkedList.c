/*

   write a c program to Create a Singly linked list and sort the linked list

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SinglyLinkedList{
	
	int rollNo;
	char name[20];
	
	struct SinglyLinkedList * next;	
}SLL;

// Functions
SLL * CreateLinkedList(SLL * );
SLL * SortLinkedList(SLL * );
void DisplaySinglyLinkedList(SLL * );
void FreeLinkedList(SLL* );


//List creation
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


//Sort List
SLL * SortLinkedList(SLL * Head){
	SLL * iter1 = NULL;
	SLL * iter2 = NULL;
	SLL * tempNode = NULL;
	
	tempNode = (SLL*)malloc(sizeof(SLL));
	tempNode->next = NULL;
	
	for(iter1 = Head;iter1->next!=NULL;iter1 = iter1->next){
		for(iter2 = iter1->next;iter2!=NULL;iter2 = iter2->next){
			
			if(iter1->rollNo > iter2->rollNo)
			{
				tempNode->rollNo = iter1->rollNo;
				iter1->rollNo = iter2->rollNo;
				iter2->rollNo = tempNode->rollNo;
		
				strcpy(tempNode->name,iter1->name);
				strcpy(iter1->name,iter2->name);
				strcpy(iter2->name,tempNode->name);  
			}					
		}	
	}
	
	iter1 = NULL;
	free(iter1);
	
	iter2 = NULL;
	free(iter2);
	
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
	SLL * tempNode = NULL;
	
	
	do{
		printf("\n********** Singly Linked List **********\n");
		printf("\nEnter 1: to Create Singly Linked list\n");
    	printf("Enter 2: to Display Singly Linked List\n");
		printf("Enter 3: to Sort the linked list\n");
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
					printf("\n\t***Students Data***\n");
					DisplaySinglyLinkedList(Start);
			break;
			
			case 3:
				if(Start==NULL||Start->next==NULL){
					printf("\n!!!Insufficient Node add nodes!!!\n");
				}
				else if(Start->next->next==NULL)
				{
					tempNode = (SLL*)malloc(sizeof(SLL));
					tempNode->next = NULL;
					
					if(Start->rollNo > Start->next->rollNo)
					{
						tempNode->rollNo = Start->next->rollNo;
						Start->next->rollNo = Start->rollNo;
						Start->rollNo = tempNode->rollNo;
							
						strcpy(tempNode->name,Start->next->name);
						strcpy(Start->next->name,Start->name);
						strcpy(Start->name,tempNode->name);
						
						printf("\n********Linked List  Sorted Successfully ********\n");
					}
					else
					{
						printf("\n!!!Linked List is already sorted!!!\n");

					}
				}
				else
				{
					Start = SortLinkedList(Start);
					printf("\n********Linked List  Sorted Successfully ********\n");
				}
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
