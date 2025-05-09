/* 


    write a C program to create, declare and initialize structure.
    - define a structure "student", which includes the details of students,
    - declare an object of the structure and initialize the structure members.
	
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student{
	
	int rollNo;
	char name[20];
	
	struct Student * next;	
}STD;

STD  CreateNode(STD std){
   	
    printf("\n\t**********Enter Students details**********\n");
		
	printf("Enter the RollNo: ");
	scanf(" %d",&std.rollNo);
	
	printf("Enter the Name of Student: ");
	scanf(" %[^\n]s",std.name);
	
		
	  return std;
}


void DisplayNode(STD std)
{
	printf("Roll no : %d \n Name : %s \n--------------------------------------------------------------------------------------\n"
	,std.rollNo,std.name);
	
}

int main()
{
    //code
	char ch; 
	int Choice;
	STD std;
	
	
	do{
		printf("\n********** Node Creation **********\n");
		printf("\nEnter 1 Create Node\n");
    	printf("Enter 2 to Display Node\n");	
        printf("Enter 3 to exit\n");
		
			
		printf("\nChoice: ");			
		scanf("%d",&Choice);
		
		
		
		switch (Choice){
			
			case 1:	
					std = CreateNode(std);
			break;
		
			case 2: 
					printf("\n\t********* Students Data *********\n");
					DisplayNode(std);
			break;
			
			case 3: 
					printf("\n\n Exiting the program ....\n");

					exit(0);
			break;
			
		}
				
	}while(Choice!=3);
		
	return 0;
}