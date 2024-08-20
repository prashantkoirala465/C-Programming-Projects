#include <stdio.h>
//Written by: Prashant Koirala
int main() {
    FILE *file;
    int numbers[] = {1, 2, 3, 4, 5};
    size_t numCount = sizeof(numbers) / sizeof(numbers[0]);

    file = fopen("numbers.bin", "wb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fwrite(numbers, sizeof(int), numCount, file);
    fclose(file);
    printf("Binary file created successfully.\n");
    return 0;
}
