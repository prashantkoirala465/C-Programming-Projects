#include <stdio.h>

int main() {
    FILE *file;
    int number;
    long sum = 0;
    file = fopen("numbers.bin", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    while (fread(&number, sizeof(int), 1, file) == 1) {
        sum += number;
    }
    fclose(file);
    printf("The sum of all integers in the file is: %ld\n", sum);
    return 0;
}
