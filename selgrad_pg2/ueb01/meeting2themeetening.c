//  a greeting program. expects terminal parameters ./prog "firstname lastname identifier(m/f/*)"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct name {
    char *vorname, *nachname, anrede;
} name;

typedef struct node {
    struct node *next;
    name *data;
}node;

int MyStrLen(const char *name);
char* MyStringSplit(const char *input, int startIndex, int endIndex);
int FindChar(const char *input, char c);
void teilnehmer(name *name);

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        /*
        //  version using array
        name *nameArr = (name*) malloc(sizeof(name) * (argc-1));
        assert(nameArr != NULL);
        for (int i = 1; i < argc; i++)
        {
            int nameLen = MyStrLen(argv[i]);
            nameArr[i-1].vorname = MyStringSplit(argv[i], 0, FindChar(argv[i], ' ')-1);
            nameArr[i-1].nachname = MyStringSplit(argv[i], FindChar(argv[i], ' ')+1, nameLen-3);  // -4 for \0, m/f/* and ' '
            nameArr[i-1].anrede = argv[i][nameLen-1];
        }

        for (int i = 0; i < argc-1; i++)
        {
            teilnehmer(nameArr[i]);
        }

        for (int i = 0; i < argc-1; i++)
        {
            free(nameArr[i].vorname);
            free(nameArr[i].nachname);
        }
        free(nameArr);
        */

        //  version using linked list
        node *names = NULL;

        for (int i = 1; i < argc; i++)
        {
            node *newNode = (node*) malloc(sizeof(node));
            newNode->data = (name*) malloc(sizeof(name));
            int nameLen = MyStrLen(argv[i]);
            newNode->data->vorname = MyStringSplit(argv[i], 0, FindChar(argv[i], ' ')-1);
            newNode->data->nachname = MyStringSplit(argv[i], FindChar(argv[i], ' ')+1, nameLen-3);
            newNode->data->anrede = argv[i][nameLen-1];
            newNode->next = names;
            names = newNode;
        }

        node *head = names;
        for (node *run = names; run; run = run->next)
        {
            teilnehmer(run->data);
        }

        names = head;
        while(names != NULL)
        {
            node *tmp = names->next;
            free(names->data->vorname);
            free(names->data->nachname);
            free(names->data);
            free(names);
            names = tmp;
        }

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

// prints first names of each name struct in passed array
void teilnehmer(name *name)
{
    switch(name->anrede)
    {
        case 'm':
            printf("Hallo Herr %s\n", name->nachname);
            break;
        case 'f':
            printf("Hallo Frau %s\n", name->nachname);
            break;
        case '*':
            printf("Hallo %s\n", name->vorname);
            break;
    }
}