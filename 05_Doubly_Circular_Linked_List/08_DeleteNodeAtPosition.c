/*

write a c program to create a circular Doubly linked list and delete the node by position 

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
DCLL * CreateLinkedList(DCLL * ,int* );
void DisplayLinkedList(DCLL * );
DCLL* DeleteNodeAtPosition(DCLL * ,int,int* );
void FreeLinkedList(DCLL * );


//Create Doubly Circular Linked List
DCLL * CreateLinkedList(DCLL * last,int * nodeCount){
	
	DCLL * NewNode = NULL;
	char ans;
	do{
		NewNode = (DCLL*)malloc(sizeof(DCLL));
		NewNode->prev = NULL;
		NewNode->next = NULL;
		*nodeCount+=1;
		
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


DCLL* DeleteNodeAtPosition(DCLL * last,int ipos,int *nodeCount){
	
	DCLL * tempNode = NULL;
	DCLL * iter = NULL;
	int i = 1;
	
	if(ipos==1){
		if(*nodeCount == 1)
		{
			free(last);
			printf("\n\n********* Node Deleted Successfully *********\n");
			*nodeCount-=1;
			return NULL;
		}
		tempNode = last->next;
		last->next = tempNode->next;
		tempNode->next->prev = last;
	
		free(tempNode);
		printf("\n\n********* Node Deleted Successfully *********\n");
		*nodeCount-=1;
		return last;
	}
	else if(ipos == *nodeCount)
	{
		tempNode = last;
		last = tempNode->prev;
		last->next = tempNode->next;
		tempNode->next->prev = last;
		
		free(tempNode);
		printf("\n\n********* Node Deleted Successfully *********\n");
		*nodeCount-=1;
		return last;
	}
	
	iter = last;
	
	if(ipos<=(*nodeCount/2))
	{
		i = 0;
		while(i!=ipos-1)
		{
			iter = iter->next;
			i = i+1;
		}
		
		tempNode = iter->next;
		iter->next = tempNode->next;
		tempNode->next->prev = iter;
		
		free(tempNode);
		printf("\n\n********* Node Deleted Successfully *********\n");
		*nodeCount-=1;
		return last;
	}
	else if(ipos>(*nodeCount/2))
	{
		i = *nodeCount;
		
		while(i!=ipos+1)
		{
			iter = iter->prev;
			i = i-1;
		}
		
		tempNode = iter->prev;
		iter->prev = tempNode->prev;
		tempNode->prev->next = iter;
		
		free(tempNode);
		printf("\n\n********* Node Deleted Successfully *********\n");
		*nodeCount-=1;
		return last;	
	}
	
	free(iter);
	iter = NULL;
	
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
	int position;
	int totalNodes = 0;
	
	do{
		printf("\n********** Doubly Circular Linked List **********\n");
		printf("\nEnter 1: to Create Doubly Linked list\n");
    	printf("Enter 2: to Display Doubly Linked List\n");	
		printf("Enter 3: to Delete Node at Given Position\n");	
		printf("Enter 4: to Exit the Linked List\n");
	
			printf("\nChoice: ");			
			scanf(" %d",&Choice);
			getchar();
		
		switch (Choice){
			
			case 1:	
					FreeLinkedList(End);
					End = NULL;
					End = CreateLinkedList(End,&totalNodes);
					
			break;
		
			case 2: 
					DisplayLinkedList(End);
			break;
			
			case 3:
					if(End==NULL)
					{
						printf("\n!!! The List is Empty enter data !!!\n");
					}
					else
					{
						printf("\nEnter the Position:  ");
						scanf(" %d",&position);
						
						if(position <0 || position > totalNodes)
						{
							printf("\n!!!Invalid Position please enter the position again!!!\n");
						}
						else{
							End = DeleteNodeAtPosition(End,position,&totalNodes);
						}
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
