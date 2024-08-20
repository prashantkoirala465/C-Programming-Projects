#include <stdio.h>
//Written by: Prashant Koirala
float calculate(float num1, float num2, char operation) {
    switch(operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0) {
                return num1 / num2;
            } else {
                printf("Error: Division by zero is not allowed.\n");
                return 0;
            }
        default:
            printf("Invalid operation.\n");
            return 0;
    }
}
