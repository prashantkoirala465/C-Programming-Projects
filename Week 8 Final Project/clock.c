#include <stdio.h>
#include <time.h>
#include <unistd.h>  // For sleep() on Unix systems
#include <stdlib.h>
#include <string.h>

#define WIDTH 5
#define HEIGHT 7

// ANSI escape codes for colors
#define RESET_COLOR "\033[0m"
#define FG_COLOR "\033[1;32m"  // Bright green

// Patterns for digits 0-9
const char *digits[10][HEIGHT] = {
    {
        " ██████╗ ",
        "██╔═══██╗",
        "██║   ██║",
        "██║   ██║",
        "██║   ██║",
        "╚██████╔╝",
        " ╚═════╝ "
    }, // 0
    {
        " ██╗",
        "███║",
        "╚██║",
        " ██║",
        " ██║",
        " ██║",
        " ╚═╝"
    }, // 1
    {
        "██████╗ ",
        "╚════██╗",
        " █████╔╝",
        "██╔═══╝ ",
        "███████╗",
        "╚══════╝",
        "        "
    }, // 2
    {
        "██████╗ ",
        "╚════██╗",
        " █████╔╝",
        " ╚═══██╗",
        "██████╔╝",
        "╚═════╝ ",
        "        "
    }, // 3
    {
        "██╗  ██╗",
        "██║  ██║",
        "███████║",
        "╚════██║",
        "     ██║",
        "     ╚═╝",
        "        "
    }, // 4
    {
        "███████╗",
        "██╔════╝",
        "███████╗",
        "╚════██║",
        "███████║",
        "╚══════╝",
        "        "
    }, // 5
    {
        " ██████╗ ",
        "██╔════╝ ",
        "███████╗ ",
        "██╔═══██╗",
        "╚██████╔╝",
        " ╚═════╝ ",
        "         "
    }, // 6
    {
        "███████╗",
        "╚════██║",
        "    ██╔╝",
        "   ██╔╝ ",
        "  ██╔╝  ",
        "  ╚═╝   ",
        "        "
    }, // 7
    {
        " █████╗ ",
        "██╔══██╗",
        "╚█████╔╝",
        "██╔══██╗",
        "╚█████╔╝",
        " ╚════╝ ",
        "        "
    }, // 8
    {
        " █████╗ ",
        "██╔══██╗",
        "╚██████║",
        " ╚═══██║",
        " █████╔╝",
        " ╚════╝ ",
        "        "
    }  // 9
};

// Pattern for colon
const char *colon[HEIGHT] = {
    // "     ",
    // "  *  ",
    // "  *  ",
    // "     ",
    // "  *  ",
    // "  *  ",
    // "     "
"    ",
"  ▀ ",
"  ▀  ",
"    ",
"  ▀  ",
"  ▀  ",
"    ",

};



// Patterns for AM and PM using '*' instead of '#'
const char *am[HEIGHT] = {
" █████╗ ███╗   ███╗",
"██╔══██╗████╗ ████║",
"███████║██╔████╔██║",
"██╔══██║██║╚██╔╝██║",
"██║  ██║██║ ╚═╝ ██║",
"╚═╝  ╚═╝╚═╝     ╚═╝",
"                   "
};

// Patterns for AM and PM using '*' instead of '#'
const char *pm[HEIGHT] = {
"██████╗ ███╗   ███╗",
"██╔══██╗████╗ ████║",
"██████╔╝██╔████╔██║",
"██╔═══╝ ██║╚██╔╝██║",
"██║     ██║ ╚═╝ ██║",
"╚═╝     ╚═╝     ╚═╝",
"                   "
};

// Function to clear the screen
void clearScreen() {
    printf("\033[2J");
    printf("\033[H");
}

// Function to display a single digit
void displayDigit(int digit, int x, int y) {
    for (int i = 0; i < HEIGHT; i++) {
        printf("\033[%d;%dH", y + i, x);
        printf("%s%s%s", FG_COLOR, digits[digit][i], RESET_COLOR);
    }
}

// Function to display colon
void displayColon(int x, int y) {
    for (int i = 0; i < HEIGHT; i++) {
        printf("\033[%d;%dH", y + i, x);
        printf("%s%s%s", FG_COLOR, colon[i], RESET_COLOR);
    }
}

// Function to display AM/PM
void displayAmPm(int isPm, int x, int y) {
    const char **pattern = isPm ? pm : am;
    for (int i = 0; i < HEIGHT; i++) {
        printf("\033[%d;%dH", y + i, x);
        printf("%s%s%s", FG_COLOR, pattern[i], RESET_COLOR);
    }
}

// Function to get time zone offset based on location
int getTimeZoneOffset(const char *location) {
    // Time zone offsets for some common locations (hours from UTC)
    if (strcmp(location, "London") == 0) return 1;      // GMT
    if (strcmp(location, "Berlin") == 0) return +2;     // CET
    if (strcmp(location, "Tokyo") == 0) return +9;      // JST
    if (strcmp(location, "Sydney") == 0) return +10;    // AEDT
    if (strcmp(location, "Kathmandu") == 0) return +5;  // NPT

    // Default to UTC if location is not found
    return -9999;
}

// Function to get minutes offset for locations with non-integer offsets
int getMinutesOffset(const char *location) {
    if (strcmp(location, "Kathmandu") == 0) {
        return 45;  // NPT is GMT+5:45
    }
    return 0;
}

// Function to validate and get user input for time format
int getUserInput(const char *prompt, int min, int max) {
    int input;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &input) == 1 && (input == min || input == max)) {
            break;
        } else {
            printf("Invalid input. You can only select %d or %d.\n", min, max);
            while (getchar() != '\n');  // Clear the input buffer
        }
    }
    return input;
}

// Function to validate and get location input
void getLocationInput(char *location, size_t size) {
    while (1) {
        printf("1. Enter your location (e.g., Sydney, Berlin, Tokyo, London, Kathmandu): ");
        scanf("%49s", location);

        if (getTimeZoneOffset(location) != -9999) {
            break;
        } else {
            printf("Invalid location. Please enter a valid location.\n");
        }
    }
}

int main() {
    int timeFormat;   // 24-hour or 12-hour format
    int displaySeconds; // Whether to display seconds
    char location[50];

    // Greeting message
    clearScreen();
    printf(" __        __   _                            _ \n");
    printf(" \\ \\      / /__| | ___ ___  _ __ ___   ___  | |\n");
    printf("  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | |\n");
    printf("   \\ V  V /  __/ | (_| (_) | | | | | |  __/ |_|\n");
    printf("    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___| (_)\n");
    printf("\n");
    printf("Digital Clock Made By Prashant!\n\n");

    // Get valid location input
    getLocationInput(location, sizeof(location));

    // Get valid time format input
    timeFormat = getUserInput("2. Enter your time format (24 or 12): ", 12, 24);

    // Get valid display seconds input
    displaySeconds = getUserInput("3. Do you want to display seconds? (0 for No, 1 for Yes): ", 0, 1);

    printf("\nStarting the clock...\n\n");

    int timeZoneOffset = getTimeZoneOffset(location);
    int minuteOffset = getMinutesOffset(location);

    while (1) {
        clearScreen();

        time_t now = time(NULL);
        struct tm *t = gmtime(&now);

        // Adjust time based on time zone offset and minute offset
        t->tm_hour += timeZoneOffset;
        t->tm_min += minuteOffset;

        // Normalize minutes and hours
        mktime(t);  // Automatically adjusts tm_hour, tm_min, and tm_mday if overflow occurs

        int hour = t->tm_hour;
        int min = t->tm_min;
        int sec = t->tm_sec;

        int isPm = 0;
        if (timeFormat == 12) {
            // Convert 24-hour time to 12-hour format
            if (hour >= 12) {
                isPm = 1;
                if (hour > 12) {
                    hour -= 12;
                }
            }
            if (hour == 0) {
                hour = 12;
            }
        }

        // Calculate positions
        int startX = 10;
        int startY = 5;
        int gap = 6;

        // Display hours
        displayDigit(hour / 10, startX, startY);
        displayDigit(hour % 10, startX + (WIDTH + gap), startY);

        // Display colon
        displayColon(startX + 2 * (WIDTH + gap), startY);

        // Display minutes
        displayDigit(min / 10, startX + 2 * (WIDTH + gap) + gap, startY);
        displayDigit(min % 10, startX + 3 * (WIDTH + gap) + gap, startY);

        // Display colon if seconds are to be shown
        if (displaySeconds) {
            displayColon(startX + 4 * (WIDTH + gap) + gap, startY);
        }

        // Display seconds if required
        if (displaySeconds) {
            displayDigit(sec / 10, startX + 4 * (WIDTH + gap) + 2 * gap, startY);
            displayDigit(sec % 10, startX + 5 * (WIDTH + gap) + 2 * gap, startY);
        }

        // Display AM/PM for 12-hour format
        if (timeFormat == 12) {
            displayAmPm(isPm, startX + 6 * (WIDTH + gap) + 3 * gap, startY);
        }

        fflush(stdout);
        sleep(1);
    }

    return 0;
}
