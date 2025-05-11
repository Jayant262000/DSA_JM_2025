//Accept elements in 4*4 matrix and display the Transpose of matrix

#include <stdio.h>
#include <stdlib.h>

int **AllocateMemory(int rows, int cols) {
    int **array = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++)
	{
        for (int j = 0; j < cols; j++)
        {  
			scanf("%d", &array[i][j]);
		}
	}
    return array;
}

void DisplayArray(int **array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("\n");
        for (int j = 0; j < cols; j++) {
            printf("%d\t", array[i][j]);
        }
    }
    printf("\n");
}

int **Transpose(int **matrix, int rows, int cols) {
    int **transpose = (int **)malloc(cols * sizeof(int *));
    for (int i = 0; i < cols; i++) {
        transpose[i] = (int *)malloc(rows * sizeof(int));
    }

    for (int i = 0; i < rows; i++)
	{
        for (int j = 0; j < cols; j++)
        { 
			transpose[j][i] = matrix[i][j];
		}
	}
    return transpose;
}

int main() {
    int **matrix = NULL, **transposed = NULL;
    int row, col;

    printf("Rows: ");
    scanf("%d", &row);
    printf("Columns: ");
    scanf("%d", &col);

    printf("\n********* Enter Matrix Elements *********\n");
    matrix = AllocateMemory(row, col);

    printf("\n********* Original Matrix *********");
    DisplayArray(matrix, row, col);

    transposed = Transpose(matrix, row, col);

    printf("\n********* Transposed Matrix *********");
    DisplayArray(transposed, col, row);  

    
    return 0;
}
