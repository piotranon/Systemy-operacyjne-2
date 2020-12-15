#include <stdio.h>
#include <stdlib.h>

int main()
{
    if (fork() == 0)
    {
        printf("child pid = %d\n", getpid());
        exit(0);
    }
    sleep(20);

    wait(NULL);

    exit(0);
}
