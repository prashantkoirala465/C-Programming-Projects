//Write a recursive function named reverseString that takes a string as input and returns the reversed string.
#include <stdio.h>
//Written by: Prashant Koirala
void reverseString(char *str, int start, int end){
    if(start >= end){
        return;
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseString(str, start + 1, end - 1);
}
int main(){
    char str[] = "world";
    reverseString(str, 0, 4);
    printf("The reversed string is: %s\n", str);
    return 0;
}
