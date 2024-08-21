#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "display.h"
#include "input.h"
#include "util.h"

int main() {
    int timeFormat;   // 24-hour or 12-hour format
    int displaySeconds; // Whether to display seconds
    char location[50];
    char userName[50];

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
    printf("1. Enter your name: ");
    scanf("%s", userName);

    getLocationInput(location, sizeof(location));
    timeFormat = getUserInput("3. Choose time format (12 or 24-hour): ", 12, 24);
    displaySeconds = getUserInput("4. Display seconds? (1 for Yes, 0 for No): ", 0, 1);

    int timeZoneOffset = getTimeZoneOffset(location);
    int minuteOffset = getMinutesOffset(location);

    // Save user choices to log file
    logUserChoice(userName, location, timeFormat, displaySeconds);

    // Main loop
    while (1) {
        clearScreen();

        time_t now = time(NULL);
        struct tm *t = gmtime(&now);

        // Adjust time based on time zone offset and minute offset
        t->tm_hour += timeZoneOffset;
        t->tm_min += minuteOffset;

        // Normalize minutes and hours
        mktime(t);  // Normalize the time structure

        int hour = t->tm_hour;
        int minute = t->tm_min;
        int second = t->tm_sec;

        int isPm = 0;
        if (timeFormat == 12) {
            isPm = hour >= 12;
            hour = hour % 12;
            if (hour == 0) hour = 12;
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
            displayAmPm(isPm, 74, 5); // AM/PM indicator
        }

        fflush(stdout);
        sleep(1);  // Sleep for 1 second
    }

    return 0;
}
