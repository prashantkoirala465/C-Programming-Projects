#include <stdio.h>
// Written by: Prashant Koirala
int calculateSum(int numbers[5], int count) {
    int sum = 0;
    for(int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    return sum;
}
float calculateAverage(int sum, int count) {
    return (float)sum / count;
}
