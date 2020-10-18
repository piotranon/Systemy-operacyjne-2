#include<stdio.h>

// podaj definicję ciągu Fibonacciego
// ciag fibonnacciego jest to ciag liczb obliczamy rekurencyjnie ze wzoru
// dla n = 0 wartość 0
// dla n = 1 wartość 1
// dla n > 1 wartość f(n-1) + f(n-2)

// Zad_2_1
int fibo1(int n)
{
    if (n==0) return 0;
    if (n==1) return 1;
    return fibo1(n-1)+fibo1(n-2);
}

/*
Analiza wywołania fibo1(4)

sprawdzamy czy n (4) == 0 lub n(4) == 1 [false]
zwracamy sumę wartości z wywołań [ fibo1(n-1 (3))+fibo1(n-2 (2)) ] [5]

Analiza wywołania fibo1(3)
sprawdzamy czy n (3) == 0 lub n(3) == 1 [false]
zwracamy sumę wartości z wywołań [ fibo1(n-1 (2))+fibo1(n-2 (1)) ] [3]

Analiza wywołania fibo1(2)
sprawdzamy czy n (2) == 0 lub n(2) == 1 [false]
zwracamy sumę wartości z wywołań [ fibo1(n-1 (1))+fibo1(n-2 (0)) ] [2]

Analiza wywołania fibo1(1)
sprawdzamy czy n (1) == 0 lub n(1) == 1 [true]
zwracamy [1]

Analiza wywołania fibo1(0)
sprawdzamy czy n (0) == 0 lub n(0) == 1 [true]
zwracamy [1]
*/

/*
Drzewo wywołania
                                   fibo1(4)
                                     ||
                    fibo1(3)          +        fibo1(2)
                        ||                        ||
            fibo1(2)    +    fibo1(1)     fibo1(1)  + fibo1(0)
               ||       
       fibo1(1) + fibo1(0) 
*/

int fibo2(int n)
{
    int r0=0;
    int r1=1;
    int r2=r1+r0;

    int i=0;
    for(i;i<n;i++)
    {
        r0=r1;
        r1=r2;
        r2=r1+r0;
    }
    return r0;
}
// ile razy należy przesunąć ramkę w prawo, aby wyznaczyć wartość n-tego wyrazu ciągu Fibonacciego w funkcji fibo2 dla n >= 3 ?
// n razy

/* 
Analiza wywołania fibo2(4)

przypisujemy warości 
n=4
r0=0,
r1=1,
r2=r1+r0 (1)
i=0

petla i<n (0<4) [true]
r0=r1 [1]
r1=r2 [1]
r2= r1+r0 [1+1 = 2]

petla i<n (1<4) [true]
r0=r1 [1]
r1=r2 [2]
r2=r1+r0[2+1 = 3]

petla i<n (2<4) [true]
ro=r1 [2]
r1=r2 [3]
r2=r1+r0 [3+2 = 5]

petla i<n (3<4) [true]
ro=r1 [3]
r1=r2 [5]
r2=r1+r0 [5+3 = 8]

petla i<n (4<4) [false]
zwroc r0 [3]

*/

/*
graf obliczeń fibo2(4)
jak graf dla petli?

*/
int fibo3(int n)
{
    int r0=0;
    int r1=1;
    int i=0;
    
    for(i;i<n;i++)
    {
        int pom = r0;
        r0=r1;
        r1=r0+pom;
    }
    return r0;
}
// ile razy należy przesunąć ramkę w prawo, aby wyznaczyć wartość n-tego wyrazu ciągu Fibonacciego w funkcji fibo3 dla n >= 2 ?
// ramkę należy przesunać n razy

/*
analiza wywołania fibo3(4)

fibo3(4)

przypisujemy wartości
n=4;
r0=1;
r1=1;
i=0;

petla i<n [0<4] [true]
    pom = r0; [1]
    r0 = r1; [1]
    r1 = r0 + pom; [ 1 + 1 = 2]
    i++; [1]

petla i<n [1<4] [true]
    pom = r0; [1]
    r0 = r1; [2]
    r1 = r0 + pom; [ 2 + 1 = 3]
    i++; [2]

petla i<n [2<4] [true]
    pom = r0; [2]
    r0 = r1; [3]
    r1 = r0 + pom; [ 3 + 2 = 5]
    i++; [3]

petla i<n [3<4] [true]
    pom = r0; [3]
    r0 = r1; [5]
    r1 = r0 +pom; [ 5 + 3 = 8]
    i++; [4]

petla i<b [4<4] [false]

zwroc r0 [5]

*/

/*
graf obliczeń fibo3(4)
jak graf dla petli?

*/

//która funkcja ma mniejszą złożoność obliczeniową fibo2 czy fibo3 ?
//funkcja fibo2(n) ma złożoność mniejszą, obie mają złożoność liniową O(n)
//fibo2(n) = 1+1+2+1 + n(1+1+2) + 1 = 6 + 4n
//fibo3(n) = 1+1+1 + n(1+1+2) + 1 = 5 + 4n

// Zad 2
void Fibo(int n)
{
    printf("fibo1(%d) = %d\n",n,fibo1(n));
    printf("fibo2(%d) = %d\n",n,fibo2(n));
    printf("fibo3(%d) = %d\n",n,fibo3(n));
}

// Zad 3
void Sequence(int n)
{

}
//wylicz dziesięć pierwszych wyrazów ciągu {an} w programie Excel
//https://i.imgur.com/bq2hB0j.png

float a1(int n)
{
    if (n==0) return 1;
    if (n==1) return 4;
    return 2*a1(n-1) + 0.5*a1(n-2);
}
/*
analiza wywołania a1(4)

a1(4)   [42.25]
n=4;

if n==0 [false]
if n==1 [false]
zwroc 2*a1(3) + 0.5*a1(2); [ 2 * 19 + 0.5 * 8.5 = 42.25]

a1(3)
n=3;

if n==0 [false]
if n==1 [false]
zwroc 2*a1(2) + 0.5*a1(1); [ 2 * 8.5 + 0.5 * 4 = 19]

a1(2)
n=2;

if n==0 [false]
if n==1 [false]
zwroc 2*a1(1) + 0.5*a1(0); [ 2 * 4 + 0.5 * 1 = 8.5]

a1(1)
n=1;

if n==0 [false]
if n==1 [true]
    zwroc 4;[4]

a1(0)
n=0;

if n==0 [true]
    zwroc 1;[1]

*/
/*
drzewo wywołań
                                    a1(4)
                                     ||
                    2* a1(3)          +          0.5* a1(2)
                        ||                            ||
            2* a1(2)    +    0.5* a1(1)       2*a1(1)  + 0.5*a1(0)
               ||       
       a1(1) + a1(0) 
*/


void test(int n)
{
    printf("------------------------------------\n");

    int i=0;
    for(i;i<=n;i++)
    {
        printf("fibo1(%d) = %d\n",i,fibo1(i));
    }

    printf("------------------------------------\n");

    i=0;
    for(i;i<=n;i++)
    {
        printf("fibo2(%d) = %d\n",i,fibo2(i));
    }

    printf("------------------------------------\n");

    i=0;
    for(i;i<=n;i++)
    {
        printf("fibo3(%d) = %d\n",i,fibo3(i));
    }

    printf("------------------------------------\n");
}
void main(){
    test(5);
    Fibo(4);
}