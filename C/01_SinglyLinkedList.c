
//Cipher_Coding_Academy Singly Linked list

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SinglyLinkedList{
	
	int no;
	char name[20];
	struct SinglyLinkedList * next;	
}SLL;


SLL * InsertAtFirst(SLL * last){
	
	
	SLL * Head = NULL;
		
	Head = (SLL *)malloc(sizeof(SLL));
	Head->next = NULL;
	
	
	printf("\nEnter the Roll No: ");
	scanf("%d",&Head->no);
	
	printf("\nEnter the Name:");
	scanf(" %[^\n]s",Head->name);
	
		
	if(last == NULL)
	{
		last = Head; 
	}
   	else{
		
		Head->next = last;
		last = Head;
		
	}
	  
	
	return last;
}

SLL * InsertAtEnd(SLL * last){
	
	    SLL * Head = NULL;
		SLL * iter = last;
		
	   Head = (SLL *)malloc(sizeof(SLL));
	    Head->next = NULL;
	
	
	    printf("\nEnter the data\n");
	    scanf("%d",&Head->no);
		
		printf("\nEnter the Name: ");
	    scanf(" %[^\n]s",Head->name);
	
	
	if(last == NULL)
	{
		last = Head; 
	}
   	else{
		for(;iter->next!=NULL;iter = iter->next);
		
		iter->next = Head;
			
		
	}
	  
	  return last;
}

SLL * InsertInPosition(SLL * last, int pos){
	
		SLL * Head = NULL;
		SLL * iter = last;
		int ipos;
	
	Head = (SLL *)malloc(sizeof(SLL));
	Head->next = NULL;
	
	
		for(ipos = 1;(ipos < pos-1)&&(iter!=NULL);iter = iter->next,ipos++);
		if((ipos<pos)&&(iter==NULL))
		{
		
			printf("\n!!!The position is out of linked list!!!\n");
			return last;
	
		}
		else
		{
			printf("\nEnter the data\n");
           scanf("%d",&Head->no);
		   
		   printf("\nEnter the Name: ");
        	scanf(" %[^\n]s",Head->name);
	
		if((pos==1)&&(last->next!=NULL))
		{
			Head->next = last;
	    	last = Head;
		
		}
		else if((pos == 1)&&(last == NULL))
		{
			last = Head;
			return last;
		}
		else if(iter->next == NULL)
		{
			iter->next = Head;
		}
		else{
				
				Head->next = iter->next;
				iter->next = Head;
			}			
		}
		return last;
	
}


SLL * DeleteAtFirst(SLL * last){
	
		SLL * Head = NULL;
    
		Head = last;
		last = last->next;
		free(Head);
		
			return last;

}

SLL * DeleteAtEnd(SLL * last){
	
		
		SLL * iter = last;
		SLL * temp = NULL;
        if(last->next == NULL)
		{
			free(last);
			return NULL;
		}
		else
		{
	
  
		for(;iter->next->next!=NULL;iter = iter->next);	
		temp = iter->next; 
		
		free(temp);
		iter->next = NULL;
		
		
			return last;		
		}
		
}

SLL * DeleteInPosition(SLL * last, int pos){
	
		
		SLL * iter = last;
	    SLL * temp = NULL;
	    int ipos;
	      	
		for( ipos = 1;(ipos < pos-1)&&(iter->next!=NULL);iter = iter->next,ipos++);
		
		
	    if((ipos<pos)&&(iter->next==NULL))
		{
			printf("\nCouldn't find the node at this position\n");
			return last;
		}
		else if((pos==1)&&(last->next!=NULL))
		{
			temp = last;
			last = last->next;
			free(temp);
		
			return last;
		}
        else if((pos==1)&&(last->next==NULL))	
		{
			free(last);
			return NULL;
	    }
		
        else		
 		{
			temp = iter -> next;
			iter->next = iter->next->next;
			free(temp);
	    }	
	return last;
	
}


SLL * SwapNode(SLL* last){
	
	int temp=0;
	char tempName[20];
	SLL *p = last;
	
	for(;p!=NULL;p=p->next->next){
		if(p->next!=NULL){
		temp = p->no;
		p->no = p->next->no;
		p->next->no = temp;
		
		strcpy(tempName,p->name);
		strcpy(p->name,p->next->name);
		strcpy(p->next->name,tempName);

		
		}
	}
	return last;
	
}


SLL * AddConsecutiveNode(SLL * last){
	
	SLL * p = last;
	SLL *temp=NULL;
		
	
	for(;p->next!=NULL;){
		
		
		   temp = (SLL*)malloc(sizeof(SLL));
		   temp->next = NULL;
		   temp->next = p->next->next;
		   p->next->next = temp;
		   temp->no = p->no+p->next->no;
		   		   
		   strcpy(temp->name,p->name);
		   strcat(temp->name,p->next->name);
	   
	     
		   if(temp->next==NULL)
		   {
			   break;
		   }
		  else
		  {			  
		   p = temp->next;
		  }
		
	}
	
	return last;
}

void PrintMiddleNode(SLL * last){
	
	SLL*p = last;
	
	
	while(p!=NULL&&p->next!=NULL){
		p=p->next->next;
		last=last->next;
			
	}
	printf("\n Middle Node:  | %d : %s |\n",last->no,last->name);

}

void DisplaySinglyLinkedList(SLL * last)
{
	if(last == NULL)
	{
		printf("\n!!!The List is Empty!!!\n");
	}
	else
	{	
		for(;last!=NULL;last=last->next)
		{
			printf("| %d : %s |->",last->no,last->name);
		}	   
	}
}


int main()
{
	
	int ch;
	 int position,ans = 0;
	 int n;
	SLL * Start = NULL;
	
	do{
		printf("\n*************Singly Linked List Menu***********\n");
		printf("+------------------------------------------------------------------------------------------+\n");
		printf("|  Press 1 to Insert the data in the Linked list                                           |\n");
		printf("|  Press 2 to Insert data in the Linked list at the end                                    |\n");
		printf("|  Press 3 to Insert the data in position inside the linked list                           |\n");
	    printf("|  Press 4 to delete the data from the first node                                          |\n");
		printf("|  Press 5 to delete the data from the end of the Linked list                              |\n");
		printf("|  Press 6 to delete the data from the position inside the linked list                     |\n");		
		printf("|  Press 7 to swap nodes                                                                   |\n");
		printf("|  Press 8 to Add Consecutive Node                                                         |\n");
		printf("|  Press 9 to display the Middle Node                                                      |\n");	
		printf("|  Press 10 to display the Singly Linked List                                              |\n");
		printf("+------------------------------------------------------------------------------------------+\n");
 
        printf("+-------------------------------------+\n");
		printf("   Enter your choice: ");
		scanf("%d", &ch);
		printf("+-------------------------------------+\n");		
	    switch(ch){
			
			case 1:
				Start = InsertAtFirst(Start);
				break;
            case 2: 
                Start = InsertAtEnd(Start);
				break;
            case 3: 
			   
			
					printf("\nEnter the Position:  ");
					scanf("%d",&position);
					if(position <= 0)
				{
						printf("\n!!!Invalid Positio please enter the position again!!!\n");
				}
				else
					Start = InsertInPosition(Start,position);
					break;
			case 4: 
				
				if(Start == NULL){
					printf("\n!!!The List is Empty!!!\n");
				}
				else
				{
					Start = DeleteAtFirst(Start);
					if(Start == NULL)
					{
						printf("\n!!!The List is Empty !!!\n");
					}
				}
				break;
			case 5: 
			    if(Start == NULL){
					printf("\n!!!The List is Empty!!!\n");
				}
				else
				{
					Start = DeleteAtEnd(Start);
					 if(Start == NULL){
					     printf("\n!!!The List is Empty!!!\n");
				      }
				}
			    break;					
			case 6: 
				if(Start == NULL)
				{
					printf("\n!!!The List is Empty!!!\n");
				}
				else
				{
					int position;
					printf("\nEnter the Position:  ");
					 scanf("%d",&position);
					if(position <= 0)
					{
						printf("\n!!!Invalid Position please enter the position again!!!\n");
					}
					else
					{
					 
					 Start = DeleteInPosition(Start,position);
					 if(Start == NULL)
					{
						printf("\n!!!The List is Empty !!!\n");
					}
					}
				}
				break;
				
			case 7: 
				Start = SwapNode(Start);
				break;
				
			case 8: 
				Start = AddConsecutiveNode(Start);
				break;
				
			case 9:
				PrintMiddleNode(Start);
			    break;
				
			case 10:
				DisplaySinglyLinkedList(Start);
			    break;
		} 
		printf("+------------------------------------------------+\n");
		do{
		printf("\nDo you want to update linked list ? 0/1\n");
		scanf("%d",&n);
		if(n>1||n<0){
			printf("!!!Invalid choice!!!\n");
			printf("+------------------------------------------------+\n");
			continue;
		}
		else 
		{
			ans = n;
			break;
		}
		}while(1);
		
		printf("+------------------------------------------------+\n");
				
	}while(ans!=0);
	
	
	
	return 0;
}