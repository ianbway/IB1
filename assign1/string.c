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
	string *s1 = (string*)v;
	string *s2 = (string*)w;
	char* c1 = (char *)s1->value;
	char* c2 = (char *)s2->value;
  return strcmp(c1,c2);
}

void
freeString (string * v)
{
  free (v);
}
