#include "binary_trees.h"

/**
 * array_to_bst - a function that builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array
 * @size: size of the array
 * Return: a pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root, *check_failure;

	root = NULL;
	for (i = 0; i < size; i++)
	{
		check_failure = bst_insert(&root, array[i]);
		if (!check_failure)
			return (NULL);
	}
	return (root);
}
