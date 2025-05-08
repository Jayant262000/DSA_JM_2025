/* 

	write a c program to Re-Arrange doubly linked list in pair format.
	input -> 6 <-> 1 <-> 9 <-> 4 <-> 3 <-> 8 <-> 2
	output -> 1 <-> 6 <-> 4 <-> 9 <-> 3 <-> 8 <-> 2

	If first value is greater than second then swap  , if 3rd value is less than 4th then don't swap same for remaining pair

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct DoublyLinkedList{
	
	int rollNo;
	char name[20];
	
	struct DoublyLinkedList * previous;	
	struct DoublyLinkedList * next;	
}DLL;

DLL * CreateLinkedList(DLL * Head){
	char ans;
	
	DLL * last = Head;
	printf("\n\t**********Enter Students details**********\n");
    do{
	    DLL * Node = NULL;
		
		
	    Node = (DLL *)malloc(sizeof(DLL));
		Node->previous = NULL;
		Node->next = NULL;
		
		printf("\nRollNo: ");
		scanf(" %d",&Node->rollNo);
		getchar();
		
		printf("Student Name : ");
		fgets(Node->name,sizeof(Node->name),stdin);
		Node->name[strcspn(Node->name,"\n")] = '\0';
	
		if(Head == NULL)
		{
			Head = Node; 
		}
		else{
			last->next = Node;
			Node->previous = last;
		}
		last = Node;
		
		 while(ans!='y'||ans!='Y')
		 {			
			printf("\nDo you want to enter new node? [Y/N]: ");
			scanf(" %c",&ans);
		
			if((ans == 'Y'||ans == 'y')||(ans == 'N'||ans == 'n')){
				break;
			}
			else{
				printf("\n!!!Invalid Choice!!!\n");
				continue;
			}
		 }
				
	}while((ans=='y')||(ans=='Y'));
	
	  return Head;
}



DLL * SwapNodeAscending(DLL* last)
{
	DLL * swapNode = NULL;
	DLL * tempNode = last;
	
	swapNode = (DLL*)malloc(sizeof(DLL));
	swapNode->next = NULL;
	
	while(tempNode->next!= NULL)
	{	
		if(tempNode->rollNo > tempNode->next->rollNo){
			swapNode->rollNo = tempNode->rollNo;
			tempNode->rollNo = tempNode->next->rollNo;
			tempNode->next->rollNo = swapNode->rollNo;
		
			strcpy(swapNode->name,tempNode->name);
			strcpy(tempNode->name,tempNode->next->name);
			strcpy(tempNode->next->name,swapNode->name);   
		}
				
			if((tempNode->next->next!= NULL))
			{
				tempNode=tempNode->next->next;
			}
			else
			{
				break;
			}
	}	
	return last;
}

void DisplayDoublyLinkedList(DLL * Head)
{
	if(Head == NULL)
	{
		printf("\n!!!The List is Empty!!!\n");
	}
	else
	{		
		for(;Head!=NULL;Head=Head->next)
		{
			printf("Roll no : %d \n Name : %s \n Prev: %p \n Base: %p \n Next: %p \n-------------------------------------------------------------------------------------------------------------\n"
			,Head->rollNo,Head->name,Head->previous,Head,Head->next);
		}	   
	}
}

//Free Linked List
void FreeLinkedList(DLL * Head){
	DLL * temp = NULL;
	
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
	DLL * Start = NULL;
	
	
	do{
		printf("\n********** DoublyLinkedList Linked List **********\n");
		printf("\nEnter 1 Create DoublyLinkedList Linked list\n");
    	printf("Enter 2 to Display DoublyLinkedList Linked List\n");	
		printf("Enter 3 to Swap Nodes in Ascending order\n");	
		printf("Enter 4 to Exit\n");
		
		printf("\nChoice: ");			
		scanf("%d",&Choice);
		getchar();
		
		switch (Choice){
			
			case 1:	
					FreeLinkedList(Start);
					Start = NULL;
					Start = CreateLinkedList(Start);
			break;
		
			case 2: 
					printf("\n\t***Students Data***\n");
					DisplayDoublyLinkedList(Start);
			break;
			
			case 3: 
					if(Start->next==NULL)
					{
						printf("\n!!!Insufficient data!!!\n!!!Please Enter more data!!!\n");				
					}
					else
					{
						Start = SwapNodeAscending(Start);
						printf("\n\t*** Nodes are swaped successfully ***\n");
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