#include <stdio.h>
#include <stdlib.h>

#define TYPE int
#define BUFF_SIZE 4

typedef struct CircularBuffer
{
  TYPE* data;
  TYPE* head;
  TYPE* tail;
} CircularBuffer;

void CircularInit(CircularBuffer* buff)
{
    buff->data = (TYPE*) malloc(BUFF_SIZE*sizeof(TYPE));
    buff->head = buff->data;
    buff->tail = buff->data;
}

void CircularPut(CircularBuffer *buff, TYPE value)
{
    *(buff->tail) = value;

    if(buff->tail - buff->data == BUFF_SIZE-1)
    {
        buff->tail = buff->data;
    }
    else
    {
        buff->tail++;
    }
}

TYPE CircularGet(CircularBuffer *buff)
{
    TYPE ret = *(buff->head);

    if(buff->head - buff->data == BUFF_SIZE-1)
    {
        buff->head = buff->data;
    }
    else
    {
        buff->head++;
    }

    return ret;
}

void CircularDump(CircularBuffer *buff)
{
    int i;

    TYPE* begin = buff->head;

    while(begin != buff->tail)
    {
        printf("%d ", *begin);

        if(begin == buff->data+BUFF_SIZE-1)
        {
            begin = buff->data;
        }
        else
        {
            begin++;
        }
    }
    printf("\n");
}

int CircularEmpty(CircularBuffer *buff)
{
    int diff = buff->head - buff->tail;

    if(diff < 0)
    {
        diff += BUFF_SIZE;
    }

    if(diff == 1 || diff == 0)
        return 1;
    else
        return 0;
}

int CircularFull(CircularBuffer *buff)
{
    int diff = buff->tail - buff->head;

    if(diff < 0)
    {
        diff += BUFF_SIZE;
    }

    if(diff == BUFF_SIZE-1)
        return 1;
    else
        return 0;
}

void CircularDelete(CircularBuffer* buff)
{
    free(buff->data);
    buff->head = NULL;
    buff->tail = NULL;
}
