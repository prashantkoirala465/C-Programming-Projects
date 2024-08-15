#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int number, i = 1;
    printf("Welcome to multiplication program.\n");
    printf("Please, enter a number: ");
    scanf("%d", &number);
    printf("Multiplication table of %d:\n", number);
    do {
        printf("%d x %d = %d\n", number, i, number * i);
        i++;
    } while (i <= 10);
    return 0;
}
