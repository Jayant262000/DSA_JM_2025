/*  

    Write a c program which demonstrate a nested structure 
	- define a structure employee inside a structure person.
    - structure person data: 
                        Name, Age, Date of birth, blood group.
    - structure employee data:
                        Company name, Emp id, salary, years of experiance.
						
	- create objects of structure and display the all details of a person.

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Employee{
		
		char company[20];
		int empID;
		double salary;
		int experiance;
		
}Emp;


typedef struct Person{
	
	char name[20];
	int age;
	char  DOB[10];
	char bloodGr[2];
     Emp emp;
}Per;

Per AllocateMemory(Per per)
{
	printf("\nPerson Name: ");
	scanf("%[^\n]s",per.name);
	getchar();
	
	printf("\nPerson Age: ");
	getchar();
	scanf("%d",&per.age);
	
	printf("\nPerson DOB: ");
	getchar();
	scanf("%s",per.DOB);
	
	printf("\nPerson Blood Group: ");
	getchar();
	scanf("%s",per.bloodGr);
	
	printf("\nPerson Company name: ");
	getchar();
	scanf("%[^\n]s",per.emp.company);
	
	printf("\nPerson Employee No.: ");
	getchar();
	scanf("%d",&per.emp.empID);
	
	printf("\nPerson salary: ");
	getchar();
	scanf("%lf",&per.emp.salary);
	
	printf("\nPerson experiance: ");
	getchar();
	scanf("%d",&per.emp.experiance);
	
	return per;
}


void Display(Per per)
{
	printf("\n--------- Person's Details ----------\n");
	printf("\nPerson Name: %s\n",per.name);
	printf("\nPerson Age: %d\n",per.age);
	printf("\nPerson DOB: %s\n",per.DOB);
	printf("\nPerson Blood Group: %s\n",per.bloodGr);
	printf("\nPerson Company name: %s\n",per.emp.company);
	printf("\nPerson Employee No.: %d\n",per.emp.empID);
	printf("\nPerson salary: %lf\n",per.emp.salary);
	printf("\nPerson experiance: %d\n",per.emp.experiance);
}

int main()
{
    Per per;

	printf("\nEnter the details of Person\n");
	per = AllocateMemory(per);
	Display(per);
	
   return 0;
 
}	
