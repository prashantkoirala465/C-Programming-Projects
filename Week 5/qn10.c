//Write a function named calculateGCD that takes two integers as input and returns their greatest common divisor (GCD).
#include <stdio.h>
//Written by: Prashant Koirala
int calculateGCD(int a, int b){
    int gcd = 1;
    for(int i = 1; i <= a && i <= b; i++){
        if(a%i == 0 && b%i == 0){
            gcd = i;
        }
    }
    return gcd;
}
int main(){
    int a = 12;
    int b = 18;
    printf("The Greatest common divisior of %d and %d is: %d\n", a, b, calculateGCD(a, b));
    return 0;
}