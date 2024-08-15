#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int i, j;
    int rows = 5; 
    for (i = rows; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
