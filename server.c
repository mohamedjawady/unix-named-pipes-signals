#include "serv_cli_fifo.h"
#include "Handlers_Serv.h"
#include "utils.h"

void fin_serveur(int sig)
{
    debugMessage("Received signal from client");
    printf("Client request processed\n");
    printf("----------------------------------------------------------\n");
    fflush(stdout);
}

int main(int argc, char **argv, char **envp)
{
    pid_t pid = getpid();
    signal(SIGUSR1, fin_serveur);
    srand(pid);
    int fd, fd2;

    Question question;
    Reponse answer;

    char *fifo1 = FIFO1;
    if (access(fifo1, F_OK) == -1)
    {

        if (mkfifo(fifo1, 0666) == -1)
        {
            errorHandleServer(1);
        }
        debugMessage("Fifo1 created");
    }
    else
    {
        debugMessage("Fifo1 already exists");
    }

    char *fifo2 = FIFO2;
    if (access(fifo2, F_OK) == -1)
    {
        if (mkfifo(fifo2, 0666) == -1)
        {
            errorHandleServer(2);
        }
        debugMessage("Fifo2 created");
    }
    else
    {
        debugMessage("Fifo2 Already Exists");
    }
    printf("listening for requests...\n");
    while (1)
    {
        fflush(stdout);
        fd = open(fifo1, O_RDONLY);
        if (fd == -1)
        {
            errorHandleServer(3);
        }
        if (read(fd, &question, sizeof(question)) == -1)
        {
            errorHandleServer(4);
            close(fd);
        }
        printf("Request Received: [pid_client:%d, question:%d]\n", (int)question.pid, question.n);

        answer.pid = pid;
        answer.seq_length = question.n;
        for (int i = 0; i < question.n; i++)
        {
            answer.sequence[i] = rand();

            char output[20];
            sprintf(output, "answer[%d]:%d", i, answer.sequence[i]);
            debugMessage(output);
        }

        close(fd);
        kill(question.pid, SIGUSR1);
        debugMessage("Sent Signal to client");
        fd2 = open(fifo2, O_WRONLY);
        if (fd2 == -1)
        {
            errorHandleServer(5);
        }
        if (write(fd2, &answer, sizeof(answer)) == -1)
        {
            errorHandleServer(6);
            close(fd2);
        }
        debugMessage("Answer generated and sent via fifo2");
        close(fd2);
    }
}
