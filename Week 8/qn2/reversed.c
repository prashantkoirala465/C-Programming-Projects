#include <stdio.h>
#include <stdlib.h>
//Written by: Prashant Koirala
int main() {
    FILE *inputFile, *outputFile;
    long fileSize;
    char *buffer;
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    outputFile = fopen("reversed_output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }
    fseek(inputFile, 0, SEEK_END);
    fileSize = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);
    buffer = (char*)malloc(fileSize + 1);
    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        fclose(inputFile);
        fclose(outputFile);
        return 1;
    }
    fread(buffer, 1, fileSize, inputFile);
    for (long i = fileSize - 1; i >= 0; i--) {
        fputc(buffer[i], outputFile);
    }
    free(buffer);
    fclose(inputFile);
    fclose(outputFile);
    printf("The content of the file has been reversed and saved to 'reversed_output.txt'.\n");
    return 0;
}
