#ifndef HANDLERS_SERV
#define HANDLERS_SERV

// handle signal coming from server
void hand_reveil(int sig);

// handle signal 10 coming from client
void fin_conversation(int sig);

// handle other signals
void fin_serveur(int sig);

#endif