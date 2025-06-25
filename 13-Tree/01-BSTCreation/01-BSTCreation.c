/* 
    Write a program to create  a BST (eg: PreOrder: 25,15,30,10,12,6,45,29,50).
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct BinarySearchTree{
    int data;
    struct BinarySearchTree *left;
    struct BinarySearchTree *right;
}BST;

BST * MemoryAllocation(BST * NewNode){
   
    NewNode = (BST*)malloc(sizeof(BST));
    NewNode->left = NULL;
    NewNode->right = NULL;

    printf("\nData: ");
    scanf(" %d",&NewNode->data);
	getchar();

    return NewNode;
}

BST * CreateBST(BST * Root){

    BST * newNode = NULL;
    BST * iter = Root;
    int choice = 0;

    do{
        newNode = MemoryAllocation(newNode);

        if(Root==NULL)
        {
            Root = newNode;
        }
        else 
        {
			iter = Root;
            while(1){
                
                if(iter->data>newNode->data){
                    if(iter->left==NULL)
                    {
                        iter->left = newNode;
                        break;
                    }
                    iter = iter->left;
                }
                else if(iter->data<newNode->data)
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
        printf("\nDo you want to enter new node? 0/1: ");
        scanf(" %d",&choice);
		getchar();

    }while(choice!=0);

    return Root;

}

void DisplayTree(BST * Root)
{
    
    if(Root!=NULL)
    {
        DisplayTree(Root->left);
        printf("%p\t%d\t%p\n",Root->left,Root->data,Root->right);
        DisplayTree(Root->right);
        
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
    Root = CreateBST(Root);

    printf("\n*****Tree*****\n");
	printf("\nleft\t\tdata\tright\n");
    DisplayTree(Root);
	
	
	printf("\n\nFreeing the BST........\n");
	FreeBST(Root);
   
   return 0;

}	