#ifndef DISPLAY_H
#define DISPLAY_H

void displayDigit(int digit, int x, int y);
void displayColon(int x, int y);
void displayAmPm(int isPm, int x, int y);
void displayTime(int hour, int min, int sec, int isPm, int timeFormat, int displaySeconds, int startX, int startY, int gap);

#endif