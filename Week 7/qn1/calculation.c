#include <stdio.h>
//Written by: Prashant Koirala
int calculation(int num) {
    int i, fact = 1;
    for (i = 1; i <= num; i++) {
        fact = fact * i;
    }
    return fact;
}
