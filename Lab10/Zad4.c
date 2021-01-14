#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

#define MAX 512

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Za malo argumentow. Uzyj:\n%s <plik zrodlowy> <plik docelowy>\n", argv[0]);
        exit(1);
    }
    FILE *in, *out;

    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w");

    if (in == NULL)
    {
        perror("Blad otwarcia pliku odczytu");
        exit(1);
    }
    if (out == NULL)
    {
        perror("Blad otwarcia pliku zapisu");
        exit(1);
    }
    printf("Plik zrodlowy: %s\n", argv[1]);
    printf("Plik docelowy: %s\n", argv[2]);

    char *c;

    while (!feof(in))
    {
        char napis[MAX];
        c = fgets(napis, MAX, in);
        if (c != NULL)
        {
            fputs(strrev(c), out);
        }
    }

    fclose(in);
    fclose(out);
}