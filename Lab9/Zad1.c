#include <regex.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    regex_t regex;
    int reti;

    // Kompilacja regexu
    reti = regcomp(&regex, "^Ala ma kot[[:alnum:]]", 0);

    // porownanie wiadomosci z regexem
    reti = regexec(&regex, "Ala ma kota!@##!@FASa1231fa1X", 0, NULL, 0);
    if (!reti)
    {
        puts("Znaleziono lancuch w tekscie");
    }
    else if (reti == REG_NOMATCH)
    {
        puts("Nie znaleziono lancucha w tekscie");
    }
    else
    {
        fprintf(stderr, "Program napotkal blad!\n");
        exit(1);
    }

    regfree(&regex); // zwolnienie pamieci zaalokowanej dla regexu
}
