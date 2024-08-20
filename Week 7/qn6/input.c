#include <stdio.h>
//Written by: Prashant Koirala
void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}
void inputDimensions(int *rowsA, int *colsA, int *rowsB, int *colsB) {
    printf("Enter dimensions of Matrix A (rows and columns): ");
    scanf("%d %d", rowsA, colsA);
    printf("Enter dimensions of Matrix B (rows and columns): ");
    scanf("%d %d", rowsB, colsB);
}
