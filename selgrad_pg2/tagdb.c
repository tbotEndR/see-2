// simple commandline tag-database.
// add content: tagdb -a tag1,tag2,...,tagn content
// query by tag: tagdb -q tag1,tag2,...,tagn (matches all tags)

#include <stdio.h>
#include <stdlib.h>

typedef struct Entry{
    char **tags;
    char *content;
} Entry;

enum EFlag{add, query};

Entry *EntryCtor(char *tags, char *content);
void EntryDtor(Entry *entry);
void AddEntry(Entry *entry);
void QueryDatabase(char **tags);
enum EFlag ParseCommand(char *argument);
char **TagListCtor(char *tags);
void TagListDtor(char **query);

int main(int argc, char **argv)
{
        enum EFlag flag;
        FILE *pDatabase;

        if (argv[1]) flag = ParseCommand(argv[1]);
        pDatabase = fopen("path", "r+");
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
                    char **query = TagListCtor(argv[2]);
                    QueryDatabase(query);
                    TagListDtor(query);
                    break;
                }
                
        }
        fclose(pDatabase);

    return 0;
}

Entry *EntryCtor(char *tags, char *content)
{

}
void EntryDtor(Entry *entry)
{

}
void AddEntry(Entry *entry)
{

}
void QueryDatabase(char **tags)
{

}
enum EFlag ParseCommand(char *argument)
{

}
char **TagListCtor(char *tags)
{

}
void TagListDtor(char **query)
{
    
}