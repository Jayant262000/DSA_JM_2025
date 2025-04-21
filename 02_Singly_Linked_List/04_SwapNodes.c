/* 

      write a c program to Create a Singly linked list and swap the two consecutive nodes 
	  
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_400_| --> |_5_|_EE_|_500_| --> |_6_|_FF_|_NULL_|  


O/P  ---->   |_2_|_BB_|_100_| --> |_1_|_AA_|_200_| --> |_4_|_DD_|_300_| --> |_3_|_CC_|_400_| --> |_6_|_FF_|_500_| --> |_5_|_EE_|_NULL_|

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
SLL * SwapNode(SLL* );
void DisplaySinglyLinkedList(SLL * );


// Linked List creation 
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


// Swap Consecutive Nodes 
SLL * SwapNode(SLL* last)
{
	SLL  swapNode;
	SLL * tempNode = last;
	
	while(tempNode->next!= NULL)
	{	
		
			swapNode.rollNo = tempNode->rollNo;
			tempNode->rollNo = tempNode->next->rollNo;
			tempNode->next->rollNo = swapNode.rollNo;
		
			strcpy(swapNode.name,tempNode->name);
			strcpy(tempNode->name,tempNode->next->name);
			strcpy(tempNode->next->name,swapNode.name);   
				
			if((tempNode->next->next!= NULL))
			{
				tempNode=tempNode->next->next;
			}
			else
			{
				break;
			}
	}	
	tempNode = NULL;
	free(tempNode);
	
	return last;
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
		printf("Enter 3: to Swap Nodes\n");
        printf("Enter 4: to Exit the Linked List\n");		
	
		printf("\nChoice: ");			
		scanf("%d",&Choice);
		
		switch (Choice){
			
			case 1:	
					Start = NULL;
					Start = CreateLinkedList(Start);
			break;
		
			case 2: 
					printf("\n\t**********Students Data**********\n");
					DisplaySinglyLinkedList(Start);
			break;
			
			case 3: 
					if(Start->next==NULL)
					{
						printf("\n!!!Insufficient data!!!\n!!!Please Enter more data!!!\n");				
					}
					else
					{
						Start = SwapNode(Start);
						printf("\n\t********** Nodes are swaped successfully **********\n");
					}
			break;
			
			case 4:
					printf("\n Exiting the linked list ....\n");
					Start = NULL;
					free(Start);	
					exit(0);
			break;
			
		}
	
	}while(Choice!=4);

	return 0;
}
