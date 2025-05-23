//write a c program to create a stack and perform push and pop operation (Using Array)

#include<stdio.h>
#include<stdlib.h>


int * AllocateStack(int *stk,int *size){
	
	printf("Enter the size of Stack: ");
	scanf("%d",size);
	
	stk = (int*)malloc(*size*(sizeof(int)));
	
	return stk;
}

int * Push(int * stk,int *size,int *top)
{
	*top=*top+1;
	if(*(top)>=*size)
	{
		*top=*top-1;
		printf("\n!!!The Stack is full can not push any value!!!\n");
	}
	else
	{
		printf("Enter the value: ");
		scanf("%d",&stk[*top]);
		printf("\nThe Value %d is pushed successfully\n",stk[*top]);
	}
	return stk;
}

int * Pop(int * stk,int *size,int *top)
{
	if(*(top)<=-1)
	{
		printf("\n!!!The Stack is empty can not pop any value!!!\n");
	}
	else
	{
		*top=*top-1;
		printf("\nThe Value %d is poped successfully\n",stk[(*top)+1]);
	}
	return stk;
}



void DisplayStack(int * stk,int top){
	
	printf("\n***** Stack *****\n");
	for(int i = 0;i<=top;++i){
		printf("stack[%d]: %d\n",i,stk[i]);	
	}
}


int main()
{
	
	int * stack = NULL;
	int Choice;
	int size;
	int top = -1;
	
	do{
		printf("\n********** Stack using array **********\n");
		printf("\nEnter 1: to Push a value to stack\n");
    	printf("Enter 2: to Pop a value from stack\n");	
		printf("Enter 3: to get a top value\n");	
		printf("Enter 4: to get size of stack\n");	
		printf("Enter 5: to Display stack\n");
		printf("Enter 6: to Exit the Linked List\n");
	
			printf("\nChoice: ");			
			scanf("%d",&Choice);
			getchar();

		switch (Choice){
			
			case 1:	
					if(stack == NULL)
						stack = AllocateStack(stack,&size);
					
					stack = Push(stack,&size,&top);
			break;
		
			case 2: 
					if(stack == NULL||top==-1)
						printf("\n!!!The Stack is empty!!!\n");
					else
						stack = Pop(stack,&size,&top);
			break;
			
			case 3: 
					if(stack == NULL||top==-1)
						printf("\n!!!The Stack is empty!!!\n");
					else
						printf("\nTop Value: %d",stack[top]);
					
			break;
			
			case 4: 
					if(stack == NULL||top==-1)
					{
						printf("\n!!!The Stack is empty!!!\n");
						printf("\nSize of stack is: 0\n");
					}
					else
						printf("\nSize of stack is: %d\n",top+1);
			break;
			
			case 5: 
					if(stack == NULL||top==-1)
						printf("\n!!!The Stack is empty!!!\n");
					else
						DisplayStack(stack,top);
			break;
			
			case 6:
			        printf("\n\n Exiting the program ....\n");
					free(stack);
					stack = NULL;
					exit(0);
			break;
			
			default: 
					printf("!!! Invalid Choice  !!!");
			continue;
			
		}			
	}while(Choice!=6);
	return 0;
}
