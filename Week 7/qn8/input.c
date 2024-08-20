#include <stdio.h>
//Written by: Prashant Koirala
void inputNumbers(float *num1, float *num2) {
    printf("Enter the first number: ");
    scanf("%f", num1);
    printf("Enter the second number: ");
    scanf("%f", num2);
}
void inputOperation(char *operation) {
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", operation);
}
