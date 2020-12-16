#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/*Function to return the digit of n-th position of num. Position starts from 0*/
int getdigit(int num, int n)
{
    int r;

    r = num / pow(10, n);

    r = r % 10;

    return r;
}
void multiply(unsigned int a, unsigned int b)
{
    if (a < 0 || b < 0)
    {
        printf("no operation on negative numbers.");
        return;
    }
    printf("\n");

    // a = 57;
    // b = 372;

    if (b > a)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    // printf("\nXd: %d\n", getdigit(a, 0));
    unsigned int value = a * b;

    int aSize = (int)floor(log10(abs(a))) + 1;
    int bSize = (int)floor(log10(abs(b))) + 1;
    int valueSize = (int)floor(log10(abs(value))) + 1;

    int i;

    // char *transferred[10];

    // foreach number in b[i] we are multiplying it by all a numbers one by one
    // and adding it to corresponding string pointer if > 10
    if (bSize > 1)
    {

        char **transferred = (char **)calloc(bSize, sizeof(char *));
        for (i = bSize - 1; i >= 0; i--)
        {
            // printf("i:%d\n", i);
            transferred[i] = (char *)calloc(valueSize + 1, sizeof(char));
            // printf("i:%d\n", i);
            int j;
            for (j = 0; j < aSize; j++)
            {
                // printf("j:%d\n", j);

                int multiplied;
                if (j == 0 || transferred[i][j] == ' ')
                {
                    multiplied = getdigit(b, i) * getdigit(a, j);
                    // printf("%d * %d = %d\n", getdigit(b, i), getdigit(a, j), multiplied);
                }
                else
                {
                    multiplied = getdigit(b, i) * getdigit(a, j) + (transferred[i][j - 1] != ' ' ? transferred[i][j - 1] - '0' : 0);
                    // printf("%d * %d + %d = %d : .%c.\n", getdigit(b, i), getdigit(a, j), (transferred[i][j - 1] != ' ' ? transferred[i][j - 1] - '0' : 0), multiplied, transferred[i][j - 1]);
                }

                if (multiplied > 10)
                {
                    // printf("dodanie : .%c.\n", ((multiplied / 10) + '0'));
                    transferred[i][j] = ((multiplied / 10) + '0');
                }
                else
                {
                    // printf("dodanie : .%c.\n", ' ');
                    transferred[i][j] = ' ';
                }
                // printf("b,i:%d\na,j:%d\ntransf:.%c.\n", getdigit(b, i), getdigit(a, j), transferred[i][j - 1]);
                // printf("j:%d m:%d\n", j, multiplied);
            }
            // printf("i:%d\n", i);

            for (j; j < valueSize + 1; j++)
                transferred[i][j] = ' ';
            // printf("i:%d\n", i);

            transferred[i][j] = '\0';

            strrev(transferred[i]);
            printf("%s\n", transferred[i]);
        }
    }

    //print a
    for (i = 0; i < valueSize - aSize + 2; i++)
        printf(" ");
    printf("%d\n", a);

    // print * b
    printf("*");
    for (i = 0; i < valueSize - bSize + 1; i++)
        printf(" ");
    printf("%d\n", b);

    //print ------
    for (i = 0; i < (valueSize + 2 < 3 ? 3 : valueSize + 2); i++)
        printf("-");
    printf("\n");

    if (bSize > 1)
    {
        // print numbers to add
        for (i = 0; i < bSize; i++)
        {
            int j;
            int val = getdigit(b, i) * a;
            int valSize = (int)floor(log10(abs(val))) + 1;

            if (val != 0)
            {
                if (i == bSize - 1)
                    printf("+");
                else
                    printf(" ");

                for (j = 0; j < valueSize - valSize + 1 - i; j++)
                    printf(" ");

                printf("%d\n", val);
            }
        }

        // prints --------
        for (i = 0; i < valueSize + 2; i++)
            printf("-");
        printf("\n");
    }

    printf("  %d", value);
    return;
    // printf("\n\n\na: %d\nb: %d\nvalue: %d\naSize: %d\nbSize: %d\nvalueSize: %d", a, b, value, aSize, bSize, valueSize);
}
void main()
{
    int a, b;
    printf("a= ");
    scanf("%d", &a);
    printf("b= ");
    scanf("%d", &b);
    printf("\n");

    multiply(a, b);
    // multiply(20, 10);
    // multiply(0, 0);
    // printf("\n\n");
    // multiply(12, 2);
    // printf("\n\n");
    // multiply(372, 57);
    // printf("\n\n");
    // multiply(999, 73);
    // printf("\n\n");
    // multiply(9999, 42);
    // printf("\n\n");
    // multiply(99999, 88);
    // printf("\n\n");
    // multiply(999999, 123); tu w przykładzie wywala błąd (zle wypisuje gorne przesuniecia)
    // printf("\n\n");
    // multiply(54321, 1234);
    // printf("\n\n");
    // multiply(9999999, 88);
    // printf("\n\n");
    // multiply(99999999, 88);
    // printf("\n\n");
    // multiply(999999999, 88);
    // multiply(3456, 4567);  tu w przykładzie wywala błąd (zle wartosci u gory 4*7=28 powinno byc 2 przniesione 8 zapisane,w przykładzie 3 przeniesione 8 zapisane, w [3 mnozeniu * 1 liczba])
}