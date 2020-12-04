#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int cyfry1(int num)
{
    int count = (int)floor(log10(abs(num))) + 1;
}

int cyfry2(int num)
{
    return snprintf(NULL, 0, "%d", num) - (num < 0);
}

int cyfry3(int num)
{
    int count = 0;
    while (num != 0)
    {
        num /= 10;
        ++count;
    }
    return count;
}

void main()
{
    printf("cyfry1(-3579) = %d",cyfry1(-3579));
    printf("\ncyfry2(-3579) = %d",cyfry2(-3579));
    printf("\ncyfry3(-3579) = %d",cyfry3(-3579));
}