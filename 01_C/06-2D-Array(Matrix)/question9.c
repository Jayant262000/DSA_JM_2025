//accept n elements in  2D - array and perform 90 degree right rotaion and 90 degree left rotation (rotate N elements (N is an user input)) .  
//(Allocate the (N x M) 2D - array dynamically)


#include <stdio.h>
#include <stdlib.h>

int **AllocateMemory(int rows, int cols) {
    int **array = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
    }

    return array;
}

int ** leftRotation(int ** matrix,int **leftMatrix, int rows, int cols)
{
	 
	for (int i = 0; i < rows; i++)
	{
        for (int j = 0; j < cols; j++)
        {  
			leftMatrix[(cols-1)-j][i] = matrix[i][j];
		}
	} 
	
	return leftMatrix;
}

int ** rightRotation(int ** matrix,int **rightMatrix, int rows, int cols)
{
	 
	for (int i = 0; i < rows; i++)
	{
        for (int j = 0; j < cols; j++)
        {  
			rightMatrix[j][(cols-1)-i] = matrix[i][j];
		}
	} 
	
	return rightMatrix;
}

void DisplayArray(int **array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("\n");
        for (int j = 0; j < cols; j++) {
            printf("%d\t", array[i][j]);
        }
    }
   
}



int main() {
    int **matrix = NULL;
	int **leftMatrix=NULL;
	int **rightMatrix=NULL;
    int row, col;

    printf("Rows: ");
    scanf("%d", &row);
    printf("Columns: ");
    scanf("%d", &col);

    printf("\n********* Enter Matrix Elements *********\n");
    matrix = AllocateMemory(row, col);
	
	 for (int i = 0; i < row; i++)
	{
        for (int j = 0; j < col; j++)
        {  
			scanf("%d", &matrix[i][j]);
		}
	}
	
	leftMatrix =  AllocateMemory(col,row);
	rightMatrix =  AllocateMemory(col,row);

    printf("\n********* Original Matrix *********\n");
    DisplayArray(matrix, row, col);
	
	leftMatrix = leftRotation(matrix,leftMatrix, row, col);
	 printf("\n********* Left Rotation Matrix *********\n");
	  DisplayArray(leftMatrix, row, col);
	  
	  rightMatrix = rightRotation(matrix,leftMatrix, row, col);
	 printf("\n********* right Rotation Matrix *********\n");
	  DisplayArray(rightMatrix, row, col);
	

    return 0;
}
