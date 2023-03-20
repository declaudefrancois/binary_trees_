#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *y;

	if (!tree || !tree->left)
		return (tree);
	y = tree->left;
	y->parent = tree->parent;
	if (y->right)
		(y->right)->parent = tree;
	tree->left = y->right;
	y->right = tree;
	tree->parent = y;
	while (y->parent)
	{
		y = y->parent;
	}
	return (y);
}
