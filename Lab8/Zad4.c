#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    printf("Poczatek\n");

    pid_t pid = fork();

    if (pid == 0)
        printf("Proces dziecko, zmienna pid = %d\n", pid);

    if (pid != 0)
        printf("Proces rodzic, zmienna pid = %d\n", pid);

    printf("getpid = %d\n", getpid());

    wait(NULL);

    printf("Koniec procesu: %d\n", pid);

    return 0;
}
