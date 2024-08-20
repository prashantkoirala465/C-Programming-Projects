#include <stdio.h>
//Written by: Prashant Koirala
int main()
{
    char str[] = "Rojan Sir!";
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    printf("The reverse of the string from the above is: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", str[j]);
    }
    printf("\n");
    return 0;
}