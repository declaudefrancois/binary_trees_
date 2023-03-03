#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node.
 *
 * @node: a pointer to the node to find the sibling.
 *
 * Return: A pointer to the sibling node or NULL
 *         if either node is NULL or the parent is NULL
 *         or the sibling is not found.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
