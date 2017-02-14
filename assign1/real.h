#include <stdio.h>

#ifndef __REAL_INCLUDED__
#define __REAL_INCLUDED__

typedef struct real
{
  int value;
} real;

extern real *newReal (int);
extern int getReal (real *);
extern int setReal (real *, int);
extern void displayReal (FILE *, void *);
extern int compareReal (void *, void *);
extern void freeReal (real *);

#define PINFINITY IN_MAX
#define NINFINITY IN_MIN

#endif
