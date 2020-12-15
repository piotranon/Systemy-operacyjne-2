#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    printf("Poczatek\n");

    pid_t pid = fork();

    if (pid == 0)
    {
        printf("Proces dziecko, zmienna pid = %d\n", getpid());
        printf("Proces dziecko, zmienna pid rodzica = %d\n", getppid());
    }

    if (pid != 0)
        printf("Proces rodzic, zmienna pid = %d\n", getpid());

    wait(NULL);

    printf("Koniec procesu: %d\n", pid);

    return 0;
}
