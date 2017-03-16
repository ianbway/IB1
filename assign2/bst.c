#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "queue.h"

//macros for min/max
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)

bst *newBST(void (*d) (FILE *,void *),int (*c) (void *,void *))
{
	bst *tree = malloc(sizeof(bst));
	if (tree == 0) 
	{
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}

	tree->root = 0;
	tree->display = d;
	tree->compare = c;
	tree->size = 0;

	return tree;
}

bstNode *insertBST(bst *tree,void *value)
{
	bstNode *node = malloc(sizeof(bstNode));
	bstNode *current = 0;
	bstNode *parent = 0;

	node->value = value;
	node->left = 0;
	node->right = 0;

	if (tree->root == 0)
	{
		tree->root = node;
	}
	else
	{
		current = tree->root;
		parent = 0;		
	}

	while(1) 
	{
		parent = current;
		//go to the left of the tree
		if (tree->compare(node->value, parent->value))
		{
			current = current->left;

			if (current == 0)
			{
				parent->left = node;
				break;
			}
		}
		//go to the right of the tree
		else
		{
			current = current->right;

			if (current == 0)
			{
				parent->right = node;
				break;
			}	
		}
	}

	tree->size++;
	return node;
}

int findBST(bst *tree,void *value)
{
	bstNode *node = findBSTNode(tree,value);
	if (node == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

bstNode *findBSTNode(bst *tree,void *value)
{
	bstNode *current = tree->root;

	while(current->value != value)
		{
			if (current != 0)
			{
				//go to the left tree
				if (tree->compare(current->value,value))
				{
					current = current->left;
				}
				//go to the right tree
				else
				{
					current = current->right;
				}

				//not found
				if(current == 0)
				{
					break;
				}
			}


		}

	return current;
}

void pruneBSTNode(bst *tree, bstNode *node)
{
	//is root node
	if (node == tree->root && tree->root->left == 0 && tree->root->right == 0)
	{
		tree->root = 0;
	}

	if(node->left == 0 && node->right == 0)
	{
		if(node->parent->left == node)
		{
			node->parent->left = 0;
		}
		else
		{
			node->parent->right = 0;
		}
	}
	tree->size--;
}

int sizeBST(bst *tree)
{
	return tree->size;
}

int getMaxDepth(bstNode *node)
{
	if (node == 0)
	{
		return 0;
	}

	int depth = 0;
	int maxLeft = getMaxDepth(node->left);
	int maxRight = getMaxDepth(node->right);
	depth = max(maxLeft, maxRight);
	return ++depth;
}

int getMinDepth(bstNode *node)
{
	if(node == 0)
	{
		return 0;
	}
	else
	{
			int depth = min(getMinDepth(node->left),getMinDepth(node->right));
			return ++depth;
	}
}
void statisticsBST(bst *tree,FILE *fp)
{
	bstNode *root = tree->root;
	int minDepth = getMinDepth(root);
	int maxDepth = getMaxDepth(root);

	fprintf(fp,"Nodes: %d\n", sizeBST(tree));
	fprintf(fp,"Minimum depth: %d\n", minDepth);
	fprintf(fp,"Maximum depth: %d\n", maxDepth);
}

void displayBST(FILE *fp,bst *tree)
{
	if(tree->root == 0)
	{
		fprintf(fp, "0:\n");
		return;
	}

	queue *newQ = newQueue(tree->display);
	enqueue(newQ, tree->root);//enqueue root and a null character to represent first level
	enqueue(newQ, 0);

	bstNode *node;

	int breadthLevel = 0;
	fprintf(fp, "%d: ", breadthLevel);

	while (sizeQueue(newQ)) //while the queue is not empty 
	{
		node = dequeue(newQ); //begin dequeue
		if(sizeQueue(newQ) == 0)
		{
			fprintf(fp, "\n");
			break;
		}
		else if(node == 0)//if the dequeue value is null
		{
			fprintf(fp,"\n");
			enqueue(newQ, 0);//enqueue null to represent end of level
			breadthLevel++;
			if(sizeQueue(newQ) > 0)
			{
				fprintf(fp, "%d: ", breadthLevel);
			}
		}
		else
		{
			if(node->left == 0 && node->right == 0)
			{
				fprintf(fp, "=");
			}

			tree->display(fp, node->value);

			if(node == tree->root)
			{
				fprintf(fp, "("); 
				tree->display(fp, node->parent->value);
				fprintf(fp, ")-");
			}
			else if(node->parent != 0)
			{
				if(tree->compare(node->value, node->parent->value)<0)
				{
					fprintf(fp, "("); 
					tree->display(fp, node->parent->value);
					fprintf(fp, ")-l"); 
				}
				else
				{
					fprintf(fp, "("); 
					tree->display(fp, node->parent->value);
					fprintf(fp, ")-r"); 
				}
			}

			if(peekQueue(newQ) != 0) 
			{
				fprintf(fp, " ");
			}

			if(node->left != 0)
			{
				enqueue(newQ, node->left);
			}

			if(node->right != 0)
			{
				enqueue(newQ, node->right);
			}
		}
	}
}

bstNode *swapToLeafBSTNode(bstNode *node)
{ 
	bstNode *hold;
	void *tmp;

	// its already a leaf node
	if (node->left == 0 && node->right == 0)
	{
		return node;
	}

	if(node->left != 0)//if n has a left child
	{
		hold = node->left;//hold value for later swap
		while (hold->right != 0)//after going left, search all the way right
		{
			//only gets us part way in some cases, need recursive call
			hold = hold->right;
		}
		//after you've reached the end of the left childs rightmost child
		//swap the original value for the value in the leaf
		tmp = node->value;
		node->value = hold->value;
		hold->value = tmp;
		return swapToLeafBSTNode(hold);//recursive call to go all the way to the leaf
	}
	else
	{
		hold = node->right;
		while(hold->left != 0)
		{
			hold = hold->left;
		}
		tmp = node->value;
		node->value = hold->value;
		hold->value = tmp;
		return swapToLeafBSTNode(hold);
	}
}

