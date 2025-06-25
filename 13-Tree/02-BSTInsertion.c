/*
	Wrtie a C program to create BST and insert an element in the BST

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct BinarySearchTree{
	int data;
	struct BinarySearchTree * left;
	struct BinarySearchTree * right;
}BST;

BST * MemoryAllocation(BST * );
BST * CreateBST(BST * );
BST * InsertNode(BST * );
void InOrderDisplay(BST * );




BST * MemoryAllocation(BST * NewNode){
	
	NewNode = (BST*)malloc(sizeof(BST));
	NewNode->left = NULL;
	NewNode->right = NULL;

	printf("\nData: ");
	scanf(" %d",&NewNode->data);
    getchar();

	return NewNode;
}

BST * BSTCreation(BST * Root)
{
	BST * newNode = NULL;
	BST * iter = NULL;
	int choice = 0;

	do{
		newNode = MemoryAllocation(newNode);

		if(Root == NULL)
		{
			Root = newNode;
		}
		else
		{
			iter = Root;
			while(1)
			{
				if(newNode->data < iter->data)
				{
					if(iter->left == NULL)
					{
						iter->left = newNode;
                        break;
					}
					iter = iter->left; 
				}
				else if(newNode->data > iter->data)
				{
					if(iter->right == NULL)
					{
						iter->right = newNode;
                           break;
					}
					iter = iter->right; 
				}
				else if(iter->data == newNode->data)
				{
					printf("\n!!! The Node is already exists !!!\n");
					break;
				}
			}
		}

		printf("\nDo you want to enter New Node?0/1: ");
		scanf("%d",&choice);
	}while(choice!=0);

	printf("\n***BST Creation is successfull***\n\nDo you want to insert the data?0/1: ");
	scanf("%d",&choice);
	if(choice==1)
	{
		Root = InsertNode(Root);
	}

		return Root;
	
}

BST * InsertNode(BST * Root){
	BST * iter = Root;
	BST * newNode = NULL;

	newNode = MemoryAllocation(newNode);

	while(1){
		if(Root->data > newNode->data){
			if(iter->left==NULL){
				iter->left = newNode;
				break;
			}
			iter = iter->left;
		}
		else if(Root->data < newNode->data){
			if(iter->right == NULL){
				iter->right = newNode;
				break;
			}
			iter = iter->right;
		}
	}

	return Root;

}

void InOrderDisplay(BST * Root)
{
    if(Root!=NULL){
        InOrderDisplay(Root->left);
        printf("%p\t%d[%p]\t%p\n",Root->left,Root->data,Root,Root->right);
        InOrderDisplay(Root->right);
    }
}

void FreeBST(BST * Root)
{
    if(Root!=NULL){
        FreeBST(Root->left);
        FreeBST(Root->right);
        printf("\nThe Node with data %d at %p is freed from the memory\n",Root->data,Root);
        free(Root);
        Root = NULL;
    }
}

int main()
{
     BST * Root = NULL;

    printf("\nBinary Search Tree Creation.....\n");
    Root = BSTCreation(Root);

    printf("\n*****Tree InOrder Display*****\n");
	printf("\nleft\t\tdata[Base]\tright\n");
    InOrderDisplay(Root);
	
	printf("\n\nFreeing the BST........\n");
	FreeBST(Root);

    return 0;
}