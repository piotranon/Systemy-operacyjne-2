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
void main()
{
    int a, b;
    // printf("a= ");
    // scanf("%d", &a);
    // printf("b= ");
    // scanf("%d", &b);
    // printf("\n");

    a = 9237;
    b = 1267;

    if (b > a)
    {
        int temp = b;
        b = a;
        a = temp;
    }
    if (a < 0 || b < 0)
    {
        printf("no operation on negative numbers");
        return;
    }
    int val = a + b;

    int aSize = (int)floor(log10(abs(a))) + 1;
    int bSize = (int)floor(log10(abs(b))) + 1;
    int valSize = (int)floor(log10(abs(val))) + 1;

    int maxSize = valSize < 2 ? 2 : valSize;

    int i = 0;

    char *transferred = malloc(maxSize + 1);

    for (i = 0; i < bSize; i++)
    {
        int v;
        if (i == 0 || transferred[i - 1] == ' ')
            v = getdigit(b, i) + getdigit(a, i);
        else
            v = getdigit(b, i) + getdigit(a, i) + transferred[i - 1] - '0';

        if (v >= 10)
            transferred[i] = ((v / 10) + '0');
        else
            transferred[i] = ' ';
    }
    for (i; i < maxSize; i++)
    {
        transferred[i] = ' ';
    }
    transferred[i] = '\0';

    strrev(transferred);

    printf("%s\n", transferred);

    // print a
    for (i = 0; i < maxSize - aSize + 1; i++)
        printf(" ");
    printf("%d\n", a);

    // print b
    printf("+");
    for (i = 0; i < maxSize - bSize; i++)
        printf(" ");
    printf("%d\n", b);

    // print ---------
    for (i = 0; i < maxSize + 1; i++)
        printf("-");
    printf("\n");

    // print val
    for (i = 0; i < maxSize - valSize + 1; i++)
        printf(" ");
    printf("%d", val);
}