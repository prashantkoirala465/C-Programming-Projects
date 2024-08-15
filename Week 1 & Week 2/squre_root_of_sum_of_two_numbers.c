#include <stdio.h>
#include <math.h>
//Written by: Prashant Koirala
int main() {
    double num1, num2, sum, sqrt_result, rounded_result;
    printf("Please, enter the first number: ");
    scanf("%lf", &num1);
    printf("Please, enter the second number: ");
    scanf("%lf", &num2);
    sum = num1 + num2;
    sqrt_result = sqrt(sum);
    rounded_result = round(sqrt_result);
    printf("The square root of the sum of %.2f and %.2f, rounded to the nearest integer, is %.0f\n", num1, num2, rounded_result);
    return 0;
}
