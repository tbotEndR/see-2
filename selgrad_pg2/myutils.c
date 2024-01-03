#include "myutils.h"
#include <stdlib.h>
#include <stdio.h>

//  copies source string into destination buffer (no check for overflows)
void myStrcpy(char *destination, const char *source)
{
    int i = 0;
    while (source[i])
    {
        destination[i] = source[i];
        i++;
    }
}

//  returns string length including null-byte
int myStrlen(const char *source)
{
    int i = 0;
    while(source[i]) i++;
    return i+1;
}

//  returns the number of occurrences of ch in str
int charCounter(const char *str, char ch)
{
    char *cursor = str;
    int occ = 0;
    while(*cursor != '\0')
    {
        if (*cursor == ch) occ++;
        cursor++;
    }
    return occ;
}

//  appends arg2 to arg1
char *myStrcat(const char *arg1, const char *arg2)
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

//  returns pointer to first occurrence of c in source
char *myStrchr(char *str, char ch)
{
    char *cursor = str;
    while(*cursor != '\0')
    {
        if (*cursor == ch) return cursor;
        cursor++;
    }
    return NULL;
}

//  returns substring beginning at str[start] to str[end]
char *myStrsplit(const char *str, char *start, char *end)
{
    if (!(start && end)) return NULL;
    int newStrLen = abs(end-start)+2;   //  +2 for char at str[end] and null byte
    char *newStr = (char*) malloc(newStrLen);
    if (!newStr) perror("Error allocating memory");
    for (int i = 0; (i < newStrLen) && (start <= end); i++)
    {
        newStr[i] = *start++;
    }
    newStr[newStrLen-1] = '\0';
    return newStr;
}

//  returns an array of substrings between delimiter
char **myStrtok(const char *str, char delim)
{
    int len = myStrlen(str);
    int words = charCounter(str, delim);
    char **tokens = (char**) malloc(sizeof(char*) * words);
    char **cursor = tokens;
    char *start = str;
    char *end = NULL;
    while(end = myStrchr(start, delim))             //  becomes false when myStrchr reaches null byte
    {
        *cursor = myStrsplit(str, start, end-1);    //  end-1 to not copy delimiter
        start = end+1;                              //  move start position after last delimiter
        cursor++;
    }                                               
    *cursor = myStrsplit(str, start, &str[len-1]);  //  copy final remaining token after last delimiter

    return tokens;    
}

