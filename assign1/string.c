#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "string.h"

string *
newString (int x)
{
  string *p = malloc (sizeof (string));
  if (p == 0)
    {
      fprintf (stderr, "out of memory\n");
      exit (-1);
    }
  p->value = x;
  return p;
}

int
getString (string * v)
{
  return v->value;
}

int
setString (string * v, int x)
{
  int old = v->value;
  v->value = x;
  return old;
}

void
displayString (FILE * fp, void *v)
{
  fprintf (fp, "%d", getString ((string *) v));
}

int
compareString (void *v, void *w)
{
  return ((string *) v)->value - ((string *) w)->value;
}

void
freeString (string * v)
{
  free (v);
}
