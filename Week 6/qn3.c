//Write a C program that reverses an array of characters using pointers.
#include <stdio.h>
// Written by: Prashant Koirala
void reverse(char *arr, int n) {
    char temp;
    for (int i = 0; i < n / 2; i++) {
        temp = *(arr + i);
        *(arr + i) = *(arr + n - i - 1);
        *(arr + n - i - 1) = temp;
    }
}
int main() {
    char arr[] = "ramro";
    int n = sizeof(arr)/sizeof(arr[0]) - 1;
    printf("The value of array before reversing: %s\n", arr);
    reverse(arr, n);
    printf("Thevalue of array after reversing: %s\n", arr);
    return 0;
}
