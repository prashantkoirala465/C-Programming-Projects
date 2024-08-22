#include "hangman.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // The word to guess
    char secretWord[MAX_WORD_LENGTH];
    readWordFromFile(secretWord);

    int wordLength = strlen(secretWord);
    int guessedLetters[26] = {0}; // Array to track guessed letters
    int tries = 0;

    printf("Welcome to Hangman!\n");

    // Game loop
    while (tries < MAX_TRIES)
    {
        printf("\n");
        displayWord(secretWord, guessedLetters);
        drawHangman(tries);

        // Get user input
        char guess;
        printf("Enter a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        // Check if letter has been guessed before
        if (guessedLetters[guess - 'a'])
        {
            printf("You've already guessed that letter. Try again.\n");
            continue;
        }

        guessedLetters[guess - 'a'] = 1;

        // Check if the guessed letter is in the word
        int found = 0;
        for (int i = 0; i < wordLength; i++)
        {
            if (secretWord[i] == guess)
            {
                found = 1;
            }
        }

        // If the letter wasn't found, increment tries
        if (!found)
        {
            tries++;
            printf("Incorrect guess!\n");
        }

        // Check if the whole word is guessed
        int wordGuessed = 1;
        for (int i = 0; i < wordLength; i++)
        {
            if (!guessedLetters[secretWord[i] - 'a'])
            {
                wordGuessed = 0;
                break;
            }
        }

        if (wordGuessed)
        {
            printf("\nCongratulations! You've guessed the word: %s\n", secretWord);
            break;
        }
    }

    if (tries >= MAX_TRIES)
    {
        printf("\nSorry, you've run out of tries. The word was: %s\n", secretWord);
    }

    return 0;
}