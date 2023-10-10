#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (!tree || !tree->right)
		return (tree);
	pivot = tree->right;

	pivot->parent = tree->parent;
	if (pivot->left)
		(pivot->left)->parent = tree;
	tree->right = pivot->left;

	pivot->left = tree;
	tree->parent = pivot;

	pivot->parent = NULL;
	return (pivot);
}
