#include<stdio.h>
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

char *identity(const char *name, const char *surname)
{
    int namelength = strlen(name);
    int surnamelength = strlen(surname);

    printf("%d - %s - %d\n",name,name,namelength);
    printf("%d - %s - %d\n",surname,surname,surnamelength);
    
    // char *both;
    char both[namelength+surnamelength+1];
    int indeksboth=0;

    printf("xd1\n");


    printf("%s - %d\n",both,strlen(both));

    int i=0;
    for(i;i<namelength;i++)
    {
        printf("%c - %d\n",name[i],i);
        both[indeksboth]=name[i];
    }

    printf("xd2\n");

    both[indeksboth]=' ';
    indeksboth++;

    i=0;
    for(i;i<surnamelength;i++)
    {
        printf("%c - %d\n",surname[i],i);
        both[indeksboth]=surname[i];
    }
    printf("xd3\n");

    // printf("xd2\n");
    // while (*name)
    // {
    //     printf("x");    
	// 	printf("%d - name\n",name);
    //     *both = *name;
    //     both++;
    //     name++;
    // }
    // printf("%s - name",both);
    // *both=' ';
    // both++;
    // printf("%s - name",both);
    // while (*surname)
    // {
    //     *both = *surname;
    //     both++;
    //     surname++;
    // }
    // *both='\0';
    // printf("%s - surname",both);
    
    // // ustawiwienie adresow na poczatek tekstow
    // name-=namelength;
    // surname-=surnamelength;

    printf("wynik: %d - %s\n",both,*both);

    return both;
}

// char *login(const char *name, const char *surname)
// {
//     int namelength = strlen(name);
//     int surnamelength = strlen(surname);
    
//     printf("%d - dlugosc tekstow\n",namelength+surnamelength);

//     int size=0;
//     if(1+surnamelength>32)
//         size=32;
//     else
//         size=1+surnamelength;


//     char *login;

//     printf("%d\n",strlen(login));

//     int i=0;
//     login[i]=*name;
//     i++;

//     int wasAllLettersFromSurname = 0;
//     while (*surname)
//     {
//         login[i]= *surname;
//         surname++;
//         i++;
//         if(i==32)
//         {
//             wasAllLettersFromSurname=1;
//             break;
//         }
//     }

//     //ustawiwienie adresow na poczatek
//     if(wasAllLettersFromSurname==1)
//     {
//         surname-=31;
//     }else
//     {
//         surname-=surnamelength;
//     }
    
//     printf("%s - login - %d - %d\n",login,login,strlen(login));
//     printf("%s - imie - %d - %d\n",name,name,strlen(name));
//     printf("%s - nazw - %d - %d\n",surname,surname,strlen(surname));

//     return login;
// }

void main()
{
    printf("Zad.3\n");
    // printf("%d - index\n",indexOf("ale jazda z zadaniami",'z'));
    // char *wynik= ;
    printf("%s - tekst\n",identity("Piotr","Dlugosz"));
    // printf("%s - wynik\n",login("Piotr","Dlugosz"));
    // printf("%s - wynik2\n",login("Piotr","Dlugoszaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));

}
