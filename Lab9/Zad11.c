#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX 512

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
        wait(NULL);

        pdesk = open("/tmp/fifo", O_RDONLY);

        char buf[MAX];
        int lb, i;

        while ((lb = read(pdesk, buf, MAX)) > 0)
        {
            for (i = 0; i < lb; i++)
                buf[i] = toupper(buf[i]);

            if (write(1, buf, lb) == -1)
            {
                perror("Blad zapisu na standardowe wyjscie.\n");
                exit(1);
            }
        }

        if (lb == -1)
        {
            perror("Blad odczytu z potoku.\n");
            exit(1);
        }
    }

    return 0;
}