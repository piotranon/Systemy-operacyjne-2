#include<stdio.h>
//Zad 3
float a1Tree(int n,int i)
{
    float answer;
	i+=1;
	if(n==0)
    {
		answer = 1;
    }
	else if(n==1)
    {
        answer = 4;
    }
	else
    {
        answer = 2*a1Tree(n-1,i)+0.5*a1Tree(n-2,i);
    }        

    printf("%d - a1Tree(%d) = %f\n",i,n,answer);

    return answer;
}
// Zad 3
void SequenceTree(int n)
{
    a1Tree(n,0);
}
// sprawdź czy drzewo wywołań z wcześniejszego zadania zostało poprawnie narysowane
// poprawne

void main(){
    SequenceTree(4);
}