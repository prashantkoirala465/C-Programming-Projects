//Write a function named isPalindrome that takes a string as input and returns 1 if it is a palindrome(reads the same forwards and backwards), and 0 otherwise.
#include <stdio.h>
//Written by: Prashant Koirala
int isPalindrome(char str[]){
    int length = 0;
    while(str[length] != '\0'){
        length++;
    }
    for(int i = 0; i < length/2; i++){
        if(str[i] != str[length - i - 1]){
            return 0;
        }
    }
    return 1;
}
int main(){
    char str[] = "hello";
    if(isPalindrome(str)){
        printf("The string is a palindrome.\n");
    }else{
        printf("The string is not a palindrome.\n");
    }
    return 0;
}


