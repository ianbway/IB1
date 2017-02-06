#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "dll.h"

/* Ian Braudaway */

/* Creates a stack */
stack *
newStack(void (*d)(FILE *, void *)) {
    stack *items = malloc(sizeof(stack));
    if (items == 0) {
        fprintf(stderr, "out of memory\n");
        exit(-1);
    }
    items->stackItems = newDLL(d);
    return items;
}

/* Pushes an item on the top of the stack */
void
push(stack *items, void *value) {
    insertDLL(items->stackItems, 0, value);
}

/* Pops an item from the top of the stack, returning the value */
void *
pop(stack *items) {
    return removeDLL(items->stackItems, 0);
}

/* Shows item at the top of the stack */
void *
peekStack(stack *items) {
    return getDLL(items->stackItems, 0);
}

/* Returns size of stack */
int
sizeStack(stack *items) {
    return sizeDLL(items->stackItems);
}

/* Prints out content of stack */
void
displayStack(FILE *fp, stack *items) {
    displayDLL(fp, items->stackItems);
}
