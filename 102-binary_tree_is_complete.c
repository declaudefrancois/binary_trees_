#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if complete, 0 if not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *array[1024];
	int i, insert, old_node_has_no_child = 0;

	if (!tree)
		return (0);
	for (i = 0; i < 1024; i++)
		array[i] = NULL;
	i = 0;
	array[i] = (binary_tree_t *)tree;
	insert = 1;
	while (array[i])
	{
		if (!array[i]->left && array[i]->right)
			return (0);
		if ((array[i]->right || array[i]->left) && old_node_has_no_child == 1)
			return (0);
		if (!array[i]->right)
			old_node_has_no_child = 1;
		if (array[i]->left)
		{
			array[insert] = array[i]->left;
			insert++;
		}
		if (array[i]->right)
		{
			array[insert] = array[i]->right;
			insert++;
		}
		i++;
	}
	return (1);
}

