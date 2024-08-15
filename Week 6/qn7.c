//Write a C program that dynamically allocates memory for an integer array of size n, where n is entered by the user. Prompt the user to enter n elements and display them using pointers.
#include <stdio.h>
#include <stdlib.h>
//Written by: Prashant Koirala
int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    int *ptr = arr;
    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", ptr + i);
    }
    printf("The elements you entered are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", *(ptr + i));
    }
    free(arr);
    return 0;
}