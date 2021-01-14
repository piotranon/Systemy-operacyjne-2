
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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

        dup2(pdesk[0], 0);

        execlp("tr", "tr", "a-z", "A-Z", NULL);

        perror("Blad uruchomienie programu tr.\n");
    }

    return 0;
}