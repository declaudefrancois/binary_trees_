#include "binary_trees.h"

/**
 * binary_tree_balance  - measures the balance factor of a binary tree.
 *
 * @tree: A pointer the the root node of the tree to measure the balance
 * factor.
 *
 * Return: The int value of the balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	/* Respectively heights of the rigth and left trees from the root. */
	size_t height_l = 0;
	size_t height_r = 0;

	if (tree == NULL)
		return (0);

	/* Get the left and right subtrees heights. */
	height_l = binary_tree_height(tree->left);
	height_r = binary_tree_height(tree->right);

	/* Heights must be taken from the main root. */
	height_l += tree->left ? 1 : 0;
	height_r += tree->right ? 1 : 0;

	return (height_l - height_r);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure the height of
 *
 * Return: height of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
