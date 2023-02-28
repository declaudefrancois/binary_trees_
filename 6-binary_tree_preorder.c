#include "binary_trees.h"

/**
 * binary_tree_preorder - Goes through a binary tree using
 * pre-order traversal.
 *
 * @tree: A pointer to the root of the tree to traverse.
 * @func: A function pointer being called for each node.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
