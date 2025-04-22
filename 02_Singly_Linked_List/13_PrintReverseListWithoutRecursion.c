/* 

      write a c program to Create a Singly linked list and Display it in reverse order (Use Normal Function)
	  
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| 


O/P :
------  
4 DD
3 CC
2 BB
1 AA

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
SLL * CreateLinkedList(SLL * ,int * );
void DisplayReverseList(SLL * ,int );
void DisplaySinglyLinkedList(SLL * );
void FreeLinkedList(SLL* );


//List Creation
SLL * CreateLinkedList(SLL * Head,int * nodeCount){
	char ans;
	 SLL * Node = NULL;
	 SLL * last = Head;
    do{
		
	    Node = (SLL *)malloc(sizeof(SLL));
		Node->next = NULL;
		*nodeCount+=1;
	
	    printf("\n\t**********Enter Students details**********\n");
		printf("Enter the Name of Student: ");
		scanf(" %[^\n]s",Node->name);
		
		printf("Enter the RollNo: ");
		scanf(" %d",&Node->rollNo);
	
	
		if(Head == NULL)
		{
			Head = Node; 
		}
		else{
			last->next = Node;		
		}
		last = Node;
				
			printf("\nDo you want to enter new node? [Y/N]: ");
			scanf(" %c",&ans);				
	}while((ans=='y')||(ans=='Y'));	
	

	last = NULL;
	free(last);
		
	Node = NULL;
	free(Node);
	
	return Head;

}


//Display Reverse List
void DisplayReverseList(SLL * Head,int cnt){
	
	SLL*iter = NULL;
	
	if(Head == NULL)
	{
		printf("\n!!!The List is Empty!!!\n");
	}
	else{
		
		
	    while(cnt!=0){
			iter = Head;
			for(int i = 0;i<cnt-1;iter=iter->next,i++);
		
			printf(" Roll no : %d \n Name : %s \n------------------------------------------------------------------------------------------------------------------------\n",
			iter->rollNo,iter->name);
			cnt--;
    	}
	}
	
	iter = NULL;
	free(iter);
}


//Display List
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
    //code
	char ch; 
	int Choice;
	int totalNodes = 0;
	SLL * Start = NULL;
	
	
	do{
		printf("\n********** Singly Linked List **********\n");
		printf("\nEnter 1: to Create Singly Linked list\n");
    	printf("Enter 2: to Display Singly Linked List\n");	
		printf("Enter 3: to Display Reverse Singly Linked List\n");	
		printf("Enter 4: to Exit the Linked List\n");


		printf("\nChoice: ");			
		scanf(" %d",&Choice);
		getchar();
		
			
		
		switch (Choice){
			
			case 1:	
					FreeLinkedList(Start);
					Start = NULL;
					Start = CreateLinkedList(Start,&totalNodes);
			break;
		
			case 2: 
					printf("\n\t*********Students Data *********\n");
					DisplaySinglyLinkedList(Start);
			break;
			
			case 3: 
					printf("\n\t********* Students Data *********\n");
					DisplayReverseList(Start,totalNodes);
			break;
			
			case 4:
					printf("\n\n Exiting the linked list ....\n");
					FreeLinkedList(Start);
					Start = NULL;
					exit(0);
			break;
			
			default: 
					printf("!!! Invalid Choice  !!!");
			continue;
			
		}
	    	
	}while(Choice!=4);
		
	return 0;
}