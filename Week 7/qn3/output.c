#include <stdio.h>
#include "input.c"
#include "calculation.c"
//Written by: Prashant Koirala
void output(int max, int min) {
    printf("The maximum element is %d\n", max);
    printf("The minimum element is %d\n", min);
}
int main() {
    int n = inputSize();
    int arr[n];
    input(arr, n);
    int max, min;
    findMaxMin(arr, n, &max, &min);
    output(max, min);
    return 0;
}
