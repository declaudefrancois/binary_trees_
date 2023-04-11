#include "binary_trees.h"

/**
 * compare_all_left_children -  compares the values of tree node
 * to all nodes of the left subtree
 * @tree: pointer to root node of the subtree
 * @child: pointer to the node of left child
 * Return: 1 if all values in left subtree are less than the value of tree,
 * 0 if not
 */
int compare_all_left_children(const binary_tree_t *tree, binary_tree_t *child)
{
	if (!child)
		return (1);
	if (tree->n <= child->n)
		return (0);
	return (1 * compare_all_left_children(tree, child->left)
			* compare_all_left_children(tree, child->right));
}

/**
 * compare_all_right_children -  compares the values of tree node
 * to all nodes of the right subtree
 * @tree: pointer to root node of the subtree
 * @child: pointer to the node of right child
 * Return: 1 if all values in right subtree are greater than the value of tree,
 * 0 if not
 */
int compare_all_right_children(const binary_tree_t *tree, binary_tree_t *child)
{
	if (!child)
		return (1);
	if (tree->n >= child->n)
		return (0);
	return (1 * compare_all_right_children(tree, child->left)
			* compare_all_right_children(tree, child->right));
}


/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if Binary Search Tree, 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if ((!tree->left && compare_all_right_children(tree, tree->right))
			|| (!tree->right && compare_all_left_children(tree, tree->left)))
		return (1);
	if (!compare_all_left_children(tree, tree->left)
			|| !compare_all_right_children(tree, tree->right))
		return (0);
	return (1 * binary_tree_is_bst(tree->left)
			* binary_tree_is_bst(tree->right));
}
