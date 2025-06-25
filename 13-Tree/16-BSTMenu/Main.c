#include "BST.h"


int main()
{
    BST * Root = NULL;
	int choice = 0;
    int key = 0;

	do{
		printf("\n---------- Binary Search Tree Menu ----------\n");
		printf("1. Create BST\n");
		printf("2. Insert Node in BST\n");
		printf("3. Search the Node\n");
		printf("4. Total Nodes in BST\n");
		printf("5. Height of the BST\n");
		printf("6. InOrder Display\n");
		printf("7. PreOrder Display\n");
		printf("8. PostOrder Display\n");
		printf("9. Exit\n");

		printf("\nEnter the Choice: ");
		scanf("%d",&choice);
        getchar();

		switch(choice)
		{
			case 1:
				printf("\nBinary Search Tree Creation.....\n");
    			Root = BSTCreation(Root);
			break;

			case 2: 
				Root = InsertNode(Root);
			break;
			
			case 3: 
				printf("\nEnter the Key to Search: \n");
    			scanf("%d",&key);

  				SearchNode(Root,key);
			break;

			case 4:
				printf("\nTotal Number of Nodes are: %d\n",CountNodes(Root));
			break;
			
			case 5:
				printf("\nHeight of Tree: %d\n", MaxHeight(Root));
			break;
			
			case 6:
				printf("\n*****Tree InOrder Display*****\n");
				printf("\nleft\t\tdata[Base]\tright\n");
    			InOrderDisplay(Root);
			break;
			
			case 7:
				printf("\n*****Tree PreOrder Display*****\n");
				printf("\nleft\t\tdata[Base]\tright\n");
    			PreOrderDisplay(Root);
			break;
			
			case 8: 
				printf("\n*****Tree PostOrder Display*****\n");
				printf("\nleft\t\tdata[Base]\tright\n");
			    PostOrderDisplay(Root);
			break;

			case 9:
				printf("\n\nFreeing the BST........\n");
				FreeBST(Root);	
				exit(0);
			break;	
			
			default:
				printf("\n !!! Invalid Choice !!!\n");
			break;	
			
		}

	}while(choice!=9);

    return 0;
}