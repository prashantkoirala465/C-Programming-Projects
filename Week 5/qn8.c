//Write a function named findPrimeNumbers that takes an integer n as input and prints all prime numbers from 1 to n.
#include <stdio.h>
//Written by: Prashant Koirala
int isPrime(int n){
    if(n <= 1){
        return 0;
    }
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}
void findPrimeNumbers(int n){
    for(int i = 1; i <= n; i++){
        if(isPrime(i)){
            printf("%d ", i);
        }
    }
    printf("\n");
}
int main(){
    int n = 20;
    findPrimeNumbers(n);
    return 0;
}