#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef __COMPARATOR_INCLUDED__
#define __COMPARATOR_INCLUDED__
typedef int (*Comparator)(void*,void*);
typedef void (*Printer)(FILE*,void*);
int compareInteger(void *, void *);
int compareReal(void *, void *);
int compareString(void *,void *);
void displayInteger(FILE *, void *);
void displayReal(FILE *, void *);
void displayString(FILE *, void *);

#endif
