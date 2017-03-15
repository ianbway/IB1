#include <stdio.h>
#include "vbst.h"

vbst *newVBST(void (*d)(FILE *,void *),int (*c)(void *,void *))
{
	return vbst tree = newBST(d,c);
}
void insertVBST(vbst *tree,void *value)
{
	//check to see if exists and update frequency count
	insertBST(tree,value);
}
int findVBST(vbst *tree,void *value)
{
	return findBST(tree,value);
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
	return 0;
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
