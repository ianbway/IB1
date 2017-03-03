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


void Fatal(char *, ...);
void printAuthor();
void printPostfix();
void printResult();
int processFile(FILE *, char, Comparator, Printer);
void sort(Comparator, queue *, queue *, stack *);

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

	while (argIndex < argc)
	{
		arg = argv[argIndex];

		if (arg[0] == '-')
		{
			// get char after hyphen
			type = arg[1];
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

	processFile(input, type, cmp, prt);

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

	fprintf(stderr, "An error occured: ");
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);

	exit(-1);
}

int processFile(FILE *fp, char type, Comparator comp, Printer print)
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

	fclose(fp);
	return 0;
}

void sort(Comparator comp, queue *input, queue *output, stack *stack)
{
	int sorted = 0;
	void *lastOutput = 0;

	while (!sorted) {
		int itemPushed = 0;

		while (sizeQueue(input) > 0) {
			void *dequeueItem = dequeue(input);

			if (dequeueItem != 0) {
				// move item from input to output
				if (sizeQueue(input) == 0 && sizeStack(stack) == 0) { //last item
					enqueue(output, dequeueItem);
				} else if (sizeQueue(input) > 0 && comp(dequeueItem, peekQueue(input)) <= 0) {
					enqueue(output, dequeueItem);
					lastOutput = dequeueItem;
				}
				else //item dequeued is > than item at front of inputQueue
				{
					push(stack, dequeueItem);
					itemPushed = 1;
				}
			}

			// move item from stack to output
			// determine if item on the stack is greater than next item on input and less than the last item place on output
			int stackLessThanOutput = (lastOutput != 0 && (sizeStack(stack) > 0 && comp(peekStack(stack), lastOutput) <= 0));
			int inputLessThanStack = (sizeQueue(input) > 0 && sizeStack(stack) > 0 && comp(peekQueue(input), peekStack(stack)) <= 0);

			if (stackLessThanOutput && inputLessThanStack) {
				enqueue(output, pop(stack));
			}
			printf("inputQueue:\t");
			displayQueue(stdout,input);
			printf("\nsortStack:\t");
			displayStack(stdout,stack);
			printf("\noutputQueue:\t");
			displayQueue(stdout,output);
			printf("\n");
		}

		// move stack items directly to output queue if input is exhausted
		if ( sizeStack(stack) > 0) {
			for (int i = sizeStack(stack) - 1; i >= 0; i--) {
				enqueue(output, pop(stack));
			}
		}
		
		sorted = !itemPushed;

		// Swap queues and resort
		if (!sorted) {
			queue *tempQueue = input;
			input = output;
			output = tempQueue;
		}
		else {
			printf("SORTED inputQueue:\t");
			displayQueue(stdout,input);
			printf("\nsortStack:\t");
			displayStack(stdout,stack);
			printf("\noutputQueue:\t");
			displayQueue(stdout,output);
			printf("\n");
		}
	}
}
