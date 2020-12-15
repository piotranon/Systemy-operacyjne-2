#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Poczatek\n");

    execlp("ls", "ls", "-l", NULL);

    printf("Koniec\n");

    return 0;
}
