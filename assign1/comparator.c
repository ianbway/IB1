#include "comparator.h"
#include "string.h"
#include "real.h"
#include "integer.h"

int compareInteger(void *v, void *w);

int compareReal(void *v, void *w);

int compareString(void *v, void *w);

void displayInteger(FILE *fp, void *v);

void displayReal(FILE *fp, void *v); 
	
void displayString(FILE *fp, void *v); 
