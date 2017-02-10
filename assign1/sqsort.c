#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "scanner.h"
#include "stack.h"
#include "queue.h"

int ProcessOptions(int,char **);
void Fatal(char *,...);

FILE *inputFile;

int main(int argc, char **argv)
	{

	ProcessOptions(argc,argv);

	return 0;
	}

// print the error string and return
void Fatal(char *fmt, ...)
	{
	va_list ap;

	fprintf(stderr,"An error occured: ");
	va_start(ap,fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);

	exit(-1);
	}

int ProcessFile(FILE *fp)
	{
		
	char *s;
	int ch;

	s = readLine(fp);
	ch = s[0];
		while (s[0] != '\0')
			{
			printf("<%s>\n",s);
			s = readLine(fp);
			ch = s[0];
			printf("<%s>after\n",s);
		}
	printf("before file close");
	fclose(fp);
	printf("after file close");
	return 0;
	}

// process command line options
int ProcessOptions(int argc, char **argv)
	{
	int argIndex;
	int argUsed;
	int seperateArg;
	char *arg;
	FILE *fp;
	
	if (argc == 3)
	{
	 printf("processing %s\n",argv[2]);
	 fp = fopen(argv[2],"r"); 
	}
	else
	{ 
	 fp = stdin; 
	} 
	
	argIndex = 1;

	if (argc == 1) 
	{
		ProcessFile(fp);
	}

	else 
	{
	while (argIndex < argc && *argv[argIndex] == '-')
	{	
	
		printf("processing %s\n",argv[argIndex]);

		// no arguments
		if (argv[argIndex][1] == '\0') return argIndex;
	
		seperateArg = 0;
		argUsed = 0;

		// check arguments
		// determine if the argument has a seperate value
			if (argv[argIndex][2] == '\0')
				{
			arg = argv[argIndex+1];
			seperateArg = 1;
			}
		else
			arg = argv[argIndex]+2;

		switch (argv[argIndex][1])
			{
			case 'v':
				printf("Ian W. Braudaway\n");
				argUsed = 1;
				break;
			case 'd':
				argUsed = 1;
				ProcessFile(fp);
				break;
			default:
				Fatal("option %s not understood\n",argv[argIndex]);		
			}

		if (seperateArg && argUsed)
			++argIndex;
			++argIndex;
		}
	}
	return argIndex;
}


