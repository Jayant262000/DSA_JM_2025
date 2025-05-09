/* 

    Create a structure "Students" with below member variables:
	- Name of student,
    - Roll no. Of Student,
    - array of 5 Subject marks,
	- Total Percentage 
    
- Calculate the Percentage for "N" number of students,
- Display all details for all students,
- Display the details of topper.
(use array of structure)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct StudentDetails{
	
	int rollNo;
	char name[20];
	int marks[5];
	double percentage;
	
}STD;

STD * CreateNode(STD * Node,int size){
   	
		int total = 0;
	

	    Node = (STD *)malloc(size*sizeof(STD));
	
	    printf("\n\t**********Enter Students details**********\n");
	
	for(int i=0;i<size;i++)
	{
		printf("\n RollNo: ");
		scanf(" %d",&Node[i].rollNo);
	
		printf(" Name: ");
		scanf(" %[^\n]s",Node[i].name);
		
		
		printf("\n----------Enter Marks----------\n");
		printf(" Maths: ");
		scanf(" %d",&Node[i].marks[0]);
		printf(" English: ");
		scanf(" %d",&Node[i].marks[1]);
		printf(" Physics: ");
		scanf(" %d",&Node[i].marks[2]);
		printf(" Chemistry: ");
		scanf(" %d",&Node[i].marks[3]);
		printf(" Biology: ");
		scanf(" %d",&Node[i].marks[4]);
	
		total = ( Node[i].marks[0] + Node[i].marks[1] + Node[i].marks[2] + Node[i].marks[3] +Node[i].marks[4]);
		Node[i].percentage =((double)total / 500.00) * 100.00;
	}
	  return Node;
}


void DisplayNode(STD* Node, int size) {
	double high = 0.0;
	int top = 0;
    for (int i = 0; i < size; i++) {
        printf(" Roll No : %d\n Name : %s\n", Node[i].rollNo, Node[i].name);
		printf(" Maths: %d\n English: %d\n Physics: %d\n Chemistry: %d\n Biology: %d\n Total Percentage: %f\n",
		Node[i].marks[0],
		Node[i].marks[1],
		Node[i].marks[2],
		Node[i].marks[3],
		Node[i].marks[4],
		Node[i].percentage);
        printf("------------------------------------------------------------\n");
		
		if(high<Node[i].percentage)
		{
			high = Node[i].percentage;
			top = i;
		}
    }
	
	printf("\n********** Topper **********\n");
	 printf("------------------------------------------------------------\n");
	printf(" Roll No : %d\n Name : %s\n", Node[top].rollNo, Node[top].name);
		printf(" Maths: %d\n English: %d\n Physics: %d\n Chemistry: %d\n Biology: %d\n Total Percentage: %f\n",
		Node[top].marks[0],
		Node[top].marks[1],
		Node[top].marks[2],
		Node[top].marks[3],
		Node[top].marks[4],
		Node[top].percentage);
        printf("------------------------------------------------------------\n");
	

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
	int size;
	
	do{
		printf("\n********** Node Creation **********\n");
		printf("\nEnter 1 Create Node\n");
    	printf("Enter 2 to Display Node\n");	
        printf("Enter 3 to exit\n");
		
			
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
					printf("\n\n Exiting the linked list ....\n");
					FreeMemory(Start);
					Start = NULL;
					exit(0);
			break;
			
		}
				
	}while(Choice!=3);
		
	return 0;
}
 
	