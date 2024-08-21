#ifndef UTIL_H
#define UTIL_H

int getTimeZoneOffset(const char *location);
int getMinutesOffset(const char *location);
void logUserChoice(const char *name, const char *location, int timeFormat, int displaySeconds);

#endif
