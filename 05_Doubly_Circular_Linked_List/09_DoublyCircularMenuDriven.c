/*

  write a c program to Create a Menu driven for circular Doubly linked list which consists the following functions: - 
          - Create(), 
          - Insert(),
          - Delete(), 
          - Display().

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
DCLL * CreateLinkedList(DCLL * , int* );
DCLL* InsertNodeAtFirst(DCLL * );
DCLL* InsertNodeAtPosition(DCLL * ,int ,int* );
DCLL* InsertNodeAtLast(DCLL * );
DCLL* DeleteNodeAtLast(DCLL * );
DCLL* DeleteNodeAtFirst(DCLL * );
DCLL* DeleteSpecificNode(DCLL * , int);
DCLL* DeleteNodeAtPosition(DCLL * ,int,int* );
void DisplayLinkedList(DCLL * );
void FreeLinkedList(DCLL * );



//Create Doubly Circular Linked List
DCLL * CreateLinkedList(DCLL * last,int *nodeCount){
	
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
//Insert node at first
DCLL* InsertNodeAtFirst(DCLL * last){
	
	DCLL * NewNode = NULL;
	NewNode = (DCLL*)malloc(sizeof(DCLL));
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
		last->prev = NewNode;
	}
	else{
		NewNode->next = last->next;
		NewNode->next->prev = NewNode;
		last->next = NewNode;
		NewNode->prev = last;
	}
	return last;
}


//Insert node at given position
DCLL* InsertNodeAtPosition(DCLL * last,int ipos,int *nodeCount){
	
	DCLL * NewNode = NULL;
	DCLL * iter = NULL;
	int i = 1;
	
	NewNode = (DCLL*)malloc(sizeof(DCLL));
	NewNode->next = NULL;
	*nodeCount+=1;
		
	printf("\n\t**********Enter Students details**********\n");
		
	printf("Roll No: ");
	scanf("%d",&NewNode->rollNo);
	getchar();
		
	printf("Name: ");
	fgets(NewNode->name,sizeof(NewNode->name),stdin);
	NewNode->name[strcspn(NewNode->name,"\n")] = '\0';
	
	if(ipos==1){
		if(last==NULL)
		{
			last = NewNode;
			last->next = NewNode;
			last->prev = NewNode;
			return last;
		}
		else
		{
			NewNode->next = last->next;
			last->next = NewNode;
			NewNode->prev = last;
			NewNode->next->prev = NewNode;
			
			return  last;
		}
	}
	iter = last->next;
	do{	
		if(i==ipos-1)
		{		
			NewNode->next = iter->next;
			iter->next = NewNode;
			NewNode->prev = iter;
			NewNode->next->prev = NewNode;
			return last;	
		}	
		i++;
		iter = iter->next;
	}while(iter!=last);
	
	if((iter == last)&&i==ipos-1)
	{
		NewNode->next = iter->next;
		iter->next = NewNode;
		NewNode->prev = iter;
		NewNode->next->prev = NewNode;
		last = iter->next;
		return last;
	}

	return last;
}



//Insert Node at last

DCLL* InsertNodeAtLast(DCLL * last){
	
	DCLL * NewNode = NULL;
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
	return last;
}

//Delete Node At first
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


//Delete Node at last
DCLL* DeleteNodeAtLast(DCLL * last){
	
	DCLL * tempNode = NULL;
	
	if(last == NULL||last->next == last){
		free(last);
		last = NULL;
		return NULL;
	}
	
	tempNode = last;
	last = tempNode->prev;
	last->next = tempNode->next;
	tempNode->next->prev = last;
	
	free(tempNode);
	
	return last;
}


//Delete specific node
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



//Delete node at given position
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
	int RollNo;
	
	do{
		printf("\n********** Doubly Circular Linked List **********\n");
		printf("\nEnter 1: to Create Doubly Linked list\n");
    	printf("Enter 2: to Display Doubly Linked List\n");	
		printf("Enter 3: to Insert Node in the begining\n");
		printf("Enter 4: to Insert Node at Given Position\n");
		printf("Enter 5: to Insert Node at last\n");			
		printf("Enter 6: to Delete Node in the begining\n");
		printf("Enter 7: to Delete Node at last\n");
		printf("Enter 8: to Delete specific Node\n");
		printf("Enter 9: to Delete Node at Given Position\n");	
		printf("Enter 0: to Exit the Linked List\n");
	
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
			        End = InsertNodeAtFirst(End);
					 printf("\n\n********** Node Inserted Successfully **********\n");
			break;
			
			case 4:
					printf("\nEnter the Position:  ");
					scanf("%d",&position);
					
					if(position <= 0 || position > totalNodes+1)
					{
						printf("\n!!!Invalid Position please enter the position again!!!\n");
					}
					else{
						End = InsertNodeAtPosition(End,position,&totalNodes);
						printf("\n********* Node Insered Successfully *********\n");
					}
			break;
			
			case 5:
			        End = InsertNodeAtLast(End);
					 printf("\n\n********** Node Inserted Successfully **********\n");
			break;
			
			case 6:
			         End = DeleteNodeAtFirst(End);
					 if(End==NULL){
						 printf("\n!!! Linked List is Empty !!!\n");
					 }
					 else
					 {
						printf("\n\n********** Node Deleted Successfully **********\n");
					 }
			break;
			
			case 7:
			         
					 if(End==NULL){
						 printf("\n!!! Linked List is Empty !!!\n");
					 }
					 else
					 {
						 End = DeleteNodeAtLast(End);
						printf("\n\n********** Node Deleted Successfully **********\n");
					 }
			break;
			
			case 8:     
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
			
			case 9:
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
			
			case 0:
			        printf("\n\n Exiting the linked list ....\n");
					FreeLinkedList(End);
					End = NULL;
					exit(0);
			break;
			
			default: 
					printf("!!! Invalid Choice  !!!");
			continue;
					
		}			
	}while(Choice!=0);
	
	
	
	
	return 0;
}