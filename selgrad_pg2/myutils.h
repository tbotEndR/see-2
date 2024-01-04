#ifndef myutils_h
#define myutils_h

#include <stddef.h>

char *MyStrcpy(const char *str, size_t len);
int MyStrlen(const char *str);
int CharCounter(const char *str, char ch);
char *MyStrcat(const char *arg1, const char *arg2);
char *MyStrcatfree(char *arg1, const char *arg2);
char *MyStrchr(char *str, char ch);
char *MyStrsplit(const char *start, const char *end);
char **MyStrtok(const char *str, char delim);

#endif