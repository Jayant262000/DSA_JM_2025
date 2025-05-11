//Accept elements in n*m matrix and display its saddle point 
//(sadle point : the element which is the highest in the row and at the same time lowest in the column )

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

void SaddlePoint(int **array, int rows, int cols)
{
	int largeR = 0;
	int flag=0;
	int colIndex = 0;
	int flag2 = 0;
	
	for (int i = 0; i < rows; i++)
	{
		largeR = array[i][0];
		for (int j = 0; j < cols; j++)
        {  
			if(largeR<array[i][j])
			{
				largeR = array[i][j];
				colIndex = j;
			}
		}
		for(int i=0;i<rows;i++)
		{
			if(largeR>array[i][colIndex])
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			printf("\nsaddle  point: %d\n",largeR);
			flag2=2;
			
		}
	}
	
	
	if (flag2!=2)
	{
		printf("\nThere is no saddle  point\n");
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
	
	SaddlePoint(matrix, row, col);
	

    return 0;
}
