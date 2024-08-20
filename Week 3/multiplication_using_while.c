#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int number, i = 1;
    printf("Multiplication Table:\n");
    printf("Enter a positive integer:");
    scanf("%d", &number);
    if (number <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        // Print the multiplication table using a while loop
        printf("Multiplication table of %d:\n", number);
        while (i <= 10) {
            printf("%d x %d = %d\n", number, i, number * i);
            i++;
        }
    }
    return 0;
}
