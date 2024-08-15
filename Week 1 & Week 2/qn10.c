#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int a, b, c;
    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);
    printf("Enter the value of c: ");
    scanf("%d", &c);
    if (a == b && b != c) {
        printf("a is equal to b and b is not equal to c.\n");
    } else {
        printf(" The numbers you provided did not met with the condition: a == b and b != c.\n");
    }
    return 0;
}
