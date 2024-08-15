#include <stdio.h>
//Written by: Prashant Koirala
void inputArray(int n, int array[n]) {
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
}
void inputSize(int *n) {
    printf("Enter the number of elements: ");
    scanf("%d", n);
}
