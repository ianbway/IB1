#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "string.h"

string *
newString (char* x)
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

char*
getString (string * v)
{
  return v->value;
}

char*
setString (string * v, char* x)
{
  char* old = v->value;
  v->value = x;
  return old;
}

void
freeString (string * v)
{
  free (v);
}
