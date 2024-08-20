//Write a function named calculateFactorialSeries that takes an integer n as input and prints the factorial series up to n.
#include <stdio.h>
//Written by: Prashant Koirala
int findFactorial(int n){
    int factorial = 1;
    for(int i = 1; i <= n; i++){
        factorial *= i;
    }
    return factorial;
}
void calculateFactorialSeries(int n){
    for(int i = 1; i <= n; i++){
        printf("%d! = %d\n", i, findFactorial(i));
    }
}
int main(){
    int n = 5;
    calculateFactorialSeries(n);
    return 0;
}