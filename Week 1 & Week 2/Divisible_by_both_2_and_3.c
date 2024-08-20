#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int number = 24;
    int divisible_by_2 = (number / 2) * 2 == number;
    int divisible_by_3 = (number / 3) * 3 == number;

    if (divisible_by_2 && divisible_by_3) {
        printf("%d is divisible by both 2 and 3.\n", number);
    } else {
        printf("%d is not divisible by both 2 and 3.\n", number);
    }
    return 0;
}
