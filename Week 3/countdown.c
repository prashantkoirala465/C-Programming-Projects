#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int number;
    printf("Please, enter a positive integer: ");
    scanf("%d", &number);
    if (number <= 0) {
        printf("Invalid, Please enter a positive integer.\n");
    } else {
        for (int i = number; i >= 1; i--) {
            printf("%d\n", i);
        }
    }
    return 0;
}
