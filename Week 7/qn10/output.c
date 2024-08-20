#include <stdio.h>
#include "input.c"
#include "calculation.c"
//Written by: Prashant Koirala
void outputResult(float num1, float num2, char operation, float result) {
    if (operation == '/' && num2 == 0) {
        printf("Cannot perform division by zero.\n");
    } else {
        printf("Result of %.2f %c %.2f = %.2f\n", num1, operation, num2, result);
    }
}
int main() {
    float num1, num2, result;
    char operation;
    inputNumbers(&num1, &num2);
    inputOperation(&operation);
    result = calculate(num1, num2, operation);
    outputResult(num1, num2, operation, result);
    return 0;
}
