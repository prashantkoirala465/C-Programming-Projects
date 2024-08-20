//Write a function named convertTemperature that takes a temperature value in Celsius and converts it to Fahrenheit. The function should return the converted temperature.
#include <stdio.h>
//Written by: Prashant Koirala
float convertTemperature(float celsius){
    return (celsius * 9/5) + 32;
}
int main(){
    float celsius = 37;
    printf("The temperature in Fahrenheit is: %.2f\n", convertTemperature(celsius));
    return 0;
}