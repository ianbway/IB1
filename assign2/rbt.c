#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"
#include "bst.h"

rbt *newRBT(void (*d)(FILE *,void *),int (*c)(void *,void *))
{
	rbt r = malloc(sizeof(rbt));
	if (r = 0) {
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}
	r->tree = newBST(d,c);
	r->display = d;
	r->compare = c;
	r->words = 0;
	r->size = 0;
	return r;

}

void insertRBT(rbt *tree,void *value)
{

}

int findRBT(rbt *tree,void *value)
{

}

void deleteRBT(rbt *tree,void *value)
{

}

int sizeRBT(rbt *tree)
{
	return tree->size;
}

int wordsRBT(rbt *tree)
{
	return tree->words;
}

void statisticsRBT(rbt *tree,FILE *fp)
{

}

void displayRBT(FILE *fp,rbt *tree)
{
	displayBST(fp,tree);
}

void checkRBT(rbt *tree)
{

}
