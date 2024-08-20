#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int number;
    unsigned long long factorial = 1; 
    printf("Please, enter a positive integer: ");
    scanf("%d", &number);
    if (number < 0) {
        printf("I'm sorry, Please enter positive number :).\n");
    } else {
        int i = number;
        while (i > 0) {
            factorial *= i;
            i--;
        }
        printf("The Factorial of %d = %llu\n", number, factorial);
    }
    return 0;
}
