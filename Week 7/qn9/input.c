#include <stdio.h>
//Written by: Prashant Koirala
void inputNumbers(int n, float numbers[n]) {
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &numbers[i]);
    }
}
void inputSize(int *n) {
    printf("Enter the number of elements: ");
    scanf("%d", n);
}
