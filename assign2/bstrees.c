#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "scanner.h"
#include "queue.h"
#include "integer.h"
#include "real.h"
#include "comparator.h"

void Fatal(char *, ...);
void printResult();
int processBST(char, FILE, FILE*, FILE*, FILE*);

int main(int argc, char **argv)
{

	int argIndex = 1; //default to 1 in order to skip executable
	char *arg;
	char *fileName = 0;
	int printAuthorOption = 0;
	Comparator cmp = 0;
	Printer prt = 0;
	char type;
	FILE *input;

	arg = argv[argIndex];

	if (arg[0] == '-')
	{
		// get char after hyphen
		type = arg[1];
		switch (type)
		{
		case 'v':
			break;
		case 'r':
			break;
		default:
			Fatal("unknown flag '%s', valid flags are -v, -r\n", arg);
		}
	}
	else
	{
		Fatal("Must be -v or -r");
	}

	if (corpus)
	{
		input = fopen(corpus, "r");
		if (input == NULL)
		{
			Fatal("could not open %s file\n", corpus);
		}
	}
	
	if (commands)
	{
		input = fopen(commands, "r");
		if (input == NULL)
		{
			Fatal("could not open %s file\n", commands);
		}
	}

	if (outputfile)
	{
		input = fopen(outputfile, "w");
		if (input == NULL)
		{
			Fatal("could not open %s file\n", outputfile);
		}
	}
	else 
	{
		outputfile = stdout;
	}

	return 0;
}

// print the error string and return
void Fatal(char *fmt, ...)
{
	va_list ap;

	fprintf(stderr, "An error occured: ");
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);

	exit(-1);
}

int processBST(char, FILE, FILE* corp, FILE* cmds, FILE* out)
{
	queue *inputQueue = newQueue(print);
	queue *outputQueue = newQueue(print);
	stack *sortStack = newStack(print);

	double r;
	int d;
	char *s;
	switch (type) {
	case 'r':
		while (!feof(fp) && (r = readReal(fp)))
		{
			enqueue(inputQueue, newReal(r));
		}
		break;
	case 'd':
		while (!feof(fp) && (d = readInt(fp)))
		{
			enqueue(inputQueue, newInteger(d));
		}
		break;
	case 's':
		while (!feof(fp) && (s = readString(fp)))
		{
			enqueue(inputQueue, newString(s));
		}
		break;
	}

	// display queue before sorting
	displayQueue(stdout, inputQueue);
	fprintf(stdout, "\n");

	// sort queue
	sort(comp, inputQueue, outputQueue, sortStack);

	// display queue after sorting
	displayQueue(stdout, outputQueue);
	fprintf(stdout, "\n");

	fclose(corp);
	fclose(cmds);
	fclose(out);

	return 0;
}
