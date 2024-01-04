#ifndef myutils_h
#define myutils_h

#include <stddef.h>

char *myStrcpy(const char *str, size_t len);
int myStrlen(const char *str);
int charCounter(const char *str, char ch);
char *myStrcat(const char *arg1, const char *arg2);
char *myStrchr(char *str, char ch);
char *myStrsplit(const char *start, const char *end);
char **myStrtok(const char *str, char delim);

#endif