#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int number;
    printf("Please, enter a number: ");
    scanf("%d", &number);
    if (number > 0 && number % 2 == 0) {
        printf("%d is both positive and even.\n", number);
    } else {
        printf("%d is not both positive and even.\n", number);
    }
    return 0;
}
