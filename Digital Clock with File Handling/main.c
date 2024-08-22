#include <stdio.h> // For printf() and scanf()
#include <time.h> // For time_t, time(), gmtime(), and struct tm
#include <unistd.h> // For sleep()

// Function declarations
void clearScreen(); // Clear the screen
void displayDigit(int digit, int x, int y); // Display a digit at position (x, y)
void displayColon(int x, int y); // Display a colon at position (x, y)
void displayAmPm(int isPm, int x, int y); // Display AM or PM at position (x, y)
int getUserInput(const char *prompt, int min, int max); // Get user input within a range
void getLocationInput(char *location, size_t size); // Get a valid location input
int getTimeZoneOffset(const char *location); // Get the time zone offset for a location
int getMinutesOffset(const char *location); // Get the minute offset for a location
void logUserChoice(const char *name, const char *location, int timeFormat, int displaySeconds); // Log user choices to a file

int main() {
    int timeFormat;   // 24-hour or 12-hour format
    int displaySeconds; // Whether to display seconds
    char location[50]; // Location name
    char userName[50]; // User name

    // Greeting message
    clearScreen();
    printf(" __        __   _                            _ \n");
    printf(" \\ \\      / /__| | ___ ___  _ __ ___   ___  | |\n");
    printf("  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | |\n");
    printf("   \\ V  V /  __/ | (_| (_) | | | | | |  __/ |_|\n");
    printf("    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___| (_)\n");
    printf("\nWelcome to the Digital Clock - Made By Prashant!\n");
    printf("Please enter the following details to customize your clock.\n");

    // Get user inputs
    printf("1. Enter your name: "); // Display the prompt
    scanf("%s", userName); // Get the user name

    getLocationInput(location, sizeof(location)); // Get the location input
    timeFormat = getUserInput("3. Choose time format (12 or 24-hour): ", 12, 24); // Get the time formats
    displaySeconds = getUserInput("4. Display seconds? (1 for Yes, 0 for No): ", 0, 1); // Get the display seconds choice

    int timeZoneOffset = getTimeZoneOffset(location); // Get the time zone offset for the location
    int minuteOffset = getMinutesOffset(location); // Get the minute offset for the location

    // Save user choices to log file
    logUserChoice(userName, location, timeFormat, displaySeconds); // Log user choices to a file

    // Main loop
    while (1) {
        clearScreen(); // Clear the screen

        time_t now = time(NULL); // Get the current time
        struct tm *t = gmtime(&now); // Convert to the UTC time

        // Adjust time based on time zone offset and minute offset
        t->tm_hour += timeZoneOffset; // Adjust hours based on time zone offset
        t->tm_min += minuteOffset; // Adjust minutes based on minute offset

        // Normalize minutes and hours
        mktime(t);  // Normalize the time structure

        int hour = t->tm_hour; // Get the current hour
        int minute = t->tm_min; // Get the current minute
        int second = t->tm_sec; // Get the current seconds

        int isPm = 0; // Flag to indicate if it's PM
        if (timeFormat == 12) { // If 12-hour format
            isPm = hour >= 12; // Set the PM flag
            hour = hour % 12; // Convert to 12-hour format
            if (hour == 0) hour = 12; // Handle midnight
        }

        // Display the clock digits with gaps
        displayDigit(hour / 10, 10, 5);  // Digit 1 of hour
        displayDigit(hour % 10, 18, 5);  // Digit 2 of hour
        displayColon(26, 5);             // Colon
        displayDigit(minute / 10, 34, 5); // Digit 1 of minute
        displayDigit(minute % 10, 42, 5); // Digit 2 of minute

        if (displaySeconds) {
            displayColon(50, 5);          // Colon before seconds
            displayDigit(second / 10, 58, 5); // Digit 1 of second
            displayDigit(second % 10, 66, 5); // Digit 2 of second
        }

        if (timeFormat == 12) {
            displayAmPm(isPm, 80, 5); // AM/PM indicator
        }

        fflush(stdout); // Flush the output buffer
        sleep(1);  // Sleep for 1 second
    }

    return 0;
}
