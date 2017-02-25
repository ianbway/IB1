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
displayString (FILE * fp, void *v)
{
  fprintf (fp, "%s", getString ((string *) v));
}

int
compareString (void *v, void *w)
{
	char* s1 = (string)v->value;
	char* s2 = (string)w->value;
  return strcmp(s1,s2);
}

void
freeString (string * v)
{
  free (v);
}
