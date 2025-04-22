/*

  write a c program to Create a Menu driven for circular singly linked list which consists the following functions: - 
          - Create(), 
          - Insert(),
          - Delete(), 
          - Display().

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
SCLL * CreateLinkedList(SCLL * , int* );
SCLL* InsertNodeAtFirst(SCLL * );
SCLL* InsertNodeAtPosition(SCLL * ,int ,int* );
SCLL* InsertNodeAtLast(SCLL * );
SCLL* DeleteNodeAtLast(SCLL * );
SCLL* DeleteNodeAtFirst(SCLL * );
SCLL* DeleteSpecificNode(SCLL * , int);
SCLL* DeleteNodeAtPosition(SCLL * ,int,int* );
void DisplayLinkedList(SCLL * );
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

//Insert node at first
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


//Insert node at given position
SCLL* InsertNodeAtPosition(SCLL * last,int ipos,int *nodeCount){
	
	SCLL * NewNode = NULL;
	SCLL * iter = NULL;
	int i = 1;
	
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
	
	if(ipos==1){
		if(last==NULL)
		{
			last = NewNode;
			last->next = NewNode;
			return last;
		}
		else
		{
			NewNode->next = last->next;
			last->next = NewNode;
			return  last;
		}
	}
	iter = last->next;
	do{	
		if(i==ipos-1)
		{		
			NewNode->next = iter->next;
			iter->next = NewNode;
			return last;	
		}	
		i++;
		iter = iter->next;
	}while(iter!=last);
	
	if((iter == last)&&i==ipos-1)
	{
		NewNode->next = iter->next;
		iter->next = NewNode;
		last = iter->next;
		return last;
	}

	return last;
}



//Insert Node at last
SCLL* InsertNodeAtLast(SCLL * last){
	
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
		last = NewNode;
	}
	return last;
}


//Delete Node At first
SCLL* DeleteNodeAtFirst(SCLL * last){
	
	SCLL * tempNode = NULL;
		
	if(last == NULL||last->next == last){
		free(last);
		last = NULL;
		return NULL;
	}
	
	tempNode = last->next;
	last->next = tempNode->next;
	free(tempNode);
	
	return last;
}


//Delete Node at last
SCLL* DeleteNodeAtLast(SCLL * last){
	
	SCLL * tempNode = NULL;
	SCLL * iter = last->next;
	
	if(last == NULL||last->next == last){
		free(last);
		last = NULL;
		return NULL;
	}
	
	while(iter->next!=last){
		iter = iter->next;
	}
	
	tempNode = last;
	iter->next = last->next;
	last = iter;
	free(tempNode);
	
	return last;
}


//Delete specific node
SCLL* DeleteSpecificNode(SCLL * last,int RollNo){
	
	SCLL * tempNode = NULL;
	SCLL * iter = last->next;
	int flag = 0;
	
	
	if((last == NULL||last->next == last)&&last->rollNo == RollNo){
		free(last);
		last = NULL;
		printf("\n********Node deleted successfully ********\n");
		return NULL;
	}
	else if(last->next->rollNo == RollNo)
	{
		tempNode = last->next;
		last->next = tempNode->next;
		flag = 1;
		free(tempNode);
	}
	
	while(iter!=last){
		if(iter->next->rollNo==RollNo){
			if(iter->next==last)
			{
				tempNode = iter->next;
				iter->next = tempNode->next;
				last = iter;
				free(tempNode);
				flag = 1;
				
			}
			else
			{
				tempNode = iter->next;
				iter->next = tempNode->next;
				free(tempNode);
				flag = 1;
			}
		}
		else
		{	
			iter = iter->next;
		}
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
	int position;
	int totalNodes = 0;
	int RollNo;
	
	do{
		printf("\n********** Singly Circular Linked List **********\n");
		printf("\nEnter 1: to Create Singly Linked list\n");
    	printf("Enter 2: to Display Singly Linked List\n");	
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