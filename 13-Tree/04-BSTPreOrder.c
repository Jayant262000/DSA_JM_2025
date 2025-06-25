/*
    Wrtie a C program to create BST and Display the elements in the BST in PreOrder
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct BinarySearchTree{
    int data;
    struct BinarySearchTree * left;
    struct BinarySearchTree * right;
}BST;

BST *  MemoryAllocation(BST * NewNode){
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
                    if(iter->left==NULL)
                    {
                        iter->left = newNode;
                        break;
                    }
                    iter = iter->left;
                }
                else if(newNode->data > iter->data)
                {
                    if(iter->right==NULL)
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

        printf("\nDo you want to enter new data?0/1: ");
        scanf("%d",&choice);
    }while(choice!=0);

    return Root;
}

void PreOrderDisplay(BST * Root)
{
    if(Root!=NULL)
    {
       printf("%p\t%d[%p]\t%p\n",Root->left,Root->data,Root,Root->right);
       PreOrderDisplay(Root->left);
       PreOrderDisplay(Root->right);
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

    printf("\n*****Tree PreOrder Display*****\n");
	printf("\nleft\t\tdata[Base]\tright\n");
    PreOrderDisplay(Root);
	
	printf("\n\nFreeing the BST........\n");
	FreeBST(Root);

    return 0;
}