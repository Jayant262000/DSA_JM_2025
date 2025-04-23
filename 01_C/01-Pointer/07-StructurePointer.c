#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct StudentDetails{
	
	int RollNo;
	char Name[20];
		
}STD;


STD * InsertStudentDetails(STD * stdPtr){
	
	stdPtr = (STD*)malloc(sizeof(STD));
	printf("Enter the RollNo: ");
	scanf("%d",&stdPtr->RollNo);
	
	printf("Enter the Name: ");
	scanf(" %[^\n]s",stdPtr->Name);
	
	return stdPtr;
}


void StudentDetails(STD * stdPtr){
		printf("Student Roll No: %d\nStudent Name: %s",stdPtr->RollNo,stdPtr->Name);

}

int main(){
	
	STD * stdPtr = NULL;
	
	printf("!!!Enter the Student Details!!!\n");
	stdPtr = InsertStudentDetails(stdPtr);
	
	printf("\n!!!Display the Student Details!!!\n");
	StudentDetails(stdPtr);
	
	
	return 0;
}