//Write a recursive function named countOccurrences that takes a string and a character as input and returns the number of times the character appears in the string.
#include <stdio.h>
//Written by: Prashant Koirala
int countOccurrences(char str[], char c, int i){
    if(str[i] == '\0'){
        return 0;
    }
    return (str[i] == c) + countOccurrences(str, c, i + 1);
}
int main(){
    char str[] = "rojansir";
    char c = 'r';
    printf("The character %c appears %d times in the string.\n", c, countOccurrences(str, c, 0));
    return 0;
}