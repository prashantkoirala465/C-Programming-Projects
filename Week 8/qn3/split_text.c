#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile, *outputFile;
    char buffer[256];
    int linesPerFile, lineCount = 0, fileCount = 1;
    char outputFileName[20];
    inputFile = fopen("large_text_file.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    printf("Enter the number of lines per smaller file: ");
    scanf("%d", &linesPerFile);
    sprintf(outputFileName, "output_%d.txt", fileCount);
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error creating output file %s.\n", outputFileName);
        fclose(inputFile);
        return 1;
    }
    while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
        fprintf(outputFile, "%s", buffer);
        lineCount++;
        if (lineCount == linesPerFile) {
            fclose(outputFile);
            fileCount++;
            sprintf(outputFileName, "output_%d.txt", fileCount);
            outputFile = fopen(outputFileName, "w");
            if (outputFile == NULL) {
                printf("Error creating output file %s.\n", outputFileName);
                fclose(inputFile);
                return 1;
            }
            lineCount = 0;
        }
    }
    fclose(outputFile);
    fclose(inputFile);
    printf("File splitting completed. %d files created.\n", fileCount);
    return 0;
}
