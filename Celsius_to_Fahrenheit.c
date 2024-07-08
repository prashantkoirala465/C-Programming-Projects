#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    float celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9/5) + 32;
    printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
    return 0;
}
/*This program asks user to input temperature in celsius 
and then converts into fahrenheit by using a 
mathematical formula ie.fahrenheit = (celsius * 9/5) + 32; */