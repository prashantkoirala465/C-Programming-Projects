#include <stdio.h>
//Written by: Prashant Koirala
void calculateSumAndAverage(int n, float numbers[n], float *sum, float *average) {
    *sum = 0;
    for (int i = 0; i < n; i++) {
        *sum += numbers[i];
    }
    *average = *sum / n;
}
