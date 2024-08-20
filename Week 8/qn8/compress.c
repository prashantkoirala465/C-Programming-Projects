#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compressFile(const char *inputFileName, const char *outputFileName) {
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

    int currentChar, previousChar = EOF;
    int count = 0;

    while ((currentChar = fgetc(inputFile)) != EOF) {
        if (currentChar == previousChar) {
            count++;
        } else {
            if (previousChar != EOF) {
                fprintf(outputFile, "%c%d", previousChar, count);
            }
            previousChar = currentChar;
            count = 1;
        }
    }

    // Write the last sequence
    if (previousChar != EOF) {
        fprintf(outputFile, "%c%d", previousChar, count);
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("File compressed successfully!\n");
}

int main() {
    char inputFileName[100], outputFileName[100];

    printf("Enter the name of the file to compress: ");
    scanf("%s", inputFileName);
    printf("Enter the name of the compressed file: ");
    scanf("%s", outputFileName);

    compressFile(inputFileName, outputFileName);

    return 0;
}
