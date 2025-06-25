/*
    Wrtie a C program to create BST and Search an element in BST using iterative aproach 

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct BinarySearchTree{
    int data;
    struct BinarySearchTree * left;
    struct BinarySearchTree * right;
}BST;

BST * MemoryAllocation(BST * NewNode)
{
    NewNode = (BST*)malloc(sizeof(BST));
    NewNode->left = NULL;
    NewNode->right = NULL;
    
    printf("\nData: ");
    scanf("%d",&NewNode->data);

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

        printf("\nDo you want to enter more data?0/1: ");
        scanf("%d",&choice);

    }while(choice!=0);
    
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

void SearchNode(BST * Root,int key)
{

    int flag = 0;
    while(Root!=NULL)
    {
        if(Root->data == key)
        {
            flag = 1;
            break;
        }
        else if(Root->data > key)
        {
            Root = Root->left;
        }
        else if(Root->data < key)
        {
            Root = Root->right;
        }
    }

    if(flag == 1)
    {
        printf("\n ***** Node with Key %d is found in the BST at %p *** ",key,(void*)Root);
    }
    else
    {
        printf("\n !!! Node with Key %d is not found in the BST !!! ",key);
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

int main(){

    BST * Root = NULL;
    int key = 0;

    printf("\nBinary Search Tree Creation.....\n");
    Root = BSTCreation(Root);

    printf("\n*****Tree InOrder Display*****\n");
	printf("\nleft\t\tdata[Base]\tright\n");
    InOrderDisplay(Root);

    printf("\nEnter the Key to Search: \n");
    scanf("%d",&key);

    SearchNode(Root,key);
	
	printf("\n\nFreeing the BST........\n");
	FreeBST(Root);

    return 0;
}