/*
    Wrtie a C program to create BST and insert an element in the BST using recursion(Call insert function from create function)
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct BinarySearchTree{
    int data;
    struct BinarySearchTree * left;
    struct BinarySearchTree * right;
}BST;


BST * CreateBST(int data)
{
    BST * NewNode = (BST*)malloc(sizeof(BST));

    if(!NewNode){
        printf("\n!!! Memory allocation is failed !!!\n");
        return NULL;
    }

    NewNode->left = NULL;
    NewNode->right = NULL;
    NewNode->data = data;

    return NewNode;
}


BST * InsertNode(BST * Root, int data)
{
    
    if(!Root) 
    {
         Root = CreateBST(data); 
    }
    else if(data < Root->data)
    {
        Root->left = InsertNode(Root->left,data);
    }
    else if(data > Root->data)
    {
        Root->right = InsertNode(Root->right,data);
    }

    return Root;

}

void InOrderDisplay(BST * Root)
{
    if(Root!=NULL)
    {
        InOrderDisplay(Root->left);
        printf("%p\t%d[%p]\t%p\n",Root->left,Root->data,Root,Root->right);
        InOrderDisplay(Root->right);
    }
}

void FreeBST(BST * Root)
{
    if(Root != NULL)
    {
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
    int no = 0;
    int data = 0;

    printf("\nEnter the number of nodes you want to insert in BST: ");
    scanf("%d",&no);

    for(int i = 0;i<no;i++){
        printf("\nData: ");
        scanf("%d",&data);
		
		Root = InsertNode(Root,data);
	
    }

    printf("\n*****Tree InOrder Display*****\n");
	printf("\nleft\t\tdata[Base]\tright\n");
    InOrderDisplay(Root);

    printf("\nFreeing the BST........\n");
    FreeBST(Root);

    return 0;
}