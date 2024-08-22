#include "hangman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Read a random word from the file
void readWordFromFile(char word[])
{
    FILE *file = fopen("words.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    int lineCount = 0;
    char buffer[MAX_WORD_LENGTH];

    // Count the number of words in the file
    while (fgets(buffer, MAX_WORD_LENGTH, file))
    {
        lineCount++;
    }

    // Select a random word
    int randomLine = rand() % lineCount;

    // Go back to the beginning of the file and get the random word
    rewind(file);
    for (int i = 0; i <= randomLine; i++)
    {
        fgets(word, MAX_WORD_LENGTH, file);
    }

    // Remove newline character from the word
    word[strcspn(word, "\n")] = 0;

    fclose(file);
}

// Display the current state of the word
void displayWord(const char word[], const int guessedLetters[])
{
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (guessedLetters[word[i] - 'a'])
        {
            printf("%c ", word[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\n");
}

// Draw the hangman based on the number of tries
void drawHangman(int tries)
{
    const char *hangmanParts[] = {
        "     _______",
        "    |         |",
        "    |         O",
        "    |        /|\\",
        "    |        / \\",
        "    |"};

    for (int i = 0; i <= tries; i++)
    {
        printf("%s\n", hangmanParts[i]);
    }
}