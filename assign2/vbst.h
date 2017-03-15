#include <stdio.h>
#include "bst.h"

#ifndef __VBST_INCLUDED__
#define __VBST_INCLUDED__
typedef struct vbst
		{
		bst *tree;
		void (*display)(FILE *,void *);
		int (*compare)(void *,void *);
		int size;
		int words;
		} rbt;

extern rbt *newVBST(void (*)(FILE *,void *),int (*)(void *,void *));
extern void insertVBST(rbt *,void *);
extern int findVBST(rbt *,void *);
extern void deleteVBST(rbt *,void *);
extern int sizeVBST(rbt *);
extern int wordsVBST(rbt *);
extern void statisticsVBST(rbt *,FILE *);
extern void displayVBST(FILE *,rbt *);
extern void checkVBST(rbt *);               //optional
#endif
