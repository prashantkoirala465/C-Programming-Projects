#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    printf("Even numbers between the numbers 1 and 100 are:\n");
    for (int i = 1; i <= 100; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }
    return 0;
}
