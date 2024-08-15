#include <stdio.h>
//Written by: Prashant Koirala
int main()
{
    char str[] = "rojan sir is a great teacher!";
    char ch = 'r';
    int i = 0;
    int count = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ch)
        {
            count++;
        }
        i++;
    }
    printf("The character '%c' occurs %d times in the string.\n", ch, count);
    return 0;
}