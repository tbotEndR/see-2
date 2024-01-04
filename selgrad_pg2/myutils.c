#include "myutils.h"
#include <stdlib.h>
#include <stdio.h>

//  copies string to new location and returns pointer
char *MyStrcpy(const char *str, size_t len)
{
    char *newStr = (char*) malloc(len);
    for (int i = 0; i < len; i++) newStr[i] = str[i];
    return newStr;
}

//  returns string length including null-byte
int MyStrlen(const char *str)
{
    if (str)
    {
        int i = 0;
        while(str[i]) i++;
        return i+1;
    }
    return 0;    
}

//  returns the number of occurrences of ch in str
int CharCounter(const char *str, char ch)
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
char *MyStrcat(const char *arg1, const char *arg2)
{
    int firstStrLen = MyStrlen(arg1);
    int secondStrLen = MyStrlen(arg2);
    int newStrLen = firstStrLen+secondStrLen-1;
    int i = 0;
    char *newStr = (char*) malloc(newStrLen);
    if (!newStr) abort();

    for (; i < firstStrLen-1; i++)     //  loop terminates at position of arg1's null byte
    {
        newStr[i] = arg1[i];
    }
    for (int n = 0; (i < newStrLen) && (n < secondStrLen); n++)     //  copies nullbyte of arg2 too
    {
        newStr[i] = arg2[n];
        i++;
    }

    return newStr;    
}

//  appends arg2 to arg1 but frees arg1 after concatenation
char *MyStrcatfree(char *arg1, const char *arg2)
{
    int firstStrLen = MyStrlen(arg1);
    int secondStrLen = MyStrlen(arg2);
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
    free(arg1);
    return newStr;    
}

//  returns pointer to first occurrence of c in source
char *MyStrchr(char *str, char ch)
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
char *MyStrsplit(const char *start, const char *end)
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
char **MyStrtok(const char *str, char delim)
{
    int len = MyStrlen(str);
    int words = CharCounter(str, delim)+1;
    char **tokens = (char**) malloc(sizeof(char*) * words);
    char **cursor = tokens;
    char *start = str;
    char *end = NULL;
    while(end = MyStrchr(start, delim))             //  becomes false when myStrchr reaches null byte
    {
        *cursor = MyStrsplit(start, end-1);    //  end-1 to not copy delimiter
        start = end+1;                              //  move start position after last delimiter
        cursor++;
    }                                               
    *cursor = MyStrsplit(start, &str[len-1]);  //  copy final remaining token after last delimiter

    return tokens;    
}

