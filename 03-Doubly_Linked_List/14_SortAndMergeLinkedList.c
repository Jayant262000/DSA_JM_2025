/*

   write a c program to create two doubly linked lists, sort them individually and then merge the two sorted lists

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


DLL * SortLinkedList(DLL * last){
	DLL * iter1 = NULL;
	DLL * iter2 = NULL;
	DLL * tempNode = NULL;
	
	tempNode = (DLL*)malloc(sizeof(DLL));
	tempNode->previous = NULL;
	tempNode->next = NULL;
	
	for(iter1 = last;iter1->next!=NULL;iter1 = iter1->next){
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
	return last;
}

DLL * MergeTwoLists(DLL * last1, DLL * last2 ){
	
	DLL * iter = last1;
	
	if(last1==NULL&&last2!=NULL)
	{
		return last2;
	}
	else if(last2==NULL&&last1!=NULL)
	{
		return last1;
	}
	else
	{
		for(;iter->next!=NULL;iter = iter->next);
	
	    iter->next = last2;
		last2->previous = iter;
	
        return last1;
	}
	
	
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
	DLL * Start1 = NULL;
	DLL * Start2 = NULL;
	DLL * Start = NULL;
	DLL * tempNode = NULL;
	
	
	do{
		printf("\n********** Doubly Linked List **********\n");
		printf("\nEnter 1 Create First Doubly Linked list\n");
		printf("Enter 2 Create Second Doubly Linked list\n");
    	printf("Enter 3 to Display First Doubly Linked List\n");
    	printf("Enter 4 to Display Second Doubly Linked List\n");
		printf("Enter 5 to Sort First Doubly Linked List\n");	
		printf("Enter 6 to Sort Second Doubly Linked List\n");	
		printf("Enter 7 to Merge Second Doubly Linked List\n");	
		printf("Enter 8 to Display Merged Doubly Linked List\n");
		printf("Enter 9 to Exit\n");


		printf("\nChoice: ");			
		scanf("%d",&Choice);
		getchar();
		
		switch (Choice){
			
			case 1:	
					FreeLinkedList(Start1);
					Start1 = NULL;
					Start1 = CreateLinkedList(Start1);
			break;
			
			case 2:	
					FreeLinkedList(Start2);
					Start2 = NULL;
					Start2 = CreateLinkedList(Start2);
			break;
		
			case 3: 
					printf("\n\t***Students Data [List 1]***\n");
					DisplayDoublyLinkedList(Start1);
			break;
			
			case 4: 
					printf("\n\t***Students Data [List 2]***\n");
					DisplayDoublyLinkedList(Start2);
			break;
			
			case 5: 				
					if(Start1==NULL||Start1->next==NULL){
					printf("\n!!!Insufficient Node add nodes!!!\n");
				}
				else if(Start1->next->next==NULL)
				{
					tempNode = (DLL*)malloc(sizeof(DLL));
					tempNode->next = NULL;
					
					if(Start1->rollNo > Start1->next->rollNo)
					{
						tempNode->rollNo = Start1->next->rollNo;
						Start1->next->rollNo = Start1->rollNo;
						Start1->rollNo = tempNode->rollNo;
						
						strcpy(tempNode->name,Start1->next->name);
						strcpy(Start1->next->name,Start1->name);
						strcpy(Start1->name,tempNode->name);
						
						printf("\n********Linked List1  Sorted Successfully ********\n");
					}
					else
					{
						printf("\n!!!Linked List1 is already sorted!!!\n");

					}
				}
				else
				{
					Start1 = SortLinkedList(Start1);
					printf("\n********Linked List1  Sorted Successfully ********\n");
				}
					
			break;
			
			case 6: 
					if(Start2==NULL||Start2->next==NULL){
					printf("\n!!!Insufficient Node add nodes!!!\n");
				}
				else if(Start2->next->next==NULL)
				{
					tempNode = (DLL*)malloc(sizeof(DLL));
					tempNode->next = NULL;
					
					if(Start2->rollNo > Start2->next->rollNo)
					{
						tempNode->rollNo = Start2->next->rollNo;
						Start2->next->rollNo = Start2->rollNo;
						Start2->rollNo = tempNode->rollNo;
						
						strcpy(tempNode->name,Start2->next->name);
						strcpy(Start2->next->name,Start2->name);
						strcpy(Start2->name,tempNode->name);
						
						printf("\n********Linked List2  Sorted Successfully ********\n");
					}
					else
					{
						printf("\n!!!Linked List2 is already sorted!!!\n");

					}
				}
				else
				{
					Start2 = SortLinkedList(Start2);
					printf("\n********Linked List2  Sorted Successfully ********\n");
				}
					
			break;
			
			case 7: 
					if(Start1 == NULL && Start2 == NULL)
					{
						printf("\n!!!Both Lists are Empty!!!\n");

					}
					else
					{
						Start = MergeTwoLists(Start1, Start2 );
						printf("\n\t***[List 1 & List2] Successfully merged***\n");
					}
			break;
			
			case 8: 
					printf("\n\t***Students Data [Merged List1 & List 2]***\n");
					DisplayDoublyLinkedList(Start);
			break;
		
			case 9:
			        printf("\n\n Exiting the linked list ....\n");
					FreeLinkedList(Start1);
					Start1 = NULL;
					FreeLinkedList(Start2);
					Start2 = NULL;
					exit(0);
			break;
			
			default: 
					printf("!!! Invalid Choice  !!!");
			continue;
			
		}			
	}while(Choice!=9);
		
	return 0;
}