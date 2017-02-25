#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef __COMPARATOR_INCLUDED__
#define __COMPARATOR_INCLUDED__
typedef int (*Comparator)(void*,void*);
typedef void (*Printer)(FILE*,void*);
int intCompare(void *, void *);
int realCompare(void *, void *);
int stringCompare(void *,void *);
void intPrint(FILE *, void *);
void realPrint(FILE *, void *);
void stringPrint(FILE *, void *);

#endif
