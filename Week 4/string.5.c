#include <stdio.h>
//Written by: Prashant Koirala
int main()
{
    char str1[] = "Hello,";
    char str2[] = "Rojan Sir!";
    int i = 0;
    int j = 0;
    while (str1[i] != '\0')
    {
        i++;
    }
    while (str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
    printf("The concatenated string from the above is: %s\n", str1);
    return 0;
}