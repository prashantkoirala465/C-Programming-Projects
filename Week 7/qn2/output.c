#include <stdio.h>
#include "input.c"
#include "prime_check.c"
//Written by: Prashant Koirala
void output(int num, int isPrime) {
    if (isPrime) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }
}
int main() {
    int num = input();
    int primeStatus = isPrime(num);
    output(num, primeStatus);
    return 0;
}
