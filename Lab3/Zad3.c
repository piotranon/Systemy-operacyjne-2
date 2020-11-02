#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int indexOf(const char *str,int c){
    int i=0;
    for(i;i<strlen(str); i++){
        if(str[i]==c)
        {
            return i;
        }
    }
    return -1;
}

char *identity(const char *name,const char *surname)
{
    char *result = malloc(strlen(name) + strlen(surname)+2);
    strcpy(result,name);
    strcat(result," ");
    strcat(result,surname);

    return result;
}

char *login(const char *name, const char *surname)
{
    int size = strlen(surname);

    if(size>32);
    {
        size=32;
    }

    char *result = malloc(size+1);

    result[0]=name[0];

    int i=1;
    int index=0;
    for(i;i<size;i++)
    {
        result[i]=surname[index];
        index++;
    }

    result[size]='\0';

    return result;
}

void main()
{
    printf("Zad.3\n");
    // printf("%d - index\n",indexOf("ale jazda z zadaniami",'z'));
    // char *wynik= ;
    // printf("%s - imie i nazwisko\n",identity("Piotr","Dlugosz"));
    printf("%s - login\n",login("Piotr","Dlugosz"));
    printf("%s - login\n",login("Piotr","Dlugoszsssssssssssssssssssssssssss"));

}
