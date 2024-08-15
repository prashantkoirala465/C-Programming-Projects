//Write a C program that takes two strings as input from the user and concatenates them using pointers.
#include <stdio.h>
// Written by: Prashant Koirala
int main() {
    char str1[100], str2[100];
    char *ptr1 = str1;
    char *ptr2 = str2;
    printf("Please, Enter the first string: ");
    scanf("%99s", ptr1);
    printf("Please, Enter the second string: ");
    scanf("%99s", ptr2);
    while (*ptr1) {
        ptr1++;
    }
    while (*ptr2) {
        *ptr1 = *ptr2;
        ptr1++;
        ptr2++;
    }
    *ptr1 = '\0';
    printf("From the above, The concatenated string is: %s\n", str1);
    return 0;
}
