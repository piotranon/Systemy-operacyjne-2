#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
//Zad.1_1
int isNumber(const char *s)
{
    int i=1;

    if(s[0]=='-' || isdigit(s[0]))
    {
    }else
    {
        return 0;
    }
    

    for(i;i<strlen(s);i++)
    {
        if(! isdigit(s[i]))
        {
            return 0;
        }
    }
    return 1;
}

//Zad.1_2
char *trim(char *s){
    int i=0;
    for(i;i<strlen(s);i++)
    {
        if(!isspace(s[i]))
            break;
    }

    int j=strlen(s)-1;
    for(j;j>0;j--)
    {
        if(!isspace(s[j]))
            break;
    }

    int newSize = j-i;

    char *result = malloc(newSize+1);

    int index=0;
    for(i;i<=j;i++)
    {
        result[index]=s[i];
        index++;
    }

    result[index]='\0';

    return result;
}
//Zad 1.3
int getOperator(char *op,const char *s)
{
    int i=0;
    for(i;i<strlen(s);i++)
    {
        if(!isdigit(s[i]))
        {
            break;
        }
    }

    if(s[i]=='-' || s[i]=='+' || s[i]=='*' || s[i]=='/' || s[i]==':')
    {
        op[0]=s[i];
        op[1]='\0';
        return 1;
    }
    return 0;
}

struct Fraction {
    int num, den;
};

//Zad 1.4
int getFraction(struct Fraction *x, const char *s)
{
    int i=0;
    for(i;i<strlen(s);i++)
    {
        if(!isdigit(s[i]))
        {
            break;
        }
    }

    if(s[i]=='/')
    {
        char *licznik = malloc(i+1);
        char *mianownik = malloc(strlen(s)-i+1);

        int j=0;
        for(j;j<i;j++)
        {
            licznik[j]=s[j];
        }
        licznik[j]='\0';

        int k=i+1;
        int index=0;
        for(k;k<strlen(s);k++)
        {
            mianownik[index]=s[k];
            index++;
        }
        mianownik[index]='\0';

        x->den = atoi(mianownik);
        x->num = atoi(licznik);

        //jest ułamkiem
        return 1;
    }
    else
    {

        //nie jest ułamkiem
        //sprawdz czy jest liczba caly
        if(i==strlen(s))
        {
            x->num=atoi(s);
            x->den=1;

            return 1;
        }
        return 0;
    }
}
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
void printFraction(struct Fraction x){
    
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
int poprawnyOperator(char *op)
{
    if(op[0]=='+' || op[0]=='-' || op[0]=='*' || op[0]=='/')
        return 1;
    return 0;
}
void print(struct Fraction x,struct Fraction y, const char op)
{
    struct Fraction solution;

    if(op == '+')
        solution = sum(x,y);
    else if(op == '-')
        solution = subtract(x,y);
    else if(op == '*')
        solution = multiplicate(x,y);
    else if(op == '/' || op == ':')
        solution = division(x,y);
    else
        {
            printf("%c - nieznane dzialanie",op);
            return;
        }

    printf("%d/%d %c %d/%d = %d/%d\n",x.num,x.den,op,y.num,y.den,solution.num,solution.den);
}
char *safeReadFromConsole()
{
    unsigned int len_max = 128;
    unsigned int currentSize = 0;
    char *data = malloc(len_max);
    currentSize = len_max;

    if(data != NULL)
    {
        int c;
        unsigned int i=0;
        //accept user input until hit enter or new line
        while ((c = getchar()) !=  '\n')
        {
            data[i++]=(char)c;
            //if max size realocate
            if (i==currentSize)
            {
                currentSize = i+len_max;
                data = realloc(data,currentSize);
            }
        }
        data[i] = '\0';
        return data;
    }
    return data;
}
//Zad.1.5
void odczytTerminal(){
    int MAX_LEN =20;

    // char *ulamek1=malloc(sizeof(char)*MAX_LEN);
    printf("podaj a/b =");
    char *ulamek1 = safeReadFromConsole();
    // fgets(ulamek1, MAX_LEN, stdin);

    struct Fraction *ul1Pointer,ul1;
    ul1Pointer=&ul1;

    while (getFraction(ul1Pointer,ulamek1)==0)
    {
        printf("podano nieprawidlowe dane.\n");
        printf("podaj a/b =");
        fgets(ulamek1, MAX_LEN, stdin);
    }

    printf("podaj c/d =");
    char *ulamek2 = safeReadFromConsole();

    struct Fraction *ul2Pointer,ul2;
    ul2Pointer = &ul2;
    
    while (getFraction(ul2Pointer,ulamek2)==0)
    {
        printf("podano nieprawidlowe dane.\n");
        printf("podaj c/d =");
        fgets(ulamek2, MAX_LEN, stdin);
    }
    
    char *opPointer=malloc(2);

    printf("podaj operator = ");
    fgets(opPointer, 2, stdin);

    while (poprawnyOperator(opPointer)==0)
    {
        printf("podano bledny operator\n");
        printf("podaj operator = ");
        fgets(opPointer, 1, stdin);
    }
    
    print(ul1,ul2,opPointer[0]);
}


void main()
{   
    // printf("%d - isNumber\n",isNumber("XD elo 213"));
    // printf("%d - isNumber\n",isNumber("213"));
    // printf("%d - isNumber\n",isNumber("-213"));

    // printf("%s - trim",trim("  elo elo  "));
    // char *op=malloc(2);

    // printf("%d - getOperator = %s\n",getOperator(op,"5/2"),op);

    // struct Fraction *solutionPointer,solution;
    // solutionPointer=&solution;

    // printf("%d - ulamek\n",getFraction(solutionPointer,"52"));
    // printf("%d - ulamek\n",getFraction(solutionPointer,"2/3"));
    // printf("%d - ulamek\n",getFraction(solutionPointer,"dsa/dsa"));

    // printFraction(solution);

    odczytTerminal();

    // char *xd = saveReadFromConsole();
    // printf("%s - string",xd);

}