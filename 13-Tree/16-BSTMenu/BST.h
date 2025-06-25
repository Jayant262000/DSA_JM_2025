#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct BinarySearchTree{
    int data;
    struct BinarySearchTree *left;
    struct BinarySearchTree *right;
}BST;

BST * NodeCreation(BST * );
BST * BSTCreation(BST * );
BST * InsertNode(BST * );
void SearchNode(BST * ,int );
int CountNodes(BST * );
int MaxHeight(BST * );
void InOrderDisplay(BST * );
void PreOrderDisplay(BST * );
void PostOrderDisplay(BST * );
void FreeBST(BST * );
