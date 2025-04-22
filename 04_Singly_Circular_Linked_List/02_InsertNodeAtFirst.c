/*

  write a c program to Create a circular singly  linked list and insert a new node at the beginning 

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
SCLL * CreateLinkedList(SCLL * );
void DisplayLinkedList(SCLL * );
SCLL* InsertNodeAtFirst(SCLL * );
void FreeLinkedList(SCLL * );


//Create Singly Circular Linked List
SCLL * CreateLinkedList(SCLL * last){
	
	SCLL * NewNode = NULL;
	char ans;
	do{
		NewNode = (SCLL*)malloc(sizeof(SCLL));
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


SCLL* InsertNodeAtFirst(SCLL * last){
	
	SCLL * NewNode = NULL;
	NewNode = (SCLL*)malloc(sizeof(SCLL));
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
		last->next = NewNode;
	}
	else{
		NewNode->next = last->next;
		last->next = NewNode;
	}
	return last;
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
			printf(" Roll no : %d \n Name : %s  \n------------------------------------------------------------------------------------------------------------------------\n",Head->rollNo,Head->name);		
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
	
	do{
		printf("\n********** Singly Circular Linked List **********\n");
		printf("\nEnter 1: to Create Singly Linked list\n");
    	printf("Enter 2: to Display Singly Linked List\n");	
		printf("Enter 3: to Insert Node in the begining\n");	
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
			        End = InsertNodeAtFirst(End);
					 printf("\n\n********** Node Inserted Successfully **********\n");
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