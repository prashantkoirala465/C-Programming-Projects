#include <stdio.h>
//Written by: Prashant Koirala
int main()
{
    int arr[10] = {45, 46, 47, 48, 49, 50, 51, 52, 53, 54};
    int max = arr[0];
    int second_max = arr[0];
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > max)
        {
            second_max = max;
            max = arr[i];
        }
        else if (arr[i] > second_max && arr[i] != max)
        {
            second_max = arr[i];
        }
    }
    printf("The Second Largest element in the above array above is: %d\n", second_max);
    return 0;
}