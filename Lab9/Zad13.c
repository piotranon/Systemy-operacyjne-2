#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int pdesk[2];

    pipe(pdesk);

    pid_t pid = fork();

    if (pid == 0)
        write(pdesk[1], "Piotr", 7);

    wait(NULL);

    pid_t pid2 = fork();

    if (pid2 == 0)
    {
        char buf[10];

        read(pdesk[0], buf, 10);

        printf("Odczytano z potoku: %s\n", buf);
    }

    wait(NULL);

    pid_t pid3 = fork();
    if (pid3 == 0)
        write(pdesk[1], "Dlugosz", 7);

    wait(NULL);

    if (pid2 == 0)
    {
        char buf[10];

        read(pdesk[0], buf, 10);

        printf("Odczytano z potoku: %s\n", buf);
        exit(1);
    }

    return 0;
}