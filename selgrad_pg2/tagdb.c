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
void AddEntry(Entry *entry, FILE *db);
void QueryDatabase(char **tags);
enum EFlag ParseCommand(char *argument);
char *EntryFormatter(Entry *entry);

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
                    AddEntry(newEntry, pDatabase);
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
    newEntry->tags = MyStrtok(tags, ',');
    newEntry->t = CharCounter(tags, ',')+1;      
    newEntry->content = MyStrcpy(content, MyStrlen(content));
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

void AddEntry(Entry *entry, FILE *db)
{
    char *entryStr = EntryFormatter(entry);
    fwrite(entryStr, sizeof(entryStr[0]), MyStrlen(entryStr), db);
    free(entryStr);
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

//  returns entry contents formatted for writing to database
char *EntryFormatter(Entry *entry)
{
    char *contentFormat = MyStrcpy("Content:", MyStrlen("Content:"));
    contentFormat = MyStrcatfree(contentFormat, entry->content);
    contentFormat = MyStrcatfree(contentFormat, ",");

    char *tagFormat = MyStrcpy("{tags:[", MyStrlen("{tags:["));
    for (int i = 0; i < entry->t; i++)
    {
        tagFormat = MyStrcatfree(tagFormat, entry->tags[i]);
        tagFormat = MyStrcatfree(tagFormat, ",");
    }
    tagFormat = MyStrcatfree(tagFormat, "]}");
    contentFormat = MyStrcatfree(contentFormat, tagFormat);
    free(tagFormat);
    return contentFormat;
}