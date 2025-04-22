/*

write a c program to create a circular singly linked list and delete the node by position 

*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct SinglyCircularLinkedList{
	
	int rollNo;
	char name[20];
	
	struct SinglyCircularLinkedList * next;
	
}SCLL;

//Functions
SCLL * CreateLinkedList(SCLL * ,int* );
void DisplayLinkedList(SCLL * );
SCLL* DeleteNodeAtPosition(SCLL * ,int,int* );
void FreeLinkedList(SCLL * );


//Create Singly Circular Linked List
SCLL * CreateLinkedList(SCLL * last,int *nodeCount){
	
	SCLL * NewNode = NULL;
	char ans;
	do{
		NewNode = (SCLL*)malloc(sizeof(SCLL));
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
			last->next = NewNode;
		}
		else{
			NewNode->next = last->next;
			last->next = NewNode;
			last = NewNode;
		}
		printf("\nDo you want to Enter new node? [Y/N]:  ");
		scanf("%c",&ans);
	}while(ans=='Y'||ans=='y');
	return last;
}


SCLL* DeleteNodeAtPosition(SCLL * last,int ipos,int *nodeCount){
	
	SCLL * tempNode = NULL;
	SCLL * iter = NULL;
	int i = 1;
	
	if(ipos==1){
		if(last->next==last)
		{
			free(last);
			last=NULL;
			printf("\n\n********* Node Deleted Successfully *********\n");
			*nodeCount-=1;
			return last;
		}
		else
		{
			tempNode = last->next;
			last->next = tempNode->next;
			free(tempNode);
			printf("\n\n********* Node Deleted Successfully *********\n");
			*nodeCount-=1;
			return last;
		}
	}
	iter = last->next;
	do{	
		if(i==ipos-1)
		{	
			if(iter->next == last)
			{
				tempNode = last;
				iter->next = last->next;
				last = iter;
				free(tempNode);
				printf("\n\n********* Node Deleted Successfully *********\n");
				return last;
			}	
			tempNode = iter->next;
			iter->next = tempNode->next;
			free(tempNode);
			printf("\n\n********* Node Deleted Successfully *********\n");
			*nodeCount-=1;
			return last;	
		}	
		i++;
		iter = iter->next;
	}while(iter!=last);
}


//Display Singly Circular Linked list
void DisplayLinkedList(SCLL * last){
	
	if(last == NULL)
	{
		printf("\n!!!Linked List is empty!!!\n");
	}
	else
	{
		SCLL * Head = last->next;
		printf("\n\t**********Students deta**********\n");
		do{
			printf(" Roll no : %d \n Name : %s \n next: %p \n Node: %p \n------------------------------------------------------------------------------------------------------------------------\n",Head->rollNo,Head->name,Head->next,Head);		
			Head = Head->next;			
		}while(Head!=last->next);
	}
}

//Free Linked List
void FreeLinkedList(SCLL * last){
	
	if(last == NULL){
		return;
	}
	SCLL * temp = NULL;	
	SCLL * Head = last->next;
		do{
			temp = Head;
			Head = Head->next;
			free(temp);
		}while(Head!=last->next);
}

int main(void){
	
	SCLL* End = NULL;
	int Choice;
	int position;
	int totalNodes = 0;
	
	do{
		printf("\n********** Singly Circular Linked List **********\n");
		printf("\nEnter 1: to Create Singly Linked list\n");
    	printf("Enter 2: to Display Singly Linked List\n");	
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