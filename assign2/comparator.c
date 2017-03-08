#include "comparator.h"
#include "string.h"
#include "real.h"
#include "integer.h"

int compareInteger(void *v, void *w)
{
	return ((integer *) v)->value - ((integer *) w)->value;
}

int compareReal(void *v, void *w)
{
	return ((real *) v)->value - ((real *) w)->value;
}

int compareString(void *v, void *w)
{
	string *s1 = (string*)v;
	string *s2 = (string*)w;
	char* c1 = (char *)s1->value;
	char* c2 = (char *)s2->value;
	return strcmp(c1,c2);
}

void displayInteger(FILE *fp, void *v)
{
	fprintf (fp, "%d", getInteger ((integer *) v));
}

void displayReal(FILE *fp, void *v)
{
	fprintf (fp, "%f", getReal ((real *) v));
}
	
void displayString(FILE *fp, void *v)
{
	fprintf (fp, "\"%s\"", getString ((string *) v));
}
