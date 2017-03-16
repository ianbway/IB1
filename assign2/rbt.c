#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"
#include "bst.h"

rbt *newRBT(void (*d)(FILE *,void *),int (*c)(void *,void *))
{
	rbt r = malloc(sizeof(rbt));
	if (r = 0) 
	{
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

void insertRBT(rbt *r,void *value)
{

}

int findRBT(rbt *r,void *value)
{

}

void deleteRBT(rbt *r,void *value)
{

}

int sizeRBT(rbt *r)
{
	return r->size;
}

int wordsRBT(rbt *r)
{
	return r->words;
}

void statisticsRBT(rbt *r,FILE *fp)
{
	//print out items specific to rbt
	fprintf(fp,"Words/Phrases: %d\n",r->words);

	//print out items specific to bst
	statisticsRBT(r->tree,fp);

}

void displayRBT(FILE *fp,rbt *r)
{
	displayBST(fp,r->tree);
}
