#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

int losuj(int a, int b)
{
    return a + rand() % (b - a);
}

int wariacje1()
{

    int one = ('z' - 'a' + 1) + ('Z' - 'A' + 1) + ('9' - '0' + 1) + 1 + 1;
    int two = one * one;

    return two;
}

int wariacje2()
{
    int i_max = ('z' - 'a' + 1) + ('Z' - 'A' + 1) + ('9' - '0' + 1) + 1 + 1;
    int i, j, z;
    int ilosc = 0;

    for (i = 0; i < i_max; i++)
        for (j = 0; j < i_max; j++)
            ilosc++;

    return ilosc;
}

void errnoExample()
{

    FILE *plik = fopen("plik.txt", "rw");
    if (!plik)
    {
        _get_errno(&errno);

        if (errno == 2)
        {

            printf("\nErrno: Nie znaleziono pliku\n");
        }
        else if (errno == 1)
        {

            printf("\nErrno:Brak uprawnienien\n");
        }
    }
    else
    {
        puts("plik otwart pomyslnie");
        fclose(plik);
    }

    return;
}

void perrorExample()
{

    FILE *plik = fopen("plik.txt", "rw");

    if (plik == NULL)
    {
        perror("plik.txt");
    }
    else
    {
        puts("plik otwart pomyslnie");
        fclose(plik);
    }
    return;
}

void set(char salt[2])
{
    int one = ('z' - 'a' + 1) + ('Z' - 'A' + 1) + ('9' - '0' + 1) + 1 + 1;

    char tab[one];
    int i = 0;

    int j;

    for (j = 'a'; j <= 'z'; j++)
    {
        tab[i] = j;
        i++;
    }

    for (j = 'A'; j <= 'Z'; j++)
    {
        tab[i] = j;
        i++;
    }

    for (j = '0'; j <= '9'; j++)
    {
        tab[i] = j;
        i++;
    }

    tab[i] = '.';
    i++;
    tab[i] = '/';

    salt[0] = tab[losuj(0, one)];
    salt[1] = tab[losuj(0, one)];
}

void main()
{
    srand(time(0)); //initzialization of pseudo rand
    printf("Liczba wylosowana: %d\n", losuj(0, 20));
    printf("wariacje1: %d\n", wariacje1());
    printf("wariacje2: %d\n", wariacje2());

    errnoExample();
    perrorExample();

    char salt[2];
    set(salt);
    printf("%c%c\n", salt[0], salt[1]);

    return;
}
