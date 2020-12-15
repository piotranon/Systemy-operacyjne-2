#include <stdio.h>
#include <stdlib.h>

int main()
{
    if (fork() == 0)
    {
        printf("child pid = %d\n", getpid());

        sleep(20);

        exit(0);
    }

    exit(0);
}
