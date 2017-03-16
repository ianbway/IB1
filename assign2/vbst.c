#include <stdio.h>
#include <stdlib.h>
#include "vbst.h"
#include "bst.h"

typedef struct vbstValue
		{
		void *value;
		int frequency;
		void (*display)(FILE *, void *);
		int (*compare)(void *,void *);
		} vbstValue;

//vbstValue *findVBSTNode(vbst *, void *);
//void displayVBSTValue(FILE *, vbstValue *);
//int compareVBSTValue(vbst *, vbstValue *);

static void displayVBSTValue(FILE *fp, void *value)
{
	vbstValue *v = value;

	v->display(fp, v->value);
	if(v->frequency > 1)
	{
		fprintf(fp, "-%d", v->frequency);
	}
}

static int compareVBSTValue(void *a, void *b)
{
	vbstValue *va = a;
	vbstValue *vb = b;
	int result = va->compare(va->value, vb->value);
	return result;
}

vbst *newVBST(void (*d)(FILE *,void *),int (*c)(void *,void *))
{
	vbst *v = malloc(sizeof(vbst));
	if (v == 0) 
	{
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}
	v->tree = newBST(displayVBSTValue,compareVBSTValue);
	v->display = d;
	v->compare = c;
	v->words = 0;
	v->size = 0;
	return v;
}

vbstValue *newVBSTValue(void (*d)(FILE *,void *),int (*c)(void *, void *))
{
	vbstValue *vVal = malloc(sizeof(vbstValue));
	vVal->value = 0;
	vVal->frequency = 1;
	vVal->display = d;
	vVal->compare = c;

  	return vVal;
}

void insertVBST(vbst *v,void *value)
{
	//create a new vbstValue item and check to see if it exists
	vbstValue *vVal = newVBSTValue(v->display, v->compare);
	
	//check to see if exists and update frequency count
  	bstNode *node = findBSTNode(v->tree,vVal);

	// create a new node, its frequency should be 1
	if (node == 0) 
	{
		insertBST(v->tree,value);
		v->size++;
	} 
	else 
	{
		//update the frequency of found node
		((vbstValue *)(node->value))->frequency++;
	}

	//update vbst word count
	v->words++;
}

vbstValue *findVBSTValue(vbst *v, void *value)
{
	vbstValue *vVal = newVBSTValue(v->display, v->compare);
	vVal->value = value;

  	bstNode *node = findBSTNode(v->tree,vVal);
	if (node==0) 
	{
		return 0;
	} 
	
	return (vbstValue *)(node->value);
}

int findVBST(vbst *v,void *value)
{
	vbstValue *vVal = findVBSTValue(v, value);

	if (vVal == 0)
	{
		return 0;
	}
	else 
	{
		return vVal->frequency;
	}
}

void deleteVBST(vbst *v,void *value)
{
	vbstValue *vVal = findVBSTValue(v, value);
	if (vVal == 0) 
	{
		return;
	}

	//check to see if node exists and update frequency count for deletion
	if (vVal->frequency > 1) 
	{
		vVal->frequency--;
	} 
	else 
	{
		bstNode *n = (bstNode *)vVal;
		bstNode *node = swapToLeafBSTNode(n);
		pruneBSTNode(v->tree,node);
		v->size--;
	}

	v->words--;
}
extern int sizeVBST(vbst *v) 
{
	return v->size;
}

extern int wordsVBST(vbst *v)
{
	return v->words;
}

extern void statisticsVBST(vbst *v,FILE *fp) 
{
	//print out items specific to vbst
	fprintf(fp,"Words/Phrases: %d\n",v->words);

	//print out items specific to bst
	statisticsBST(v->tree,fp);	
}

extern void displayVBST(FILE *fp,vbst *v) 
{
	displayBST(fp,v->tree);
}

