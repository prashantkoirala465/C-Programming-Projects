//Write a recursive function named calculateBinary that takes an integer n as input and returns its binary representation as a string.
#include <stdio.h>
//Written by: Prashant Koirala
void calculateBinary(int n){
    if(n == 0){
        return;
    }
    calculateBinary(n / 2);
    printf("%d", n % 2);
}
int main(){
    int n = 11;
    calculateBinary(n);
    printf("\n");
    return 0;
}