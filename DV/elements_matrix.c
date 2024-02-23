#include <stdio.h>
#include "../data_structures_C/imatriz2d/imatriz2d.c"

#define ROWS = 4;
#define COLUMNS = 4;

// Function to print a Matrix
void printMatrix(int M[ROWS][COLUMNS]){
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLUMNS; j++){
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }
}

int main(){

    //PREGUNTAR ESTO DE AQUÍ ABAJO PORQUE NO FUNCIONA

    int matrix[ROWS][COLUMNS] = {
        {4,  8, 5, 6},
        {6, 12, 4, 1},
        {3,  1, 3, 5},
        {5, 13, 6, 2}
    };
    printf("The given matrix is:\n");
    //printMatrix(matrix,4,4);

}