#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int number;
    unsigned long long factorial = 1;
    printf("Please, enter a positive integer: ");
    scanf("%d", &number);
    if (number < 0) {
        printf("Please enter a positive number because, factorial is not defined for negative numbers.\n");
    } else {
        int i = number;
        do {
            factorial *= i;
            i--;
        } while (i > 0);
        printf("Calculation of Factorial of %d = %llu\n", number, factorial);
    }
    return 0;
}
