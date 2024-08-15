#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);
    if (ch >= 'A' && ch <= 'Z') {
        printf("The character you entered '%c' is an uppercase letter.\n", ch);
    } 
    else {
        printf("The character you entered '%c' sadly, is not an uppercase letter.\n", ch);
    }
    return 0;
}
