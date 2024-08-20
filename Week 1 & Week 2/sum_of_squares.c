#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int num1, num2, num3;
    int sum_of_square;
    printf("Please, enter the first number: ");
    scanf("%d", &num1);
    printf("Please, enter the second number: ");
    scanf("%d", &num2);
    printf("Please, enter the third number: ");
    scanf("%d", &num3);
    sum_of_square = num1 * num1 + num2 * num2 + num3 * num3;
    printf("The sum of the squares of %d, %d, and %d is %d\n", num1, num2, num3, sum_of_square);
    return 0;
}
