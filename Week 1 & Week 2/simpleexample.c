#include <stdio.h>
//Written by: Prashant Koirala
//the program to print 0,3,8,15,24 to 1000th element...using for loop
int main() {
    int i;
    for (i = 1; i <= 10; i++) {
        printf("%d\n", i * i - 1);
    }

    return 0;
}