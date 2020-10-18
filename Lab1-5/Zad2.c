#include<stdio.h>

int fibo1(int n)
{   
    if(0==n)
        return 0;
    else if(1==n)
        return 1;
    else
        return fibo1(n-1)+fibo1(n-2);
}
int FiboTree(int n)
{
    int sum;
    if(0==n)
        sum = 0;
    else if(1==n)
        sum = 1;
    else
        sum = FiboTree(n-1)+FiboTree(n-2);

    printf("fibo1( %d ) = %d\n",n,sum);
    return sum;
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



Drzewo wywołań dla fibo1(4)

*/
int fibo2(int n)
{
    int r0=0;
    int r1=1;
    int r2=r1+r0;
    for(int i=0;i<n;i++)
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
r0=0,
r1=1,
r2=r1+r0 (1)
i=0

petla i<n (0<4) [true]
r0=r1 [1]
r1=r2 [1]
r2= r1+r0 [2]

petla i<n (1<4) [true]
r0=r1 [1]
r1=r2 [2]
r2=r1+r0[3]

petla i<n (2<4) [true]
ro=r1 [2]
r1=r2 [3]
r2=r1+r0 [5]

petla i<n (3<4) [true]
ro=r1 [3]
r1=r2 [5]
r2=r1+r0 [8]

petla i<n (4<4) [false]
zwroc r0 [3]

*/
void Fibo(int n)
{
    printf("fibo1(%d) = %d\n",n,fibo1(n));
    printf("fibo2(%d) = %d\n",n,fibo2(n));
    // printf("fibo1(%d) = ",n,fibo1(n));
}
void main()
{
    int n=4;
    // printf("fibo1(%d) : %d\n",n,fibo1(n));
    // printf("-------------------------------\n");


    // printf("FiboTree(%d) : %d\n",n,FiboTree(n));
    // printf("-------------------------------\n");

    // printf("fibo2(%d) : %d\n",n,fibo2(n));
    // printf("-------------------------------\n");

    Fibo(n);
}