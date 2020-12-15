#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Poczatek\n");
    pid_t pid = fork();
    if (pid == -1) {
        perror("Blad tworzenia procesu potomnego.");
        return 1;
    }
    if (pid == 0) {
        execlp("ls", "ls", "-l", NULL);
        perror("Blad uruchmienia programu.");
        exit(1);
    }
    if (wait(NULL) == -1)
        perror("Blad w oczekiwaniu na zakonczenie potomka.");
    printf("Koniec\n");

    return 0;
}
