#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    int x, y, z;
    printf("Please, enter the value of x: ");
    scanf("%d", &x);
    printf("Please, enter the value of y: ");
    scanf("%d", &y);
    printf("Please, enter the value of z: ");
    scanf("%d", &z);
    printf("The value you entered before swapping was: x = %d, y = %d, z = %d\n", x, y, z);
    int temp = x; 
    x = y;        
    y = z;         
    z = temp;      
    printf("The value you entered after swapping becomes: x = %d, y = %d, z = %d\n", x, y, z);
    return 0;
}
