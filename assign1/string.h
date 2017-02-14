#include <stdio.h>

#ifndef __STRING_INCLUDED__
#define __STRING_INCLUDED__

typedef struct string
{
  int value;
} string;

extern string *newString (int);
extern int getString (string *);
extern int setString (string *, int);
extern void displayString (FILE *, void *);
extern int compareString (void *, void *);
extern void freeString (string *);

#define PINFINITY IN_MAX
#define NINFINITY IN_MIN

#endif
