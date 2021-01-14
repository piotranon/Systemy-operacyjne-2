
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int pdesk;

    if (mkfifo("/tmp/fifo", 0600) == -1)
    {
        perror("Blad tworzenia kolejki FIFO.\n");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == -1)
    {
        perror("Blad tworzenia procesu potomnego.\n");
        exit(1);
    }

    if (pid == 0)
    {
        close(1);

        pdesk = open("/tmp/fifo", O_WRONLY);

        if (pdesk == -1)
        {
            perror("Blad otwarcia potoku do zapisu.\n");
            exit(1);
        }

        if (pdesk != 1)
        {
            perror("Niewlasciwy deskryptor do zapisu.\n");
            exit(1);
        }

        execvp("ls", argv);

        perror("Blad uruchmienia programu.\n");
        exit(1);
    }

    if (pid > 0)
    {
        close(0);

        pdesk = open("/tmp/fifo", O_RDONLY);

        if (pdesk == -1)
        {
            perror("Blad otwarcia potoku do odczytu.\n");
            exit(1);
        }

        if (pdesk != 0)
        {
            perror("Niewlasciwy deskryptor do odczytu.\n");
            exit(1);
        }

        execlp("tr", "tr", "a-z", "A-Z", NULL);

        perror("Blad uruchomienia programu tr.\n");
    }

    return 0;
}