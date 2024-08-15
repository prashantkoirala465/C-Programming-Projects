#include <stdio.h>
#include "input.c"
#include "maths.c"
// Written by: Prashant Koirala
int main() {
    int numbers[5];
    getInput(numbers);

    int sum = calculateSum(numbers, 5);
    printf("The Average of the numbers is: %.2f\n", calculateAverage(sum, 5));

    return 0;
}
