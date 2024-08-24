#include <stdio.h>
#include <string.h>
//Written by: Prashant Koirala
int getUserInput(const char *prompt, int min, int max);
void getLocationInput(char *location, size_t size);
int getTimeZoneOffset(const char *location);
int getMinutesOffset(const char *location);

int getUserInput(const char *prompt, int min, int max) {
    int input;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &input) == 1 && (input == min || input == max)) {
            break;
        } else {
            printf("Invalid input. You can only select %d or %d.\n", min, max);
            while (getchar() != '\n');
        }
    }
    return input;
}

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
