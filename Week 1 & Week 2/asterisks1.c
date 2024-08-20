//Write a C program that prints a pattern of asterisks.
/*
*
* *
* * *
* * * *
* * * * *
* * * *
* * *
* *
*
*/
#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int start = 1;
    int middle = 5;
    int end = 1;
    int i, j;
    for (i = start; i <= middle; i++) {
        for (j = start; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    for (i = middle - 1; i >= end; i--) {
        for (j = start; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}

