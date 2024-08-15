#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int number;
    printf("Please, enter an integer: ");
    scanf("%d", &number);
    if (number > 0) {
        printf("The number you entered is positive.\n");
    } else if (number < 0) {
        printf("The number you entered is negative.\n");
    } else {
        printf("The number you entered is zero.\n");
    }
    return 0;
}
