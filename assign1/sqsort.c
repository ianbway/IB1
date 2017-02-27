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
#include "comparator.h"


void Fatal(char *,...);
void printAuthor();
void printPostfix();
void printResult();
int processFile(FILE *,char,Comparator,Printer);
void sort(Comparator, queue *,queue *,stack *);

int main(int argc, char **argv)
	{

	int argIndex = 1; //default to 1 in order to skip executable
	char *arg;
	char *fileName = 0;
	int printAuthorOption = 0;
	Comparator cmp;
	Printer prt;
	char type;
	FILE *input;

	while (argIndex < argc)
	{
		arg = argv[argIndex];

		if (arg[0] == '-')
		{
			// get char after hyphen
			type=arg[1];
			switch (type)
			{
			case 'v':
				printAuthorOption = 1;
				break;
			case 'd':
				cmp = intCompare;
				prt = intPrint;
				break;
			case 'r':
				cmp = realCompare;
				prt = realPrint;
				break;
			case 's':
				cmp = stringCompare;
				prt = stringPrint;
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

	processFile(input,type,cmp,prt);

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

int processFile(FILE *fp,char type, Comparator comp, Printer print)
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
          enqueue(inputQueue,newReal(r));
        }
        break;
      case 'd':
        while (!feof(fp) && (d = readInt(fp)))
        {
          enqueue(inputQueue,newInteger(d));
        }
        break;
      case 's':
        while (!feof(fp) && (s = readString(fp)))
        {
          enqueue(inputQueue,newString(s));
        }
        break;
    }

		// display queue before sorting
		displayQueue(stdout,inputQueue);
		fprintf(stdout,"\n");
		
		// sort queue
		sort(comp,inputQueue,outputQueue,sortStack);
		sort(comp,outputQueue,inputQueue,sortStack);
    if (comp(peekQueue(outputQueue),peekQueue(inputQueue)) > 0) {
		  sort(comp,inputQueue,outputQueue,sortStack);
    }

		// display queue after sorting
		displayQueue(stdout,outputQueue);
		fprintf(stdout,"\n");
		
		fclose(fp);
		return 0;
	}

void sort(Comparator comp, queue *inputQueue, queue *outputQueue, stack *sortStack)
{
  //TODO sort according to the bullet points in assign1
  //TODO must use stack here
  void *outputItem = 0;
  while (sizeQueue(inputQueue) > 0) {
    void *dequeueItem = dequeue(inputQueue);
    printf("%d\n",sizeQueue(inputQueue));

    // move item from input to output
    if (comp(dequeueItem ,peekQueue(inputQueue)) <= 0) {
      enqueue(outputQueue, dequeueItem);
    }

    // move item from input to stack
    else
    {
      push(sortStack, dequeueItem);      
    }   

    // move item from stack to output
    if (sizeStack(sortStack) > 0) {
      if(comp(peekStack(sortStack),outputItem) < 0 && comp(peekQueue(inputQueue),peekStack(sortStack)) < 0) {
         enqueue(outputQueue,pop(sortStack));
      }
    }

  }
    // move stack items directly to output queue if input is exhausted
    if (sizeQueue(inputQueue)==0 && sizeStack(sortStack) > 0) {
      for (int i = sizeStack(sortStack) -1; i>=0; i--) {
        enqueue(outputQueue,pop(sortStack));
      }
    }
}
