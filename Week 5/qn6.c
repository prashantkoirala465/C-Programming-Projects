//Write a function named reverseArray that takes an array of integers as input and reverses the order of the elements in the array.
#include <stdio.h>
//Written by: Prashant Koirala
void reverseArray(int arr[], int size){
    for(int i = 0; i < size/2; i++){
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}
int main(){
    int arr[] = {9, 8, 6, 5, 1, 4, 4, 5, 3, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    reverseArray(arr, size);
    printf("The reversed array is: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}