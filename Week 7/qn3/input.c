#include <stdio.h>
//Written by: Prashant Koirala
void input(int arr[], int n) {
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}
int inputSize() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    return n;
}
