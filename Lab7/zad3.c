#include <stdio.h>
#include <stdlib.h>

void main(int argc, char* argv[])
{
	char buffer [100];
	#ifdef _WIN32
		if(argc<2)  system("dir");
	    else{
		 snprintf(buffer, sizeof(buffer), "dir %s", argv[1]);
		system(buffer);
		}
	#elif __linux__
	   if(argc<2)  system("ls");
	    else{
		 snprintf(buffer, sizeof(buffer), "ls %s", argv[1]);
		system(buffer);
		}
	#endif
}

