#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decompressFile(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        return;
    }

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        fclose(inputFile);
        return;
    }

    int currentChar;
    while ((currentChar = fgetc(inputFile)) != EOF) {
        if (currentChar >= '0' && currentChar <= '9') {
            // Process the count of characters
            int count = currentChar - '0';
            while ((currentChar = fgetc(inputFile)) >= '0' && currentChar <= '9') {
                count = count * 10 + (currentChar - '0');
            }
            fputc(currentChar, outputFile);
            for (int i = 1; i < count; i++) {
                fputc(currentChar, outputFile);
            }
        }
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("File decompressed successfully!\n");
}

int main() {
    char inputFileName[100], outputFileName[100];

    printf("Enter the name of the compressed file: ");
    scanf("%s", inputFileName);
    printf("Enter the name of the decompressed file: ");
    scanf("%s", outputFileName);

    decompressFile(inputFileName, outputFileName);

    return 0;
}
