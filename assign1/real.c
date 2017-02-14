#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "real.h"

real *
newReal (int x)
{
  real *p = malloc (sizeof (real));
  if (p == 0)
    {
      fprintf (stderr, "out of memory\n");
      exit (-1);
    }
  p->value = x;
  return p;
}

int
getReal (real * v)
{
  return v->value;
}

int
setReal (real * v, int x)
{
  int old = v->value;
  v->value = x;
  return old;
}

void
displayReal (FILE * fp, void *v)
{
  fprintf (fp, "%d", getReal ((real *) v));
}

int
compareReal (void *v, void *w)
{
  return ((real *) v)->value - ((real *) w)->value;
}

void
freeReal (real * v)
{
  free (v);
}
