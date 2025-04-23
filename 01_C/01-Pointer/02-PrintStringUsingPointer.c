#include<stdio.h>
#include<stdlib.h>


int main(){
	
	char * string = NULL;
	int size;
	printf("Enter the size of String: ");
	scanf("%d",&size);
	
	string = (char*)malloc(size*sizeof(char));
	
	printf("Enter characters in String:");
	for(int i = 0;i<size;i++){
		
		scanf("%c",&string[i]);
		
	}
		
	printf("String:");
	for(int i = 0;i<size;i++){
		
		printf("%c",string[i]);
	}
	return 0;
}