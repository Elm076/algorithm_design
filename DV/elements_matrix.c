#include <stdio.h>
#include "../data_structures_C/imatriz2d/imatriz2d.c"

#define ROWS 4
#define COLUMNS 4


// Function to print a Matrix
void printMatrix(int rows, int columns, imatriz2d M){
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLUMNS; j++){
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }
}

int classicAlgorithm(imatriz2d M, int rows, int columns, int smallest, int greatest)
{
    int cont = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (smallest <= M[i][j] && M[i][j] <= greatest)
                cont++;
        }
    }
    return cont;
}

int divConqAlgorithm(imatriz2d M, int rowBegin, int columnBegin, int length, int smallest, int greatest, imatriz2d V)
{
    if (length == 2)
    {
        int cont = 0;
        for (int i = rowBegin; i < rowBegin+length; i++)
        {
            for (int j = columnBegin; j < columnBegin+length; j++)
            {
                if (smallest <= M[i][j] && M[i][j] <= greatest)
                {
                    cont++;
                    V[i][j] = 1;
                }
            }
        }
        return cont;
    }

    int newLength = length/2;
    int mRows = rowBegin + ((rowBegin + length) - rowBegin) / 2;
    int mColumns = columnBegin + ((columnBegin + length) - rowBegin) / 2;

    int upLeft = divConqAlgorithm(M, rowBegin, columnBegin, newLength, smallest, greatest, V);
    int upRight = divConqAlgorithm(M, rowBegin, mColumns, newLength, smallest, greatest, V);
    int downLeft = divConqAlgorithm(M, mRows, columnBegin, newLength, smallest, greatest, V);
    int downRight = divConqAlgorithm(M, mRows, mColumns, newLength, smallest, greatest, V);

    return upLeft + upRight + downLeft + downRight;
}

int divConq(imatriz2d M, int smallest, int greatest, imatriz2d V)
{
    return divConqAlgorithm(M,0,0,ROWS,smallest,greatest, V);
}

int main(){

    // int matrix[ROWS][COLUMNS] = {
    //     {4,  8, 5, 6},
    //     {6, 12, 4, 1},
    //     {3,  1, 3, 5},
    //     {5, 13, 6, 2}
    // };

    int initiliazeM[ROWS*COLUMNS] = {4,8,5,6,6,12,4,1,3,1,3,5,5,13,6,2}; 

    int initVerifyM[ROWS*COLUMNS] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    imatriz2d m = icreamatriz2d(ROWS,COLUMNS);
    imatriz2d verifyM = icreamatriz2d(ROWS,COLUMNS);
    int count = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            m[i][j] = initiliazeM[count];
            verifyM[i][j] = initVerifyM[count];
            count++;
        }
    }

    printf("The given matrix is:\n");
    printMatrix(ROWS,COLUMNS,m);

    printf("The matrix to verify elements between smallest and greatest is initialize to:\n");
    printMatrix(ROWS,COLUMNS,verifyM);

    // int result = classicAlgorithm(m,ROWS,COLUMNS,5,8);
    // printf("The elements between 5 and 8 in the matrix is:\n%d\n", result);

    int result = divConq(m,5,8,verifyM);
    printf("The elements between 5 and 8 in the matrix is:\n%d\n", result);

    printf("The postions of the elements between min and max given are printed as 1, here is the checking:\n");
    printMatrix(ROWS,COLUMNS,verifyM);

    ifreematriz2d(&m);
    ifreematriz2d(&verifyM);

}