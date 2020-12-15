#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    for (i = 0; i < 3; i++)
    {
        if (fork() == 0)
        {
            printf("child [%d] pid = %d\n", i, getpid());
            exit(0);
        }
    }
    sleep(5);

    wait(NULL);

    printf("Koniec");
}
