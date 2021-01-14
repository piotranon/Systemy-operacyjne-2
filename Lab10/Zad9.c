#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define MAX 512

void main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Nie poprawne wywołanie. \nUzyj:%s <plik 1> <plik 2>\n", argv[0]);
        exit(1);
    }

    FILE *one, *two;
    one = fopen(argv[1], "r");
    two = fopen(argv[2], "r");

    if (one == NULL)
    {
        perror("Blad otwarcia pliku1 odczytu");
        exit(1);
    }
    if (two == NULL)
    {
        perror("Blad otwarcia pliku2 odczytu");
        exit(1);
    }

    int niepoprawne = 0;
    int linia = 0;
    int znakwlini = 0;
    int roznicaznakow = 0;

    int onel = ftell(one);
    int twol = ftell(two);

    if (onel > twol)
        while (!feof(one))
        {
            char ch1 = fgetc(one);
            char ch2 = fgetc(two);
            if (ch1 == '\n')
            {
                linia++;
                znakwlini = 0;
            }
            else
                znakwlini++;

            if (ch1 != ch2)
            {
                if (ch1 == EOF)
                {
                    niepoprawne = 2;
                    roznicaznakow++;
                }
                else if (ch2 == EOF)
                {
                    niepoprawne = 3;
                    roznicaznakow++;
                }
                else
                    niepoprawne = 1;
            }
        }
    else
        while (!feof(two))
        {
            char ch1 = fgetc(one);
            char ch2 = fgetc(two);
            if (ch2 == '\n')
            {
                linia++;
                znakwlini = 0;
                // printf("znak=0\n");
            }
            else
            {
                znakwlini++;
                // printf("znak++\n");
            }

            if (ch1 != ch2)
            {
                if (ch1 == EOF)
                {
                    niepoprawne = 2;
                    roznicaznakow++;
                }
                else if (ch2 == EOF)
                {
                    niepoprawne = 3;
                    roznicaznakow++;
                }
                else
                {
                    // printf("%c - %c\n", ch1, ch2);
                    niepoprawne = 1;
                    // printf("break\n");
                    break;
                }
            }
        }

    fclose(one);
    fclose(two);

    if (niepoprawne == 1)
        printf("Pliki roznia sie od znaku %d w lini %d.\n", znakwlini, linia);
    else if (niepoprawne == 2)
        printf("Plik %s zawiera o %d znakow wiecej od pliku %s\n", argv[2], roznicaznakow, argv[1]);
    else if (niepoprawne == 3)
        printf("Plik %s zawiera o %d znakow wiecej od pliku %s\n", argv[1], roznicaznakow, argv[2]);
    else
        printf("Plik sa identyczne\n");

    return;
}