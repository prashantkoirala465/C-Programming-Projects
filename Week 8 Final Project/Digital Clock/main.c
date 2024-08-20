#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
#include "time_zone.h"
#include "input.h"
#include "digits.h"

void clearScreen() {
    printf("\033[2J");
    printf("\033[H");
}

int main() {
    int timeFormat;
    int displaySeconds;
    char location[50];

    clearScreen();
    printf(" __        __   _                            _ \n");
    printf(" \\ \\      / /__| | ___ ___  _ __ ___   ___  | |\n");
    printf("  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | |\n");
    printf("   \\ V  V /  __/ | (_| (_) | | | | | |  __/ |_|\n");
    printf("    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___| (_)\n");
    printf("\n");
    printf("Digital Clock Made By Prashant!\n\n");

    getLocationInput(location, sizeof(location));
    timeFormat = getUserInput("Enter your time format (24 or 12): ", 12, 24);
    displaySeconds = getUserInput("Do you want to display seconds? (0 for No, 1 for Yes): ", 0, 1);

    printf("\nStarting the clock...\n\n");

    int timeZoneOffset = getTimeZoneOffset(location);
    int minuteOffset = getMinutesOffset(location);

    while (1) {
        clearScreen();

        time_t now = time(NULL);
        struct tm *t = gmtime(&now);

        t->tm_hour += timeZoneOffset;
        t->tm_min += minuteOffset;
        mktime(t);

        int hour = t->tm_hour;
        int min = t->tm_min;
        int sec = t->tm_sec;

        int isPm = 0;
        if (timeFormat == 12) {
            isPm = (hour >= 12);
            hour = hour % 12;
            if (hour == 0) hour = 12;
        }

        int startX = 10, startY = 5, gap = 6;

        displayTime(hour, min, sec, isPm, timeFormat, displaySeconds, startX, startY, gap);

        fflush(stdout);
        sleep(1);
    }

    return 0;
}