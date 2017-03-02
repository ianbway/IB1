#include "comparator.h"
#include "string.h"
#include "real.h"
#include "integer.h"

int intCompare(void *v, void *w) {
	return compareInteger(v, w);
}
int realCompare(void *v, void *w) {
	return compareReal(v, w);
}
int stringCompare(void *v, void *w) {
	return compareString(v, w);
}

void intPrint(FILE *fp, void *v) {
	displayInteger(fp, v);
}
void realPrint(FILE *fp, void *v) {
	displayReal(fp, v);
}
void stringPrint(FILE *fp, void *v) {
	displayString(fp, v);
}

