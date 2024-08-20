#include <stdio.h>
#include "input.c"
#include "calculation.c"
//Written by: Prashant Koirala
void output(int num, int fact) {
    printf("The factorial of %d is %d\n", num, fact);
}
int main() {
    int num = input();               // Get input
    int fact = calculation(num);     // Calculate factorial
    output(num, fact);               // Display the result
    return 0;
}
