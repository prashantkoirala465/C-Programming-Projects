#include <stdio.h>
//Written by: Prashant Koirala
void calculate(float length, float width, float *area, float *perimeter) {
    *area = length * width;
    *perimeter = 2 * (length + width);
}
