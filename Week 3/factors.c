#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int number;
    printf("Please, enter a positive integer: ");
    scanf("%d", &number);
    if (number <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        printf("Factors of %d are: ", number);
        for (int i = 1; i <= number; i++) {
            if (number % i == 0) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    return 0;
}
