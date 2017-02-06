#include "dll.h"

#ifndef __STACK_INCLUDED__
#define __STACK_INCLUDED__

/* Ian Braudaway */

typedef struct stack {
    dll *stackItems;
} stack;

extern stack *newStack(void (*d)(FILE *, void *));    //constructor
extern void push(stack *items, void *value);    //stores a generic value
extern void *pop(stack *items);    //returns a generic value
extern void *peekStack(stack *items);    //returns a generic value
extern int sizeStack(stack *items);    //returns size of a stack

extern void displayStack(FILE *fp, stack *items);  //prints out values of stack

#endif
