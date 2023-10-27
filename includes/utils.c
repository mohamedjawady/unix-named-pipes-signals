#include "utils.h"

void debugMessage(char *message)
{
#ifdef DEBUG
    printf("[DBG] %s\n", message);
    fflush(stdout);
#endif
}