//Write a recursive function named calculateGCD that takes two integers a and b as input and returns their greatest common divisor (GCD).
#include <stdio.h>
//Written by: Prashant Koirala
int calculateGCD(int a, int b){
    if(b == 0){
        return a;
    }
    return calculateGCD(b, a%b);
}
int main(){
    int a = 12;
    int b = 18;
    printf("The Greatest common divisior of %d and %d is: %d\n", a, b, calculateGCD(a, b));
    return 0;
}
