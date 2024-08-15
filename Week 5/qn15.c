//Write a recursive function named calculateSumOfDigits that takes an integer n as input and returns the sum of its digits.
#include <stdio.h>
//Written by: Prashant Koirala
int calculateSumOfDigits(int n){
    if(n == 0){
        return 0;
    }
    return n % 10 + calculateSumOfDigits(n / 10);
}
int main(){
    int n = 123456789;
    printf("The sum of the digits of %d is: %d\n", n, calculateSumOfDigits(n));
    return 0;
}