#ifndef HANGMAN_H
#define HANGMAN_H

#define MAX_WORD_LENGTH 50
#define MAX_TRIES 6

// Function declarations
void readWordFromFile(char word[]);
void displayWord(const char word[], const int guessedLetters[]);
void drawHangman(int tries);

#endif // HANGMAN_H