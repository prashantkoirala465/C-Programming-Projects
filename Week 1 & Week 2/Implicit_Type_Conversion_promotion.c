#include <stdio.h>
//Written by: Prashant Koirala
int main()
{
int a = 10;
float b = 3.5;

float result = a + b;  
printf("%f",result);
return 0;
}
/* Implicit conversion of 'a' to float*/
/* In this Program, a is promoted to a float before addition with b.*/