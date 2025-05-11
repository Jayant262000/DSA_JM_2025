//Accept  two different n*m matrix and store and display the addition of two matrix in 3rd matrix 


#include<stdio.h>
#include<stdlib.h>


int ** AllocateMemory(int ** array,int row,int col)
{
	
	array = (int **)malloc(row*sizeof(int*));
	for(int i =0;i<row;i++)
	{
		array[i] = (int*)malloc(col*sizeof(int));
	}
	
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			scanf("%d",&array[i][j]);
		}
	}
	
	return array;
}

int ** SumofTwoMatrices(int ** matrix1,int ** matrix2,int ** matrix3,int row,int col)
{
	matrix3 = (int **)malloc(row*sizeof(int*));
	for(int i =0;i<row;i++)
	{
		matrix3[i] = (int*)malloc(col*sizeof(int));
	}
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	 
	return matrix3;
}


void DisplayArray(int ** array,int  row,int  col)
{
	for(int i=0;i<row;i++)
	{
		printf("\n");
		for(int j=0;j<col;j++)
		{
			printf("%d\t",array[i][j]);
		}
	}
}


int main()
{
	int **  matrix1 = NULL;
	int **  matrix2 = NULL;
	int **	matrix3 = NULL;
	int row,col;
	
	printf("\nEnter no. of Rows: ");
	scanf("%d",&row);
	
	printf("\nEnter no. of Columns: ");
	scanf("%d",&col);
	
	printf("\n*********Enter the data in Matrix1**********\n");
	matrix1 =  AllocateMemory(matrix1,row,col);
	printf("\n*********Enter the data in Matrix2**********\n");
	matrix2 =  AllocateMemory(matrix2,row,col);
	
	printf("\n*********Matrix1**********\n");
	DisplayArray(matrix1,row,col);
	printf("\n");
		printf("\n*********Matrix2**********\n");
	DisplayArray(matrix2,row,col);
	printf("\n");
	
	
	matrix3 = SumofTwoMatrices(matrix1,matrix2,matrix3,row,col);
	printf("\n*********Matrix3**********\n");
	DisplayArray(matrix3,row,col);
	
	
	
	return 0;
}