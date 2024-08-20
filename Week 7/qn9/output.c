#include <stdio.h>
#include "input.c"
#include "calculation.c"
//Written by: Prashant Koirala
void outputResults(float sum, float average) {
    printf("Sum: %.2f\n", sum);
    printf("Average: %.2f\n", average);
}
int main() {
    int n;
    float sum, average;
    inputSize(&n);
    float numbers[n];
    inputNumbers(n, numbers);
    calculateSumAndAverage(n, numbers, &sum, &average);
    outputResults(sum, average);
    return 0;
}
