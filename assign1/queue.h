#include "sll.h"

#ifndef __QUEUE_INCLUDED__
#define __QUEUE_INCLUDED__

/* Ian Braudaway */

typedef struct queue {
    sll *queueItems;
} queue;

extern queue *newQueue(void (*d)(FILE *, void *));    //constructor
extern void enqueue(queue *items, void *value);    //stores a generic value
extern void *dequeue(queue *items);    //returns a generic value
extern void *peekQueue(queue *items);    //returns a generic value
extern int sizeQueue(queue *items);    //returns size of a queue

extern void displayQueue(FILE *fp, queue *items);  //prints out values of queue

#endif
