#ifndef myutils_h
#define myutils_h

void myStrcpy(char *destination, const char *source);
int myStrlen(const char *str);
int charCounter(const char *str, char ch);
char *myStrcat(const char *arg1, const char *arg2);
char *myStrchr(char *str, char ch);
char *myStrsplit(const char *str, char *start, char *end);
char **myStrtok(const char *str, char delim);

#endif