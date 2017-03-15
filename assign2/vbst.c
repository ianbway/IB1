#include <stdio.h>
#include <stdlib.h>
#include "vbst.h"
#include "bst.h"

typedef struct vbstValue
		{
		void *value;
		int freq;
		void (*display)(FILE *,void *);
		int (*compare)(void *,void *);
		} vbstValue;


vbst *newVBST(void (*d)(FILE *,void *),int (*c)(void *,void *))
{
	vbst *v = malloc(sizeof(vbst));
	if (v == 0) {
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}
	v->tree = newBST(d,c);
	v->display = d;
	v->compare = c;
	v->words = 0;
	v->size = 0;
	return v;
}
void insertVBST(vbst *tree,void *value)
{
	//check to see if exists and update frequency count
	insertBST(tree,value);
}

vbstNode findVBSTNode(vbst *tree, void *value)
{
	vbstNode *node = (vbstNode)findBSTNode(tree,value);
	return node;
}

int findVBST(vbst *tree,void *value)
{
	vbstNode *node = findVBSTNode(tree,value);
	if (node == 0)
	{
		return 0;
	}
	else 
	{
		return 1;
	}
}
void deleteVBST(vbst *tree,void *value)
{
	//check to see if node exists and update frequency count
	deleteBST(tree,value);
}
extern int sizeVBST(vbst *tree) 
{
	return sizeBST(tree);	
}
extern int wordsVBST(vbst *tree)
{
	return tree->words;
}
extern void statisticsVBST(vbst *tree,FILE *fp) {
	//print out other stuff if needed
	statisticsBST(tree,fp);	
}
extern void displayVBST(FILE *fp,vbst *tree) {
	displayBST(fp,tree);
}
extern void checkVBST(vbst *tree) {
	checkBST(tree);
}
