#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    float x, y, average;
    printf("Enter the value of x: ");
    scanf("%f", &x);
    printf("Enter the value of y: ");
    scanf("%f", &y);
    average = (x + y) / 2;
    printf("The average of %.2f and %.2f is %.2f\n", x, y, average);
    return 0;
}
