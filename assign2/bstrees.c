#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "scanner.h"
#include "queue.h"
#include "integer.h"
#include "real.h"
#include "comparator.h"
#include "vbst.h"
#include "rbt.h"

void Fatal(char *, ...);
int processBST(char, FILE*, FILE*, FILE*);

int main(int argc, char **argv)
{

	char *arg;
	char type;
	char *corpusFileName = 0;
	char *commandsFileName = 0;
	char *outputFileName = 0;
	FILE *corpus;
	FILE *commands;
	FILE *output;

	if (argc < 4 || argc > 5) 
	{
			Fatal("invalid number of arguments, usage: bstrees -v -r corpusFile commandsFile [output]\n");
	}

	arg = argv[1];

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

	corpusFileName = argv[2];
	if (corpusFileName)
	{
		corpus = fopen(corpusFileName, "r");
		if (corpus == 0)
		{
			Fatal("could not open %s file\n", corpusFileName);
		}
	}
	
	commandsFileName = argv[3];
	if (commandsFileName)
	{
		commands = fopen(commandsFileName, "r");
		if (commands == 0)
		{
			Fatal("could not open %s file\n", commandsFileName);
		}
	}

	if (argc == 5) 
	{
		outputFileName = argv[4];
	}

	if (outputFileName)
	{
		output = fopen(outputFileName, "w");
		if (output == 0)
		{
			Fatal("could not open %s file\n", outputFileName);
		}
	}
	else 
	{
		output = stdout;
	}
	
	return processBST(type,corpus,commands,output);
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

char *processString(FILE *fp)
{
	char *string;
	if (stringPending(fp)) 
			string = readString(fp);
		else
			string = readToken(fp);

	return string;
}

int processBST(char bstType, FILE* corp, FILE* cmds, FILE* out)
{
	Comparator cmp = compareString;
	Printer prt = displayString;

	vbst *vanilla = 0;
	//rbt *redBlack = 0;

	if (bstType=='v') 
	{
		vanilla = newVBST(prt,cmp);
	} 
	else 
	{
	//redBlack = newRBT(prt,cmp);
	}	

	fprintf(stdout, "processBST:%c\n",bstType);
	char *s;
	// load up bst
	while (!feof(corp))
	{
		s = processString(corp);

		if (s != 0) 
		{
			fprintf(stdout, "corpus:%s\n",s);
			if (vanilla !=0) 
			{
				insertVBST(vanilla,s);
			} 
			else 
			{
			//insertRBT(redBlack,s);
			}
		}
	}

	// process commands
	while (!feof(cmds))
	{
		if (stringPending(cmds)) 
			s = readString(cmds);
		else
			s = readToken(cmds);
		if (s != 0) 
		{
			fprintf(stdout, "cmds:%s\n",s);
		}
	}	

	fclose(corp);
	fclose(cmds);
	fclose(out);

	return 0;
}
