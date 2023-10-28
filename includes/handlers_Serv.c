#include "Handlers_Serv.h"
#include "utils.h"

void fin_conversation(int sig)
{
    debugMessage("Received signal from client, waking up...");
    printf("----------------------------------------------------------\n");
    fflush(stdout);
}

void fin_serveur(int sig)
{
    char msg[50];
    sprintf(msg, "Received signal %d", sig);
    debugMessage(msg);
    printf("Shutting down...\n");
    printf("----------------------------------------------------------\n");
    fflush(stdout);
    exit(sig);
}