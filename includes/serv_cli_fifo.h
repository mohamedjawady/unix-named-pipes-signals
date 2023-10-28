#ifndef SERV_CLI_FIFO
#define SERV_CLI_FIFO

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include "errors.h"

#define FIFO_PERMS 0666
#define NMAX 100
#define FIFO1 "/tmp/fifo1"
#define FIFO2 "/tmp/fifo2"

typedef struct
{
    pid_t pid;
    int n;
} Question;

typedef struct
{
    pid_t pid;
    unsigned int seq_length;
    int sequence[NMAX];
} Reponse;

#endif