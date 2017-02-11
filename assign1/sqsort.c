#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "scanner.h"
#include "stack.h"
#include "queue.h"
#include "integer.h"
#include "real.h"
#include "string.h"

void Fatal(char *,...);
void printAuthor();
void printPostfix();
void printResult();
int processFile(FILE *,int,int,int);

int main(int argc, char **argv)
	{

	int argIndex = 1; //default to 1 in order to skip executable
	char *arg;
	char *fileName = 0;
	int printAuthorOption = 0;
	int sortDecimal = 0;
	int sortReal = 0;
	int sortString = 0;
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
				sortDecimal = 1;
				break;
			case 'r':
				sortReal = 1;
				break;
			case 's':
				sortString = 1;
				break;
			default:
				Fatal("unknown flag '%s', valid flags are -d, -r, -s and -v\n", arg);
			}
		}
		else
		{
			fileName = arg; // assume filename
		}

		++argIndex;	
	}

	if (printAuthorOption)
	{
		printAuthor();
		return 0;
	}

	if (fileName)
	{
		input = fopen(fileName, "r");
		if (input == NULL)
		{
			Fatal("could not open %s file\n", fileName);
		}
	}
	else
	{
		input = stdin;
	}

	processFile(input,sortReal,sortDecimal,sortString);

	return 0;
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

int ProcessFile(FILE *fp, int sortReal, int sortDecimal, int sortString)
	{
		printf("processFile\n");	
    queue *inputQueue = 0;
    queue *outputQueue = 0;

		//initialize queues with display function
		if (sortReal) {
			inputQueue = newQueue(displayReal);
			outputQueue = newQueue(displayReal);

			while (r = readReal(fp))
			{
				enqueue(r);
			}
		}

		// same as sort real
		if (sortDecimal)
		{
		}

		if (sortString)
		{
		}

		// display queue before sorting
		displayQueue(stdout,inputQueue);

		// sort queue

		// display queue after sorting
		displayQueue stdout,outputQueue);
		
		fclose(fp);
		return 0;
	}
