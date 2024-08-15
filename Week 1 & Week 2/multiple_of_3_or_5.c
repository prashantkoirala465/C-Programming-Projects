#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int number;
    printf("Please, enter a number: ");
    scanf("%d", &number);
    if (number % 3 == 0 || number % 5 == 0) {
        printf("%d is a multiple of either 3 or 5.\n", number);
    } else {
        printf("%d is not a multiple of either 3 or 5.\n", number);
    }
    return 0;
}
