//Write a function named countOccurrences that takes a string and a character as input and returns the number of times the character appears in the string.
#include <stdio.h>
//Written by: Prashant Koirala
int countOccurrences(char str[], char c){
    int count = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == c){
            count++;
        }
    }
    return count;
}
int main(){
    char str[] = "rojansir";
    char c = 'r';
    printf("The character %c appears %d times in the string.\n", c, countOccurrences(str, c));
    return 0;
}