/* 

Use Stacks to check a program for balanced symbols (such as {}, (), []). The closing symbol should be matched with the most recently seen
opening symbol.)
Example: {()} is legal, {() ({})} is legal, but {((} and {(}) are not legal

*/

#include<stdio.h>
#include<stdlib.h>


char * AllocateStack(char *stk,int *size){
	
	printf("Enter the size of Stack: ");
	scanf("%d",size);
	
	stk = (char*)malloc(*size*(sizeof(char)));
	
	return stk;
}

char * Push(char * stk,int *size,int *top)
{
	do
	{
		*top=*top+1;
		if(*(top)>=*size)
		{
			*top=*top-1;
			printf("\n!!!The Stack is full can not push any value!!!\n");
			break;
		}
		else
		{
			printf("\nEnter the value: ");
			scanf(" %c",&stk[*top]);
			getchar();
			
			printf("\n-->The Value %c is pushed successfully\n",stk[*top]);
		}
	}while(*top<*size);
	return stk;
}

void VerifyBalancedStk(char * stk,int *size,int *top)
{
	int flag1=0;
	int flag2=0;
	int flag3=0;
	int Gflag = 0;
	char preVal;

	do{
		
		if(*top==(*size-1)&&(stk[*top]=='('||stk[*top]=='{'||stk[*top]=='['))
		{
			flag1=1;	
			break;
		}
			
			
			switch(stk[*top])
			{
			
				case ')':
						flag1++;
						preVal = stk[*top];
				break;	
				
				case ']':
						flag2++;
						preVal = stk[*top];
				break;
				
				case '}':
						flag3++;
						preVal = stk[*top];
				break;
					
				case '(':
						if((preVal!=')'&&preVal!='['&&preVal!='{')||flag1<1)
						{
							Gflag = 1;
							break;
						}
						else
						{
							preVal = stk[*top];
							flag1--;
						}
				break;
			
				
				case '[':
						if((preVal!='('&&preVal!=']'&&preVal!='{')||flag2<1)
						{
							Gflag = 1;
							break;
						}
						else
						{
							preVal = stk[*top];
							flag2--;
						}
				break;
				
				case '{':
						if((preVal!='('&&preVal!='['&&preVal!='}')||flag3<1)
						{
							Gflag = 1;
							break;
						}
						else
						{
							preVal = stk[*top];
							flag3--;
						}
				break;
				
				default: 
					printf("\n!!! Invalid character !!!\n");
					flag1=1;
				break;
				
			}
			if(Gflag==1)
			{
				flag1=1;
				break;
			}
			
				*top=*top-1;
		
	}while(*top>-1);
	
	
	if(flag1==0&&flag2==0&&flag3==0)
	{
		printf("\n*** The Stack is Balanced ***\n");
	}
	else
	{
		printf("\n*** The Stack is Imbalanced ***\n");
	}
}



void DisplayStack(char * stk,int top){
	
	printf("\n***** Stack *****\n");
	for(int i = 0;i<=top;++i){
		printf("%c ",stk[i]);	
	}
}


int main()
{
	
	char * stack = NULL;
	int Choice;
	int size;
	int top = -1;
	
	do{
		printf("\n\n********** Stack **********\n");
		printf("\nEnter 1: to Push a value to stack\n");
    	printf("Enter 2: verify if the stack is balanced or not\n");		
		printf("Enter 3: to Exit the Linked List\n");
	
			printf("\nChoice: ");			
			scanf("%d",&Choice);
			getchar();

		switch (Choice){
			
			case 1:	
					free(stack);
					stack = NULL;
					top = -1;
						
					stack = AllocateStack(stack,&size);
		
					stack = Push(stack,&size,&top);
					DisplayStack(stack,top);
			break;
		
			case 2: 
					if(top == -1)
					{
						printf("\n!!!The Stack is empty!!!\n");
					}
					else if(size%2!=0)
					{
						printf("\n*** The Stack is Imbalanced ***\n");
					}
					else
					{
						VerifyBalancedStk(stack,&size,&top);
					}
			break;
			
			case 3:
			        printf("\n\n Exiting the program ....\n");
					free(stack);
					stack = NULL;
					exit(0);
			break;
			
			default: 
					printf("!!! Invalid Choice  !!!");
			continue;
			
		}			
	}while(Choice!=3);
	return 0;
}