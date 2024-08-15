//Write a function named calculatePower that takes two integers, base and exponent, as input and returns the result of raising the base to the exponent.
#include <stdio.h>
//Written by: Prashant Koirala
int calculatePower(int base, int exponent){
    int result = 1;
    for(int i = 0; i < exponent; i++){
        result *= base;
    }
    return result;
}
int main(){
    int base = 2;
    int exponent = 3;
    printf("%d raised to the power of %d is: %d\n", base, exponent, calculatePower(base, exponent));
    return 0;
}