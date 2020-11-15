#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

int countWords1(FILE *file)
{
    char ch = getc(file);
    int word_count = 0;
    int inside = 0;

    if(ch != ' ' || ch != '\t' || ch != '\0' || ch != '\n')
    {
        word_count++;
    }

    while ((ch = getc(file)) != EOF)
    {
        if(ch == ' ' || ch == '\t' || ch == '\n')
        {
            if(inside)
            {
                inside = 0;
                word_count++;
            }
        }else
        {
            inside++;
        }
    }
    return word_count;
}

int countWords2(FILE *file)
{
    char ch;
    int word_count = 0;

    while ((ch = getc(file)) != EOF)
    {
        if(ch == ' ' || ch == '\t' || ch == '\n')
        {
            word_count++;
        }
    }
    return word_count;
}

void main()
{
    FILE *file = fopen("plik.txt", "r");
    if (!file)
    {
        printf("Couldn't read file\n");
        return;
    }

    printf("%d - amount of words\n",countWords1(file));
    fseek(file, 0, SEEK_SET);//move pointer to start
    printf("%d - amount of words 2\n",countWords2(file));

    fclose(file);
}