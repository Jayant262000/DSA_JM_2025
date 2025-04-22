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

typedef struct SinglyLinkedList{
	
	int rollNo;
	char name[20];
	
	struct SinglyLinkedList * next;	
}SLL;

//Functions
SLL * CreateLinkedList(SLL * , SLL** ,int *);
SLL * InsertAtFirst(SLL * );
SLL * InsertNodeAtLast(SLL * ,SLL** );
SLL * InsertInPosition(SLL * , int ,int* );
SLL * DeleteNodeAtFirst(SLL * );
SLL * DeleteNodeAtLast(SLL * );
SLL * DeleteInPosition(SLL * ,int );
SLL * DeleteSpecificNode(SLL * ,int );
void DisplayReverseList(SLL * );
void DisplaySinglyLinkedList(SLL * );
void FreeLinkedList(SLL* );


//Singly Linked List creation




SLL * CreateLinkedList(SLL * Head,SLL ** last,int * countNode){
	char ans;
	 SLL * Node = NULL;
    do{
		
	    Node = (SLL *)malloc(sizeof(SLL));
		Node->next = NULL;
	
	    printf("\n\t**********Enter Students details**********\n");
		printf("Enter the Name of Student: ");
		scanf(" %[^\n]s",Node->name);
		
		printf("Enter the RollNo: ");
		scanf(" %d",&Node->rollNo);
		*countNode+=1;
	
	
		if(Head == NULL)
		{
			Head = Node; 
		}
		else{
			(*last)->next = Node;		
		}
		(*last) = Node;
				
			printf("\nDo you want to enter new node? [Y/N]: ");
			scanf(" %c",&ans);				
	}while((ans=='y')||(ans=='Y'));	
	
	
	Node = NULL;
	free(Node);
		
	return Head;

}


//Insert Node in the begining
SLL * InsertAtFirst(SLL * Head){
	
	SLL * Node = NULL;
		
	Node = (SLL *)malloc(sizeof(SLL));
	Node->next = NULL;
	
	printf("Enter the Name of Student: ");
	scanf(" %[^\n]s",Node->name);
	
	printf("Enter the RollNo: ");
	scanf(" %d",&Node->rollNo);
	
	
	if(Head == NULL)
	{
		Head = Node; 
	}
   	else{
		
		Node->next = Head;
		Head = Node;
	}
	
	Node = NULL;
	free(Node);
	
	return Head;
}


//Insert Node in given position
SLL * InsertInPosition(SLL * Head, int pos, int * totalNodes)
{
	
		SLL * Node = NULL;
		SLL * iter = Head;
		int ipos = 0;
	
		Node = (SLL *)malloc(sizeof(SLL));
		Node->next = NULL;
		*totalNodes+=1;
		
		printf("Enter the Name of Student: ");
    	scanf(" %[^\n]s",Node->name);
	
		printf("Enter the RollNo: ");
		scanf(" %d",&Node->rollNo);
	
	    if((pos == 1)&&(Head == NULL)){
			Head = Node;
			return Head;
		}
		else if((pos==1)&&(Head!=NULL)){
			Node->next = Head;
	    	Head = Node;
		}
		else{
			for( ipos = 1;(ipos < pos-1)&&(iter->next!=NULL);iter = iter->next,ipos++);
			Node->next = iter->next;
			iter->next = Node;
		}			
        
	iter = NULL;
	free(iter);
	
	Node = NULL;
	free(Node);
		
	return Head;
	
}


//Insert Node at last
SLL * InsertNodeAtLast(SLL * Head, SLL ** last){
	
	    SLL * Node = NULL;
		
	   Node = (SLL *)malloc(sizeof(SLL));
	   Node->next = NULL;
	
	
	printf("Enter the Name of Student: ");
	scanf(" %[^\n]s",Node->name);
	
	printf("Enter the RollNo: ");
	scanf(" %d",&Node->rollNo);
	
	
	if(Head == NULL)
	{
		Head = Node; 
	}
   	else
	{	
		(*last)->next = Node;	
	}
    *last = Node;	
	
	return Head;
}


//Node Deletion from the start of the list
SLL * DeleteNodeAtFirst(SLL * Head){
	    
		SLL * tempPtr = NULL;
		tempPtr = Head;
		Head = Head->next;
		
		tempPtr = NULL;
		free(tempPtr);
		
		return Head;

}

// Node deletion from given position
SLL * DeleteNodeAtPosition(SLL * Head, int pos,int * counter){
		
	    SLL * temp = NULL;
		SLL * iter = Head;
	    int ipos = 0;
	 
	    if((pos==1)&&(Head->next!=NULL))
		{
			temp = Head;
			Head = Head->next;
		
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
			iter->next = iter->next->next;
	    }	
		
		*counter-=1;
		
		temp = NULL; 
		free(temp);
		iter = NULL;
		free(iter);
		
	return Head;
}

//Delete Node at last
SLL * DeleteNodeAtLast(SLL * Head){
	    
		SLL * iter = Head;
		SLL * temp = NULL;
        if(Head->next == NULL)
		{
			free(Head);
			return NULL;
		}
		else
		{
			for(;iter->next->next!=NULL;iter = iter->next);	
			temp = iter->next; 
			iter->next = NULL;

			temp = NULL;
			free(temp);
			
			iter = NULL;
			free(iter);
			
			return Head;		
		}
}

//Delete Specific Node
SLL * DeleteSpecificNode(SLL * Head, int RollNo){
	
	   SLL * iter = Head;
	   SLL * temp = NULL;

	   if(Head->rollNo == RollNo)
			{				
				Head = Head->next;
				
			}
		else if((Head->rollNo != RollNo) && (Head->next!=NULL)){
			while(iter->next!=NULL){			
				if(iter->next->rollNo == RollNo){	
				temp = iter->next;
				iter->next = temp->next;
				free(temp);
				break;
			}
			
			iter = iter->next;
			}
		}
		else
		{
			printf("\n!!!Key Not Found in linked List!!!\n");
		}
		
		iter  = NULL;
		free(iter);
		
		temp = NULL;
		free(temp);

	return Head;
}


//Display Reverse list
void DisplayReverseList(SLL * Head){

	if(Head!=NULL)
	{	   
		DisplayReverseList(Head->next);
		printf("Roll no : %d \n Name : %s \n------------------------------------------------------------------------------------------------------------------------\n",Head->rollNo,Head->name);
	}
		
}



//Display Singly Linked List
void DisplaySinglyLinkedList(SLL * Head)
{
	if(Head == NULL)
	{
		printf("\n!!!The List is Empty!!!\n");
	}
	else
	{		
		for(;Head!=NULL;Head=Head->next)
		{
			printf(" Roll no : %d \n Name : %s  \n------------------------------------------------------------------------------------------------------------------------\n",Head->rollNo,Head->name);
		}	   
	}
}

//Free Linked List
void FreeLinkedList(SLL * Head){
	SLL * temp = NULL;
	
	while(Head!=NULL){
		temp = Head;
		Head = Head->next;
		free(temp);
	}
}

int main()
{
	
	int ch;
	 int position,totalNodes = 0;
	 int n;
	 int RollNo;
	 int data;
	 int roll_no;
	 char name[20];
	SLL * Start = NULL;
	SLL * last = NULL;
	
	do{
		printf("\n*************Singly Linked List Menu***********\n");
		printf("+------------------------------------------------------------------------------------------+\n");
		printf("|  Press 1: to Create the Singly Linked list                                                |\n");
		printf("|  Press 2: to Insert the data in the begining in the Linked list                           |\n");
		printf("|  Press 3: to Insert data in the Linked list at the end                                    |\n");
		printf("|  Press 4: to Insert the data in position inside the linked list                           |\n");
	    printf("|  Press 5: to delete the data from the first node                                          |\n");
		printf("|  Press 6: to delete the data from the end of the Linked list                              |\n");
		printf("|  Press 7: to delete the data from the position inside the linked list                     |\n");		
		printf("|  Press 8: to delete the specific node inside the linked list                              |\n");	
		printf("|  Press 9: to display the Reverse List (Using Recursion)                                   |\n");
		printf("|  Press 10: to display the Singly Linked List                                              |\n");
		printf("|  Press 0: to Exit the Linked list                                                         |\n");
		printf("+-------------------------------------------------------------------------------------------+\n");
 
        printf("+-------------------------------------+\n");
		printf("   Enter your choice: ");
		scanf("%d", &ch);
		printf("+-------------------------------------+\n");		
	    switch(ch){
			case 1:
					FreeLinkedList(Start);
					Start = NULL;
					Start = CreateLinkedList(Start,&last,&totalNodes);
			break;
			
			case 2:
					Start = InsertAtFirst(Start);
					printf("\n\t********* Node Added Successfully *********\n");
					break;
            case 3: 
					Start = InsertNodeAtLast(Start,&last);
					printf("\n\t********** Node Added Successfully **********\n");
			break;
					
            case 4: 		
					printf("\nEnter the Position:  ");
					scanf("%d",&position);
					
					if(position <= 0 || position > totalNodes+1)
					{
						printf("\n!!!Invalid Position please enter the position again!!!\n");
					}
					else{
						Start = InsertInPosition(Start,position,&totalNodes);
						printf("\n********* Node Insered Successfully *********\n");
					}
			break;
			case 5: 
				
					if(Start==NULL){
							printf("\n!!!Linked List is Empty!!!\n!!!Entert the Data!!!\n");
					}
					else
					{
						Start = DeleteNodeAtFirst(Start);
						printf("\n\t**********Node Deleted Successfully**********\n");
					}
			break;
			case 6: 
			        if(Start==NULL){
							printf("\n!!!Linked List is Empty!!!\n!!!Entert the Data!!!\n");
					}
					else
					{
						Start = DeleteNodeAtLast(Start);
						printf("\n\t**********Node Deleted Successfully**********\n");
					}
			    break;					
			case 7: 
					if(Start==NULL){
						printf("\n!!!Linked List is Empty!!!\n!!!Entert the Data!!!\n");
					}
					else
					{
				
						printf("\nEnter the Position: ");
						scanf("%d",&position);
		
						if((position>=1)&&(position<=totalNodes)){	
							Start = DeleteNodeAtPosition(Start,position,&totalNodes);
					        printf("\n\t**********Node Deleted Successfully**********\n");
						}
						else
						{
							printf("\n!!!Invalid Position!!!\n!!!Enter position again!!!\n");
						}
					}
				break;
				
			case 8: 
				    if(Start == NULL){
						printf("\n!!!The List is Empty!!!\n ");
					}
					else
					{
						printf("\n**********Enter Student Data**********\n");
					
							printf("Enter the RollNo: ");
							scanf(" %d",&RollNo);
	
						Start = DeleteSpecificNode(Start,RollNo);
						printf("\n********Node deleted successfully ********\n");
					}
			break;
				
			case 9:
	    			if(Start == NULL){
	            	    printf("\n!!!List is Empty!!!\n");
                  	}
					else
					{
						printf("\n\t********* Students Data *********\n");
						DisplayReverseList(Start);
					}
			break;
				
			case 10:
				    DisplaySinglyLinkedList(Start);
			break;	

			case 0: 
					printf("\n\n Exiting the linked list ....");
					FreeLinkedList(Start);
					Start = NULL;
					last = NULL;
					free(last);
					exit(0);
			break;		
				
		} 
				
	}while(ch!=0);
	
	return 0;
}