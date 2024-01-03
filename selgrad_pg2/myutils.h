#ifndef myutils_h
#define myutils_h

void myStrcpy(char *destination, const char *source);
int myStrlen(const char* source);
char *myStrcat(const char *arg1, const char *arg2);
char *myStrchr(const char c, const char *source);
char *myStrtok(char *str, const char token);

#endif