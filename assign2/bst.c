#include <stdio.h>

bst *newBST(void (*d) (FILE *,void *),int (*c) (void *,void *))
{
	bst *tree = malloc(sizeof(bst));
	if (tree = 0) {
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}
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

	return node;
}

int findBST(bst *,void *)
{

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

bstNode *swapToLeafBSTNode(bstNode *)
{

}

void pruneBSTNode(bst *tree,bstNode*)
{

}

int sizeBST(bst *tree)
{
	return tree->size;
}

void statisticsBST(bst *tree,FILE *f)
{
	int words = 0;
	int nodes = 0;
	int minDepth = 0;
	int maxDepth = 0;
	printf("Words/Phrases: %d\n", words);
	printf("Nodes: %d\n", nodes);
	printf("Minimum depth: %d\n", minDepth);
	printf("Maximum depth: %d\n", maxDepth);
}

void displayBST(FILE *,bst *tree)
{

}

void checkBST(bst *tree)
{

}
