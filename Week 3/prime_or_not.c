#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int number;
    int is_prime = 1;
    while (1) {
        printf("Please, enter a positive integer: ");
        scanf("%d", &number);
        if (number <= 0) {
            printf("Please enter a positive integer.\n");
        }
        else {
            break;
        }
    }
    if (number == 1) {
        is_prime = 0;
    } else {
        int i = 2;
        while (i * i <= number) {
            if (number % i == 0) {
                is_prime = 0;
                break;
            }
            i++;
        }
    }
    if (is_prime) {
        printf("The number is prime.\n");
    } else {
        printf("The number is not prime.\n");
    }
    return 0;
}