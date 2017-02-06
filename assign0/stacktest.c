#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "integer.h"

static void
showStack (stack * s)
{
  printf ("The stack is ");
  displayStack (stdout, s);
  printf (".\n");
}

int
main (int argc, char **argv)
{
  stack *items = newStack (displayInteger);
  showStack (items);
  push (items, newInteger (3));
  push (items, newInteger (2));
  showStack (items);
  printf ("The value ");
  displayInteger (stdout, pop (items));
  printf (" was popped.\n");
  showStack (items);
  return 0;
}
