#include <stdio.h>
#include "CircularBuffer.h"

int main()
{
    printf("Hello World!\n");

    CircularBuffer buff;

    CircularInit(&buff);

    if(!CircularEmpty(&buff))
    {
        printf("upo\n");
        int c = CircularGet(&buff);
    }

    CircularPut(&buff, 1);
    CircularPut(&buff, 2);
    int a = CircularGet(&buff);
    int b = CircularGet(&buff);
    if(!CircularEmpty(&buff))
    {
        int c = CircularGet(&buff);
    }

    CircularPut(&buff, 3);
    CircularPut(&buff, 2);
    if(!CircularFull(&buff))
    {
        printf("upo\n");
        CircularPut(&buff, 1);
    }

    if(!CircularFull(&buff))
    {
        printf("upo\n");
        CircularPut(&buff, 1);
    }

    CircularDump(&buff);

    CircularDelete(&buff);

    return 0;
}
