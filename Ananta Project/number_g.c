#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Function to generate a hard number (prime number)
int generateHardNumber() {
    int num;
    do {
        num = rand() % 100 + 1; // Generate a random number between 1 and 100
    } while (!isPrime(num));   // Ensure it's a prime number
    return num;
}

void provideHint(int level, int correctAnswer, int position, int* sequence, int size) {
    printf("Hint: ");
    if (level == 1) {
        printf("The sequence is an arithmetic sequence.\n");
    } else if (level == 2) {
        printf("The sequence is based on the division of a number and adjusted by position.\n");
    } else if (level == 3) {
        printf("The sequence follows a pattern based on prime numbers.\n");
    }
}

void playGame(int tries, int correctAnswer, int position, int* sequence, int size) {
    int guess, attempts = 0;
    int correct = 0;
    int hintProvided = 0;

    printf("Guess the missing number in the sequence:\n");

    // Print the sequence with a dash for the missing number
    for (int i = 0; i < size; i++) {
        if (i == position) {
            printf("- ");
        } else {
            printf("%d ", sequence[i]);
        }
    }
    printf("\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess == correctAnswer) {
            printf("Congratulations! You guessed the number correctly in %d attempts.\n", attempts);
            correct = 1;
            break;
        } else {
            if (attempts == tries / 2 && !hintProvided) {
                provideHint(tries / 2, correctAnswer, position, sequence, size);
                hintProvided = 1;
            }
            printf("Incorrect! You have %d attempts left.\n", tries - attempts);
        }
    } while (attempts < tries);

    if (!correct) {
        printf("Sorry, you ran out of attempts. The correct number was %d.\n", correctAnswer);
    }
}

int main() {
    int level, tries;
    int correctAnswer;
    int position;
    int sequence[5];

    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Number Guessing Game with Levels!\n");
    printf("Choose your difficulty level:\n");
    printf("1. Easy (6 tries)\n");
    printf("2. Medium (4 tries)\n");
    printf("3. Hard (2 tries)\n");
    printf("Enter your choice: ");
    scanf("%d", &level);

    switch (level) {
        case 1:
            tries = 6;
            correctAnswer = rand() % 10 + 1; // Simple random number between 1 and 10
            position = rand() % 5; // Random position to hide the number
            for (int i = 0; i < 5; i++) {
                sequence[i] = correctAnswer + i - position;
            }
            break;
        case 2:
            tries = 4;
            correctAnswer = (rand() % 10 + 1) * (rand() % 10 + 1); // Product of two numbers between 1 and 10
            position = rand() % 5; // Random position to hide the number
            for (int i = 0; i < 5; i++) {
                sequence[i] = (correctAnswer / (i + 1)) + position; // Create a more complex sequence
            }
            break;
        case 3:
            tries = 2;
            correctAnswer = generateHardNumber(); // Generate a hard-to-guess prime number
            position = rand() % 5; // Random position to hide the number
            for (int i = 0; i < 5; i++) {
                sequence[i] = correctAnswer + (i * (i + 1)); // Create a sequence based on a more complex pattern
            }
            break;
        default:
            printf("Invalid choice! Exiting the game.\n");
            return 0;
    }

    // Start the game
    playGame(tries, correctAnswer, position, sequence, 5);

    printf("Thanks for playing! Goodbye.\n");
    return 0;
}
