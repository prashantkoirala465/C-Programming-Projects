#include <stdio.h> // For FILE, fopen(), fprintf(), fclose()
#include <string.h> // For strcmp(), strlen()
#include <time.h> // For time_t, ctime()

// Function declarations
int getTimeZoneOffset(const char *location); // Get the time zone offset for a location
int getMinutesOffset(const char *location); // Get the minute offset for a location
void logUserChoice(const char *name, const char *location, int timeFormat, int displaySeconds); // Log user choices to a file

int getTimeZoneOffset(const char *location) { // Get the time zone offset for a location
    if (strcmp(location, "London") == 0) return 1; // Return the time zone offset for the location
    if (strcmp(location, "Berlin") == 0) return +2; // Return the time zone offset for the location
    if (strcmp(location, "Tokyo") == 0) return +9; // Return the time zone offset for the location
    if (strcmp(location, "Sydney") == 0) return +10; // Return the time zone offset for the location
    if (strcmp(location, "Kathmandu") == 0) return +5; // Return the time zone offset for the location
    return -9999;
}

int getMinutesOffset(const char *location) { // Get the minute offset for a location
    if (strcmp(location, "Kathmandu") == 0) { // Check if the location is Kathmandu
        return 45; // Return the minute offset for Kathmandu
    }
    return 0;// Return 0 if no offset is needed
}

void logUserChoice(const char *name, const char *location, int timeFormat, int displaySeconds) { // Log user choices to a file
    FILE *logFile = fopen("clock_log.txt", "a"); // Open the log file in append mode
    if (logFile == NULL) { // Check if the file was opened successfully
        printf("Error opening log file!\n"); // Display an error message
        return; // Return from the function
    }

    time_t now = time(NULL); // Get the current time
    char *timeStr = ctime(&now); // Convert the time to a string
    timeStr[strlen(timeStr) - 1] = '\0'; // Remove the newline character at the end

    fprintf(logFile, "User: %s\n", name); // Write user choices to the log file
    fprintf(logFile, "Location: %s\n", location); // Write user choices to the log file
    fprintf(logFile, "Time Format: %d-hour\n", timeFormat); // Write user choices to the log file
    fprintf(logFile, "Display Seconds: %s\n", displaySeconds ? "Yes" : "No"); // Write user choices to the log file
    fprintf(logFile, "Timestamp: %s\n", timeStr); // Write user choices to the log file
    fprintf(logFile, "----------------------------------------\n"); // Write user choices to the log file

    fclose(logFile); // Close the log file
}
