#include <stdio.h>
#include <math.h> 
//Written by: Prashant Koirala
int main() {
    int num;
    int square_root_number;
    printf("Please, enter a number: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("%d is not a perfect square.\n", num);
        return 0;
    }
    square_root_number = (int) sqrt(num);
    if (square_root_number * square_root_number == num) {
        printf("Congrulations, %d is a perfect square.\n", num);
    } else {
        printf("I'm sorry but %d is not a perfect square.\n", num);
    }
    return 0;
}
