//Write a recursive function named calculateFactorial that takes an integer n as input and returns its factorial.
#include <stdio.h>
//Written by: Prashant Koirala
int calculateFactorial(int n){
    if(n == 0){
        return 1;
    }
    return n * calculateFactorial(n - 1);
}
int main(){
    int n = 11;
    printf("The factorial of %d is: %d\n", n, calculateFactorial(n));
    return 0;
}