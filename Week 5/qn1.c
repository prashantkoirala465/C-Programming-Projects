//Write a function named calculateAverage that takes an array of integers as input and returns the average of the numbers.
#include <stdio.h>
//Written by: Prashant Koirala
float calculateAverage(int arr[], int size){
    float sum = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum/size;
}
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("The average of the numbers is: %.2f\n", calculateAverage(arr, size));
    return 0;
}