#include <stdio.h>
//Written by: Prashant Koirala
int main()
{
double a = 10.1345;
int b = 3;

int result = a + b;  
printf("%i",result);
return 0;
}
/* Implicit conversion of 'a' to int*/
/* In this Program, a is demoted to a int before addition with b.*/