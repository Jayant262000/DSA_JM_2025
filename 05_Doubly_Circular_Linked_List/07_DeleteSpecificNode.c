/*

  write a c program to Create a circular Doubly linked list and delete the node which key matches the user's key

*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct DoublyCircularLinkedList{
	
	int rollNo;
	char name[20];
	
	struct DoublyCircularLinkedList * prev;
	struct DoublyCircularLinkedList * next;
	
}DCLL;

//Functions
DCLL * CreateLinkedList(DCLL * );
void DisplayLinkedList(DCLL * );
DCLL* DeleteSpecificNode(DCLL * ,int );
void FreeLinkedList(DCLL * );


//Create Doubly Circular Linked List
DCLL * CreateLinkedList(DCLL * last){
	
	DCLL * NewNode = NULL;
	char ans;
	do{
		NewNode = (DCLL*)malloc(sizeof(DCLL));
		NewNode->prev = NULL;
		NewNode->next = NULL;
		
		printf("\n\t**********Enter Students details**********\n");
		
		printf("Roll No: ");
		scanf("%d",&NewNode->rollNo);
		getchar();
		
		printf("Name: ");
		fgets(NewNode->name,sizeof(NewNode->name),stdin);
		NewNode->name[strcspn(NewNode->name,"\n")] = '\0';
		
		if(last == NULL){
			last = NewNode;
			last->prev = NewNode;
			last->next = NewNode;
		}
		else{
			NewNode->next = last->next;
			NewNode->next->prev = NewNode;
			last->next = NewNode;
			NewNode->prev = last;
			last = NewNode;
		}
		printf("\nDo you want to Enter new node? [Y/N]:  ");
		scanf("%c",&ans);
	}while(ans=='Y'||ans=='y');
	return last;
}


DCLL* DeleteSpecificNode(DCLL * last,int RollNo){
	
	DCLL * tempNode = NULL;
	DCLL * iter = last->next;
	int flag = 0;
	
	
	
	do{
		if((last->next == last)&&last->rollNo == RollNo){
			free(last);
			last = NULL;
			printf("\n********Node deleted successfully ********\n");
			return NULL;
		}
		if(iter->rollNo==RollNo){
			iter = iter->prev;
			tempNode = iter->next;
			iter->next = tempNode->next;
			tempNode->next->prev = iter;
			
			free(tempNode);
			flag = 1;
		}
		
		iter = iter->next;
		
	}while(iter!=last);
	
	if(iter==last&&last->rollNo == RollNo)
	{
		last = last->prev;
		tempNode = last->next;
		last->next = tempNode->next;
		tempNode->next->prev = last;
		
		flag = 1;
		free(tempNode);
		tempNode = NULL;
	
	}
	
	
	if(flag==1)
	{
		printf("\n********Node deleted successfully ********\n");
	}
	else
	{
		printf("\n !!! ********Node not found !!! ********\n");
	}
	return last;
}


//Display Doubly Circular Linked list
void DisplayLinkedList(DCLL * last){
	
	if(last == NULL)
	{
		printf("\n!!!Linked List is empty!!!\n");
	}
	else
	{
		DCLL * Head = last->next;
		printf("\n\t**********Students data**********\n");
		do{
			printf(" Roll no : %d \n Name : %s \n Prev: %p \n base: %p \n next: %p \n------------------------------------------------------------------------------------------------------------------------\n",Head->rollNo,Head->name,Head->prev,Head,Head->next);		
			Head = Head->next;			
		}while(Head!=last->next);
	}
}

//Free Linked List
void FreeLinkedList(DCLL * last){
	
	if(last == NULL){
		return;
	}
	DCLL * temp = NULL;	
	DCLL * Head = last->next;
		do{
			temp = Head;
			Head = Head->next;
			free(temp);
		}while(Head!=last->next);
}

int main(void){
	
	DCLL* End = NULL;
	int Choice;
	int RollNo;
	
	do{
		printf("\n********** Doubly Circular Linked List **********\n");
		printf("\nEnter 1: to Create Doubly Linked list\n");
    	printf("Enter 2: to Display Doubly Linked List\n");	
		printf("Enter 3: to Delete specific Node\n");	
		printf("Enter 4: to Exit the Linked List\n");
	
			printf("\nChoice: ");			
			scanf(" %d",&Choice);
			getchar();
		
		switch (Choice){
			
			case 1:	
					FreeLinkedList(End);
					End = NULL;
					End = CreateLinkedList(End);
					
			break;
		
			case 2: 
					DisplayLinkedList(End);
			break;
			
			case 3:     
					if(End == NULL){
						printf("\n!!!The List is Empty!!!\n ");
					}
					else
					{
						printf("\n**********Enter Student Data**********\n");
					
							printf("Enter the RollNo: ");
							scanf(" %d",&RollNo);
	
						End = DeleteSpecificNode(End,RollNo);
						
					}
			break;
			
			case 4:
			        printf("\n\n Exiting the linked list ....\n");
					FreeLinkedList(End);
					End = NULL;
					exit(0);
			break;
			
			default: 
					printf("!!! Invalid Choice  !!!");
			continue;
					
		}			
	}while(Choice!=4);
	
	
	
	
	return 0;
}