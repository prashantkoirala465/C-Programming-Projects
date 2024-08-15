#include <stdio.h>
//Written by: Prashant Koirala
void input(float *temp, char *unit) {
    printf("Enter the temperature: ");
    scanf("%f", temp);
    printf("Enter the unit (C for Celsius, F for Fahrenheit): ");
    scanf(" %c", unit);
}
