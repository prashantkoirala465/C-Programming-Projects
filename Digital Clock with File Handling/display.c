#include <stdio.h> // For printf() and scanf()

// Constants and function declarations
#define HEIGHT 7 // Height of each digit pattern
#define FG_COLOR "\033[1;32m" // ANSI color code for green
#define RESET_COLOR "\033[0m" // ANSI color code to reset color

void clearScreen(); // Clear the screen
void displayDigit(int digit, int x, int y); // Display a digit at position (x, y)
void displayColon(int x, int y); // Display a colon at position (x, y)
void displayAmPm(int isPm, int x, int y); // Display AM or PM at position (x, y)

// Patterns for digits 0-9
const char *digits[10][HEIGHT] = { // 7x5 patterns for digits 0-9
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
const char *colon[HEIGHT] = { // 7x5 pattern for colon
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
"     ",
"  ▀  ",
"  ▀  ",
"     ",

};



// Patterns for AM using ascii text art
const char *am[HEIGHT] = {
" █████╗ ███╗   ███╗",
"██╔══██╗████╗ ████║",
"███████║██╔████╔██║",
"██╔══██║██║╚██╔╝██║",
"██║  ██║██║ ╚═╝ ██║",
"╚═╝  ╚═╝╚═╝     ╚═╝",
"                   "
};

// Patterns for PM using ascii text art
const char *pm[HEIGHT] = {
"██████╗ ███╗   ███╗",
"██╔══██╗████╗ ████║",
"██████╔╝██╔████╔██║",
"██╔═══╝ ██║╚██╔╝██║",
"██║     ██║ ╚═╝ ██║",
"╚═╝     ╚═╝     ╚═╝",
"                   "
};

void clearScreen() { // Clear the screen
    printf("\033[2J"); // ANSI escape code to clear screen
    printf("\033[H"); // ANSI escape code to move cursor to top left
}

void displayDigit(int digit, int x, int y) { // Display a digit at position (x, y)
    for (int i = 0; i < HEIGHT; i++) { // Loop through each row of the digit pattern
        printf("\033[%d;%dH", y + i, x); // ANSI escape code to move cursor to position (x, y)
        printf("%s%s%s", FG_COLOR, digits[digit][i], RESET_COLOR); // Print the digit pattern with color
    }
}

void displayColon(int x, int y) { // Display a colon at position (x, y)
    for (int i = 0; i < HEIGHT; i++) { // Loop through each row of the colon pattern
        printf("\033[%d;%dH", y + i, x); // ANSI escape code to move cursor to position (x, y)
        printf("%s%s%s", FG_COLOR, colon[i], RESET_COLOR); // Print the colon pattern with color
    }
}

void displayAmPm(int isPm, int x, int y) {// Display AM or PM at position (x, y)
    const char **pattern = isPm ? pm : am; // Select the pattern based on AM or PM
    for (int i = 0; i < HEIGHT; i++) { // Loop through each row of the pattern
        printf("\033[%d;%dH", y + i, x); // ANSI escape code to move cursor to position (x, y)
        printf("%s%s%s", FG_COLOR, pattern[i], RESET_COLOR); // Print the pattern with color
    }
}
