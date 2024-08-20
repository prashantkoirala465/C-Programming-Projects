#include <stdio.h>
//Written by: Prashant Koirala
int main()
{
    int array1[] = {1, 3, 5, 7, 9};
    int array2[] = {2, 4, 6, 8, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);
    int n3 = n1 + n2;
    int array3[n3];
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (array1[i] < array2[j])
        {
            array3[k] = array1[i];
            i++;
        }
        else
        {
            array3[k] = array2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        array3[k] = array1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        array3[k] = array2[j];
        j++;
        k++;
    }
    printf("The merged sorted array from the above is: \n");
    for (int i = 0; i < n3; i++)
    {
        printf("%d ", array3[i]);
    }
    printf("\n");
    return 0;
}