#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int glowny_proces = getpid();
    printf("\n");
    int i;
    for (i = 0; i < 2; i++)
    {
        pid_t pid = fork();
        if (pid == 0)
        {
            pid_t pid2 = fork();
            if (pid2 == 0)
            {
                printf("Proces[%d] rodzic = %d, dziecko = %d, potomek = %d\n", i, glowny_proces, getppid(), getpid());
                exit(0);
            }
            wait(NULL);
            exit(0);
        }
        wait(NULL);
    }
    return 0;
}
