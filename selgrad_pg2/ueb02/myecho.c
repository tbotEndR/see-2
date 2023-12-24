#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc == 1) return 0;

    for (int i = 1; i < argc; i++)
    {
        printf("%s ", argv[i]);
    }   

    if (argv[1][0] != '-' || argv[1][1] != 'n') printf("\n");

    return 0;
}