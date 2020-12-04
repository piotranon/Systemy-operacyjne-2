#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printHex(FILE *file)
{
    char ch;
    while((ch = getc(file)) != EOF)
    {
        printf("%.2x ",ch);
    }
}

void printLinesHex(FILE *file)
{
    char ch;
    while((ch = getc(file)) != EOF)
    {
        printf("%.2x ",ch);
    }
}
void printChar(FILE *file)
{
    char ch;
    while((ch = getc(file)) != EOF)
    {
        if(ch == '\n')
        {
            printf("'\\n'");
        }else
        {
            printf("'%c' ",ch);
        }
        
    }
}

void printLinesChar(FILE *file)
{
    char ch;
    while((ch = getc(file)) != EOF)
    {
        if(ch == '\n')
        {
            printf("'\\n'\n");
        }else
        {
            printf("'%c' ",ch);
        }
        
    }
}


void main()
{
    FILE *file = fopen("windows.txt", "r");
    if (!file)
    {
        printf("Couldn't read file\n");
        return;
    }

    printHex(file);
    fseek(file, 0, SEEK_SET);//move pointer to start

    printf("\n\n");

    printChar(file);
    fseek(file, 0, SEEK_SET);//move pointer to start

    printf("\n\n");

    printLinesHex(file);
    fseek(file, 0, SEEK_SET);//move pointer to start

    printf("\n");

    printLinesChar(file);

    fclose(file);

}