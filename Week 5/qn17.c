//Write a recursive function named printTriangle that takes an integer n as input and prints a triangle of asterisks (*) with n rows.
#include <stdio.h>
//Written by: Prashant Koirala
void printTriangle(int n, int i){
    if(n == 0){
        return;
    }
    if(i < n){
        printf("*");
        printTriangle(n, i + 1);
    }
    else{
        printf("\n");
        printTriangle(n - 1, 0);
    }
}
int main(){
    int n = 7;
    printTriangle(n, 0);
    return 0;
}