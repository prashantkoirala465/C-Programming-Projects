//Write a C program that dynamically allocates memory for a string entered by the user and finds its length using pointers.
#include <stdio.h>
#include <stdlib.h>
//Written by: Prashant Koirala
int main() {
    int n, i;
    printf("Enter the number of characters in the string: ");
    scanf("%d", &n);
    char *str = (char *)malloc(n * sizeof(char));
    char *ptr = str;
    printf("Enter the string: ");
    scanf("%s", ptr);
    while (*ptr) {
        ptr++;
    }
    printf("The length of the string is: %ld\n", ptr - str);
    free(str);
    return 0;
}