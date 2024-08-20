#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    int divisible_by_5 = (number / 5) * 5 == number;
    int divisible_by_7 = (number / 7) * 7 == number;
    if (divisible_by_5 && divisible_by_7) {
        printf("%d is divisible by both 5 and 7.\n", number);
    } else {
        printf("%d is not divisible by both 5 and 7.\n", number);
    }
    return 0;
}
