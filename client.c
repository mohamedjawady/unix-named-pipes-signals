#include "serv_cli_fifo.h"
#include "Handlers_Serv.h"
#include "utils.h"

void hand_response(int sig);

int main(int argc, char *argv[])
{
    pid_t pid = getpid();
    srand(pid);
    signal(SIGUSR1, hand_response);

    // Initialize question
    Question question;
    question.n = (rand() % NMAX);
    question.pid = pid;

    int fd = open(FIFO1, O_WRONLY);
    if (fd == -1)
    {
        errorHandleClient(3);
    }

    write(fd, &question, sizeof(question));

    char displaymsg[50];
    snprintf(displaymsg, 50, "Sent question %d to server", question.n);

    debugMessage(displaymsg);

    close(fd);

    pause();

    return 0;
}

void hand_response(int sig)
{
    debugMessage("Received signal from server");
    Reponse answer;
    int fd = open(FIFO2, O_RDONLY);
    if (fd == -1)
    {
        errorHandleClient(1);
    }

    int status = read(fd, &answer, sizeof(answer));
    if (status == -1)
    {
        errorHandleClient(2);
    }

    printf("--------------------------------- [pid_server:%d] ---------------------------------\n", (int)answer.pid);
    for (int i = 0; i < answer.seq_length; i++)
    {
        printf("answer[%d]: %d\n", i, answer.sequence[i]);
    }

    close(fd);

    debugMessage("Sent final Ack signal to server");
    kill(answer.pid, SIGUSR1);
}