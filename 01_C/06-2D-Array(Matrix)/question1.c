/*

	- Write a C program which allocates 2D array dynamically (N X M).
	- Implement logic to get: 
						- Sum of all elements. 
						- sum of elements from the 2nd column
						- Display left and right diagonals
						- sum of left diagonal
						- sum of right diagonal
						- larger element from left diagonal 
						- smaller element from left diagonal
						- larger element from right diagonal
						- smaller element from right diagonal 
						- Sort the left diagonal
						- sort the right diagonal

*/

#include<stdio.h>
#include<stdlib.h>


int ** AllocateMemory(int ** array,int row,int col)
{
	
	array = (int **)malloc(row*sizeof(int*));
	for(int i =0;i<row;i++)
	{
		array[i] = (int*)malloc(col*sizeof(int));
	}
	printf("\n*********Enter the data**********\n");
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			scanf("%d",&array[i][j]);
		}
	}
	
	return array;
}

int SumOfArrayElements(int ** array,int row,int col)
{
	int sum = 0;
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			sum = sum + array[i][j];
		}
	}
	
	return sum;
}

int SumOfSecondcol(int ** array,int row,int col)
{
	int sum = 0;
	

	for(int j=0;j<row;j++)
	{
		sum = sum + array[j][1];
	}
	
	
	return sum;
}


void Diagonals(int ** array,int row,int col)
{
	int sum = 0;
	int small = array[0][0];
	int large = array[0][0];
	int size = 0;
	
	if(row<col)
	{
		size = row;
		
	}
	else
	{
		size = col;
		
	}
	int leftD[size];
		int rightD[size];
	printf("\n**********left Diagonal**********\n");
	for(int i=0;i<row;i++)
	{ 	printf("\n");
		for(int j=0;j<col;j++)
		{
			if(i==j)
			{
				printf("%d\t",array[i][i]);
				sum = sum+array[i][i];
				if(small>array[i][i])
				{
					small=array[i][i];
				}
				 if(large<array[i][i])
				{
					large = array[i][i];
				}
				if(row<col)
				{
					leftD[i] = array[i][i];
				}
				else
				{
					leftD[j] = array[i][i];
				}
				
			}
		}
	}
	
	
	printf("\nsum of left diagonal: %d",sum);
	printf("\nsmall element of left diagonal: %d",small);
	printf("\nlarge element of left diagonal: %d\n",large);
	
	sum = 0;
	 small = array[0][col-1];
	 large = array[0][col-1];
	
	printf("\n**********Right Diagonal**********\n");
	for(int i=0;i<row;i++)
	{ 	
		printf("%d\n",array[i][(col-1)-i]);
		sum = sum+array[i][(col-1)-i];
		if(small>array[i][(col-1)-i])
		{
			small=array[i][(col-1)-i];
		}
		if(large<array[i][(col-1)-i])
		{
			large = array[i][(col-1)-i];
		}
			
		
		rightD[i] = array[i][(col-1)-i];
		
		
	}
	printf("\nsum of right diagonal: %d",sum);
	printf("\nsmall element of right diagonal: %d",small);
	printf("\nlarge element of right diagonal: %d\n",large);

	small = 0;
	for(int i = 0;i<size;i++)
	{
		for(int j = i+1;j<size;j++)
		{
			if(rightD[i]>rightD[j])
			{
				small = rightD[i];
				rightD[i] = rightD[j];
				rightD[j] = small;
			}
			small = 0;
			if(leftD[i]>leftD[j])
			{
				small = leftD[i];
				leftD[i] = leftD[j];
				leftD[j] = small;
			}
		}
	}
	
	printf("\nSorted left diagonal and right diagonal: \n");
	for(int i = 0; i<size; i++)
	{
		printf("%d\t%d\n",leftD[i],rightD[i]);
	}
	
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
	int **  ptr = NULL;
	int row,col;
	
	printf("\nEnter no. of Rows: ");
	scanf("%d",&row);
	
	printf("\nEnter no. of Columns: ");
	scanf("%d",&col);
	
	ptr =  AllocateMemory(ptr,row,col);
	
	DisplayArray(ptr,row,col);
	
	printf("\nSum of All elements: %d \n",SumOfArrayElements(ptr,row,col));
	printf("\nSum of second column's elements: %d \n",SumOfSecondcol(ptr,row,col));
	
	Diagonals(ptr,row,col);
	
	
	return 0;
}