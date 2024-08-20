//Write a recursive function named calculateFibonacci that takes an integer n as input and returns the nth Fibonacci number. The Fibonacci sequence starts with 0 and 1, and each subsequent number is the sum of the two preceding numbers.
#include <stdio.h>
//Written by: Prashant Koirala
int calculateFibonacci(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return calculateFibonacci(n - 1) + calculateFibonacci(n - 2);
}
int main(){
    int n = 10;
    printf("The %dth Fibonacci number is: %d\n", n, calculateFibonacci(n));
    return 0;
}