#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pdesk[2];

    pipe(pdesk);

    pid_t pid = fork();

    if (pid == 0)
        write(pdesk[1], "Hallo!", 7);

    if (pid > 0)
    {
        char buf[10];

        read(pdesk[0], buf, 10);
        read(pdesk[0], buf, 10);

        printf("Odczytano z potoku: %s\n", buf);
    }

    return 0;
}