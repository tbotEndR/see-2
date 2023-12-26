#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int start, end, step;
    if (argc == 3)
    {
        start = atoi(argv[1]);
        step = 1;
        end = atoi(argv[2]);
    }
    else if (argc == 4)
    {
        start = atoi(argv[1]);
        step = atoi(argv[2]);
        end = atoi(argv[3]);
    }

    if (start > end) return -1;
    
    while (start <= end) 
    {
        printf("%d\n", start);
        start += step;
    }    

    return 0;
}