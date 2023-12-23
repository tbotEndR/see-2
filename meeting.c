#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct {
    char *vorname, *nachname;
} name;

int MyStrLen(const char *name);
char* MyStringSplit(const char *input, int startIndex, int endIndex);
int FindChar(const char *input, char c);

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        name *nameArr = (name*) malloc(sizeof(name) * (argc-1));
        assert(nameArr != NULL);
        for (int i = 1; i < argc; i++)
        {
            nameArr[i-1].vorname = MyStringSplit(argv[i], 0, FindChar(argv[i], ' '));
            nameArr[i-1].nachname = MyStringSplit(argv[i], 0, FindChar(argv[i], ' '));
        }

        for (int i = 0; i < argc-1; i++)
        {
            printf("Hallo, %s\n", nameArr[i].vorname);
        }

        for (int i = 0; i < argc-1; i++)
        {
            free(nameArr[i].vorname);
            free(nameArr[i].nachname);
        }
        free(nameArr);
    }
    return 0;
}

//  returns the length of the string (including \0 byte)
int MyStrLen(const char *name)
{
    assert(name != NULL);
    int n = 0;
    while (name[n] != '\0') n++;
    return n;
}

//  returns new substring beginning at startIndex and ending at endIndex
char* MyStringSplit(const char *input, int startIndex, int endIndex)
{
    assert((input != NULL));
    int newStringSize = endIndex-startIndex+2;
    char *newString = (char*) malloc(sizeof(char) * newStringSize);
    int newStrIndex = 0;   
    for(int oldStrIndex = startIndex; oldStrIndex <= endIndex; )
    {
        newString[newStrIndex++] = input[oldStrIndex++];
    }
    newString[newStrIndex] = '\0';
    return newString;
}

//  returns first occurrence of char c
int FindChar(const char *input, char c)
{
    assert((input != NULL));
    int n = 0;
    while (input[n] != '\0')
    {
        if (input[n] == c) break;
        n++;
    }
    return n;
}
