//Write a C program that swaps the values of two integers using pointers.
#include <stdio.h>
//Written by: Prashant Koirala
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int a = 5;
    int b = 11;
    printf("The value Before swapping: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("The value After swapping: a = %d, b = %d\n", a, b);
    return 0;
}