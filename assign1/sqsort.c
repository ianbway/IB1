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
int processFile(FILE *,char,*Comparator,*Print);
void sort(*Comparator,*queue,*queue);

int main(int argc, char **argv)
	{

	int argIndex = 1; //default to 1 in order to skip executable
	char *arg;
	char *fileName = 0;
	int printAuthorOption = 0;
		Comparator comp;
		Printer print;

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
				comp = intCompare;
				print = intPrint;
				break;
			case 'r':
				comp = realCompare;
				print = realPrint;
				break;
			case 's':
				comp = stringCompare;
				print = stringPrint;
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

	processFile(input,comp,print);

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

int processFile(FILE *fp,char type, Comparator *comp, Printer *print);
	{
    	queue *inputQueue = 0;
    	queue *outputQueue = 0;
      stack *sortStack = 0;

		//initialize queues with display function
		inputQueue = newQueue(print);
		sortStack = newStack(print);
		outputQueue = newQueue(print);

		//TODO figure out how to process each type separately maybe just pass in a char that tells what type
		//we are dealing with: 'd','s','r'
    switch (type) {
      case 'r':

        double r = 0;
        while (!feof(fp) && (r = readReal(fp)))
        {
          enqueue(inputQueue,newReal(r));
        }
        break;
      case 'd':
        int d = 0;
        while (!feof(fp) && (d = readInt(fp)))
        {
          enqueue(inputQueue,newInteger(d));
        }
        break;
      case 's':
        char *s = "";
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
    if (peekQueue(outputQueue)>peekQueue(inputQueue)) {
		  sort(comp,inputQueue,outputQueue,sortStack);
    }

		// display queue after sorting
		displayQueue(stdout,outputQueue);
		fprintf(stdout,"\n");
		
		fclose(fp);
		return 0;
	}

void sort(Comparator *comp, queue *inputQueue, queue *outputQueue, stack *sortStack)
{
  //TODO sort according to the bullet points in assign1
  //TODO must use stack here
  while (sizeQueue(inputQueue) > 0) {
    dequeueItem = dequeue(inputQueue);

    // move item from input to output
    if (dequeueItem > peekQueue(inputQueue)) {
      push(sortStack,dequeueItem);
    }

    // move stack items directly to output queue if input is exhausted
    if (sizeQueue(inputQueue)==0 && sizeStack(sortStack) > 0) {
      for (int i - sizeStack(sortStack) -1; i>=0; i--) {
        enqueue(outputQueue,pop(sortStack));
      }
    }

    // move item from stack to output
    if (sizeStack(sortStack) > 0) {

    }

    // move item from input to stack
    if (sizeQueue(inputQueue) > 0 && peekQueue(inputQueue) > 

  }
}
