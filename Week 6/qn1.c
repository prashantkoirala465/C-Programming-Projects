//Write a C program that takes an array of integers as input from the user and finds the sum and average of the elements using pointers.
#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int n, i, sum = 0;
    float average;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    int *ptr = arr;
    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", ptr + i);
    }
    for (i = 0; i < n; i++) {
        sum += *(ptr + i);
    }
    average = (float)sum / n;
    printf("The Sum of the number you entered is = %d\n", sum);
    printf(" The Average of the number you entered is = %.2f\n", average);
    return 0;
}


