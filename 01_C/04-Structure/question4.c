/* 

   Create a structure "Item" which includes below member variables:
   - itemName, quantity, price, amount.
   calculate the amount by accessing the member variable with the help of structure pointer.

*/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Item{
	
	char itemName[20];
	int quantity;
	double price;
	double amount;

}I;

I * CreateNode(I * Node){
   	
	    Node = (I *)malloc(sizeof(I));
	
	
	    printf("\n\t**********Enter Item details**********\n");
		
		printf("Enter the Name of Item: ");
		scanf(" %[^\n]s",Node->itemName);
		
		printf("Enter quantity: ");
		scanf(" %d",&Node->quantity);
		
		printf("Enter price per item: ");
		scanf(" %lf",&Node->price);
	
		
	  return Node;
}


void DisplayNode(I * Node)
{
	if(Node == NULL)
	{
		printf("\n!!!Node is does not exist!!!\n");
	}
	else
	{		
		Node->amount = Node->quantity * Node->price;
		printf(" Item : %s\n Quantity: %d\n price per item: %lf\n Total Amount: %f\n------------------------------------------------------------------------------------------------------------------------\n"
		,Node->itemName,Node->quantity,Node->price,Node->amount);
	   
	}
}

int main()
{
    //code
	char ch; 
	int Choice;
	I * Start = NULL;
	
	
	do{
		printf("\n********** Node Creation **********\n");
		printf("\nEnter 1 Create Node\n");
    	printf("Enter 2 to Display Node\n");	
        printf("Enter 3 to exit\n");
		
			
		printf("\nChoice: ");			
		scanf("%d",&Choice);
		
		
		
		switch (Choice){
			
			case 1:	
					Start = CreateNode(Start);
			break;
		
			case 2: 
					printf("\n\t********* Item Data *********\n");
					DisplayNode(Start);
			break;
			
			case 3: 
					printf("\n\n Exiting the linked list ....\n");
					Start = NULL;
					free(Start);
					exit(0);
			break;
			
		}
				
	}while(Choice!=3);
		
	return 0;
}