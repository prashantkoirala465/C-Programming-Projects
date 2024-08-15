#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int i, j, rows = 3;
    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= rows - i; j++) {
            printf("  ");
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("* ");
        }
        printf("\n");
    }
    for (i = rows - 1; i >= 1; i--) {
        for (j = 1; j <= rows - i; j++) {
            printf("  ");
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
