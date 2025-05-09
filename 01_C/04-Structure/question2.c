/*


   write a C program to read and print an employee's detail using structure.
   - read and print the employee's details like name, employee id, salary etc using structure.
   
*/


#include<stdio.h>
#include<stdlib.h>

typedef struct Employee{
		
		char name[20];
		char company[20];
		int empID;
		double salary;
		int experiance;
		
}Emp;


Emp AllocateMemory(Emp emp)
{
	printf("\nPerson Name: ");
	scanf("%[^\n]s",emp.name);
	getchar();
	
	printf("\nPerson Company name: ");
	getchar();
	scanf("%[^\n]s",emp.company);
	
	printf("\nPerson Employee No.: ");
	getchar();
	scanf("%d",&emp.empID);
	
	printf("\nPerson salary: ");
	getchar();
	scanf("%lf",&emp.salary);
	
	printf("\nPerson experiance: ");
	getchar();
	scanf("%d",&emp.experiance);
	
	return emp;
}


void Display(Emp emp)
{
	printf("\n--------- Person's Details ----------\n");
	printf("\nPerson Name: %s\n",emp.name);
	printf("\nPerson Company name: %s\n",emp.company);
	printf("\nPerson Employee No.: %d\n",emp.empID);
	printf("\nPerson salary: %lf\n",emp.salary);
	printf("\nPerson experiance: %d\n",emp.experiance);
}

int main()
{
    Emp emp;

	printf("\nEnter the details of Person\n");
	emp = AllocateMemory(emp);
	Display(emp);
	
   return 0;
 
}	