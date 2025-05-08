/* 

      write a c program to Create a Singly linked list  and perform menu driven which includes following functions: 
	  - create(),
	  - Insert(),
	  - Delete(),
	  - Reverse(),
	  - print()


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



DLL * CreateLinkedList(DLL * Head,DLL ** last, int * countNode){
	char ans;
	
 (*last) = Head;
	printf("\n\t**********Enter Students details**********\n");
    do{
	    DLL * Node = NULL;
		
		
	    Node = (DLL *)malloc(sizeof(DLL));
		Node->previous = NULL;
		Node->next = NULL;
		*countNode += 1;
		
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
			(*last)->next = Node;
			Node->previous = (*last);
		}
		(*last) = Node;
		
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



DLL * InsertAtFirst(DLL * Head){
	
	
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
		
		Head->previous = Node;
		Node->next = Head;
		Head = Node;
	}

	return Head;
}



DLL * InsertInPosition(DLL * Head, int pos,int * counter){
	
		DLL * Node = NULL;
		DLL * iter = Head;
		int ipos = 0;
	
		Node = (DLL *)malloc(sizeof(DLL));
		Node->previous = NULL;
		Node->next = NULL;
		
		printf("\nRollNo: ");
		scanf(" %d",&Node->rollNo);
		getchar();
		
		printf("Student Name : ");
		fgets(Node->name,sizeof(Node->name),stdin);
		Node->name[strcspn(Node->name,"\n")] = '\0';
	
		if((pos==1)&&(Head!=NULL))
		{
			Head->previous = Node;
			Node->next = Head;
	    	Head = Node;		
		}
		else if((pos == 1)&&(Head == NULL))
		{
			Head = Node;
			return Head;
		}
		else
		{
			for(ipos = 1;(ipos < pos-1)&&(iter->next!=NULL);iter = iter->next,ipos++);
			if(iter->next!=NULL)
			{
				Node->previous = iter;
				Node->next = iter->next;
				iter->next->previous = Node;
				iter->next = Node;
			}
			else
			{
				iter->next = Node;
				Node->previous = iter;		
			}
			
		}				 
	    *counter += 1;
		return Head;
}



DLL * InsertNodeAt(DLL * Head, DLL ** last){
	
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
   	else
	{

		(*last)->next = Node;
		Node->previous = (*last);
	}  
	  return Head;
}



DLL * DeleteNodeAtFirst(DLL * Head){
	
		if(Head->next==NULL){
			free(Head);
			return NULL;
		}
		else
		{
			DLL * tempPtr = NULL;
			tempPtr = Head;
			Head = Head->next;
			Head->previous = NULL;
			free(tempPtr);
		
			return Head;
		}
}



DLL * DeleteNodeAtPosition(DLL * Head, int pos,int * counter){
	
		
	    DLL * temp = NULL;
		DLL * iter = Head;
	    int ipos = 0;
	    		
		
	     if((pos==1)&&(Head->next!=NULL))
		{
			temp = Head;
			Head = Head->next;
			Head->previous = NULL;
			free(temp);
		
			return Head;
		}
        else if((pos==1)&&(Head->next==NULL))	
		{
			free(Head);
			return NULL;
	    }
		
        else		
 		{

			for( ipos = 1;(ipos < pos-1)&&(iter->next!=NULL);iter = iter->next,ipos++);
			
				temp = iter->next;
				if(temp->next == NULL)
				{
					iter->next = NULL;
					free(temp);
					temp = NULL;
				}
				else
				{
					iter->next = temp->next;
					temp->next->previous = iter;
					free(temp);
					temp = NULL;
				}
	    }	
		*counter-=1;
		
	return Head;
}



DLL * DeleteNodeAtLast(DLL * Head,DLL ** last){
	    
	DLL * temp = (*last);
	
	if(Head->next==NULL)
	{
		free(Head);
		Head = NULL;
		return NULL;
	}
	else
	{
		(*last) = (*last)->previous;
	    (*last)->next = NULL;
	
		free(temp);
		temp = NULL;
	
		return Head;
	}

}



void DisplayReverseList(DLL * Head){
	
	if(Head!=NULL)
	{	   
		DisplayReverseList(Head->next);
		printf(" Roll no : %d \n Name : %s \n Prev: %p \n Base: %p \n Next: %p \n-------------------------------------------------------------------------------------------------------------\n"
		,Head->rollNo,Head->name,Head->previous,Head,Head->next);
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
	int position;
	int totalNode = 0;
	DLL * Start = NULL;
	DLL * last = NULL;
	
	
	do{
		printf("\n********** Doubly Linked List **********\n");
		printf("\nEnter 1 Create Doubly Linked list\n");
		printf("Enter 2 to Insert Node At First \n");
		printf("Enter 3 to Insert Node in given position\n");
		printf("Enter 4 to Insert Node at Last\n");
		printf("Enter 5 to Delete First Node\n");	
		printf("Enter 6 to Delete Node at given position\n");	
		printf("Enter 7 to Delete Last Node\n");	
		printf("Enter 8 to Display Reverse Doubly Linked List\n");	
    	printf("Enter 9 to Display Doubly Linked List\n");	
		printf("Enter 10 to Exit\n");

		
		printf("\nChoice: ");			
		scanf("%d",&Choice);
		getchar();
		
		switch (Choice){
			
			case 1:	
					FreeLinkedList(Start);
					Start = NULL;
					free(last);
					last = NULL;
					Start = CreateLinkedList(Start,&last,&totalNode);
			break;
			
			case 2: 
					Start = InsertAtFirst(Start);
					printf("\n\t**********Node inserted successfully**********\n");
			break;
			
			case 3: 
					printf("\nEnter the Position:  ");
					scanf("%d",&position);
					
					if(position <= 0 || position > totalNode+1)
					{
						printf("\n!!!Invalid Position please enter the position again!!!\n");
					}
					else{
						Start = InsertInPosition(Start,position,&totalNode);
						printf("\n**********Node Insered Successfully**********\n");
					}
			break;
			
			case 4:
					Start = InsertNodeAt(Start,&last);
					printf("\n\t********** Node Inserted Successfully **********\n");
			break;	
			
			case 5:
					if(Start==NULL){
							printf("\n!!!Linked List is Empty!!!\n!!!Entert the Data!!!\n");
					}
					else
					{
						Start = DeleteNodeAtFirst(Start);
						if(Start==NULL){
							printf("\n\t**********Node Deleted Successfully**********\n");
							printf("\n!!!Linked List is Empty!!!\n!!!Entert the Data!!!\n");
					    }
						else
						{
							printf("\n\t**********Node Deleted Successfully**********\n");
						}
					}
			break;
			
			case 6:
					if(Start==NULL){
						printf("\n!!!Linked List is Empty!!!\n!!!Entert the Data!!!\n");
					}
					else
					{
						do{
							printf("\nEnter the Position: ");
							scanf(" %d",&position);
							getchar();
							
							if((position>=1)&&(position<=totalNode)){
								break;
							}
							else
							{
								printf("\n!!!Invalid Position!!!\n!!!Enter position again!!!\n");
								continue;
							}
							
						}while(1);
						Start = DeleteNodeAtPosition(Start,position,&totalNode);
						printf("\n\t**********Node Deleted Successfully**********\n");
					}
			break;
			
			case 7:
					if(Start==NULL){
							printf("\n!!!Linked List is Empty!!!\n!!!Entert the Data!!!\n");
					}
					else
					{
						Start = DeleteNodeAtLast(Start,&last);
						if(Start==NULL)
						{
							printf("\n\t**********Node Deleted Successfully**********\n");
							printf("\n!!!Linked List is Empty!!!\n!!!Entert the Data!!!\n");
							
						}
						else
						{
							printf("\n\t**********Node Deleted Successfully**********\n");
						}
					}
			break;
			
			case 8: 
					printf("\n\t***Students Data***\n");
					DisplayReverseList(Start);
			break;
		
			case 9: 
					printf("\n\t***Students Data***\n");
					DisplayDoublyLinkedList(Start);
			break;
			
			case 10:
			        printf("\n\n Exiting the linked list ....\n");
					FreeLinkedList(Start);
					Start = NULL;
					free(last);
					last = NULL;
					exit(0);
			break;
			
			default: 
					printf("!!! Invalid Choice  !!!");
			continue;
			
		}			
	}while(Choice!=10);
		
	return 0;
}