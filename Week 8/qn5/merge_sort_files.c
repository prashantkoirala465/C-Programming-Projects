#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Written by: Prashant Koirala
#define MAX_LINES 1000
#define MAX_LINE_LENGTH 256
int compareFirstWord(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s output_file input_file1 input_file2 ...\n", argv[0]);
        return 1;
    }
    char *outputFileName = argv[1];
    char *lines[MAX_LINES];
    int lineCount = 0;
    for (int i = 2; i < argc; i++) {
        FILE *inputFile = fopen(argv[i], "r");
        if (inputFile == NULL) {
            printf("Error opening file %s.\n", argv[i]);
            continue;
        }
        while (fgets(lines[lineCount] = malloc(MAX_LINE_LENGTH), MAX_LINE_LENGTH, inputFile)) {
            lineCount++;
        }
        fclose(inputFile);
    }
    qsort(lines, lineCount, sizeof(char *), compareFirstWord);
    FILE *outputFile = fopen(outputFileName, "w");
    for (int i = 0; i < lineCount; i++) {
        fputs(lines[i], outputFile);
        free(lines[i]);
    }
    fclose(outputFile);
    printf("Files merged and sorted into %s.\n", outputFileName);
    return 0;
}
