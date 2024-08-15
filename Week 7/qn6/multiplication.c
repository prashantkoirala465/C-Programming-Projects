#include <stdio.h>
//Written by: Prashant Koirala
void multiplyMatrices(int rowsA, int colsA, int matrixA[rowsA][colsA],
                      int rowsB, int colsB, int matrixB[rowsB][colsB],
                      int result[rowsA][colsB]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}
