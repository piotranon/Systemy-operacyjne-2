#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX 512

int main(int argc, char *argv[])
{
    int pdesk[2];

    if (pipe(pdesk) == -1)
    {
        perror("Blad tworzenia potoku.\n");
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
        dup2(pdesk[1], 1);

        execvp("ls", argv);

        perror("Blad uruchomienie programu ls.\n");
        exit(1);
    }

    if (pid > 0)
    {
        close(pdesk[1]);

        wait(NULL);

        char buf[MAX];
        int lb, i;

        while ((lb = read(pdesk[0], buf, MAX)) > 0)
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