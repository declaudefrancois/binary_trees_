#include "binary_trees.h"

/**
 * bst_search - seacrhes for a value in a Binary Search Tree
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to search in the tree
 * Return: a pointer to the node containing a value equals to value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node;

	if (!tree)
		return (NULL);
	node = (bst_t *)tree;
	while (node)
	{
		if (node->n == value)
			return (node);
		if (node->n > value)
			node = node->left;
		if (node->n < value)
			node = node->right;
	}
	return (NULL);
}
