#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int num, absolute_value;
    printf("Please, enter an number: ");
    scanf("%d", &num);
    if (num < 0) {
        absolute_value = -num;
    } else {
        absolute_value = num;
    }
    printf("The absolute value of %d is %d\n", num, absolute_value);
    return 0;
}
