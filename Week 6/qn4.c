//Write a C program that prompts the user to enter a string and counts the number of vowels in it using pointers.
#include <stdio.h>
// Written by: Prashant Koirala
int main() {
    char str[100];
    char *ptr = str;
    int count = 0;
    printf("Please, enter a string: ");
    fgets(str, sizeof(str), stdin);
    while (*ptr != '\0') {
        if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u' ||
            *ptr == 'A' || *ptr == 'E' || *ptr == 'I' || *ptr == 'O' || *ptr == 'U') {
            count++;
        }
        ptr++;
    }
    printf("The number of vowels in the string is: %d\n", count);
    return 0;
}
