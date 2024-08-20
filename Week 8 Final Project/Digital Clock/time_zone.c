#include <string.h>
#include "time_zone.h"

int getTimeZoneOffset(const char *location) {
    if (strcmp(location, "London") == 0) return 1;
    if (strcmp(location, "Berlin") == 0) return +2;
    if (strcmp(location, "Tokyo") == 0) return +9;
    if (strcmp(location, "Sydney") == 0) return +10;
    if (strcmp(location, "Kathmandu") == 0) return +5;
    if (strcmp(location, "New-York") == 0) return -4;
    return -9999;
}

int getMinutesOffset(const char *location) {
    if (strcmp(location, "Kathmandu") == 0) {
        return 45;
    }
    return 0;
}