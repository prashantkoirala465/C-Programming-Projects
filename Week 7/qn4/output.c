#include <stdio.h>
#include "input.c"
#include "conversion.c"
//Written by: Prashant Koirala
void output(float convertedTemp, char unit) {
    if (convertedTemp != -1) {
        if (unit == 'C' || unit == 'c') {
            printf("The temperature in Fahrenheit is: %.2f F\n", convertedTemp);
        } else if (unit == 'F' || unit == 'f') {
            printf("The temperature in Celsius is: %.2f C\n", convertedTemp);
        }
    } else {
        printf("Invalid unit entered!\n");
    }
}
int main() {
    float temp;
    char unit;
    input(&temp, &unit);
    float convertedTemp = convertTemperature(temp, unit);
    output(convertedTemp, unit);
    return 0;
}
