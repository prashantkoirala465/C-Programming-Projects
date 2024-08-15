#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int age;
    printf("Please, enter your age: ");
    scanf("%d", &age);
    if (age >= 18) {
        printf("You are eligible to vote.\n");
    } else {
        printf("I'm sorry, but you are not eligible to vote.\n");
    }

    return 0;
}
