#include <stdio.h>
#include <string.h>
#include <time.h>
#include "util.h"

int getTimeZoneOffset(const char *location) {
    if (strcmp(location, "London") == 0) return 1;
    if (strcmp(location, "Berlin") == 0) return +2;
    if (strcmp(location, "Tokyo") == 0) return +9;
    if (strcmp(location, "Sydney") == 0) return +10;
    if (strcmp(location, "Kathmandu") == 0) return +5;
    return -9999;
}

int getMinutesOffset(const char *location) {
    if (strcmp(location, "Kathmandu") == 0) {
        return 45;
    }
    return 0;
}

void logUserChoice(const char *name, const char *location, int timeFormat, int displaySeconds) {
    FILE *logFile = fopen("clock_log.txt", "a");
    if (logFile == NULL) {
        printf("Error opening log file!\n");
        return;
    }

    time_t now = time(NULL);
    char *timeStr = ctime(&now);
    timeStr[strlen(timeStr) - 1] = '\0';

    fprintf(logFile, "User: %s\n", name);
    fprintf(logFile, "Location: %s\n", location);
    fprintf(logFile, "Time Format: %d-hour\n", timeFormat);
    fprintf(logFile, "Display Seconds: %s\n", displaySeconds ? "Yes" : "No");
    fprintf(logFile, "Timestamp: %s\n", timeStr);
    fprintf(logFile, "----------------------------------------\n");

    fclose(logFile);
}
