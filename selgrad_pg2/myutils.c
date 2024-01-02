#include "myutils.h"
#include <stdlib.h>
#include <stdio.h>

//  copies source string into destination buffer (no check for overflows)
void myStrcpy(char *destination, char *source)
{
    int i = 0;
    while (source[i])
    {
        destination[i] = source[i];
        i++;
    }
    
}

//  returns string length including null-byte
int myStrlen(char *source)
{
    int i = 0;
    while(source[i]) i++;
    return i+1;
}

//  appends arg2 to arg1
char *myStrAppend(char *arg1, char *arg2)
{
    int firstStrLen = myStrlen(arg1);
    int secondStrLen = myStrlen(arg2);
    int newStrLen = firstStrLen+secondStrLen-1;
    int i = 0;
    char *newStr = (char*) malloc(newStrLen);
    if (!newStr) abort();

    for (; i < firstStrLen-1; i++)     //  loop terminates at position of arg1's null byte
    {
        newStr[i] = arg1[i];
    }
    for (int n = 0; (i < newStrLen) && (n < secondStrLen); n++)
    {
        newStr[i] = arg2[n];
        i++;
    }
    newStr[i] = '\0';

    return newStr;    
}