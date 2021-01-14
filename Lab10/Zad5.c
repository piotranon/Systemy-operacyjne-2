#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

#define MAX 512

int main(int argc, char *argv[])
{
    if (argc < 5)
    {
        fprintf(stderr, "Za malo argumentow. Uzyj:\n");
        fprintf(stderr, "%s <plik zrodlowy> <plik docelowy> <typ kopiowania(znak/slowo/linia)> <ilosc>\n", argv[0]);
        exit(1);
    }
    FILE *in, *out;
    long n = strtol(argv[4], NULL, 10);

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
    if (n < 1)
    {
        perror("Za mała ilosc linii");
        exit(1);
    }
    printf("Plik zrodlowy: %s\n", argv[1]);
    printf("Plik docelowy: %s\n", argv[2]);
    printf("Typ: %s\n", argv[3]);
    printf("Ilosc: %d\n", n);
    if (strstr(argv[3], "linia"))
    {
        int line_total = 1;
        while (!feof(in))
        {
            char ch = fgetc(in);
            if (ch == '\n')
            {
                line_total++;
            }
        }
        char *c;
        int line_count = 0;

        rewind(in);

        int i = 0;
        for (i; i < line_total; i++)
        {
            char napis[MAX], *result;
            c = fgets(napis, MAX, in);
            if (c != NULL && i >= line_total - n)
            {
                fprintf(out, napis, i);
            }
        }
    }
    else if (strstr(argv[3], "znak"))
    {
        long length;
        char ch;
        length = ftell(in);
        fseek(in, (length - n), SEEK_END);
        int i = 0;
        do
        {
            ch = fgetc(in);
            if (ch != EOF)
                putc(ch, out);
        } while (ch != EOF);
    }
    else if (strstr(argv[3], "slowo"))
    {
        // 10 slow po 25 znakow
        char a[10][25];
        char buf[25];
        while (fscanf(in, "%s", buf) != EOF)
        {
            int i = 9;
            for (i; i > 0; i--)
                strcpy(a[i], a[i - 1]);
            strcpy(a[0], buf);
        }

        int i = 9;
        for (i; i >= 0; i--)
        {
            fprintf(out, a[i]);
            putc('\n', out);
        }
    }
    else
    {
        perror("Nieprawidlowy typ kopowania.");
        exit(1);
    }

    fclose(in);
    fclose(out);
}