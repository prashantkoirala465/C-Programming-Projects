#include <stdio.h>
#include "display.h"

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
"     ",
"  ▀  ",
"  ▀  ",
"     ",

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


void clearScreen() {
    printf("\033[2J");
    printf("\033[H");
}

void displayDigit(int digit, int x, int y) {
    for (int i = 0; i < HEIGHT; i++) {
        printf("\033[%d;%dH", y + i, x);
        printf("%s%s%s", FG_COLOR, digits[digit][i], RESET_COLOR);
    }
}

void displayColon(int x, int y) {
    for (int i = 0; i < HEIGHT; i++) {
        printf("\033[%d;%dH", y + i, x);
        printf("%s%s%s", FG_COLOR, colon[i], RESET_COLOR);
    }
}

void displayAmPm(int isPm, int x, int y) {
    const char **pattern = isPm ? pm : am;
    for (int i = 0; i < HEIGHT; i++) {
        printf("\033[%d;%dH", y + i, x);
        printf("%s%s%s", FG_COLOR, pattern[i], RESET_COLOR);
    }
}
