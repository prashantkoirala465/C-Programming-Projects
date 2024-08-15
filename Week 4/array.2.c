#include <stdio.h>
//Written by Prashant Koirala
int main()
{
    int array[10] = {45, 46, 47, 48, 49, 50, 51, 52, 53, 54};
    int temp;
    for (int i = 0; i < 5; i++)
    {
        temp = array[i];
        array[i] = array[9 - i];
        array[9 - i] = temp;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}