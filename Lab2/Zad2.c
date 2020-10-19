#include<stdio.h>
//Zad 2
float a1(int n)
{
	if(n==0)
		return 1;
	else if(n==1)
		return 4;
	else
		return 2*a1(n-1)+0.5*a1(n-2);
}
//Zad 2_1
float a2(int n)
{
    if (n==0)
        return 1;

	float a0=1;
	float a1=4;
	float a2=2*a1+0.5*a0;
	int i=1;
	
	for(i;i<n;i++)
	{
		a0=a1;
		a1=a2;
		a2=2*a1+0.5*a0;
	}

	return a1;
}
//ramka trojzebna do a2
/*
	a0    a1    a2
	| --- | --- |
	0     1     2     3        indeksy
	1     4    8.5    19       wartości  
	      | --- | --- |	
         a0    a1    a2
*/

//ile razy należy przesunąć ramkę w prawo, aby wyznaczyć wartość n-tego wyrazu ciągu {an} w funkcji a2 dla n >= 3 ? 
//ramkę w prawo należy przesunąć n razy

//pętla przesuwająca ramkę tym razem musi startować od indeksu 1

//analiza wywołania a2(4)
/*
	wywołanie a2(4)
	n=4;
	
	a0=1;
	a1=4;
	a2=2*a1+0.5*a0;[8.5]
	i=1;
	
	petla i<n [1<4] [true]
		a0 = a1; [4]
		a1 = a2; [8.5]
		a2 = 2*a1+0.5*a0;[19]
		i++; [2]
	
	petla i<n [2<4] [true]
		a0 = a1; [8.5]
		a1 = a2; [19]
		a2 = 2*a1+0.5*a0;[42.25]
		i++; [3]
	
	petla i<n [3<4] [true]
		a0 = a1; [19]
		a1 = a2; [42.25]
		a2 = 2*a1+0.5*a0;[94]
		i++; [4]
	
	petla i<n [4<4] [false]
	
	return a1; [42.25]
*/
/*
graf obliczeń a2(4)

        a2(4)
		if(n==0) --------- zwroc 1
        a0 = 1
        a1 = 4
        a2 = 2*a1+0.5*a0;[8.5]
        i = 1
        if(i<n)  <----------------------
       /       \                       |
(i>=n)/         \(i<n)                 |
     /           \                     |
  zwroc a1      a0 = a1                |
                a1 = a2                |
                a2 = 2*a1+0.5*a0;[8.5] |
                i += 1                 |
                   |                   |
                    --------------------
*/
//Zad 2_2
float a3(int n)
{
	if(n==0)
		return 1;
	float a0=1;
	float a1=4;
	int i=1;
	for(i;i<n;i++)
	{
		float pom = a0;
		a0 = a1;
		a1 = 2*a0+0.5*pom;
	}
	return a1;
}
//ramka dwojzebna do a3
/*
	a0    a1
	| --- | 
	0     1     2     3        indeksy
	1     4    8.5    19       wartości  
	| --- | --- |	
   pom    a0    a1
*/

//ile razy należy przesunąć ramkę w prawo, aby wyznaczyć wartość n-tego wyrazu ciągu {an} w funkcji a3 dla n >= 2 ? 
//ramke nalezy przesunac n razy w prawo

//pętla przesuwająca ramkę tym razem musi startować od indeksu 1
//zrobione

/*
analiza wywołania a3(4)
a3(4)

n=4;
a0 =1;
a1 =4;
i=1;

petla i<n [1<4] [true]
    pom = a0;[1]
    a0 = a1;[4]
    a1 = 2*a0 + 0.5*pom;[8.5]

petla i<n [2<4] [true]
    pom = a0;[4]
    a0 = a1;[8.5]
    a1 = 2*a0 + 0.5*pom;[19] 

petla i<n [3<4] [true]
    pom = a0;[8.5]
    a0 = a1;[19]
    a1 = 2*a0 + 0.5*pom;[42.25] 

petla i<n [4<4] [false]
    zwroc a1; [42.25]
*/
/*
graf obliczeń a3(4)

        a3(4)
		if(n==0) --------- zwroc 1
        a0 = 1
        a1 = 4
        a2 = 2*a1+0.5*a0;[8.5]
        i = 1
        if(i<n)  <----------------------
       /       \                       |
(i>=n)/         \(i<n)                 |
     /           \                     |
  zwroc a1      a0 = a1                |
                a1 = a2                |
                a2 = 2*a1+0.5*a0;[8.5] |
                i += 1                 |
                   |                   |
                    --------------------
*/
void Sequence(int n)
{
    printf("a1(%d) = %f\n",n,a1(n));
    printf("a2(%d) = %f\n",n,a2(n));
    printf("a3(%d) = %f\n",n,a3(n));
}

void main(){
    // printf("a1(%d) = %f\n",4,a1(4));
    // printf("a2(%d) = %f\n",4,a2(4));
	// printf("a3(%d) = %f\n",4,a3(4));
    Sequence(4);
}