#include<stdio.h>


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

float a2(int n)
{
    float a0=1;
    float a1=4;
    float a2=2*a1+0.5*a0;

    int i=0;
    for(i;i<n;i++)
    {
        a0=a1;
        a1=a2;
        a2=2*a1+0.5*a0;
    }
    return a0;
}

float a3(int n)
{
    float a0=1;
    float a1=4;
    int i=0;
    
    for(i;i<n;i++)
    {
        float pom = a0;
        a0=a1;
        a1=2*a0+0.5*pom;
    }
    return a0;
}
// Zad 3
void Sequence(int n)
{
    printf("a1(%d) = %f\n",n,a1(n));
    printf("a2(%d) = %f\n",n,a2(n));
    printf("a3(%d) = %f\n",n,a3(n));
}

void main()
{
    // Sequence(4);
    printf("a1(%d) = %f\n",4,a1(4));
}