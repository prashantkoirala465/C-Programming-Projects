#ifndef DISPLAY_H
#define DISPLAY_H

#define HEIGHT 7
#define FG_COLOR "\033[1;32m"
#define RESET_COLOR "\033[0m"

void clearScreen();
void displayDigit(int digit, int x, int y);
void displayColon(int x, int y);
void displayAmPm(int isPm, int x, int y);

#endif
