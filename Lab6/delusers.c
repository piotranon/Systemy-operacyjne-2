#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

char *login(const char *name, const char *surname)
{
    int size = strlen(surname);

    if (size > 32)
        ;
    {
        size = 32;
    }

    char *result = malloc(size + 1);

    result[0] = name[0];

    int i = 1;
    int index = 0;
    for (i; i < size; i++)
    {
        result[i] = surname[index];
        index++;
    }

    result[size] = '\0';

    return result;
}

void delUser(char *name, char *surname, char *password)
{
    char *logi = login(name, surname);
    // printf("%s - login\n", logi);
    // printf("%s - password\n\n", password);
    char *test="xd\0";


    char *all= malloc(128);

    sprintf(all,"userdel -r %s",logi);

    // strcpy(all,polecenie);
    // strcat(all,password);
    // strcat(all," ");
    // strcat(all,logi);
    // strcat(all,"\0");


    printf("\n%s - polecenie %d\n",all,strlen(all));

    // printf("%s - login %d\n",logi,strlen(logi));
    // printf("%s - password %d\n",password,strlen(password));
    // printf("%s - polecenie %d\n",polecenie,strlen(polecenie));

    free(all);
    // system("useradd -p piotr test");
    int m=system(all);
    // printf("%d - kod\n",m);
    if(m==0)
    {
        printf("User was deleted. His Login data\n");
        printf("Login : %s\n",logi);
    }else if(m==2304)
    {
        // printf("konto juz istnieje z loginem: %s\n",logi);
    }else
    {
        // printf("wystapil konkretny blad");
    }
    
    
    
    // system("useradd -p "+password+" "+logi);
    // execl("/usr/sbin/useradd", "--password",password, logi,);
    

    free(name);
    free(surname);
    free(password);

    name = malloc(128);
    surname = malloc(128);
    password = malloc(128);
}

void main()
{
    FILE *in_file = fopen("dane.txt", "r");
    if (!in_file)
    {
        printf("Couldn't read file\n");
        return;
    }
    int c;

    char *name = malloc(128);
    int nameI = 0;
    char *surname = malloc(128);
    int surnameI = 0;
    char *password = malloc(128);
    int passwordI = 0;

    int kolejnosc = 0;
    int i = 0;
    while ((c = getc(in_file)))
    {
        if (kolejnosc == 0)
        {
            if (c != ';')
            {
                name[nameI] = c;
                nameI++;
            }
            else
            {
                kolejnosc++;
                name[nameI] = '\0';
            }
        }
        else if (kolejnosc == 1)
        {
            if (c != ';')
            {
                surname[surnameI] = c;
                surnameI++;
            }
            else
            {
                kolejnosc++;
                surname[surnameI] = '\0';
            }
        }
        else if (kolejnosc == 2)
        {
            if (c != '\n')
            {
                password[passwordI] = c;
                passwordI++;
            }
            else
            {
                password[passwordI] = '\0';
                kolejnosc = 0;

                delUser(name, surname, password);
                surnameI = 0;
                passwordI = 0;
                nameI = 0;
                //dodanie do uzytkownikow
                //wyczyszczeinei wszystkich zmiennych
            }
        }
        if (c == EOF)
        {
            // password[passwordI-1] = '\0';
            // kolejnosc = 0;

            // createUser(name, surname, password);
            // surnameI = 0;
            // passwordI = 0;
            // nameI = 0;

            break;
        }
    }
    // printf("%s - name\n",name);
    // printf("%s - surname\n",surname);
    // printf("%s - password\n",password);

    fclose(in_file);
}