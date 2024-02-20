#include <stdio.h>

#define ROWS 4;
#define COLUMNS 4;

// Function to print a Matrix
void printMatrix(int M[][COLUMNS], const int rows, const int columns){
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLUMNS; j++){
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }
}

//#define SIZE_PER_DIMENSION 4;

int main(){

    //PREGUNTAR ESTO DE AQUÍ ABAJO PORQUE NO FUNCIONA

    //const int SIZE_PER_DIMENSION = 4;
    //int matrix[SIZE_PER_DIMENSION][SIZE_PER_DIMENSION] = {
    int matrix[ROWS][COLUMNS] = {
        {4,  8, 5, 6},
        {6, 12, 4, 1},
        {3,  1, 3, 5},
        {5, 13, 6, 2}
    };
    printf("The given matrix is:\n");
    printMatrix(matrix,4,4);

}