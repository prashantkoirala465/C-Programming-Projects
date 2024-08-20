//Make a int called age that holds that holds aa person's age
//print the address and address value without directly using age using pointer

// #include <stdio.h>

// int main() {
//     int age = 20;
//     int *ptr = &age;
//     printf("The Address of age: %p\n", ptr);
//     printf("The Value of age: %d\n", *ptr);
//     return 0;
// }

// #include <stdio.h>

// int sumOfArray(int *p, int length)
// {
//     for (int i = 0; i < length; i++)
//     {
//         printf("The value of element is %d\n", *(p + i));
//     }
//     return 0;
// }
// int main()
// {
//     int arr[5] = {19, 18, 20, 21, 18};
//     sumOfArray(arr, 5);
// }

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = (int *)malloc(5 * sizeof(int));
    arr[0] = 120;
    printf("%d\n", arr[0]);
    free(arr);
    printf("%d\n", arr[0]);

}

