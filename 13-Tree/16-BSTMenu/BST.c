#include "BST.h"

BST * NodeCreation(BST * NewNode){
   
    NewNode = (BST*)malloc(sizeof(BST));

    if(!NewNode)
    {
        if(!NewNode){
        printf("\n!!! Memory allocation is failed !!!\n");
        return NULL;
        }
    }

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
		newNode = NodeCreation(newNode);

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

		return Root;
	
}

BST * InsertNode(BST * Root){
	BST * iter = Root;
	BST * newNode = NULL;

	newNode = NodeCreation(newNode);

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

int CountNodes(BST * Root)
{
	int cnt = 0;
    if(Root!=NULL){
        cnt++;
       cnt +=  CountNodes(Root->left);
       cnt +=  CountNodes(Root->right);
    }

	return cnt;
}

int MaxHeight(BST * Root)
{
    if(!Root) return 0;

	int LH = MaxHeight(Root->left);
	int RH = MaxHeight(Root->right);

	return ((LH > RH)? LH:RH)+1;
}


void InOrderDisplay(BST * Root)
{
    if(Root!=NULL){
        InOrderDisplay(Root->left);
        printf("%p\t%d[%p]\t%p\n",Root->left,Root->data,Root,Root->right);
        InOrderDisplay(Root->right);
    }
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

void PostOrderDisplay(BST * Root)
{
    if(Root!=NULL)
    {
        PostOrderDisplay(Root->left);
        PostOrderDisplay(Root->right);
        printf("%p\t%d[%p]\t%p\n",Root->left,Root->data,Root,Root->right);
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
