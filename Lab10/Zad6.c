#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

#define MAX 512

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Za malo argumentow. Uzyj:\n");
        fprintf(stderr, "%s <plik zrodlowy>\n", argv[0]);
        exit(1);
    }
    FILE *in;

    in = fopen(argv[1], "r");

    if (in == NULL)
    {
        perror("Blad otwarcia pliku odczytu");
        exit(1);
    }
    printf("Plik zrodlowy: %s\n", argv[1]);

    char ch;
    int isasci = 1;
    do
    {
        ch = fgetc(in);
        if (ch != EOF)
            if (isascii(ch) == 0)
                isasci = 0;
    } while (ch != EOF);

    if (isasci == 1)
    {
        printf("%s jest plikiem tekstowym", argv[1]);
    }
    else
    {
        printf("%s Nie jest plikiem tekstowym\n", argv[1]);
        printf("nieporawny znak : %c", ch);
    }

    fclose(in);
}