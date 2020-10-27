#include <stdio.h>
#include <string.h>

char identity(const char *name, const char *surname){
    int i, new_lenght;
    printf("Dlugosc imienia: %d\n",strlen(name));
    printf("Dlugosc nazwiska: %d\n",strlen(surname));
    
    new_lenght = strlen(name)+strlen(surname);
    
    printf("Dlugosc nowego napisu: %d\n", new_lenght);
    
    // printf("indeks | litera | ascii |\n");
    for(i=0;i<=new_lenght; i++){
        if(i<strlen(name)){
            printf("Indeks(%d)| %c | %d \n",i,name[i],(int)name[i]);    
        }
        if(i==strlen(name))
            printf("Indeks(%d)| %c | %d \n",i,' ',(int)' ');
        if(i>strlen(name)){
            int indeks = i-strlen(name)-1;
            printf("Indeks(%d)| %c | %d \n",i,surname[indeks],(int)surname[indeks]);
        }
    }
    return -1;
}

void main(){
    identity("Kamil","Filar");
}