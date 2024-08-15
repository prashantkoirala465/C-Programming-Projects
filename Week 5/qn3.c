//Write a function named findFactorial that takes an integer as input and returns its factorial.
#include <stdio.h>
//Written by: Prashant Koirala
int findFactorial(int n){
    int factorial = 1;
    for(int i = 1; i <= n; i++){
        factorial *= i;
    }
    return factorial;
}
int main(){
    int n = 5;
    printf("The factorial of %d is: %d\n", n, findFactorial(n));
    return 0;
}
