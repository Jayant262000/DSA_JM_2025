//Accept elements in 3x3 matrix and check whther it is magic square or not(magic square: sum of all elements in row and column are same)

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

void MagicSquare(int **array, int rows, int cols)
{
	int row[rows];
	int col[rows];
	
	for(int i=0;i<rows;i++)
	{
		row[i] = 0;
		col[i] = 0;
		
	}
	
	int sum1 = 0;
	int sum2 = 0;
	int flag = 0;

	for (int i = 0; i < rows; i++)
	{
		sum1 = sum1+array[i][(cols-1)-i];
        for (int j = 0; j < cols; j++)
        {  
			row[i] += array[i][j];
			
			col[i] += array[j][i];
			
			if(i==j)
			{
				sum2 = sum2+array[i][i];
			}
		}
	}
	
	for(int i=0;i<rows;i++)
	{
		if(sum1==sum2&&sum2==col[i]&&sum1==row[i])
		{
			flag=1;
		}
		
	}

		if(flag==1)
		{
			printf("\nThe Matrix is a magic square\n");
		}
		else
		{
			printf("\nThe Matrix is not a magic square\n");
		}
	
	
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



int main() {
    int **matrix = NULL;
    int row, col;

    printf("Rows: ");
    scanf("%d", &row);
    printf("Columns: ");
    scanf("%d", &col);

    printf("\n********* Enter Matrix Elements *********\n");
    matrix = AllocateMemory(row, col);

    printf("\n********* Original Matrix *********");
    DisplayArray(matrix, row, col);
	
	if(row==col)
	{
		MagicSquare(matrix, row, col);
	}
	else
	{
		printf("\nMagic Square matrix requires same number of rows and columns\n");
	}
	

    return 0;
}
