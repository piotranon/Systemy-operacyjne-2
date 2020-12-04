#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

void main()
{
    #ifdef _WIN32 // Includes both 32 bit and 64 bit
	    printf("Program compiled on: Windows");
	#elif __unix__
	    printf("Program compiled on: Unix");
	#endif
}