#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char lines = '0';
    FILE *pFile = NULL;
    if (argc == 3)
    {
        if (argv[1][0] == '-' && argv[1][1] == 'n') 
        {
            lines = '1';
            pFile = fopen(argv[2], "r");
        }
        else if (argv[2][0] == '-' && argv[2][1] == 'n') 
        {
            lines = '1';
            pFile = fopen(argv[1], "r");
        }
        else perror("Couldn't parse arguments");
    }
    else if (argc == 2) pFile = fopen(argv[1], "r");

    if (pFile == NULL)
    {
        perror("ERROR while opening file");
        return -1;
    }
    
    int c, n = 1;
    if (lines == '1')
    {
        printf("%d ", n++);
        while ((c=getc(pFile)) != EOF)
        {
            //  syscall for every single char?
            printf("%c", c);
            if (c == '\n') printf("%d ", n++);
        }
    }
    else 
    {
        while ((c=getc(pFile)) != EOF)
        {
            //  syscall for every single char?
            printf("%c", c);
        }
    }
    

    fclose(pFile);
    return 0;
}