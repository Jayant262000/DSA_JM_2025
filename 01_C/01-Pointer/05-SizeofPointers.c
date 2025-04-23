#include<stdio.h>
#include<stdlib.h>


int main(){
	
	int * IntegerPtr = NULL;
	char * CharacterPtr = NULL;
	float * FloatPtr = NULL;
	double * DoublePtr = NULL;
	long int * LongIntegerPtr = NULL;
	long long int * LongLongIntegerPtr = NULL;
	typedef struct Structre{
		
		int data1;
		double data2;
		long int data3;
		long long int data4; 
	}Str;
	
	Str * StructurePtr = NULL;
	
	
	printf("Size of IntegerPtr = %ld				Address of IntegerPtr = %u\n",sizeof(IntegerPtr), &IntegerPtr);
	printf("Size of CharacterPtr = %ld				Address of CharacterPtr = %u\n",sizeof(CharacterPtr), &CharacterPtr);
	printf("Size of FloatPtr = %ld	    			Address of FloatPtr = %u\n",sizeof(FloatPtr), &FloatPtr);
	printf("Size of DoublePtr = %ld					Address of DoublePtr = %u\n",sizeof(DoublePtr), &DoublePtr);
	printf("Size of LongIntegerPtr = %ld			Address of LongIntegerPtr = %u\n",sizeof(LongIntegerPtr), &LongIntegerPtr);
	printf("Size of LongLongIntegerPtr = %ld		Address of LongLongIntegerPtr = %u\n",sizeof(LongLongIntegerPtr), &LongLongIntegerPtr);
	printf("Size of StructurePtr = %ld				Address of StructurePtr = %u\n",sizeof(StructurePtr), &StructurePtr);



	
	
	return 0;
}