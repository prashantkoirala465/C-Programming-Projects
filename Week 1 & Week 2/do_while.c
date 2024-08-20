#include<stdio.h>
//Written by: Prashant Koirala
//for loop
//while loop
//do while loop
// program to print odd number multiplication table of any number when user enters a number;
int main ()
{
    int num;
    int i = 1;
    printf(" Odd Multiplication Table Program: Created by Prashant Koirala\n");
    printf("Please, enter a number: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Please enter a positive number.\n");
        return 0;
    }
    do {
        printf("%d x %d = %d\n", num, i, num * i);
        i = i + 2;
    } while (i <= 20);
    return 0;
}