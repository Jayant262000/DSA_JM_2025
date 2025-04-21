/* 

      write a c program to Create a singly linked list and search a particular node. 
	  
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_400_| --> |_5_|_EE_|_500_| --> |_6_|_FF_|_NULL_|  

Enter : Key = 5

O/P ---->  

 |_5_|_EE_|_500_|

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SinglyLinkedList{
	
	int rollNo;
	char name[20];
	
	struct SinglyLinkedList * next;	
}SLL;

// Functions
SLL * CreateLinkedList(SLL * );
void SearchNode(SLL* ,int );
void DisplaySinglyLinkedList(SLL * );


// Linked List Creation
SLL * CreateLinkedList(SLL * Head){
	char ans;
	 SLL * Node = NULL;
	 SLL * last = Head;
    do{
		
	    Node = (SLL *)malloc(sizeof(SLL));
		Node->next = NULL;
	
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

// Search Node
void SearchNode(SLL*Head,int RollNo){
	
	SLL *iter = Head;
	int flag=0;
	
	for(;iter!=NULL;iter=iter->next){
		
		if(iter->rollNo==RollNo){    		   
			flag = 1;
			break;
		}	
	}
	
	if(flag==1)
	{
	   printf("\n**********Student Details**********\n\n"); 
	   printf(" Roll no : %d \n Name : %s \n------------------------------------------------------------------------------------------------------------------------\n",iter->rollNo,iter->name);
	}
	else
	{
	   printf("\n!!! The RollNo: %d is not found !!!\n",RollNo);
	}
	
	iter = NULL;
	free(iter);
	
}


//Display list
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

int main()
{
    //code
	char ch; 
	int Choice;
	int roll_no;
	SLL * Start = NULL;
	
	
	do{
		printf("\n********** Singly Linked List **********\n");
		printf("\nEnter 1: to Create Singly Linked list\n");
    	printf("Enter 2: to Display Singly Linked List\n");	
		printf("Enter 3: to Search the Node\n");
		printf("Enter 4: to Exit the Linked List\n");
	
			
		printf("\nChoice: ");			
		scanf("%d",&Choice);
		

		
		switch (Choice){
			
			case 1:	
					Start = NULL;
					Start = CreateLinkedList(Start);
			break;
		
			case 2: 
					printf("\n\t***Students Data***\n\n");
					DisplaySinglyLinkedList(Start);
			break;
			
			case 3: 
			        
					printf("\n\t**********Search Node**********\n\n");
					printf("Enter the RollNo: ");
					scanf(" %d",&roll_no);
					
			    	SearchNode(Start,roll_no);
				
			break;
			
			case 4:
					printf("\n\n Exiting the linked list ....\n");
					Start = NULL;
					free(Start);
					exit(0);
			break;
			
		}
	     	
	}while(Choice!=4);
		
	return 0;
}