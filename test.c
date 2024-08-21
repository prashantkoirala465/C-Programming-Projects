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

// Function to log user choices
void logUserChoice(const char *name, const char *location, int timeFormat, int displaySeconds) {
    FILE *logFile = fopen("clock_log.txt", "a");  // Open in append mode
    if (logFile == NULL) {
        printf("Error opening log file!\n");
        return;
    }

    time_t now = time(NULL);
    char *timeStr = ctime(&now);  // Get current time as string
    timeStr[strlen(timeStr) - 1] = '\0';  // Remove newline character

    fprintf(logFile, "User: %s\n", name);
    fprintf(logFile, "Location: %s\n", location);
    fprintf(logFile, "Time Format: %d-hour\n", timeFormat);
    fprintf(logFile, "Display Seconds: %s\n", displaySeconds ? "Yes" : "No");
    fprintf(logFile, "Timestamp: %s\n", timeStr);
    fprintf(logFile, "----------------------------------------\n");

    fclose(logFile);  // Close the file
}

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
