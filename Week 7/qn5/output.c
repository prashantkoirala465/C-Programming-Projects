#include <stdio.h>
#include "input.c"
#include "calculation.c"
//Written by: Prashant Koirala
void output(float area, float perimeter) {
    printf("Area of the rectangle: %.2f\n", area);
    printf("Perimeter of the rectangle: %.2f\n", perimeter);
}
int main() {
    float length, width, area, perimeter;
    input(&length, &width);
    calculate(length, width, &area, &perimeter);
    output(area, perimeter);
    return 0;
}
