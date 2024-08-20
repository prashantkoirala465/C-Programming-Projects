#include <stdio.h>
#include "input.c"
#include "sorting.c"
//Written by: Prashant Koirala
void outputArray(int n, int array[n]) {
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int main() {
    int n;
    inputSize(&n);
    int array[n];
    inputArray(n, array);
    bubbleSort(n, array);
    outputArray(n, array);
    return 0;
}
