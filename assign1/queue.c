#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "sll.h"

/* Ian Braudaway */

/* Creates a queue */
queue *newQueue(void(*d)(FILE *, void *)) {
	queue *items = malloc(sizeof(queue));
	if (items == 0) {
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}
	items->queueItems = newSLL(d);
	return items;
}

/* Enqueues item at the end of queue */
void enqueue(queue *items, void *value) {
	insertSLL(items->queueItems, items->queueItems->size, value);
}

/* Dequeues item from the front of queue */
void *dequeue(queue *items) {
	return removeSLL(items->queueItems, 0);
}

/* Returns first item in queue */
void *peekQueue(queue *items) {
	return getSLL(items->queueItems, 0);
}

/* Returns size of queue */
int sizeQueue(queue *items) {
	return sizeSLL(items->queueItems);
}

/* Prints out values in queue in list format */
void displayQueue(FILE *fp, queue *items) {
	displaySLL(fp, items->queueItems);
}
