/*

  write a c program to Create a circular singly linked list and delete the node which key matches the user's key

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
SCLL* DeleteSpecificNode(SCLL * , int );
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


SCLL* DeleteSpecificNode(SCLL * last,int RollNo){
	
	SCLL * tempNode = NULL;
	SCLL * iter = last->next;
	SCLL * prev = last;

	int flag = 0;
	
	
	if((last->next == last)&&last->rollNo == RollNo){
		free(last);
		last = NULL;
		printf("\n********Node deleted successfully ********\n");
		return NULL;
	}
	

	while(iter!=last){
		
		if(iter->rollNo==RollNo){
			iter = prev;
			tempNode = iter->next;
			iter->next = tempNode->next;
			
			free(tempNode);
			flag = 1;
		}
		prev = iter;
		iter = iter->next;
	}
	if(iter == last&&last->rollNo == RollNo)
	{
		if((last->next == last)&&last->rollNo == RollNo)
		{
			free(last);
			last = NULL;
			printf("\n********Node deleted successfully ********\n");
			return NULL;
		}
		iter = prev;
		tempNode = iter->next;
		iter->next = tempNode->next;
		last = iter;
			
		free(tempNode);
		flag = 1;
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
	int RollNo;
	
	do{
		printf("\n********** Singly Circular Linked List **********\n");
		printf("\nEnter 1: to Create Singly Linked list\n");
    	printf("Enter 2: to Display Singly Linked List\n");	
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