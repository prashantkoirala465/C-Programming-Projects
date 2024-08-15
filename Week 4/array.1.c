#include <stdio.h>
//Written by: Prashant Koirala
int main()
{
    int arr[10] = {45, 46, 47, 48, 49, 50, 51, 52, 53, 54};
    int max = arr[0];
    int min = arr[0];
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("The Maximum element in the above array above is: %d\n", max);
    printf("The Minimum element in the above array above is: %d\n", min);
    return 0;
}
