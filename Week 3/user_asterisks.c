#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int n;
    printf("Enter the size of the square: ");
    scanf("%d", &n);
    if (n % 2 != 0) {
        printf("Please enter an even integer.\n");
        return 1;
    }
    int rows = n / 2;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 2; j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
