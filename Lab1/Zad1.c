#include<stdio.h>

// Napisz program InputOutput odczytujący z terminala i wypisujący na konsoli kolejno wartości typu: całkowitego, zmienno-przecinkowego float i napis.

void InputOutput()
{
    int int_number;
    printf("Podaj liczbe calkowita : ");
    scanf("%d", &int_number);
    printf("Liczba calkowita : %d\n", int_number);

    float float_number;
    printf("Podaj liczbe zmienno-przecinkowa (float) : ");
    scanf("%f", &float_number);
    printf("Liczba zmienno-przecinkowa (float) : %f\n", float_number);


    // char *test = malloc(20+1);
    // scanf("%[^\n]", test);


    // char *name = "name";
    // char *surname = "surname";
    // char *all = malloc(strlen(name)+strlen(surname)+1);

    // int allindex=0;
    // int nameindex=0;
    // int surnameindex=0;

    // for(nameindex;nameindex<strlen(name);nameindex++)
    // {
    //     all[allindex]=name[nameindex];
    //     allindex++;
    // }    

    // for(surnameindex;surnameindex<strlen(surname);surnameindex++)
    // {
    //     all[allindex]=surname[surnameindex];
    //     allindex++;
    // }

    // all[allindex]='/0';


    // test[i] = '/0';

    char tekst[20];
    printf("Podaj tekst : ");
    scanf("%[^\n]", &tekst);
    printf("Tekst : %s\n", tekst);
}

void Zad_1_1()
{
    // Odczytaj i wypisz na konsoli wartość zmienno-przecinkową typu double.
    double double_number;
    printf("Podaj liczbe zmienno-przecinkowa (double) : ");
    scanf("%lf", &double_number);
    printf("Liczba zmienno-przecinkowa (double) : %lf\n", double_number);
}

void Zad_1_2()
{
    // Odczytaj i wypisz na konsoli cały napis "ala ma kota” przy pomocy funkcji scanf.
    char tekst[20];
    printf("Podaj tekst : ");
    scanf("%[^\n]", &tekst);
    printf("Tekst : %s\n", tekst);
}

void Zad_1_3()
{
    // Odczytaj i wypisz na konsoli cały napis "ala ma kota” przy pomocy funkcji fgets.
    char tekst[20];
    printf("Podaj tekst : ");
    fgets(tekst,20,stdin);
    printf("Tekst : %s\n", tekst);
}

void main()
{
    // InputOutput();
    // Zad_1_1();
    // Zad_1_2();
    // Zad_1_3();
}