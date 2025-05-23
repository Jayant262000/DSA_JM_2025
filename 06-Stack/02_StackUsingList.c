//write a c program to create a stack and perform push and pop operation (Using Linked List)


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack{
	
	int rollNo;
	int top;
	struct Stack * next;	
}STK;


//Functions
STK * Push(STK * ,STK**,int  );
STK * Pop(STK *,STK** );
void DisplayStack(STK * );

//Insert Node at last
STK * Push(STK * Head, STK ** last,int size){
	
	STK * Node = NULL;

	if(Head == NULL)
	{
	
	
		Node = (STK *)malloc(sizeof(STK));
		Node->next = NULL;
	
	
		printf("Enter the RollNo: ");
		scanf(" %d",&Node->rollNo);
		
		Node->top = 1;
		Head = Node; 
		
	}
	else
	{	
		if((*last)->top >= size)
		{
			printf("\n!!! Stack is full can not push a node !!!\n");
			return Head;
		}	
		
		
	
		Node = (STK *)malloc(sizeof(STK));
		Node->next = NULL;
	
	
		printf("Enter the RollNo: ");
		scanf(" %d",&Node->rollNo);
			
		Node->top = (*last)->top + 1;
		(*last)->next = Node;	
	}
		*last = Node;	
		
	printf("\nNode Pushed Successfully \n");	
	return Head;
}


STK * Pop(STK * Head,STK ** last){
	    
	if(Head==NULL)
	{
		printf("\n!!! Stack is empty can not pop a node !!!\n");
		return NULL;
	}		
	STK * iter = Head;
	STK * temp = NULL;
    if(Head->next == NULL)
	{
		printf("\nNode Poped Successfully \n");	
		free(Head);
		return NULL;
	}
	else
	{
		for(;iter->next->next!=NULL;iter = iter->next);	
		temp = iter->next;
		iter->top = (*last)->top-1;
		(*last) = iter;
		iter->next = NULL;

		temp = NULL;
		free(temp);
			
		iter = NULL;
		free(iter);
		
		printf("\nNode Poped Successfully \n");		
			
		return Head;		
	}
}

//Display List
void DisplayStack(STK * Head)
{
	if(Head == NULL)
	{
		printf("\n!!!The Stack is Empty!!!\n");
	}
	else
	{		
		for(;Head!=NULL;Head=Head->next)
		{
			printf(" Roll no : %d \n top: %d \n--------------------------------------------------------------------------------------------\n"
			,Head->rollNo,Head->top);
		}	   
	}
}

void freeStack(STK * Head)
{
	STK * iter = Head;
	while(Head!=NULL)
	{
		iter = Head;
		Head = iter->next;
		free(iter);
		iter = NULL;
	}
}

int main()
{
    //code
	int Choice;
	STK * Start = NULL;
	STK * last = NULL;
	int size;
	
	
	printf("\n********** Stack using Linked List **********\n");
		printf("\n\nEnter the size of stack: ");
		scanf("%d",&size);
		getchar();
	
	do{
		printf("\nEnter 1: to Push a value to stack\n");
    	printf("Enter 2: to Pop a value from stack\n");	
		printf("Enter 3: to get a top value\n");	
		printf("Enter 4: to get size of stack\n");	
		printf("Enter 5: to Display stack\n");
		printf("Enter 6: to Exit the Linked List\n");
	
			printf("\nChoice: ");			
			scanf("%d",&Choice);
			getchar();

		switch(Choice){
			
			case 1:	
					Start = Push(Start,&last,size);
			break;
		
			case 2: 
					Start = Pop(Start,&last);
			break;
			
			case 3: 
					if(Start==NULL)
					{
						printf("\n!!! Stack is empty can not pop a node !!!\n");
					}
					else
					{
						printf("\nTop Value\nRollNo: %d\n",last->rollNo);
					}
			break;
			
			case 4: 
					if(Start == NULL)
					{
						printf("\n!!!The Stack is empty!!!\n");
						printf("\nSize of stack is: 0\n");
					}
					else
						printf("\nSize of stack is: %d\n",last->top);
			break;
			
			case 5: 
			
					DisplayStack(Start);
			break;
			
			case 6:
			        printf("\n\n Exiting the program ....\n");
					freeStack(Start);
					Start = NULL;
					exit(0);
			break;
			
			default: 
					printf("!!! Invalid Choice  !!!");
			continue;
			
		}			
	}while(Choice!=6);
	return 0;
}