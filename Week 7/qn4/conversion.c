#include <stdio.h>
//Written by: Prashant Koirala
float convertTemperature(float temp, char unit) {
    if (unit == 'C' || unit == 'c') {
        return (temp * 9 / 5) + 32;
    } else if (unit == 'F' || unit == 'f') {
        return (temp - 32) * 5 / 9;
    }
    return -1;
}
