/*

  write a c program to Create a circular Doubly  linked list and delete the first node	

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
DCLL* DeleteNodeAtFirst(DCLL * );
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


DCLL* DeleteNodeAtFirst(DCLL * last){
	
	DCLL * tempNode = NULL;
		
	if(last == NULL||last->next == last){
		free(last);
		last = NULL;
		return NULL;
	}
	
	tempNode = last->next;
	last->next = tempNode->next;
	tempNode->next->prev = last;
	free(tempNode);
			
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
	
	do{
		printf("\n********** Doubly Circular Linked List **********\n");
		printf("\nEnter 1: to Create Doubly Linked list\n");
    	printf("Enter 2: to Display Doubly Linked List\n");	
		printf("Enter 3: to Delete Node in the begining\n");	
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
			         End = DeleteNodeAtFirst(End);
					 if(End==NULL){
						 printf("\n!!! Linked List is Empty !!!\n");
					 }
					 else
					 {
						printf("\n\n********** Node Deleted Successfully **********\n");
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