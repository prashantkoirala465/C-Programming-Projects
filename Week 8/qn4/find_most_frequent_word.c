#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//Written by: Prashant Koirala
#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;
int main() {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    WordFrequency words[MAX_WORDS] = {0};
    int wordCount = 0, maxFrequency = 0, maxIndex = 0;
    file = fopen("text_file.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    while (fscanf(file, "%s", word) != EOF) {
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].frequency++;
                found = 1;
                break;
            }
        }
        if (!found && wordCount < MAX_WORDS) {
            strcpy(words[wordCount].word, word);
            words[wordCount].frequency = 1;
            wordCount++;
        }
    }
    fclose(file);
    for (int i = 0; i < wordCount; i++) {
        if (words[i].frequency > maxFrequency) {
            maxFrequency = words[i].frequency;
            maxIndex = i;
        }
    }
    printf("The most frequent word is '%s' with a frequency of %d.\n", words[maxIndex].word, words[maxIndex].frequency);
    return 0;
}
