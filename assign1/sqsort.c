#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "scanner.h"
#include "stack.h"
#include "queue.h"

void Fatal(char *,...);
void printAuthor();
void printPostfix();
void printResult();
int processFile(FILE *);

int main(int argc, char **argv)
	{

	int argIndex = 1; //default to 1 in order to skip executable
	char *arg;
	char *fileName = 0;
	int printAuthorOption = 0;
	int printDecimalOption = 0;
	int printRealOption = 0;
	int printStringOption = 0;
	FILE *input;

	while (argIndex < argc)
	{
		arg = argv[argIndex];

		if (arg[0] == '-')
		{
			// get char after hyphen
			switch (arg[1])
			{
			case 'v':
				printAuthorOption = 1;
				break;
			case 'd':
				printDecimalOption = 1;
				break;
			case 'r':
				printRealOption = 1;
				break;
			case 's':
				printStringOption = 1;
				break;
			default:
				Fatal("option %s not understood\n", arg);
			}
		}
		else
		{
			fileName = arg; // assume filename
		}

		++argIndex;	
	}

	if (printAuthorOption == 1)
	{
		printAuthor();
		return;
	}

	if (printDecimalOption == 1)
	{
		printDecimal();
		return;
	}

	if (printRealOption == 1)
	{
		printReal();
		return;
	}

	if (printStringOption == 1)
	{
		printString();
		return;
	}

	if (fileName != 0)
	{
		input = fopen(fileName, "r");
		if (input == NULL)
		{
			Fatal("could not open %s file\n", fileName);
			return;
		}
	}
	else
	{
		input = stdin;
	}

	return;
	}

void printAuthor()
{
	printf("Ian W. Braudaway\n");
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
		printf("processFile\n");	
		char *s;

		while (s = readLine(fp))
		{
			printf("<%s>\n", s);
		}

		if (s)
		{
			printf("free %s\n", s);
			free(s);
		}
		
		fclose(fp);
		printf("fclose()\n");
		return 0;
	}
