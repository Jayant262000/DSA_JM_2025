/*

   write a  C program to pass an array of structures to a user define function
   - create a structure which accepts student details.
   - create an array of structure for "N" number of students.
   - Pass  array  of structure to a function as an argument and search for the perticular student details.
   
   
*/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct StudentDetails{
	
	int rollNo;
	char name[20];
	
}STD;

STD * CreateNode(STD * Node,int size){
   	

	

	    Node = (STD *)malloc(size*sizeof(STD));
	
	    printf("\n\t**********Enter Students details**********\n");
	
	for(int i=0;i<size;i++)
	{
		printf(" RollNo: ");
		scanf(" %d",&Node[i].rollNo);
	
		printf("Name: ");
		scanf(" %[^\n]s",Node[i].name);
	}
	  return Node;
}


void DisplayNode(STD* Node, int size) {
    for (int i = 0; i < size; i++) {
        printf("Roll No : %d\nName    : %s\n", Node[i].rollNo, Node[i].name);
        printf("------------------------------------------------------------\n");
    }
}

void SearchStudent(STD * Node,int size,int No)
{
	int flag=1;
	for (int i = 0; i < size; i++) {
		
		if(No==Node[i].rollNo)
		{
			printf("------------------------------------------------------------\n");
			printf("Roll No : %d\nName    : %s\n", Node[i].rollNo, Node[i].name);
			flag=1;
		}
		else{
			flag=0;
		}
    }
	
	if(flag==0)
	{
		printf("\n!!! Student is not present!!!!\n");
	}
	
}


void FreeMemory(STD* Node) {
    free(Node);
}
int main()
{
    //code
	char ch; 
	int Choice;
	STD * Start = NULL;
	int size,no;
	
	do{
		printf("\n********** Node Creation **********\n");
		printf("\nEnter 1 Create Node\n");
    	printf("Enter 2 to Display Node\n");
		printf("Enter 3 to Search the student\n");
        printf("Enter 4 to exit\n");
		
			
		printf("\nChoice: ");			
		scanf("%d",&Choice);
		
		
		
		switch (Choice){
			
			case 1:	
					printf("\nEnter the size : ");
					scanf("%d",&size);
					Start = CreateNode(Start,size);
			break;
		
			case 2: 
					printf("\n\t********* Students Data *********\n");
					DisplayNode(Start,size);
			break;
			
			case 3: 
					if(Start==NULL)
					{
						printf("\n\t!!! No Data !!!\n");
					}
					else
					{
						printf("\nEnter the Roll No of Student: ");
						scanf("%d",&no);
						SearchStudent(Start,size,no);
					}
			break;
			
			case 4: 
					printf("\n\n Exiting the linked list ....\n");
					FreeMemory(Start);
					Start = NULL;
					exit(0);
			break;
			
		}
				
	}while(Choice!=4);
		
	return 0;
}