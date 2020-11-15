#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

void printChars(FILE *file)
{
    char c;

    printf("Content of file\n");

    while((c=getc(file))!=EOF){
        printf("%c",c);
    }

    printf("\nEnd of file\n");
}

void printLines(FILE *file)
{
    int bufferLength = 255;
    char buffer[bufferLength];

    while(fgets(buffer, bufferLength, file)) {
        printf("%s", buffer);
    }
}

void copy(const char *addr1, const char *addr2)
{
    FILE *source = fopen(addr1,"r");
    if(!source)
    {
        printf("Couldn't read file 1\n");
        return;
    }

    FILE *target = fopen(addr2,"w");
    if(!source)
    {
        printf("Couldn't read file 2\n");
        return;
    }

    char c;

    while((c=getc(source))!=EOF){
        putc(c,target);
        // printf("%c",c);
    }

    printf("File copied succesfull.");

    fclose(source);
    fclose(target);
}

void main()
{
    FILE *file = fopen("plik.txt", "r");
    if (!file)
    {
        printf("Couldn't read file\n");
        return;
    }
    // printf("printChars\n");
    // printChars(file);

    printf("\nprintLines\n");
    printLines(file);

    fclose(file);

    // copy("plik.txt","plik2.txt");

}
