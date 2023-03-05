#include "binary_trees.h"

void traverse_level(
	const binary_tree_t *tree,
	int level,
	void (*func)(int)
);

/**
 * binary_tree_levelorder - goes through a binary tree using
 *                          level-order traversal.
 *
 * @tree: a pointer to the root node of the tree to traverse.
 * @func: is a pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t tree_h, i;

	if (!tree || !func)
		return;
	tree_h = binary_tree_height(tree);
	for (i = 1; i <= tree_h; i++)
		traverse_level(tree, i, func);
}

/**
 * levelorder_traverse - traverse all node at the given level.
 *
 * @level: The level to traverse.
 * @tree: A pointer to the root of the tree to traverse.
 * @func: A function pointer to call for each node.
 */
void traverse_level(
	const binary_tree_t *tree,
	int level,
	void (*func)(int)
)
{
	if (!tree)
		return;

	/* Skip all child up to those wo are at level `level`.*/
	if (level == 1)
	{
		func(tree->n);
		return;
	}
	traverse_level(tree->left, level - 1, func);
	traverse_level(tree->right, level - 1, func);
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

	if (!tree)
		return (0);

	height_l = binary_tree_height(tree->left);
	height_r = binary_tree_height(tree->right);
	return ((height_l > height_r ? height_l : height_r) + 1);
}
