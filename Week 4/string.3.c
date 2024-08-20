#include <stdio.h>
//Written by: Prashant Koirala
int main()
{
    char str[] = "hello";
    int i = 0;
    int j = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    for (j = 0; j < i / 2; j++)
    {
        if (str[j] != str[i - j - 1])
        {
            printf("The given string above is not a palindrome.\n");
            return 0;
        }
    }
    printf("The given string above is a palindrome.\n");
    return 0;
}