#include <stdio.h>
//Written by: Prashant Koirala
#define HEIGHT 7
#define FG_COLOR "\033[1;32m"
#define RESET_COLOR "\033[0m"

void clearScreen();
void displayDigit(int digit, int x, int y);
void displayColon(int x, int y);
void displayAmPm(int isPm, int x, int y);


const char *digits[10][HEIGHT] = {
    {
        " ██████╗ ",
        "██╔═══██╗",
        "██║   ██║",
        "██║   ██║",
        "██║   ██║",
        "╚██████╔╝",
        " ╚═════╝ "
    },
    {
        " ██╗",
        "███║",
        "╚██║",
        " ██║",
        " ██║",
        " ██║",
        " ╚═╝"
    },
    {
        "██████╗ ",
        "╚════██╗",
        " █████╔╝",
        "██╔═══╝ ",
        "███████╗",
        "╚══════╝",
        "        "
    },
    {
        "██████╗ ",
        "╚════██╗",
        " █████╔╝",
        " ╚═══██╗",
        "██████╔╝",
        "╚═════╝ ",
        "        "
    },
    {
        "██╗  ██╗",
        "██║  ██║",
        "███████║",
        "╚════██║",
        "     ██║",
        "     ╚═╝",
        "        "
    },
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
    },
    {
        "███████╗",
        "╚════██║",
        "    ██╔╝",
        "   ██╔╝ ",
        "  ██╔╝  ",
        "  ╚═╝   ",
        "        "
    },
    {
        " █████╗ ",
        "██╔══██╗",
        "╚█████╔╝",
        "██╔══██╗",
        "╚█████╔╝",
        " ╚════╝ ",
        "        "
    },
    {
        " █████╗ ",
        "██╔══██╗",
        "╚██████║",
        " ╚═══██║",
        " █████╔╝",
        " ╚════╝ ",
        "        "
    }
};


const char *colon[HEIGHT] = {
"    ",
"  ▀ ",
"  ▀  ",
"     ",
"  ▀  ",
"  ▀  ",
"     ",

};




const char *am[HEIGHT] = {
" █████╗ ███╗   ███╗",
"██╔══██╗████╗ ████║",
"███████║██╔████╔██║",
"██╔══██║██║╚██╔╝██║",
"██║  ██║██║ ╚═╝ ██║",
"╚═╝  ╚═╝╚═╝     ╚═╝",
"                   "
};


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
