//Write a C program that checks if a given string is a palindrome using pointers.
#include <stdio.h>
// Written by: Prashant Koirala
int main() {
    char str[100];
    char *ptr = str;
    int i, n = 0, flag = 0;
    printf("Please, Enter the string: ");
    scanf("%99s", ptr);
    while (*ptr) {
        n++;
        ptr++;
    }
    ptr = str;
    for (i = 0; i < n / 2; i++) {
        if (*(ptr + i) != *(ptr + n - i - 1)) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        printf("The string is not a palindrome.\n");
    } else {
        printf("The string is a palindrome.\n");
    }
    return 0;
}