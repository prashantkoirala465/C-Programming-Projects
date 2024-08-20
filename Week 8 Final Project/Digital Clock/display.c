#include <stdio.h>
#include "display.h"
#include "digits.h"

void displayDigit(int digit, int x, int y) {
    if (digit < 0 || digit > 9) {
        printf("Error: Invalid digit %d\n", digit);
        return;
    }
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

void displayTime(int hour, int min, int sec, int isPm, int timeFormat, int displaySeconds, int startX, int startY, int gap) {
    displayDigit(hour / 10, startX, startY);
    displayDigit(hour % 10, startX + (WIDTH + gap), startY);
    displayColon(startX + 2 * (WIDTH + gap), startY);
    displayDigit(min / 10, startX + 2 * (WIDTH + gap) + gap, startY);
    displayDigit(min % 10, startX + 3 * (WIDTH + gap) + gap, startY);

    if (displaySeconds) {
        displayColon(startX + 4 * (WIDTH + gap) + gap, startY);
        displayDigit(sec / 10, startX + 4 * (WIDTH + gap) + 2 * gap, startY);
        displayDigit(sec % 10, startX + 5 * (WIDTH + gap) + 2 * gap, startY);
    }

    if (timeFormat == 12) {
        displayAmPm(isPm, startX + 6 * (WIDTH + gap) + 3 * gap, startY);
    }
}