#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int x = 5; 
    int y = 11; 
    printf(" The values before swapping are: x = %d and y = %d\n", x, y);
    x = x + y; 
    y = x - y; 
    x = x - y; 
    printf(" The values after swapping are: x = %d and y = %d\n", x, y);
    return 0;
}
