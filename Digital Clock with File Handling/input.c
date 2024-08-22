#include <stdio.h> // For printf() and scanf()
#include <string.h> // For strlen()

// Function declarations
int getUserInput(const char *prompt, int min, int max); // Get user input within a range
void getLocationInput(char *location, size_t size); // Get a valid location input
int getTimeZoneOffset(const char *location); // Get the time zone offset for a location
int getMinutesOffset(const char *location); // Get the minute offset for a location

int getUserInput(const char *prompt, int min, int max) { // Get user input within a range
    int input; // User input
    while (1) { // Loop until valid input is entered
        printf("%s", prompt); // Display the prompt
        if (scanf("%d", &input) == 1 && (input == min || input == max)) { // Check if input is valid
            break; // Exit the loop
        } else { // Invalid input
            printf("Invalid input. You can only select %d or %d.\n", min, max); // Display error message
            while (getchar() != '\n');  // Clear the input buffer
        }
    }
    return input; // Return the valid input
}

void getLocationInput(char *location, size_t size) { // Get a valid location input
    while (1) { // Loop until a valid location is entered
        printf("1. Enter your location (e.g., Sydney, Berlin, Tokyo, London, Kathmandu): "); // Display the prompt
        scanf("%49s", location); // Get the location input

        if (getTimeZoneOffset(location) != -9999) { // Check if the location is valid
            break; // Exit the loop
        } else { // Invalid location
            printf("Invalid location. Please enter a valid location.\n"); // Display error message
        }
    }
}
