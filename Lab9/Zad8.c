#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
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
        pdesk = open("/tmp/fifo", O_WRONLY);

        if (pdesk == -1)
        {
            perror("Blad otwarcia potoku do zapisu./n");
            exit(1);
        }

        if (write(pdesk, "Hallo!", 7) == -1)
        {
            perror("Blad zapisu do potoku.\n");
            exit(1);
        }

        exit(0);
    }

    if (pid > 0)
    {
        pdesk = open("/tmp/fifo", O_RDONLY);

        if (pdesk == -1)
        {
            perror("Blad otwarcia potoku do odczytu.\n");
            exit(1);
        }

        char buf[10];

        if (read(pdesk, buf, 10) == -1)
        {
            perror("Blad odczytu z potoku.\n");
            exit(1);
        }

        printf("Odczytano z potoku: %s\n", buf);
    }

    return 0;
}