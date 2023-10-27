#include "errors.h"

void errorHandleServer(unsigned int err)
{
    switch (err)
    {
    case 1:
        perror("Failed to create fifo1");
        exit(err);
        break;
    case 2:
        perror("Failed to create fifo2");
        exit(err);
        break;
    case 3:
        perror("Failed to open fifo1");
        exit(err);
        break;
    case 4:
        perror("Failed to read from fifo1");
        break;
    case 5:
        perror("Failed to open fifo2");
        break;
    case 6:
        perror("Failed to write to fifo2");
        break;
    default:
        perror("Unexpected Error");
    }
}

void errorHandleClient(unsigned int err)
{
    switch (err)
    {
    case 1:
        perror("Failed to open fifo1");
        exit(err);
        break;
    case 2:
        perror("Failed to read from fifo2");
        exit(err);
        break;
    case 3:
        perror("Failed to open fifo1");
        exit(1);
        break;
    case 4:
        perror("Failed to read from fifo1");
        break;
    case 5:
        perror("Failed to open fifo2");
        break;
    case 6:
        perror("Failed to write to fifo2");
        break;
    default:
        perror("Unexpected Error");
    }
}
