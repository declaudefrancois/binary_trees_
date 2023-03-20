#include "binary_trees.h"

void free_tree_recursive(binary_tree_t *tree);

/**
 * binary_tree_delete - Deletes an entire binary tree.
 *
 * @tree: A pointer to the root of the tree to delete.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	free_tree_recursive(tree);
}

/**
 * free_tree_recursive - Frees each node of a tree recursively.
 *
 * @tree: A pointer to the root of the tree to free.
 */
void free_tree_recursive(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	free_tree_recursive(tree->left);
	free_tree_recursive(tree->right);
	free(tree);
}
