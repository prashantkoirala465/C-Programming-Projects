#include <stdio.h>
// Written by: Prashant Koirala
void getInput(int numbers[5]) {
    printf("Enter 5 numbers: ");
    for(int i = 0; i < 5; i++) {
        scanf("%d", &numbers[i]);
    }
}
