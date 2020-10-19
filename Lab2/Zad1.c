#include<stdio.h>
//Zad 1
int FiboTree(int n,int i)
{
	i+=1;
    int answer=0;

    if (n==0){
        answer = 0;
    }
    else if (n==1){
        answer = 1;
    }
    else{
    answer = FiboTree(n-1,i)+FiboTree(n-2,i);
    }

    printf("%d - FiboTree(%d) = %d\n",i,n,answer);

    return answer;
}
// sprawdź czy drzewo wywołań z wcześniejszego zadania zostało poprawnie narysowane
// drzewo zostało poprawnie narysowane

void main(){
    FiboTree(4,0);
}