#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <regex.h>

#define MAX 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Nie poprawne wywołanie. \nUzyj:%s <plik zrodlowy>\n", argv[0]);
        exit(1);
    }
    FILE *in;
    in = fopen(argv[1], "r");

    if (in == NULL)
    {
        perror("Blad otwarcia pliku odczytu");
        exit(1);
    }

    regex_t regex;
    int reti;

    // Kompilacja regexu
    reti = regcomp(&regex, "[A-Za-z0-9_]", 0);

    char ch;
    int isasci = 1;
    int wordAmount = 1;

    do
    {
        ch = fgetc(in);
        // porownanie char z regexem
        reti = regexec(&regex, &ch, 0, NULL, 0);
        if (ch != EOF)
            if (reti == REG_NOMATCH)
                wordAmount++;
    } while (ch != EOF);

    printf("Ilosc slow: %d", wordAmount);

    regfree(&regex); // zwolnienie pamieci zaalokowanej dla regexu
}