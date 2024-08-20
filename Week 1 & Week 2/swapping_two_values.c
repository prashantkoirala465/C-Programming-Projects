#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int a, b, temp;
    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);
    printf("Before swapping: a = %d, b = %d\n", a, b);
    temp = a;
    a = b;
    b = temp;
    printf("After swapping: a = %d, b = %d\n", a, b);
    return 0;
}
/*This program swaps the values of two variables in C programming language.*/
