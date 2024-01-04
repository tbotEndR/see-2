// simple commandline tag-database.
// add content: tagdb -a tag1,tag2,...,tagn content
// query by tag: tagdb -q tag1,tag2,...,tagn (matches all tags)

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "myutils.h"

typedef struct Entry{
    char *content;
    char **tags;
    int t;          //  until I figure out a better way to store tag array size for freeing
} Entry;

enum EFlag{add, query};
char *g_filePath = "/home/ce_lab/.mytagdb";

Entry *EntryCtor(char *tags, char *content);
void EntryDtor(Entry *entry);
void AddEntry(Entry *entry);
void QueryDatabase(char **tags);
enum EFlag ParseCommand(char *argument);

int main(int argc, char **argv)
{
        enum EFlag flag;
        FILE *pDatabase;

        if (argv[1]) flag = ParseCommand(argv[1]);
        pDatabase = fopen(g_filePath, "r+");
        if (pDatabase == NULL)
        {
            perror("Error opening database");
            return -1;
        }
        switch (flag)
        {
            case add:
                if (argc == 4)
                {
                    Entry *newEntry = EntryCtor(argv[2], argv[3]);
                    AddEntry(newEntry);
                    EntryDtor(newEntry);
                    break;
                }
            case query:
                if (argc == 3)
                {
                    //QueryDatabase(query);
                    break;
                }
                
        }
        fclose(pDatabase);

    return 0;
}

Entry *EntryCtor(char *tags, char *content)
{
    Entry *newEntry = (Entry*) malloc(sizeof(Entry));
    newEntry->tags = myStrtok(tags, ',');
    newEntry->t = charCounter(tags, ',')+1;      
    newEntry->content = myStrcpy(content, myStrlen(content));
    return newEntry;
}

void EntryDtor(Entry *entry)
{
    for (int i = 0; i < entry->t; i++)
    {
        free(entry->tags[i]);
    }
    free(entry->tags);
    free(entry->content);
    free(entry);
}

void AddEntry(Entry *entry)
{
    printf("Hello from inside the new entry!\n");
    printf("%s: ", entry->content);
    for(int i = 0; i < entry->t; i++)
    {
        printf("%s ", entry->tags[i]);
    }
    printf("\n");
}

void QueryDatabase(char **tags)
{

}

enum EFlag ParseCommand(char *argument)
{
    if (argument[0] == '-')
    {
        if (argument[1] == 'a') return add;
        else if (argument[1] == 'q') return query;
    }
}