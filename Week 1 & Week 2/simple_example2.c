#include <stdio.h>
//Written by: Prashant Koirala
//Program to print fibonacci sequence upto 15th position ...using for loop
int main() {
    int i;
    int a = 0;
    int b = 1;
    int c;
        for (i = 1; i <= 15; i++) {
        printf("The fibonacci sequence is: %d\n", a);
        c = a + b;
        a = b;
        b = c;
    }
    return 0;

}