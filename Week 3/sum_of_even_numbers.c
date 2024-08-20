#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int i = 1;
    int sum = 0;
    while (i <= 50) {
        if (i % 2 == 0) {
            sum += i;
        }
        i++;
    }
    printf("The sum of all even numbers from 1 to 50 is: %d\n", sum);
    return 0;
}
