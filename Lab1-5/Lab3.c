#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

struct Fraction {
    int num, den;
};

/*
a/b + c/d = (a*d + c*b) / (b*d)
*/
struct Fraction sum(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;
    
    int c = y.num;
    int d = y.den;
    
    struct Fraction z;
    
    z.num = a*d + c*b;
    z.den = b*d;
    
    return z;
}
/*
a/b - c/d = (a*d - c*b) / (b*d)
*/
struct Fraction subtract(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;
    
    int c = y.num;
    int d = y.den;
    
    struct Fraction z;
    
    z.num = a*d - c*b;
    z.den = b*d;
    
    return z;
}
/*
a/b * c/d = (a*c) / (b*d)
*/
struct Fraction multiplicate(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;
    
    int c = y.num;
    int d = y.den;
    
    struct Fraction z;
    
    z.num = a*c;
    z.den = b*d;
    
    return z;
}
/*
a/b : c/d = (a*d) / (b*c)
*/
struct Fraction division(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;
    
    int c = y.num;
    int d = y.den;
    
    struct Fraction z;
    
    z.num = a*d;
    z.den = b*c;
    
    return z;
}
struct Fraction doMagic(struct Fraction x)
{
    struct Fraction y;
    
    y.num = x.num;
    y.den = x.den;

    int a = y.num;
    int b = y.den;
    //jezeli mian < 0 a licznik > 0 to odwroc znaki
    if(a>0)
    {
        if(b<0)
        {
            a=-a;
            b=-b;
        }
    }
    //jezeli mian jest podzielny przez licznik podziel
    if(a!=-1)
        if(b%a==0)
        {
            b=b/a;
            a=1;
        }

    if(a%b==0)
    {
        a=a/b;
        b=1;
    }
    y.num=a;
    y.den=b;

    return y;
}


void print(struct Fraction x){
    
    int a = x.num;
    int b = x.den;
    
    if(b==0)
    {
        printf("(struct Fraction){%d,%d} -> NaN\n",a,b);
        return;
    }

    if(a==0)
    {
        printf("(struct Fraction){%d,%d} -> 0\n",a,b);
        return;
    }

    struct Fraction y = doMagic(x);

    if(y.den==1)
    {
        printf("(struct Fraction){%d,%d} -> %d\n",a,b,y.num);
        return;
    }
    if(abs(y.num)>y.den)
    {
        int whole = y.num/y.den;
        int c=y.num;
        int d=y.den;

        if(c<0)
        {
            c+=abs(whole)*d;
        }else
        {
            c-=abs(whole)*d;
        }
        
        printf("(struct Fraction){%d,%d} -> %d %d/%d\n",a,b,whole,abs(c),abs(d));
        return;
    }
    printf("(struct Fraction){%d,%d} -> %d/%d\n",a,b,y.num,y.den);
    return;
}

void testPrint()
{
    struct Fraction x1 = {2, 0};
    struct Fraction x2 = {0, 2};
    struct Fraction x3 = {2, 4};
    struct Fraction x4 = {-1, 2};
    struct Fraction x5 = {1, -2};
    struct Fraction x6 = {4, -2};
    struct Fraction x7 = {5, -2};

    print(x1);
    print(x2);
    print(x3);
    print(x4);
    print(x5);
    print(x6);
    print(x7);
}

// biblioteka stdbool.h
bool isNumber(char s[])
{
    int len=0;
    
    while (s[len] != '\0')
        len++;

    for (int i = 0; i < len; i++)
    {
        if (i==0 && s[i]=='-')
        {
        }else
        if (isdigit(s[i]) == false)
        {
            return false;
        }
    }
 
    return true;
}

void main() {
    // struct Fraction x = {2, 3};
    // struct Fraction y = {1, 4};
    
    // struct Fraction z = sum(x, y);
    
    // printf("%d/%d + %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, z.num, z.den);



    char input1[20],input2[20];
    int number1,number2;

    printf("Podaj licznik: ");

    while(1)
    {
        gets(input1);

        if(isNumber(input1))
            break;

        printf("Podales bledna liczbe sprobuj ponownie : ");
    }
    number1 = atoi(input1);

    printf("Podaj mianownik: ");

    while(1)
    {
        gets(input2);

        if(isNumber(input2))
            break;

        printf("Podales bledna liczbe sprobuj ponownie : ");
    }
    number2 = atoi(input2);

    struct Fraction test;
    test.num = number1;
    test.den = number2;

    print(test);

    // testPrint();

    // print(x);

    // system("pause");
}