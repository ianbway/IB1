#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "sll.h"

queue *newQueue (void (*d) (FILE *, void *))
{
	queue *items = malloc(sizeof(queue));
	if (items == 0)
		{
		fprintf(stderr,"out of memory\n");
		exit(-1);
		}
	items->queueItems = newSLL(d);
	return items;
}

void enqueue (queue *items, void *value)
{
	insertSLL(items->queueItems,items->queueItems->size,value);
}

void *dequeue (queue *items)
{
	return removeSLL(items->queueItems,0);
}

void *peekQueue (queue *items)
{
	return getSLL(items->queueItems,0);
}

int sizeQueue (queue *items)
{
	return sizeSLL(items->queueItems);
}

void displayQueue (FILE *fp, queue *items)
{
	displaySLL(fp,items->queueItems);
}
