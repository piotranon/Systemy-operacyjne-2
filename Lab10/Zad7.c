#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        perror("Za malo plików (conajmniej 2)");
        fprintf(stderr, "Poprawne uzycie: %s <plik zrodlowy> <plik zrodlowy2> .... <plik docelowy>\n", argv[0]);
        exit(1);
    }

    FILE *out;
    out = fopen(argv[argc - 1], "w");

    if (out == NULL)
    {
        perror("Blad otwarcia pliku do zapisu");
        exit(1);
    }
    int i = 1;
    for (i; i < argc; i++)
    {
        FILE *in = fopen(argv[i], "r");
        if (in == NULL)
        {
            fprintf(stderr, "Blad pliku: %s\n", argv[i]);
            exit(1);
        }
        else
        {
            while (!feof(in))
            {
                char ch = fgetc(in);
                if (ch != EOF)
                    putc(ch, out);
                else
                    putc('\n', out);
            }
        }
        fclose(in);
    }
    fclose(out);

    printf("Ukonczono");
}