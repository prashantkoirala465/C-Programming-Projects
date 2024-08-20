#include <stdio.h>
//Written by: Prashant Koirala
int main()
{
    char str[] = "Hello,Rojan Sir!";
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    printf("From the above we know that, the length of the string is: %d\n", i);
    return 0;
}
