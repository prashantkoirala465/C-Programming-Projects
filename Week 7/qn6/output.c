#include <stdio.h>
#include "input.c"
#include "multiplication.c"
//Written by: Prashant Koirala
void outputMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Resulting Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int rowsA, colsA, rowsB, colsB;
    inputDimensions(&rowsA, &colsA, &rowsB, &colsB);

    if (colsA != rowsB) {
        printf("Matrix multiplication not possible.\n");
        return 1;
    }
    int matrixA[rowsA][colsA], matrixB[rowsB][colsB], result[rowsA][colsB];
    inputMatrix(rowsA, colsA, matrixA);
    inputMatrix(rowsB, colsB, matrixB);
    multiplyMatrices(rowsA, colsA, matrixA, rowsB, colsB, matrixB, result);
    outputMatrix(rowsA, colsB, result);
    return 0;
}
