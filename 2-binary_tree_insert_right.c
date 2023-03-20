#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child
 * of another node.
 *
 * @parent: A pointer to the parent of the new node.
 * @value: The member value of the new node.
 *
 * Return: A pointer to the new Node or NULL on failure.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->right = parent->right;
	node->left = NULL;
	if (parent->right)
		parent->right->parent = node;
	parent->right = node;

	return (node);
}
