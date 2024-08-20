//Write a recursive function named calculatePower that takes two integers base and exponent as input and returns the result of raising the base to the exponent.
#include <stdio.h>
//Written by: Prashant Koirala
int calculatePower(int base, int exponent){
    if(exponent == 0){
        return 1;
    }
    return base * calculatePower(base, exponent - 1);
}
int main(){
    int base = 2;
    int exponent = 3;
    printf("%d raised to the power of %d is: %d\n", base, exponent, calculatePower(base, exponent));
    return 0;
}