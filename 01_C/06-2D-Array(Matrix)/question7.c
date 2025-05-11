//Accept  4*4 matrix and display the following patern

/*

  1 1 1 *
  1 1 * 0
  1 * 0 0
  * 0 0 0  
  
*/


#include <stdio.h>
#include <stdlib.h>

char **AllocateMemory(int rows, int cols) {
    char **array = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        array[i] = (char *)malloc(cols * sizeof(char));
    }

    for (int i = 0; i < rows; i++)
	{
        for (int j = 0; j < cols+1; j++)
        {  
			if(j<(cols-1)-i)
			{
				array[i][j] = '1';
			}
			else if(j>(cols-1)-i)
			{
				array[i][j] = '0';
			}
			else{
				array[i][j] = '*';
			}
		}
	}
    return array;
}

void DisplayArray(char **array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("\n");
        for (int j = 0; j < cols; j++) {
            printf("%c\t", array[i][j]);
        }
    }
    printf("\n");
}



int main() {
    char **matrix = NULL;
 

   
    matrix = AllocateMemory(4, 4);

    DisplayArray(matrix, 4, 4);

  

    
    return 0;
}