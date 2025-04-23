#include<stdio.h>
#include<stdlib.h>


int Countvowels(char * str,int size){

	int count=0;
	for(int i = 0;i<=size;i++){
		
	if((str[i]=='a'||str[i]=='A')||
	   (str[i]=='e'||str[i]=='E')||
	   (str[i]=='i'||str[i]=='I')||
	   (str[i]=='o'||str[i]=='O')||
	   (str[i]=='u'||str[i]=='U'))
	   {
		
			count++;			
		}
	}
	return count;
}

int CountConsonants(char * str,int size){
	
	int count=0;
	
	
	for(int i = 0;i<size;i++){
		
		if(str[i]!='a' && str[i]!='A' && str[i]!='e' && str[i]!='E' && str[i]!='i' && str[i]!='I' && str[i]!='o' && str[i]!='O' && str[i]!='u' && str[i]!='U')
	    { 
			count++;
			
		}
	}
	
	return count;
}

int main(){
	
	char * string = NULL;
	int size;

	printf("Enter the size of String: ");
	scanf("%d",&size);
	
	string = (char*)malloc((size)*sizeof(char));
	
	printf("Enter characters in String:");
	for(int i = 0;i<size;i++){
		
		scanf(" %c",string+i);
		
	}
		
	printf("String:");
	for(int i = 0;i<size;i++){
		
		printf("%c",string[i]);
	}
	
	printf("\nVowels in the string are: %d",Countvowels(string,size));
	printf("\nConsonants in the string are: %d",CountConsonants(string,size));
	return 0;
}