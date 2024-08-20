#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int num;
    printf("Please, enter a number: ");
    scanf("%d", &num);
    if (num > 0 && (num & (num - 1)) == 0) {
        printf("%d is a power of 2.\n", num);
    } else {
        printf("%d is not a power of 2.\n", num);
    }
    return 0;
}
