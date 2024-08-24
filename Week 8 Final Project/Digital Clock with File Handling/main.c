#include <stdio.h>
#include <time.h>
#include <unistd.h>
//Written by: Prashant Koirala


void clearScreen();
void displayDigit(int digit, int x, int y);
void displayColon(int x, int y);
void displayAmPm(int isPm, int x, int y);
int getUserInput(const char *prompt, int min, int max);
void getLocationInput(char *location, size_t size);
int getTimeZoneOffset(const char *location);
int getMinutesOffset(const char *location);
void logUserChoice(const char *name, const char *location, int timeFormat, int displaySeconds);

int main() {
    int timeFormat;
    int displaySeconds;
    char location[50];
    char userName[50];

    clearScreen();
    printf(" __        __   _                            _ \n");
    printf(" \\ \\      / /__| | ___ ___  _ __ ___   ___  | |\n");
    printf("  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | |\n");
    printf("   \\ V  V /  __/ | (_| (_) | | | | | |  __/ |_|\n");
    printf("    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___| (_)\n");
    printf("\nWelcome to the Digital Clock - Made By Prashant!\n");
    printf("Please enter the following details to customize your clock.\n");


    printf("1. Enter your name: ");
    scanf("%s", userName);

    getLocationInput(location, sizeof(location));
    timeFormat = getUserInput("3. Choose time format (12 or 24-hour): ", 12, 24);
    displaySeconds = getUserInput("4. Display seconds? (1 for Yes, 0 for No): ", 0, 1);

    int timeZoneOffset = getTimeZoneOffset(location);
    int minuteOffset = getMinutesOffset(location);


    logUserChoice(userName, location, timeFormat, displaySeconds);


    while (1) {
        clearScreen();

        time_t now = time(NULL);
        struct tm *t = gmtime(&now);


        t->tm_hour += timeZoneOffset;
        t->tm_min += minuteOffset;


        mktime(t);

        int hour = t->tm_hour;
        int minute = t->tm_min;
        int second = t->tm_sec;

        int isPm = 0;
        if (timeFormat == 12) {
            isPm = hour >= 12;
            hour = hour % 12;
            if (hour == 0) hour = 12;
        }


        displayDigit(hour / 10, 10, 5);
        displayDigit(hour % 10, 18, 5);
        displayColon(26, 5);
        displayDigit(minute / 10, 34, 5);
        displayDigit(minute % 10, 42, 5);

        if (displaySeconds) {
            displayColon(50, 5);
            displayDigit(second / 10, 58, 5);
            displayDigit(second % 10, 66, 5);
        }

        if (timeFormat == 12) {
            displayAmPm(isPm, 80, 5);
        }

        fflush(stdout);
        sleep(1);
    }

    return 0;
}
