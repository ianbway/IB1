#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "dll.h"

stack *
newStack (void (*d) (FILE *, void *))
{
	stack *items = malloc(sizeof(stack));
	if (items == 0)
		{
		fprintf(stderr,"out of memory\n");
		exit(-1);
		}
	items->stackItems = newDLL(d);
	return items;
}

void
push (stack *items, void *value)
{
	insertDLL(items->stackItems,0,value);
}

void *
pop (stack *items)
{
	return removeDLL(items->stackItems,0);
}

void *
peekStack (stack *items)
{
	return getDLL(items->stackItems,0);
}

int
sizeStack (stack *items)
{
	return sizeDLL(items->stackItems);
}

void
displayStack (FILE *fp, stack *items)
{
	displayDLL(fp,items->stackItems);
}
